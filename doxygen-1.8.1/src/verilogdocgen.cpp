/******************************************************************************
* Copyright (c) M.Kreis,2009 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Library General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*
* You may use and distribute this software under the terms of the
* GNU General Public License, version 2 or later
*****************************************************************************/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "verilogdocgen.h"
#include "verilogscanner.h"
#include "membergroup.h"
#include "vhdldocgen.h"
#include "doxygen.h"
#include "searchindex.h"
#include "commentscan.h"
#include "layout.h"
#include "arguments.h"

// sets the member spec variable for global variables
// needed for writing file declarations
static void setType(MemberList* ml);
static void parseDefineConstruct(QCString&, MemberDef*,OutputList& ol);
static void writeFunctionProto(OutputList& ol,const ArgumentList* al,const MemberDef* mdef);

static QDict<MemberDef> variableDict(10007);

static QDict<MemberDef> instPortDict(10007);
static QDict<MemberDef> classPortDict(10007);


static QDict<MemberDef> functionDict(5003);
static QDict<MemberDef> globalMemDict(5003);
static QList<MemberDef> includeMemList;
static QDict<MemberDef> classglobDict(17);
static QDict<ClassDef>  classInnerDict(17);


Entry* VerilogDocGen::getEntryAtLine(const Entry* ce,int line)
{
  EntryListIterator eli(*ce->children());
  Entry *found=0;
  Entry *rt;
  for (;(rt=eli.current());++eli)
  {
    if (rt->bodyLine==line)
    {
      found=rt;
    } // if
    if (!found) 
    {
      found=getEntryAtLine(rt,line);
    }
  }
  return found;
}// getEntryAtLine


static QList<Entry>  lineEntry;

QList<Entry>* VerilogDocGen::getEntryAtLine1(const Entry* ce,int line)
{
  EntryListIterator eli(*ce->children());
  Entry *found=0;
  Entry *rt;
  for (;(rt=eli.current());++eli)
  {
    if (rt->bodyLine==line)
    {
		lineEntry.insert(0,rt);
    } // if
   
    getEntryAtLine1(rt,line);
  }

  return &lineEntry;
}// getEntryAtLine




void VerilogDocGen::adjustMemberName(QCString& nn) 
{
  QRegExp regg("[_a-zA-Z]");
  int j=nn.find(regg,0);

  if (j>0)
   nn=nn.mid(j,nn.length());

 }//adjustRecordMember



QCString VerilogDocGen::convertTypeToString(int type,bool sing)
{
  uint ttype=(uint)type;
  switch(type){
  case(VerilogDocGen::MODULE) :
   if(sing)return "Module";
  return "Modules"; 
  case( VerilogDocGen::FUNCTION): 
  if(sing)return "Function";
  return "Functions";
 case( VerilogDocGen::TASK): 
  if(sing)return "Task";
  return "Tasks";
  case(VerilogDocGen::PRIMITIVE):
  if(sing)return "Primitive";
  return "Primitives";
  case(VerilogDocGen::PARAMETER):  
  if(sing) return "Parameter";
  return "Parameters";
  case(VerilogDocGen::COMPONENT): 
  if(sing) return "Module Instance";
  return "Module Instances";
  case( VerilogDocGen::PORT):
  if(sing) return "Port";
  return "Ports";
  case( VerilogDocGen::ALWAYS): 
  if(sing) return "Always Construct";
  else
  return "Always Constructs";
  case( VerilogDocGen::INPUT): 
  if(sing)return "Input";
  return "Inputs";
  case( VerilogDocGen::OUTPUT): 
  if(sing) return "Output";
  return "Outputs";
  case( VerilogDocGen::INOUT): 
  if(sing) return "Inout";
  return "Inouts";
   case(VerilogDocGen::FEATURE): 
   if(sing) return "Define";
  else
  return "Defines"; 
  case( VerilogDocGen::TIME): 
  return "Time"; 
  case( VerilogDocGen::INCLUDE): 
  if(sing) return "Include";
  return "Includes"; 
  case(VerilogDocGen::SIGNAL): 
  if(sing) 
    return "Signal";
  return "Signals";  
  case(VerilogDocGen::LIBRARY): 
  if(sing) 
    return "Library";
  return "Libraries"; 
  case(VerilogDocGen::CONFIGURATION): 
  if(sing) 
    return "Configuration";
  return "Configurations"; 
 case(VhdlDocGen::UCF_CONST): 
  if(sing) 
    return "Constraint";
  return "Constraints"; 
 case(VhdlDocGen::MISCELLANEOUS): 
  if(sing) 
    return "Miscellaneous";
    return "Miscellaneous"; 
  

  default: return "";
  }
  return "";
 
} // convertType


 void setType(MemberList *ml){
  if (ml==0) return ;
  MemberDef *mdd=0;
  MemberListIterator mmli(*ml);
  for ( ; (mdd=mmli.current()); ++mmli )
  {
     QCString type(mdd->typeString());
     if(type=="feature")
       mdd->setMemberSpecifiers(VerilogDocGen::FEATURE);
     else if(type=="include") 
          mdd->setMemberSpecifiers(VerilogDocGen::INCLUDE);
     else if(type=="library") 
          mdd->setMemberSpecifiers(VerilogDocGen::LIBRARY);
	 else if(type=="configuration") 
		 mdd->setMemberSpecifiers(VerilogDocGen::CONFIGURATION);
		  else if (stricmp(mdd->typeString(),"misc")==0)
    {
      mdd->setMemberSpecifiers(VhdlDocGen::MISCELLANEOUS);        
    } 
    else if (stricmp(mdd->typeString(),"ucf_const")==0)
    {
		mdd->setMemberSpecifiers(VhdlDocGen::UCF_CONST);        
    } 
   }
  } 
                    
 void VerilogDocGen::writeVerilogDeclarations(MemberList* ml,OutputList &ol,
               ClassDef *cd,NamespaceDef *nd,FileDef *fd,GroupDef *gd,
               const char *title,const char *subtitle,bool showEnumValues,int type) {


  MemberDef *mdd=NULL;
 // if(ml==NULL) return;
  MemberListIterator mmli(*ml);
  setType(ml);
 
if (!VhdlDocGen::membersHaveSpecificType(ml,type)) return;
  
  if (title) 
  {
    ol.startMemberHeader(title);
    ol.parseText(title);
    ol.endMemberHeader();
	ol.docify(" ");
  }
  if (subtitle && subtitle[0]!=0) 
  {
    //printf("subtitle=`%s'\n",subtitle);
    ol.startMemberSubtitle();
    ol.parseDoc("[generated]",-1,0,0,subtitle,FALSE,FALSE);
    ol.endMemberSubtitle();
  } 
  
  VerilogDocGen::writePlainVerilogDeclarations(mdd,ml,ol,cd,nd,fd,gd,type);
 
  if (ml->getMemberGroupList())
  {
    MemberGroupListIterator mgli(*ml->getMemberGroupList());
    MemberGroup *mg;
    while ((mg=mgli.current()))
    {
     // assert(0);
       if (VhdlDocGen::membersHaveSpecificType(mg->members(),type))
    
     {
      //printf("mg->header=%s\n",mg->header().data());
      bool hasHeader=mg->header()!="[NOHEADER]";
      ol.startMemberGroupHeader(hasHeader);
      if (hasHeader)
      {
        ol.parseText(mg->header());
      }
      ol.endMemberGroupHeader();
      if (!mg->documentation().isEmpty())
      {
        //printf("Member group has docs!\n");
        ol.startMemberGroupDocs();
        ol.parseDoc("[generated]",-1,0,0,mg->documentation()+"\n",FALSE,FALSE);
        ol.endMemberGroupDocs();
      }
      ol.startMemberGroup();
      //printf("--- mg->writePlainDeclarations ---\n");
      //mg->writePlainDeclarations(ol,cd,nd,fd,gd);
          VerilogDocGen::writePlainVerilogDeclarations(0,mg->members(),ol,cd,nd,fd,gd,type);
   
      ol.endMemberGroup(hasHeader);
     }
      ++mgli;
    }
  }
 
 }// writeVerilogDeclarations



void VerilogDocGen::writePlainVerilogDeclarations(MemberDef* mdef,MemberList* mlist,OutputList &ol,
               ClassDef *cd,NamespaceDef *nd,FileDef *fd,GroupDef *gd,int specifier){

  
  ol.pushGeneratorState();

  bool first=TRUE;
  MemberDef *md;
  MemberListIterator mli(*mlist);
  for ( ; (md=mli.current()); ++mli )
  { 
	int mems=md->getMemberSpecifiers();
	 
    if (md->isBriefSectionVisible() && (mems==specifier))
    {
             if (first) ol.startMemberList(),first=FALSE;
			VerilogDocGen::writeVerilogDeclarations(md,ol,cd,nd,fd,gd,false);
    }//if
  }//for
  if (!first) ol.endMemberList(); 
  
}//plainDeclaration

void VerilogDocGen::writeVerilogDeclarations(MemberList* ml,OutputList& ol,GroupDef* gd,ClassDef* cd,FileDef* fd){

	  VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::LIBRARY,FALSE),0,FALSE,VerilogDocGen::LIBRARY); 
	  VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::CONFIGURATION,FALSE),0,FALSE,VerilogDocGen::CONFIGURATION);   
	  VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::PORT,FALSE),0,FALSE,VerilogDocGen::PORT); 
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::MODULE,FALSE),0,FALSE,VerilogDocGen::MODULE);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::FEATURE,FALSE),0,FALSE,VerilogDocGen::FEATURE);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::INCLUDE,FALSE),0,FALSE,VerilogDocGen::INCLUDE);
           VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::SIGNAL,FALSE),0,FALSE,VerilogDocGen::SIGNAL);
  
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::FUNCTION,FALSE),0,FALSE,VerilogDocGen::FUNCTION);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::ALWAYS,FALSE),0,FALSE,VerilogDocGen::ALWAYS);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::TASK,FALSE),0,FALSE,VerilogDocGen::TASK);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::INPUT,FALSE),0,FALSE,VerilogDocGen::INPUT);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::INOUT,FALSE),0,FALSE,VerilogDocGen::INOUT);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::OUTPUT,FALSE),0,FALSE,VerilogDocGen::OUTPUT);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::PARAMETER,FALSE),0,FALSE,VerilogDocGen::PARAMETER);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VerilogDocGen::COMPONENT,FALSE),0,FALSE,VerilogDocGen::COMPONENT);
    
    
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VhdlDocGen::MISCELLANEOUS,FALSE),0,FALSE,VhdlDocGen::MISCELLANEOUS);
      VerilogDocGen::writeVerilogDeclarations(ml,ol,cd,0,fd,gd,VerilogDocGen::convertTypeToString(VhdlDocGen::UCF_CONST,FALSE),0,FALSE,VhdlDocGen::UCF_CONST);
   
 	 }



void VerilogDocGen::writeVerilogDeclarations(MemberDef* mdef,OutputList &ol,
                   ClassDef *cd,NamespaceDef *nd,FileDef *fd,GroupDef *gd,
                   bool inGroup) {
 
  static bool bComp=false;
  LockingPtr<MemberDef> lock(mdef,mdef);
 
  Definition *d=0;
  ASSERT (cd!=0 || nd!=0 || fd!=0 || gd!=0); // member should belong to something
 if (cd) d=cd; else if (nd) d=nd; else if (fd) d=fd; else d=gd;
//if (cd) d=cd;
  // write tag file information of this member
 int memType=mdef->getMemberSpecifiers();

  if (!Config_getString("GENERATE_TAGFILE").isEmpty())
  {
    Doxygen::tagFile << "    <member kind=\"";
    Doxygen::tagFile << VerilogDocGen::convertTypeToString(memType);
     
    Doxygen::tagFile << "\">" << endl;
    Doxygen::tagFile << "      <type>" << convertToXML(mdef->typeString()) << "</type>" << endl;
    Doxygen::tagFile << "      <name>" << convertToXML(mdef->name()) << "</name>" << endl;
    Doxygen::tagFile << "      <anchorfile>" << convertToXML(mdef->getOutputFileBase()+Doxygen::htmlFileExtension) << "</anchorfile>" << endl;
    Doxygen::tagFile << "      <anchor>" << convertToXML(mdef->anchor()) << "</anchor>" << endl;
  
	if(memType==VerilogDocGen::FUNCTION)
		Doxygen::tagFile << "      <arglist>" << convertToXML(VhdlDocGen::convertArgumentListToString(mdef->argumentList().pointer(),true)) << "</arglist>" << endl;
    else if(memType==VerilogDocGen::ALWAYS)
		Doxygen::tagFile << "      <arglist>" << convertToXML(VhdlDocGen::convertArgumentListToString(mdef->argumentList().pointer(),false)) << "</arglist>" << endl;
	else{
	Doxygen::tagFile << "      <arglist>" << convertToXML(mdef->argsString()) << "</arglist>" << endl;
   Doxygen::tagFile << "      <arglist>" << convertToXML(mdef->typeString()) << "</arglist>" << endl; 
    }
	mdef->writeDocAnchorsToTagFile();
    Doxygen::tagFile << "    </member>" << endl;
 
  }
  
  // write search index info
  if (Doxygen::searchIndex)
  {
    Doxygen::searchIndex->setCurrentDoc(mdef->qualifiedName(),mdef->getOutputFileBase(),mdef->anchor());
    Doxygen::searchIndex->addWord(mdef->localName(),TRUE);
    Doxygen::searchIndex->addWord(mdef->qualifiedName(),FALSE);
  }

  QCString cname  = d->name();
  QCString cfname = mdef->getOutputFileBase();

 // HtmlHelp *htmlHelp=0;
//  bool hasHtmlHelp = Config_getBool("GENERATE_HTML") && Config_getBool("GENERATE_HTMLHELP");
//  if (hasHtmlHelp) htmlHelp = HtmlHelp::getInstance();

  // search for the last anonymous scope in the member type
  ClassDef *annoClassDef=mdef->getClassDefOfAnonymousType();

  // start a new member declaration
  bool isAnonymous =  annoClassDef; // || m_impl->annMemb || m_impl->annEnumType;
  ///printf("startMemberItem for %s\n",name().data());
 
//  if(mdef->getMemberSpecifiers()==VerilogDocGen::FEATURE)
//  ol.startMemberItem(mdef->anchor(),3); //? 1 : m_impl->tArgList ? 3 : 0);
//  else
 ol.startMemberItem(mdef->anchor(), 0);// ? 1 : m_impl->tArgList ? 3 : 0);


  // If there is no detailed description we need to write the anchor here.
  bool detailsVisible = mdef->isDetailedSectionLinkable();
  if (!detailsVisible) // && !m_impl->annMemb)
  {
     QCString doxyName=mdef->name().copy();
    if (!cname.isEmpty()) doxyName.prepend(cname+"::");
    QCString doxyArgs=mdef->argsString();
    ol.startDoxyAnchor(cfname,cname,mdef->anchor(),doxyName,doxyArgs);

    ol.pushGeneratorState();
    ol.disable(OutputGenerator::Man);
    ol.disable(OutputGenerator::Latex);
    ol.docify("\n");
    ol.popGeneratorState();
    
  }
// *** write type
     /*Verilog CHANGE */
   VhdlDocGen::adjustRecordMember(mdef); 
  
   QCString ltype(mdef->typeString()); 
   QCString largs(mdef->argsString());
 
   int mm=mdef->getMemberSpecifiers();

   ClassDef *kl=NULL;
   FileDef *fdd=NULL;
   LockingPtr<ArgumentList> alp = mdef->argumentList();
   QCString nn;
   if(gd)gd=NULL;
   switch(mm)
   {
       
       case VhdlDocGen::MISCELLANEOUS:
      VhdlDocGen::writeCodeFragment(mdef,ol);
      break;
      case VhdlDocGen::UCF_CONST: 
		  mm=mdef->name().findRev('_');
        if(mm>0)		 
		  mdef->setName(mdef->name().left(mm));
		  VhdlDocGen::writeUCFLink(mdef,ol);
        break;
   case VerilogDocGen::INCLUDE: 
     bool ambig;
     largs=mdef->name();
     fdd=findFileDef(Doxygen::inputNameDict,largs.data(),ambig);
     if(fdd){
      QCString fbb=fdd->getFileBase();
      fbb=fdd->getReference();
     fbb= fdd->getOutputFileBase();
     fbb=fdd->getSourceFileBase();
     fbb=fdd->convertNameToFile(largs.data(),true);
     fbb=fdd->getPath();
     fbb+=fdd->getOutputFileBase()+".html";
   
       ol.writeObjectLink(fdd->getReference(),
                     fdd->getOutputFileBase(),
		     0,
		     fdd->name());
	}
	else
	 VhdlDocGen::formatString(largs,ol,mdef);	
	
        break;
	case VerilogDocGen::FEATURE: 
	
       	parseDefineConstruct(largs,mdef,ol);
		
		break;

	case VerilogDocGen::MODULE: 
       	ol.startBold();
        VhdlDocGen::formatString(ltype,ol,mdef);
        ol.endBold();
		ol.insertMemberAlign();
	   //writeLink(mdef,ol);
    case VerilogDocGen::PORT:
 		  VhdlDocGen::writeLink(mdef,ol);
		 ol.insertMemberAlign();
		  if(largs.length()>0)
		    VhdlDocGen::formatString(largs,ol,mdef);
          if(ltype.length()>0)
		    VhdlDocGen::formatString(ltype,ol,mdef);	  
		  break;
    case VerilogDocGen::ALWAYS:
	     VhdlDocGen::writeLink(mdef,ol);  
	     ol.insertMemberAlign();
		 VhdlDocGen::writeProcessProto(ol,alp.pointer(),mdef);
		break;
   case VerilogDocGen::FUNCTION:
    case VerilogDocGen::TASK:      
         VhdlDocGen::writeLink(mdef,ol);  
	   	  ol.docify(" ");// need for pdf has no effect in html
		 ol.insertMemberAlign();
		 if(ltype.length()>0)
		    VhdlDocGen::formatString(ltype,ol,mdef);
	 	   writeFunctionProto(ol,alp.pointer(),mdef);
		 break;
   case VerilogDocGen::SIGNAL:
          if(largs.length()>0)
		    VhdlDocGen::formatString(largs,ol,mdef);
           ol.docify(" ");
       	    ol.insertMemberAlign();
        
            VhdlDocGen::writeLink(mdef,ol);  
            ol.docify(" ");
	     if(ltype.length())
		    VhdlDocGen::formatString(ltype,ol,mdef);       
        break;
   case VerilogDocGen::CONFIGURATION:
   case VerilogDocGen::LIBRARY:
         VhdlDocGen::writeLink(mdef,ol);  
         break;
   case VerilogDocGen::INPUT:
   case VerilogDocGen::OUTPUT:
   case VerilogDocGen::INOUT:
   case VerilogDocGen::PARAMETER:   
          VhdlDocGen::writeLink(mdef,ol);   
	     ol.docify(" ");	   	
		 ol.insertMemberAlign();
		 if(ltype.length()>0){
		    VhdlDocGen::formatString(ltype,ol,mdef);
	   	   ol.writeString("  ");
	    }
	  //ol.insertMemberAlign();
	  if(largs.length()>0)
		    VhdlDocGen::formatString(largs,ol,mdef);	 
	 	 break;
     case VerilogDocGen::COMPONENT:
		 //VhdlDocGen::writeLink(mdef,ol);
        if(true)
		{
		nn=mdef->name();
		kl=getClass(nn);
	  //if(kl==NULL){
	    ol.startBold();
	    QCString inst=mdef->name()+"::"+ltype;
          ol.writeObjectLink(mdef->getReference(),
                     mdef->getOutputFileBase(),
		     mdef->anchor(),
		     inst.data());
        ol.docify("  ");
        ol.endBold();
       //}
       	ol.insertMemberAlign();
	
		if(kl) {
			nn=kl->getOutputFileBase();
		
		ol.pushGeneratorState();
        ol.disableAllBut(OutputGenerator::Html);
         ol.docify("   ");
        QCString name=VerilogDocGen::getClassTitle(kl);
	     name=VhdlDocGen::getIndexWord(name.data(),1);
	    // ol.insertMemberAlign();
	 
	     ol.startBold();
		ol.docify(name.data());
		ol.endBold();
		ol.startEmphasis();
		   ol.docify(" ");
      
		   ol.writeObjectLink(kl->getReference(),kl->getOutputFileBase(),0,mdef->name().data());
	    ol.endEmphasis();
        ol.popGeneratorState();
		}
		if(largs.data())
			{
				ol.docify(" ");
			ol.docify(largs.data());
			}

        } 
		break;
  default: break;
   }

   bool htmlOn = ol.isEnabled(OutputGenerator::Html);
  if (htmlOn &&  !ltype.isEmpty())
  {
    ol.disable(OutputGenerator::Html);
  }
  if (!ltype.isEmpty()) ol.docify(" ");
  
  if (htmlOn) 
  {
    ol.enable(OutputGenerator::Html);
  }

  if (!detailsVisible)// && !m_impl->annMemb)
  {
    ol.endDoxyAnchor(cfname,mdef->anchor());
  }

  //printf("endMember %s annoClassDef=%p annEnumType=%p\n",
  //    name().data(),annoClassDef,annEnumType);
  ol.endMemberItem();
   if (!mdef->briefDescription().isEmpty() &&   Config_getBool("BRIEF_MEMBER_DESC") /* && !annMemb */)
  {
	  ol.startMemberDescription(mdef->anchor());
    ol.parseDoc(mdef->briefFile(),mdef->briefLine(),mdef->getOuterScope()?mdef->getOuterScope():d,mdef,mdef->briefDescription(),TRUE,FALSE,0,TRUE,FALSE);
    if (detailsVisible) 
    {
      ol.pushGeneratorState();
      ol.disableAllBut(OutputGenerator::Html);
      //ol.endEmphasis();
      ol.docify(" ");
      if (mdef->getGroupDef()!=0 && gd==0) // forward link to the group
      {
        ol.startTextLink(mdef->getOutputFileBase(),mdef->anchor());
      }
      else // local link
      {
        ol.startTextLink(0,mdef->anchor());
      }
      ol.endTextLink();
      //ol.startEmphasis();
      ol.popGeneratorState();
    }
    //ol.newParagraph();

    ol.endMemberDescription();
    // if(VhdlDocGen::isComponent(mdef))
   //    ol.lineBreak();
  }
   mdef->warnIfUndocumented();

  }// end writeVerilogDeclaration


// returns the name of module/primitive

QCString VerilogDocGen::getClassTitle(const ClassDef* cdef){
if(cdef->protection()==Public)
  return cdef->className()+" Module";
return cdef->className()+" Primitive";
}// getClassTitle


//-----------------< Code Parsing >------------------------------------------------

static bool buildInst=false;

void buildVariableDict(ClassDef *inst, ClassDef *cl)
{
	 MemberList *instPort=NULL;
	 MemberList *classPort=NULL;
      
	  instPortDict.clear();
	  classPortDict.clear();
   
    if(inst!=NULL)
        instPort=inst->getMemberList(MemberList::variableMembers); 
	 
	if(cl!=NULL)
	 classPort=cl->getMemberList(MemberList::variableMembers); 


	  if(instPort)
		  {
            MemberListIterator mnii(*instPort);
            MemberDef *md;
			for (mnii.toFirst();(md=mnii.current());++mnii){
				//printf("\n Inst: %s %s %s",md->name().data(),md->getOutputFileBase().data(),md->getReference().data());
				 instPortDict.insert(md->name().data(),md);
				}
		  }

	  if(classPort)
		  {
             MemberListIterator mnii(*classPort);
			 MemberDef *md;
			 for (mnii.toFirst();(md=mnii.current());++mnii){
			//	 printf("\n Class: %s %s %s",md->name().data(),md->getOutputFileBase().data(),md->getReference().data());
				 classPortDict.insert(md->name().data(),md);
				 }
		  }
}//funct

void buildVariableDict(ClassDef *cd)
{
   
if(cd==0) return;
variableDict.clear();

	MemberList* ml=cd->getMemberList(MemberList::variableMembers); 
     if(ml)
		  {
             MemberListIterator mnii(*ml);
			 MemberDef *md;
             for (mnii.toFirst();(md=mnii.current());++mnii)
                variableDict.insert(md->name().data(),md);
		 }

     ml=cd->getMemberList(MemberList::pubMethods); 
	 if(ml)
		  {
             MemberListIterator mnii(*ml);
			 MemberDef *md;
             for (mnii.toFirst();(md=mnii.current());++mnii)
                variableDict.insert(md->name().data(),md);
		 }
}

MemberDef* VerilogDocGen::findInstMember(QCString & cl,QCString & inst,QCString & key,bool b)
	{
     ClassDef* cdInst=0;
	 ClassDef* cdClass=0;
	 MemberDef *mdef=NULL;
	 if(!cl.isEmpty())
		 cdClass=getClass(cl.data());

	  if(!inst.isEmpty())
		 cdInst=getClass(inst.data());

    if(!buildInst)
		{
         buildVariableDict(cdInst,cdClass);
         buildInst=true;
		}

      if(!b) 
		  return  classPortDict.find(key.data());
	  else
		  return  instPortDict.find(key.data());

    return NULL;
	}//find


MemberDef* VerilogDocGen::findMember(QCString& className, QCString& memName,int type)
{
	ClassDef* cd;
	MemberDef *mdef=NULL;
	bool feat=false;
    buildInst=false;
	
	cd=getClass(className.data());
  //  if(!cd) return NULL;

	 if(memName.contains('`'))
     memName.stripPrefix("`");
  
	 mdef=VerilogDocGen::findMemberDef(cd,memName,MemberList::variableMembers,type,feat);
     if(mdef) return mdef;
  	
 //    mdef=VerilogDocGen::findMemberDef(cd,memName,MemberList:: pubMethods,type,feat);
 //   if(mdef) return mdef;
  
 //    QCString file=VerilogDocGen::getFileNameFromString(cd->getDefFileName().data());
 //    mdef = findGlobalMember(file,memName);
	return mdef;

}//findMember


 MemberDef* VerilogDocGen::findMemberDef(ClassDef* cd,QCString& key,MemberList::ListType type,int spec,bool def)
 {

    static QCString className;
	static QCString prevName;
    static ClassDef* sClass=0;

	MemberDef  *mem=NULL;

	if(cd==0)
	{       
 	  mem=globalMemDict.find(key.data());
	  if(mem) return mem;
	  return NULL;
	}
	className=cd->name();
	 
  if(prevName != className )
  {
     prevName=className;
	 buildVariableDict(cd);
  }
  

	  if(mem==0)
		  mem=variableDict.find(key.data());
	  if(mem)
	  { 
		 return mem;
	  }
      mem=globalMemDict.find(key.data());
	  if(mem)
		 return mem;
	  	
 return NULL;


}//findMemberDef


void 
VerilogDocGen::buildGlobalVerilogVariableDict(const FileDef* fd,bool clear,int level)
{
   if(fd==0)return;
   
   if(clear)
   {
     globalMemDict.clear();
     classInnerDict.clear();
   }

 
   MemberDef *md=NULL;
   MemberList *ml=	fd->getMemberList(MemberList::decVarMembers);
   if(ml!=NULL) 
   {
   MemberListIterator fmni(*ml);
      
	for (fmni.toFirst();(md=fmni.current());++fmni)
	{
		//VhdlDocGen::adjustRecordMember(md);
		//if(stricmp(md->typeString(),"include")==0)
		/*
	    if(!findIncludeName(md->name().data()))
		{
			//	printf("\n insert %s",md->name());	
			    includeMemList.append(md);
		}
		*/
   //		printf("\n %s ....  ",md->name().data());
   //		ClassDef *ch=md->getClassDef();
   //		if(ch==0)
		globalMemDict.insert(md->name().data(),md);
	}
   }

   ml=	fd->getMemberList(MemberList::decFuncMembers);
   if(ml!=0)
   {
   MemberListIterator fmni(*ml);
   for (fmni.toFirst();(md=fmni.current());++fmni)
	{
		VhdlDocGen::adjustRecordMember(md);
		globalMemDict.insert(md->name().data(),md);
	}
   }
  } 


MemberDef* VerilogDocGen::findDefinition(ClassDef *cd, QCString& memName){
 MemberDef *md;
 MemberList *ml=	cd->getMemberList(MemberList::variableMembers);
  if(ml==NULL) return NULL;
    MemberListIterator fmni(*ml);
     
	    for (fmni.toFirst();(md=fmni.current());++fmni)
        {
            if(md->getMemberSpecifiers()==VerilogDocGen::INCLUDE){
          
		
			ClassDef* cdef=getClass(md->name());
			 if(cdef){	 
			    MemberDef* mdd=VerilogDocGen::findMemberDef(cdef,memName,MemberList::variableMembers,-1,false);
               MemberList *ml=	cdef->getMemberList(MemberList::variableMembers);
			   assert(ml);
			   if(mdd) return mdd;
			  MemberListIterator fmni(*ml);
      

			  //assert(false);
			 }
		  }
		}//for
 return NULL;
}//findDefinition

/*
MemberName* VerilogDocGen::findMemberNameSDict(QCString& mName,const QCString& className) 
{
MemberName *mn=0;
MemberDef *md;
  MemberNameSDict::Iterator mnli(*Doxygen::memberNameSDict);
  // for each member name
  for (mnli.toFirst();(mn=mnli.current());++mnli)
  {
    QCString temp(mn->memberName());
    VhdlDocGen::adjustMemberName(temp);
    if(stricmp(mName.data(),temp.data())==0){
      MemberNameIterator mni(*mn);
      for (mni.toFirst();(md=mni.current());++mni)
      {
        ClassDef *cd=md->getClassDef();
        if(cd){
         QCString nn=cd->displayName();
         if(stricmp(nn.data(),className.data())==0)
          return mn;
        }
      }
    }//if 
  }
  
  return 0;
  }//findMemberNameSdict
*/

void VerilogDocGen::initEntry(Entry *e)
{
  e->fileName +=getVerilogParsingFile();
  e->lang=SrcLangExt_VERILOG;
  initGroupInfo(e);
}


 /*!
 * writes a function/Task prototype to the output
 */

void writeFunctionProto(OutputList& ol,const ArgumentList* al,const MemberDef* mdef)
{
  if (al==0) return;
  ArgumentListIterator ali(*al);
  Argument *arg;
  bool sem=FALSE;
  int len=al->count();
  ol.startBold();
  ol.docify(" ( ");    
  ol.endBold();
  if (len>2)
  {
    //ol.lineBreak();
	ol.docify("\n ");;
  }
  for (;(arg=ali.current());++ali)
  {
    ol.startBold();
    if (sem && len < 3)
    {
      ol.docify(" , ");
    }
   

	QCString nn=arg->name.simplifyWhiteSpace();
    VerilogDocGen::adjustMemberName(nn);
   // nn+=" ";
    VhdlDocGen::formatString(nn,ol,mdef);
	QCString qargs=arg->type.simplifyWhiteSpace();
	QCString att=arg->defval.simplifyWhiteSpace();
    if (!att.isEmpty()) 
    { 
      const QCString* str=VerilogDocGen::findKeyWord(att.data());
    //  att+=" ";
      if (str==0)
	VhdlDocGen::formatString(att,ol,mdef);
      else
	VhdlDocGen::startFonts(att,str->data(),ol);         
    }  
ol.docify(":");
    //VhdlDocGen::startFonts("in ","stringliteral",ol);
    const QCString* str=VerilogDocGen::findKeyWord(qargs.data());
   // ol.startEmphasis();
    if (str==0)
      VhdlDocGen::formatString(qargs,ol,mdef);
    else
      VhdlDocGen::startFonts(qargs,str->data(),ol);         
  //   ol.endEmphasis();
     sem=TRUE;    
    ol.endBold();
    if (len > 2)    
    {
      ol.docify("\n");;
		//ol.lineBreak();
    }
  }
  ol.startBold();    
  ol.docify(" )");    
  const char *exp=mdef->excpString();
  if(exp)
  {
    ol.insertMemberAlign();
    ol.docify("[ ");
    ol.docify(exp);
    ol.docify(" ]");
  }
  ol.endBold();  
}
 
  QCString VerilogDocGen::getFileNameFromString(const char* fileName){
  
  QCString qfile(fileName);
    QStringList ql=QStringList::split('/',qfile);
	QCString lp=ql.last().data();
	return lp;
  
  }

 void parseDefineConstruct(QCString & largs, MemberDef* mdef ,OutputList& ol)
{
        
//	QCString largs=mdef->getDefinition();
	    int kr=largs.contains("\\?");	  
	
	
	    ol.startBold();
        VhdlDocGen::writeLink(mdef,ol);
	    ol.docify(" ");
		ol.insertMemberAlign();
		ol.startTextBlock();
		if(kr>0)
		{
			largs=mdef->getDefinition();
			largs.stripPrefix("feature");
			while(largs.stripPrefix(" "));
			largs.stripPrefix(mdef->name().data());
			QStringList ql=QStringList::split("\\?",largs,false);
			for(uint i=0;i<ql.count();i++)
			{
			//	ol.startParagraph();
				QCString val=ql[i].data();			
				//ol.codify(val.data());
				VhdlDocGen::formatString(val,ol,mdef);			
			    // ol.lineBreak();
				//	ol.endParagraph();
			}
		}
		else
		VhdlDocGen::formatString(largs,ol,mdef);
		ol.endTextBlock(true);
		ol.endBold();
}

void VerilogDocGen::writeSource(MemberDef *mdef,OutputList& ol,QCString & cname)
{
  //  Definition d=(Definition)mdef;
  static bool optVerilog = Config_getBool("OPTIMIZE_OUTPUT_VERILOG");
 /*
  if(optVerilog){
  VerilogDocGen::writeSource(mdef,ol,cname);
   return; 
   
  }
  */
  QCString fdd=mdef->getDefFileExtension();
  QCString scope=mdef->getScopeString();
  QCString codeFragment=mdef->documentation();
  //FileDef *fd=mdef->getFileDef();
  FileDef *fd=mdef->getBodyDef();
  QCString defFileName;
  assert(fd);
  int start=mdef->getStartBodyLine();
  int end=mdef->getEndBodyLine();
  QStringList qsl=QStringList::split("\n",codeFragment);

  ParserInterface *pIntf = Doxygen::parserManager->getParser(fdd.data());
  pIntf->resetCodeParserState();

  ol.startParagraph();
  ol.startCodeFragment();
 
  ol.endCodeFragment();
  ol.endParagraph();

  mdef->writeSourceDef(ol,cname);
  mdef->writeSourceRefs(ol,cname);
  mdef->writeSourceReffedBy(ol,cname);
}
