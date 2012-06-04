/******************************************************************************
* Copyright (c) M.Kreis,2009 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
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
****************************************************************************/

/****************************************************************************
 * Scanner for Verilog 2001 subset
 * Date: 02/2009               
 * supports the IEEE Std 1364-2001 (Revision of IEEE Std 1364-1995)Verilog subset
 *
 *****************************************************************************/


%{

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "commentscan.h"
#include "verilogscanner.h"
#include "doxygen.h"
#include "searchindex.h"
#include "verilogdocgen.h"
#include <ctype.h>
#include "scanner.h"
#include "vhdldocgen.h"
#include "util.h"
#include "verilogparser.hpp"
#include "bufstr.h"
#include "preVerilog.h"
#include "message.h"

//--------------------------------------------------------------------------

static ParserInterface *g_thisParser;

static int yyLineNr =1;
static int yyPrevLine=1;
static int yyEndLine=1;
static char* g_buf;

static int inputPosition;
static Entry* curRoots;
static Entry   gBlock;
static int num_chars;
static int defineLineContinue=0;

static int startComment;
static int iSize=0;
static QCString inputVerilogString;
static QFile inputFile;
static QCString yyFileName;
static QList<QCString> qlist;

// stores global variables like `define xxxx
static QDict<Entry>   globalMemberList(1009);

static MyParserConv *pconv;

static QCString lastLetter;
static int totLines=0;
static bool multLineComment=false;
static bool doxComment=false; // doxygen comment ? 
static QCString strComment;
static int iDocLine=-1;
// ----------------- <verilog-code > ----------------------------------

static QCString   g_CurrClass;
static QCString   g_tempComp;
static CodeOutputInterface * g_code;

static QCString      g_curClassName;
static const char *  g_inputString;       //!< the  code fragment as text
static int           g_inputLines=0;      //!<number of line in the code fragment
static bool          g_needsTermination;

static QCString      g_exampleName;
static QCString      g_exampleFile;

static QCString      g_CurrScope;
static FileDef *     g_sourceFileDef;
static Definition *  g_currentDefinition;
static MemberDef *   g_currentMemberDef;
static bool          g_includeCodeFragment;
static const char *  g_currentFontClass;
static bool          g_lexInit = FALSE;
static bool          g_parseCode=FALSE;
static bool gInit=false;
static int iCodeLen;
// ------------------< functions for verilog code scanner >---------------

static void writeFont(const char *s,const char* text);
static void generateMemLink(CodeOutputInterface &ol,QCString &clName,QCString& memberName);
static bool writeColoredWord(QCString& word );
static void startCodeLine();
static bool generateClassOrGlobalLink(CodeOutputInterface &ol,char *clName, bool typeOnly=FALSE);
static bool generateMemLink(CodeOutputInterface &ol,QCString &clName,QCString& memberName,int type);
static void codifyLines(char *text,char *cl=NULL);
static void addToSearchIndex(const char *text);
static void writeMultiLineCodeLink(CodeOutputInterface &ol,
                  const char *ref,const char *file,
                  const char *anchor,const char *text);
static void startFontClass(const char *s);
static void endFontClass();
static void writeWord(char *word,char* curr_class=NULL);

//-------------------------------------------------------------------

static void parseGlobalMember();
static void parseLib(char *);
static QCString checkComment(QCString& q);
static void composeString(QCString& q);
static void writeInclude(QCString);
//-------------------------------------------------------------------

#define YY_NEVER_INTERACTIVE 1
#define YY_USER_ACTION num_chars +=verilogScanYYleng ;

//-----------------------------------------------------------
// dictionaries for keywords
static QDict<QCString> verilogKeyDict(17,false);
static QDict<QCString> verilogGlobalDict(17,false);
static QDict<QCString> verilogDefineDict(17,false);
static QDict<QCString> dirList(17,false);

static const QCString g_verilogkeyword("vhdlkeyword");
static const QCString g_verilogDefinition("preprocessor");


static const char* VerilogKewWordMap[] = {"module","endmodule","input","output","inout","reg","parameter","always",  
"case","endcase","if","begin","posedge","negedge","or","wire","tri","tri0","instance","use","design","config","endconfig","include","library","liblist",
	"function","endfunction","assign","end","for","else","initial","integer","real","task",
	"and","buf","bufif0","bufif1","casex","casez","cmos","deassign","default","defparam","disable",
	"edge","endattribute","endprimitive","endspecify","endtable","endtask","event",
    "force","forever","fork","force","forever","ifnone","join","large","macromodule","medium","Input","Output","Inout",
	"nand","nmos","nor","not","notif0","notif1","localparam","cell",
	"pmos","primitive","pull0","pull1","pullup","pulldown","automatic",
	"rcmos","real","time","realtime","release","repeat","rnmos","rpmos","rtran","rtranif0","rtranif1",
	"scalared","signed","small","specify","specparam","strength","strong0","strong1","supply0","supply1",
	"table","tran","tranif0","tranif1","tri1","triand","trior","trireg","pulsestyle_ondetect",    "showcancelled","noshowcancelled","pulsestyle_onevent",
	"generate","endgenerate","genvar","unsigend","xor","xnor","wait","wand","weak0","weak1","while","wire","wor","vectored",""}; 

static const char* VerilogDefineMap[] = {"`line","`resetall","`define","`undef","`timescale","`ifndef","`ifdef","`elsif","`else","`endif","`include","`celldefine","`endcelldefine","`default_nettype","`unconnected_drive","`nounconnected_drive",""};

// some but not all system words
static const char* VerilogKewWordMap1[] = {"$async$and$array","$async$and$plane","$async$nand$array", "$async$nand$plane","$async$or$array", "$async$or$plane",
"$async$nor$array", "$async$nor$plane","$sync$and$array", "$sync$and$plane","$sync$nand$array", "$sync$nand$plane",
"$sync$or$array", "$sync$or$plane","$sync$nor$array", "$sync$nor$plane","$display", "$strobe",
"$displayb", "$strobeb","$displayh", "$strobeh","$displayo","$strobeo","$monitor", "$write","$monitorb", "$writeb",
"$monitorh", "$writeh","$monitoro", "$writeo","$monitoroff", "$monitoron","$fclose", "$fopen","$fdisplay", "$fstrobe",
"$fdisplayb", "$fstrobeb","$fdisplayh", "$fstrobeh","$fdisplayo", "$fstrobeo","$fgetc", "$ungetc","$fflush", "$ferror",
"$fgets", "$rewind","$fmonitor", "$fwrite","$fmonitorb", "$fwriteb","$fmonitorh",  "$fwriteh",
"$fmonitoro", "$fwriteo","$readmemb", "$readmemh","$swrite", "$swriteb","$swriteo", "$swriteh",
"$sformat", "$sdf_annotate","$fscanf", "$sscanf","$fread", "$ftell","$fseek", "$printtimescale", 
"$timeformat" ,"$finish", "$stop", "$realtime","$stime", "$time","$bitstoreal", "$realtobits",
"$itor", "$rtoi","$signed", "$unsigned","$test$plusargs", "$value$plusargs","$q_initialize", "$q_add",
"$q_remove", "$q_full","$q_exam","$period","$hold","$setup","$width","$skew","$reovery","$nochange","$timeskew","$setuphold","$fullskew",""};

/*
static void startCodeBlock(QCString qcs,int ii){
   iCodeLen=num_chars;
     int ff= getLR(iCodeLen);
     iCodeLen=ff;
   gBlock.reset();
   int len=qcs.length();
   QCString name=qcs.right(len-ii);// 
   name=VhdlDocGen::getIndexWord(name.data(),1);
    if(!name)
         gBlock.name="misc"+ VhdlDocGen::getRecordNumber(); 
    else
        gBlock.name=name;
    gBlock.bodyLine=yyLineNr+1;
    QCString q=strComment;
   VhdlDocGen::prepareComment(q);
   gBlock.brief+=q;
   strComment.resize(0);
}
*/

static void startCodeBlock(int index){
    int ll=strComment.length();
     iCodeLen=inputVerilogString.findRev(strComment.data())+ll;
  fprintf(stderr,"\n startin code..%d %d %d\n",iCodeLen,num_chars,ll);
   //assert(false);
    gBlock.reset();
   int len=strComment.length();
   QCString name=strComment.right(len-index);// 
    name=VhdlDocGen::getIndexWord(name.data(),1);
    if(!name)
      gBlock.name="misc"+ VhdlDocGen::getRecordNumber(); 
    else
      gBlock.name=name;
   strComment=strComment.left(index);
    gBlock.startLine=yyLineNr+1;
    gBlock.bodyLine=yyLineNr+1;
    VhdlDocGen::prepareComment(strComment);
   gBlock.brief+=strComment;
}
static void makeInlineDoc(int endCode)
{
     int len=endCode-iCodeLen;
     QCString par=inputVerilogString.mid(iCodeLen,len);
     gBlock.doc=par;
     gBlock.inbodyDocs=par;
     gBlock.section=Entry::VARIABLE_SEC;
     gBlock.spec=VhdlDocGen::MISCELLANEOUS;
     gBlock.fileName = yyFileName;
     gBlock.endBodyLine=yyLineNr-1;
     gBlock.lang=SrcLangExt_VHDL;
     gBlock.fileName =yyFileName;
     gBlock.lang=SrcLangExt_VHDL;
     Entry *temp=new Entry(gBlock);
     Entry* compound= getCurrVerilog();
//     fprintf(stderr,"\n <<<%s %s \n %s \n %d %d %d\n\n>>>\n",compound->name.data(),gBlock.brief.data(),par.data(),endCode,iCodeLen,yyLineNr);

    if(compound)
    compound->addSubEntry(temp);
  else
  {
     temp->type="misc"; // global code like library ieee...
     curRoots->addSubEntry(temp);
  }

 gBlock.reset();
 strComment.resize(0); 
 resetVerilogBrief();

}// makeInlineDoc

static bool isConstraintFile(QCString fileName,char *type)
{
  int i=fileName.findRev(type);
  int j=fileName.length();
  int k=strlen(type);
  if((i+k)==j)
   return true;
  return false;
}


static bool  checkMultiComment(QCString& qcs){
  QList<Entry> *pTemp=VerilogDocGen::getEntryAtLine1(curRoots,iDocLine);
 if (!pTemp->isEmpty())
  {
    int ii=pTemp->count();
   qcs.stripPrefix("//%");
    while(!pTemp->isEmpty()){
    
    Entry *e=(Entry*)pTemp->first();
    e->briefLine=yyLineNr;
    e->brief+=qcs;
    iDocLine=-1;
    pTemp->removeFirst();
    ii=pTemp->count();
    }
     return true;
    }    
 
  return false;
 }

 void addGlobalVerilogMember(const Entry *e)
{
       Entry *pNew=new Entry(*e);
       globalMemberList.insert(pNew->name,pNew);
}

static bool checkString(QCString &name)
{
  if (name.isEmpty()) return FALSE;
  static QRegExp regg("[ \t\"]");

  int len=name.length();
  if (name.at(0)=='"' && name.at(len-1)=='"' && len > 2)
  {
    QStringList qrl=QStringList::split(regg,name,FALSE);
    if (VhdlDocGen::isNumber(qrl[0].data()))
    {
      g_code->codify("\""); 
      startFontClass("vhdllogic");
      QCString mid=name.mid(1,len-2); //" 1223 "
      g_code->codify(mid.data());
      endFontClass();
      g_code->codify("\""); 
    }
    else
    {
      startFontClass("keyword");
      g_code->codify(name.data());
      endFontClass();
    }
    return TRUE;
  }

  if (VhdlDocGen::isNumber(name))
  {
    startFontClass("vhdllogic");
    g_code->codify(name.data());
    endFontClass();
    return TRUE;
  }
  return FALSE;
}

static bool writeColoredWord(QCString& temp ){
   const QCString *ss=VerilogDocGen::findKeyWord(temp);
    if (ss){
          writeFont(ss->data(),temp.data());
	return true;
	}
 return false;
}


static void writeSpecWord(const char *word,const char* curr_class=0,bool classLink=FALSE)
{
  bool found=FALSE;
  QCString temp; 
  QCString tclass(curr_class);
  QCString ttt(word);
  if (ttt.isEmpty()) return;
  for (unsigned int j=0;j<ttt.length();j++)
  {
    char c=ttt.at(j);
    if ( c==' '|| c==',' || c==';' || c==':' || c=='(' || c==')' || c=='\r' || c=='\t' || c=='.')
    {
      if (found)
      {
        if (!writeColoredWord(temp)) // is it a keyword ?
        {
          //if (VhdlDocGen::findKeyWord(temp))
          // writeFont("vhdlkeyword",temp.data());
	  //printf("writeWord: %s\n",temp.data());
          if (!tclass.isEmpty())
          {
            if (!classLink)
	    {
           writeWord(temp.data());//((   generateMemLink(*g_code,tclass,temp); // 
	    }
            else
            {
              generateClassOrGlobalLink(*g_code,temp.data());
            }
          }
          else                                                                          
	  {
          if (!checkString(temp))
            g_code->codify(temp.data());
	  }
        }
        temp.resize(0);
        found=FALSE;
      }

      char cc[2];
      cc[0]=c;
      cc[1]=0;
      g_code->codify(cc);
    }
    else
    {
      found=TRUE;
      temp+=c;
    }
  } // for

  if (!temp.isEmpty())
  {
    if (!writeColoredWord(temp))
    {
      if (!tclass.isEmpty())
      {
        if (!classLink)
        {
          writeWord(temp.data());
       //   generateMemLink(*g_code,tclass,temp); // generateMemLink(*g_code,g_CurrClass,left); 
        }
        else
        {
          generateClassOrGlobalLink(*g_code,temp.data());
        }
      }
      else                 
      {
         QCString qc(temp.data());
         if (VhdlDocGen::isNumber(qc)){
                         startFontClass("vhdllogic");
                         g_code->codify(temp.data());
                         endFontClass();
                              }
         else     
        g_code->codify(temp.data());
      }
    }
  }
}// writeWord

static void buildKeyMap()
{
	int j=0;
    verilogGlobalDict.setAutoDelete(true);
    verilogKeyDict.setAutoDelete(true);
    verilogDefineDict.setAutoDelete(true);
	qlist.setAutoDelete(true);
	dirList.setAutoDelete(true);
	
	globalMemberList.setAutoDelete(true);
 
	QCString p=VerilogKewWordMap[0];
    
    dirList.insert("martin",new QCString("martin"));
    dirList.insert("BBB",new QCString("BBB"));  
	while(!p.isEmpty())
	{
		verilogKeyDict.insert(p,new QCString(p.data()));
    	p=VerilogKewWordMap[++j];	  
	}

	j=0;
    p=VerilogKewWordMap1[0]; 
	while(!p.isEmpty())
	{
		verilogGlobalDict.insert(p,new QCString(p.data()));
    	p=VerilogKewWordMap1[++j];	  
	}

   j=0;
    p=VerilogDefineMap[0]; 
	while(!p.isEmpty())
	{
		verilogDefineDict.insert(p,new QCString(p.data()));
    	p=VerilogDefineMap[++j];	  
	}

}// buildKeypMap



const QCString* VerilogDocGen::findKeyWord(const char *str)
{
    QCString word(str);
	if (word.isEmpty() || word.at(0)=='\0') return 0;
	
	if(verilogKeyDict.find(word))
	  return &g_verilogkeyword;
 
    if(verilogGlobalDict.find(word))
	  return &g_verilogDefinition;
	  
	if(verilogDefineDict.find(word))
	 return &g_verilogDefinition;  
          
   return 0;
}

void writeVerilogFont(const char* col,const char* text)
{
  writeFont(col,text);
}

// writes a coloured word to the  output

static void writeVWord(QCString& qcs){
static bool stripComment=Config_getBool("STRIP_CODE_COMMENTS");
   if(qcs.isEmpty())return;
    QCString temp=qcs;
	if(qcs.stripPrefix("\n")){
	     codifyLines(temp.data());return;}
	else if(qcs.stripPrefix(" "))
	     {g_code->codify(temp.data()); return;}   
 	if(qcs.stripPrefix("\""))
        {writeFont("keyword",temp.data());return;}
	   if(qcs.stripPrefix("//"))
        {
        if (stripComment && temp.contains(vlogComment))
        {
         yyLineNr+=temp.contains("\n");
	    return;
        }
        else 
          writeFont("keyword",temp.data());
          return;
          }
    
    if(qcs.stripPrefix("§")){
            if(qcs.contains('\n'))
                   return; // exit(0);
               
         qcs.stripPrefix("§");   
		 VhdlDocGen::deleteAllChars(qcs,'§');
		 writeFont("undoc",qcs.data());
		 return;					
		}

	if(qcs.stripPrefix("/*!")) 
	 if( stripComment){
		 yyLineNr+=temp.contains("\n");
		 return;					
		}
        else
         qcs.prepend("/*");

	if(qcs.stripPrefix("/*")){
	     startFontClass("keyword");
	     codifyLines(temp.data());
		 endFontClass();
		 return;					
		}
    
     	 if(qcs.stripPrefix("`"))
	     {
	        qcs=temp;
		    if(qcs.stripPrefix("`define"))
		     {
              writeFont("preprocessor","`define");     
              writeInclude(qcs);
              return;
              }
		   
		   if(qcs.stripPrefix("`include"))
		     {
              writeFont("preprocessor","`include");     
              writeInclude(qcs);
              return;
              }
		  }//
		  
		   const QCString *ss=VerilogDocGen::findKeyWord(qcs.data());
	      if (ss)
          {writeFont(ss->data(),qcs.data());return;}
   
		   
	   
		   MemberDef* md=findGlobalMember(temp);  
            if(md)
             { 
	         g_code->writeCodeLink(md->getReference(),
	                      md->getOutputFileBase(),
			              md->anchor(),
			              temp.data(),
			              md->briefDescriptionAsTooltip());
              return;
              }
		   
		   
		      QCString  tempClass = getCurrVerilogParsingClass();
		        bool feat=generateVerilogMemLink(tempClass,temp,VerilogDocGen::FEATURE);
		        if(feat) return;
		     /*   
		        if(!feat)
		        {
	             writeWord(qcs.data());	
		         return;
		        }
            */
            
     if(qcs.length()==1)
         {codifyLines(qcs.data());return;}
     if(qcs.stripPrefix("$"))
          writeFont("vhdlkeyword",temp.data());
     else writeWord(temp.data());
	  
}//writeVWord


// writes the rest of the input buffer
void printVerilogBuffer(bool b)
{
  QCString qbuffer;
  uint len=qlist.count();
  for(uint j=0;j<len;j++) {
    QCString *qcs=(QCString*)qlist.at(j);
	writeVWord(*qcs);
        
 }//for
 qlist.clear();
}//printVerilogBuffer


void writePrevVerilogWords(const QCString& qcs){

 uint len=qlist.count();
 uint v=0;
  
  for(uint j=0;j<len;j++) {
    QCString *word=(QCString*)qlist.getFirst();
//	printf("\n++++++++++++++++++ %s",qcs.data()); 
//if(qcs.contains("`"))
//	 printVerilogStringList();
	 if(strcmp(qcs.data(),word->data()) != 0) {
      writeVWord(*word);
      qlist.removeFirst();
     }else { 
//	   QCString *wsord=(QCString*)qlist.getFirst();
	  qlist.removeFirst();
	 v=j; 
	 break; 
	 }
   }//for

} // writePrevVerilogWords

// only for debugging 
void printVerilogStringList()
{
  QCString qbuffer;
  int len=qlist.count();
 for(int j=0;j<len;j++) {
    QCString *qcs=(QCString*)qlist.at(j);
	 qbuffer+=qcs->data();
  }
  
  fprintf(stderr,"\n[%s]",qbuffer.data());
}


void codifyVerilogString(char* c,char* color)
{
 if(color==NULL)
  g_code->codify(c);
 else
  writeFont(color,c);
 }

bool  generateVerilogMemLink(QCString &clName,QCString& memberName,int type)
{
 return generateMemLink(*g_code,clName,memberName,type);
}

bool generateVerilogCompMemLink(QCString &cl,QCString& inst,QCString & key, bool b)
{
   MemberDef *md=0;
   md=VerilogDocGen::findInstMember(cl,inst,key,b);
  if(md){ 
    ClassDef *ddd=md->getClassDef();
    QCString nkll=md->getOutputFileBase();
    QCString nklll=ddd->name();
    }
    if (md && md->isLinkable()) // is it a linkable class
    {
   	 if(!cl.isEmpty())
   	 {
   	   writeMultiLineCodeLink(*g_code,md->getReference(),md->getOutputFileBase(),md->anchor(),md->name());
       return true;
     }
  /*  
     if(b && !inst.isEmpty())
     {
       writeMultiLineCodeLink(*g_code,md->getReference(),md->getOutputFileBase(),md->anchor(),inst);
       return true;
     }
   */ 
    }
   return false;
}

static bool generateMemLink(CodeOutputInterface &ol,QCString &clName,QCString& memberName,int type)
{
  if(clName.isEmpty() || memberName.isEmpty()) return false; 
  if((memberName.length()==1) && (isalpha(memberName.at(0))==0))
   return false;


  bool isLocal=false;

  MemberDef *md=0;
  if(memberName.contains('`'))
   isLocal=true;


   md=VerilogDocGen::findMember(clName,memberName,type);
  
 //  if(md==0)
 //  md=VerilogDocGen::findMember(clName,memberName,-1);
  
 
  if (md && md->isLinkable()) // is it a linkable class
  {
    addToSearchIndex(memberName);
    if(isLocal) memberName.prepend("`");
	 writeMultiLineCodeLink(ol,md->getReference(),md->getOutputFileBase(),md->anchor(),memberName);
   return true;
  }
 
  addToSearchIndex(memberName);

 return false;
}// generateMemLink



static void endCodeLine()
{
  if (g_currentFontClass) { g_code->endFontClass(); }
  g_code->endCodeLine();
}

static void addToSearchIndex(const char *text)
{
   if (Doxygen::searchIndex)
  {
    Doxygen::searchIndex->addWord(text,FALSE);
  }
}


/*! writes a link to a fragment \a text that may span multiple lines, inserting
 * line numbers for each line. If \a text contains newlines, the link will be 
 * split into multiple links with the same destination, one for each line.
 */
static void writeMultiLineCodeLink(CodeOutputInterface &ol,
                  const char *ref,const char *file,
                  const char *anchor,const char *text)
{
  bool done=FALSE;
  char *p=(char *)text;
  while (!done)
  {
    char *sp=p;
    char c;
    while ((c=*p++) && c!='\n');
    if (c=='\n')
    {
      yyLineNr++;
      *(p-1)='\0';
     // printf("writeCodeLink(%s,%s,%s,%s)\n",ref,file,anchor,sp);
      ol.writeCodeLink(ref,file,anchor,sp,0);
      endCodeLine();
      if (yyLineNr<g_inputLines) 
      {
	startCodeLine();
      }
    }
    else
    {
    //  printf("writeCodeLink(%s,%s,%s,%s)\n",ref,file,anchor,sp);
      ol.writeCodeLink(ref,file,anchor,sp,0);
      done=TRUE;
    }
  }
}

bool generateVerilogClassOrGlobalLink(char *clName)
{
  return generateClassOrGlobalLink(*g_code,clName,FALSE);
}


static bool generateClassOrGlobalLink(CodeOutputInterface &ol,char *clName, bool typeOnly)
{
  QCString className=QCString(clName);

  if(className.isEmpty()) return false;

  ClassDef *cd=0;
   cd = getClass(className.data()); 
  
  if (cd && cd->isLinkable()) // is it a linkable class
  {
  	  QCString temp=cd->displayName();
	  ol.linkableSymbol(yyLineNr,temp,cd, g_currentMemberDef ? g_currentMemberDef : g_currentDefinition);
      writeMultiLineCodeLink(ol,cd->getReference(),cd->getOutputFileBase(),0,temp);
      addToSearchIndex(className);
   return true;
  }
 return false;
}// generateClassOrGLink  


static void startFontClass(const char *s)
{
  if(s==NULL) return;
  g_code->startFontClass(s);
  g_currentFontClass=s;
}

static void writeFont(const char *s,const char* text)
{
  if(s==NULL) return;
  g_code->startFontClass(s);
  g_code->codify(text);
  g_code->endFontClass();
}



/*! counts the number of lines in the input */
static int countLines()
{
  const char *p=inputVerilogString.data();
  char c;
  int count=1;
  while ((c=*p)) 
  { 
    p++ ; 
    if (c=='\n') count++;  
  }
  if (p>g_inputString && *(p-1)!='\n') 
  { // last line does not end with a \n, so we add an extra
    // line and explicitly terminate the line after parsing.
    count++, 
    g_needsTermination=TRUE; 
  } 
  return count;
}

/*! writes a word to the output.
 *  If curr_class is defined, the word belongs to a class
 *  and will be linked.
 */

static void writeWord(char *word,char* curr_class)
{
   if(word==NULL)return;
   const QCString *ss=VerilogDocGen::findKeyWord(word);
   if(ss)
     writeFont(ss->data(),word);
   else{ 
   QCString w(word);
   if(!checkString(w))
   g_code->codify(word);
   } 
  return;
}// writeWord



/*! write a code fragment `text' that may span multiple lines, inserting
 * line numbers for each line.
 */
static void codifyLines(char *text,char *cl)
{
 // printf("codifyLines(%d,\"%d\")\n",yyLineNr,strlen(text));
  if(text==NULL) return;
  char *p=text,*sp=p;
  char c;
  bool done=FALSE;
  while (!done)
  {
    sp=p;
    while ((c=*p++) && c!='\n');
    if (c=='\n')
    {
      yyLineNr++;
      *(p-1)='\0';
       writeWord(sp,cl);
	  endCodeLine();
      if (yyLineNr<g_inputLines) 
      {
    	startCodeLine();
      }
    }
    else
    {
      writeWord(sp,cl);
	  done=TRUE;
    }
  }
}


static void setCurrentDoc(const QCString &name,const QCString &base,const QCString &anchor="")
{
  if (Doxygen::searchIndex)
  {
    Doxygen::searchIndex->setCurrentDoc(name,base,anchor);
  }
}


/*! start a new line of code, inserting a line number if g_sourceFileDef
 * is TRUE. If a definition starts at the current line, then the line
 * number is linked to the documentation of that definition.
 */
static void startCodeLine()
{
  //if (g_currentFontClass) { g_code->endFontClass(); }
  if (g_sourceFileDef)
  {
     if((yyLineNr % 500) == 0) 
	 fprintf(stderr,"\r parsing line %d:",yyLineNr);
    Definition *d   = g_sourceFileDef->getSourceDefinition(yyLineNr);
   // printf("startCodeLine %d d=%s\n", yyLineNr,d ? d->name().data() : "<null>");
    if (!g_includeCodeFragment && d)
    {
      g_currentDefinition = d;
      g_currentMemberDef = g_sourceFileDef->getSourceMember(yyLineNr);
      if(!g_tempComp.isEmpty() && g_currentMemberDef )
	  {
      //  ClassDef *cf=VhdlDocGen::getClass(g_tempComp.data());
	    QCString nn=g_currentMemberDef->name();
		MemberDef* mdeff=VhdlDocGen::findMember(g_tempComp,nn);
		if(mdeff)
          g_currentMemberDef=mdeff;
	  
	  }
       
       QCString lineAnchor;
      lineAnchor.sprintf("l%05d",yyLineNr);
      if (g_currentMemberDef)
      {
     	g_code->writeLineNumber(g_currentMemberDef->getReference(),
	                        g_currentMemberDef->getOutputFileBase(),
	                        g_currentMemberDef->anchor(),yyLineNr);
        setCurrentDoc(
                                g_currentMemberDef->qualifiedName(),
	                        g_sourceFileDef->getSourceFileBase(),
	                        lineAnchor);
      }
      else if (d->isLinkableInProject())
      {
        g_code->writeLineNumber(d->getReference(),
	                        d->getOutputFileBase(),
	                        0,yyLineNr);
        setCurrentDoc(
                                d->qualifiedName(),
	                        g_sourceFileDef->getSourceFileBase(),
	                        lineAnchor);
      }
    }
    else
    {
      g_code->writeLineNumber(0,0,0,yyLineNr);
    }
  }
  g_code->startCodeLine(yyLineNr); 
  if (g_currentFontClass)
  {
    g_code->startFontClass(g_currentFontClass);
  }
}


static void endFontClass()
{
  if (g_currentFontClass)
  {
    g_code->endFontClass();
    g_currentFontClass=0;
  }
}

//---------------------------------------------------------------

static void addText(char* c,int len);
static void addToken(char c);
static int startLex();
static void resetScanner(const char* s,MyParserConv* parse);



#undef	YY_INPUT
#define	YY_INPUT(buf,result,max_size) result=verilogScanYYread(buf,max_size);


static int verilogScanYYread(char *buf,int max_size)
{
 int c=0;
  while ( c < max_size && inputVerilogString.at(inputPosition) )
  {
    *buf = inputVerilogString.at(inputPosition++) ;
    c++; buf++;
  }
  
  return c;
}

// checks if we have found a correct parsed word or
// part of a word like (reg)ister
static bool check(bool bb=true)
{
  bool b=true;
  char c=yy_hold_char;
 
  if(iSize==0){
   if(g_parseCode){
      qlist.append(new QCString(verilogScanYYtext)); 
  }
  return true;
 }
 
  char d = g_buf[iSize-1];
  int l=isdigit(c);
  int k=isdigit(d);

  if(k!=0 || l!=0 || d=='$') return false;

  l=islower(c);
  k=islower(d);

  if(k!=0 || l!=0) 
    return false;

  l=isupper(c);
  k=isupper(d);

  if(k!=0 || l!=0) 
    return false;

  if(c=='_' || d=='_') return false;
  					               
  if(g_parseCode){
   qlist.append(new QCString(verilogScanYYtext));
  }

  return true;
}

static void parseToken(const char* s){
     if(g_parseCode)    
	 qlist.append(new QCString(verilogScanYYtext));
	 c_lval.ctype=s[0];
	 addToken(s[0]);
	}
/*
<Start>"`define"|"`include" {
     QCString qtemp(verilogScanYYtext);
              if(qtemp.contains("`define")) return DEFINE_TOK;
                  if(qtemp.contains("`include")) return INCLUDE_TOK;
                      
}
 

*/

%}

/* --CopyLine>"\\"\r?/\n			{ // strip line continuation characters------------ VERLIOG SECTION -----------------------------------*/



WORD        [a-zA-Z0-9_]+
LL          [ \t]
LF          [ \t\n]
COMMENT     "//"[^\n]*
COMMENT1    "//!"[^\n]*
MIT         [^\\\n]*
STRING      ["][^"]*["]
FEATURE     ("`include"|"`line"|"`timescale"|"`define"|"`ifndef"|"`endif"|"`elsif"|"`ifdef"|"`else"|"`undef")[^\n]*
FEATUREX     ("`define"){MIT}



FEATURE1    [`][a-zA-Z0-9_]+
SIGNEDBASE  ['][sS][oOhHbBdD]
BASE	    ("'b"|"'B"|"'o"|"'O"|"'d"|"'D"|"'h"|"'H"|{SIGNEDBASE})[ ]?
NETTYPE	    "wire"|"tri"|"tri1"|"supply0"|"wand"|"triand"|"tri0"|"supply1"|"wor"|"trior"|"trireg"
STRENGTH1	"supply1"|"strong1"|"pull1"|"weak1"|"highz1"
STRENGTH0	"supply0"|"strong0"|"pull0"|"weak0"|"highz0"
GATETYPE  	"and"|"nand"|"or"|"nor"|"xor"|"xnor"|"buf"|"bufif0"|"bufif1"|"not"|"notif0"|"notif1"|"pulldown"|"pullup"|"nmos"|"rnmos"|"pmos"|"rpmos"|"cmos"|"rcmos"|"tran"|"rtran"|"tranif0"|"rtranif0"|"tranif1"|"rtranif1"


%option noyywrap


  /* language parsing states */

%x Start
%x Commentt
%x FindBegin
%x StartComment
%x tagComment
%x directive
%x specc
%x EndOfText
%%

.	{
    BEGIN(Start);  
	}


             
<EndOfText>[^\\\n]+ {
                   if(yy_hold_char=='\\')
                   {
                    if(g_parseCode) 
                      qlist.append(new QCString(verilogScanYYtext));
                    else
                    {
                        addText(verilogScanYYtext,verilogScanYYleng);
                     }
                     BEGIN(EndOfText);
                    }
                     else
                     {
                      if(!g_parseCode)
                      { 
                       QCString s=verilogScanYYtext;
                       addText(verilogScanYYtext,verilogScanYYleng);
                       parseGlobalMember();
                       vbufreset();
                      }
                     else{
                          qlist.append(new QCString(verilogScanYYtext));
                         }
                      BEGIN(Start);
                    }
                    }

<EndOfText>[\\] { 
                 if(g_parseCode)
                  { 
                      char c=yy_hold_char;
                      qlist.append(new QCString("\\"));
                      if(yy_hold_char==32)
                      qlist.append(new QCString("\n"));
                   }
                      else{
                           addText(verilogScanYYtext,verilogScanYYleng);
                          // if(yy_hold_char==10)
                          //      addText("?",1);
                           if(yy_hold_char==32)
                           yyLineNr++;
                          }
                 }

<Start>"§"[^\n]* { // grey out undefined code
                   // QCString uu(verilogScanYYtext);
                    if(g_parseCode)
                    {
                    //  fprintf(stderr,"\n%s",uu.data());
                      qlist.append(new QCString(verilogScanYYtext));
                    }
                 }   


<Start>{FEATURE} { 
              //    fprintf(stderr,"<[ %s ]>",verilogScanYYtext);
				   QCString q(verilogScanYYtext);
                   defineLineContinue=yyLineNr;
				    vbufreset();  
				   if(!g_parseCode)
				   {
				    addText(verilogScanYYtext,verilogScanYYleng);
				    uint le=q.length()-1;
				    if(q.at(le)=='\\')
				    {			  
				    addText("?",1);
				     BEGIN(EndOfText); 
				    } else{
                     parseGlobalMember();
                     vbufreset();
                     }
                   }
 
                 if(g_parseCode) 
                 {
                    //  VhdlDocGen::deleteAllChars(q,'§');                                              
                      uint le=q.length()-1;
                      bool newLine=(q.at(le)=='\\');
                      QCString com=checkComment(q);
                     // qlist.append(new QCString(q.data())); 
                      if(!q.contains("`include"))
                       composeString(q);
                      else
                        qlist.append(new QCString(q.data()));
                      if(!com.isEmpty())
                         qlist.append(new QCString(com.data())); 
                    
                     
				      if(newLine)
				      {
				      BEGIN(EndOfText); 
				      }               
                  }//if
                 }       
 
 <Start>{FEATUREX} {  
                    // assert(0);
                    } 
                 
<Start>{FEATURE1} {
				    QCString s(verilogScanYYtext);
				    DefineDict* gDict=getFileDefineDictVerilog();
				    VhdlDocGen::deleteAllChars(s,'`');
				
				    Define *def=gDict->find(s);
					 
				 	if(g_parseCode)
				 	{
                      QCString *yy=0;
                     if(Config_getBool("MACRO_EXPANSION") && def)
                     {
                        yy=new QCString(def->definition.data());
                      //   VhdlDocGen::deleteAllChars(*yy,'"');   
                     } 
                      else   
                        yy=new QCString(verilogScanYYtext);
                      c_lval.cstr[0]='\0';                                                   
                     qlist.append(yy);
                    }
                    
					if(!verilogDefineDict.find(s))
					{            
					if(!g_parseCode)
					 addText(verilogScanYYtext,verilogScanYYleng);
				    }
				  	
				  	if(!def)// && !def->definition.isEmpty())
					if(Config_getBool("WARNINGS"))
					 warn(yyFileName,yyLineNr,"\n macro %s is not defined",verilogScanYYtext);		  
							  return  LETTER_TOK;	
				
					}

<Start>"ifnone"    {if(check())      return  IFNONE_TOK;REJECT;}
<Start>"realtime"    {if(check()) {yyPrevLine=yyLineNr;addText(verilogScanYYtext,verilogScanYYleng); return  REALTIME_TOK;}REJECT;}
<Start>"design"    {if(check())      return  DESIGN_TOK;REJECT;}
<Start>"library"{LF}+[^;]+ { parseLib(verilogScanYYtext);return LIBRARY_TOK; }
<Start>"config" {if(check())      return  CONFIG_TOK;REJECT;}
<Start>"endconfig" { if(check()){return  ENDCONFIG_TOK;} REJECT;}
<Start>"include"   {if(check())      return  INCLUDE_TOK;REJECT;}
<Start>"use"   {if(check())      return  USE_TOK;REJECT;}
<Start>"liblist"  { if(check())     return  LIBLIST_TOK;REJECT;}
<Start>"instance"   {if(check())      return  INSTANCE_TOK;REJECT;}
<Start>"cell"  { if(check())     return  CELL_TOK;REJECT;}
<Start>"showcancelled"   {if(check())      return  SHOWCANCEL_TOK;REJECT;}
<Start>"noshowcancelled"  { if(check())     return  NOSHOWCANCEL_TOK;REJECT;}
<Start>"pulsestyle_onevent"   {if(check())      return  PULSEONE_EVENT_TOK;REJECT;}
<Start>"pulsestyle_ondetect"  { if(check())     return  PULSEON_DETECT_TOK;REJECT;}
<Start>"edge"    {if(check())      return  EDGE_TOK;REJECT;}
<Start>"negedge" {if(check())      return  NEGEDGE_TOK;REJECT;}
<Start>"posedge" { if(check()){return  POSEDGE_TOK;} REJECT;}
<Start>"$fullskew"   {if(check())      return  FULLSKEW_TOK;REJECT;}
<Start>"$recrem"   {if(check())      return  RECREM_TOK;REJECT;}
<Start>"$removal"   {if(check())      return  REMOVAL_TOK;REJECT;}
<Start>"$timeskew"   {if(check())      return  TIMESKEW_TOK;REJECT;}
<Start>"$nochange"   {if(check())      return  NOCHANGE_TOK;REJECT;}
<Start>"$hold"   {if(check())      return  DHOLD_TOK;REJECT;}
<Start>"$setup"  { if(check())     return  DSETUP_TOK;REJECT;}
<Start>"$setuphold" {if(check())   return  DSETUPHOLD_TOK;REJECT;}
<Start>"$recovery" {if(check())    return  DRECOVERY_TOK;REJECT;}
<Start>"$skew"     {if(check())    return  DSKEW_TOK;REJECT;}
<Start>"$width"    {if(check())    return  DWIDTH_TOK;REJECT;}
<Start>"$period"   {if(check())    return  DPERIOD_TOK;REJECT;}
<Start>"time"      { if(check()){yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);  return  TIME_TOK;} REJECT; }
<Start>"specparam" {if(check())    return  SPECPARAM_TOK;REJECT;}
<Start>"endspecify" {if(check())   return  ENDSPECIFY_TOK;REJECT;}
<Start>"specify"   {  if(check())   return  SPECIFY_TOK;REJECT;}
<Start>"end"        { if(check()) {   yyEndLine=yyLineNr;  strncpy(c_lval.cstr,verilogScanYYtext,verilogScanYYleng);c_lval.cstr[verilogScanYYleng]='\0';return  END_TOK;}REJECT;}
<Start>"begin" {if(check(false))  return  BEGIN_TOK; REJECT;}
<Start>"fork" {if(check(false))  return  FORK_TOK; REJECT;}
<Start>"generate" { if(check())     return  GENERATE_TOK;REJECT;}
<Start>"endgenerate" { if(check())     return  ENDGENERATE_TOK;REJECT;}
<Start>"genvar" { if(check())     return  GENVAR_TOK;REJECT;}
<Start>"default" { if(check())     return  DEFAULT_TOK;REJECT;}
<Start>"automatic" { if(check()){ addText(verilogScanYYtext,verilogScanYYleng);     return  AUTO_TOK;}REJECT;}
<Start>"signed" { if(check()){ yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);    return  SIGNED_TOK;}REJECT;}
<Start>"default" { if(check())     return  DEFAULT_TOK;REJECT;}
<Start>"endcase" { if(check())     return  ENDCASE_TOK;REJECT;}
<Start>"else"     { if(check())    return  ELSE_TOK; REJECT;}
<Start>"while"    { if(check())    return  WHILE_TOK; REJECT;}
<Start>"repeat"   { if(check())    return  REPEAT_TOK;REJECT;}
<Start>"forever"  { if(check())    return  FOREVER_TOK;REJECT;}
<Start>"casez"    { if(check())    return  CASEZ_TOK; REJECT;}
<Start>"casex"    { if(check())    return  CASEX_TOK;REJECT;}
<Start>"case"     { if(check())    return  CASE_TOK;REJECT;}
<Start>"if"       { if(check())    return  IF_TOK;REJECT;}
<Start>"disable"  { if(check())    return  DISABLE_TOK;REJECT;}
<Start>"deassign" { if(check())    return  DEASSIGN_TOK;REJECT;}
<Start>"release"  { if(check())    return  RELEASE_TOK; REJECT;}
<Start>"force"    { if(check())    return  FORCE_TOK; REJECT; }
<Start>"wait"     { if(check())    return  WAIT_TOK; REJECT;}
<Start>"join"     { if(check())    return  JOIN_TOK; REJECT;}
<Start>"for"      { if(check())    return  FOR_TOK; REJECT;}
<Start>"always"   { if(check()) {  yyPrevLine=yyLineNr;  return  ALWAYS_TOK;}REJECT;}
<Start>"endfunction"  { if(check()){yyPrevLine=yyLineNr;  return  ENDFUNC_TOK;} REJECT;}
<Start>"function"     { if(check()){yyPrevLine=yyLineNr;  return  FUNC_TOK;} REJECT;}
<Start>"endtask"      { if(check()){yyPrevLine=yyLineNr;  return  ENDTASK_TOK;}REJECT;}
<Start>"task"         { if(check()){yyPrevLine=yyLineNr;  return  TASK_TOK;} REJECT;}
<Start>"table"        { if(check())  return  TABLE_TOK; REJECT;}
<Start>"endtable"     { if(check())  return  ENDTABLE_TOK; REJECT;}
<Start>"initial"      { if(check()) {return  INITIAL_TOK;} REJECT;}
<Start>"endprimitive" { if(check())  return  ENDPRIMITIVE_TOK;REJECT;}
<Start>"primitive"    { if(check()){yyPrevLine=yyLineNr;  return  PRIMITIVE_TOK;} REJECT;}
<Start>"macromodule"  { if(check())  return  MACRO_MODUL_TOK; REJECT;}
<Start>"module"       { if(check())   { yyPrevLine=yyLineNr; return  MODUL_TOK; } REJECT;}
<Start>"endmodule"   { if(check())   return  ENDMODUL_TOK;REJECT;}
<Start>"reg"         { if(check()) {yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);return  REG_TOK; } REJECT;}
<Start>"integer"     { if(check()) {yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);return  INTEGER_TOK;}REJECT;}
<Start>"defparam" { if(check()) return  DEFPARAM_TOK; REJECT;}
<Start>"real"     { if(check()) {yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);   return  REAL_TOK; } REJECT; }
<Start>"event"    { if(check()){yyPrevLine=yyLineNr;addText(verilogScanYYtext,verilogScanYYleng);  return  EVENT_TOK;}REJECT;}
<Start>"assign"   { if(check()) return  ASSIGN_TOK; REJECT;}
<Start>"scalared" { if(check()) return  SCALAR_TOK;REJECT;}
<Start>"vectored" { if(check()) return  VEC_TOK;   REJECT;}
<Start>"small"    { if(check()) return  SMALL_TOK;REJECT;}
<Start>"medium"   { if(check()) return  MEDIUM_TOK; REJECT;}
<Start>"large"    { if(check()) return  LARGE_TOK; REJECT;}
<Start>"output"   { if(check())  {yyPrevLine=yyLineNr;  addText(verilogScanYYtext,verilogScanYYleng);   return  OUTPUT_TOK; }REJECT;}
<Start>"input"    { if(check()) {yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng); return  INPUT_TOK;} REJECT;}
<Start>"inout"    { if(check()) {yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);    return  INOUT_TOK; }REJECT;}
<Start>"parameter" { if(check()) {yyPrevLine=yyLineNr;return  PARAMETER_TOK;}REJECT;}
<Start>"localparam" { if(check()) {yyPrevLine=yyLineNr; return  LOCALPARAM_TOK;}REJECT;}
<Start>{NETTYPE}   { if(check()) { yyPrevLine=yyLineNr; addText(verilogScanYYtext,verilogScanYYleng);return  NET_TOK;} REJECT;}
<Start>{STRENGTH0} { if(check()) {  addText(verilogScanYYtext,verilogScanYYleng);   return  STR0_TOK;} REJECT;}
<Start>{STRENGTH1} { if(check()) {  addText(verilogScanYYtext,verilogScanYYleng); return  STR1_TOK;}REJECT;}
<Start>{GATETYPE}  { if(check()) {  addText(verilogScanYYtext,verilogScanYYleng);  return  GATE_TOK;}REJECT;}
<*>B*"//%"[^{}\n][^\n]*\n/{LL}*"//%" { // found multiline comment
                     QCString text(verilogScanYYtext);
                     if(!g_parseCode){
                     if(iDocLine==-1){
                       iDocLine=yyLineNr; 
                     }
                      
  //                    Entry* pTemp=VerilogDocGen::getEntryAtLine(curRoots,iDocLine);
    
/*                      
  if (pTemp)
  { // found one line comment, add it to the entry on this line
    pTemp->briefLine=yyLineNr;
    pTemp->brief+=yytext;
    VhdlDocGen::prepareComment(pTemp->brief);
  }
    else 
  */  
   if(!checkMultiComment(text)) 
    { 
      strComment+=verilogScanYYtext;
	  multLineComment=true;
	}			                     
     
      yyLineNr+=text.contains('\n');
                      
     }
					 if(g_parseCode) {
					 if(Config_getBool("STRIP_CODE_COMMENTS"))
					      qlist.append(new QCString(verilogScanYYtext)); 
					 else{
					     QStringList ql=QStringList::split('\n',text,false);
					     //QCString trial=(QCString)ql[0];
					     qlist.append(new QCString(ql[0].data()));   
					     qlist.append(new QCString("\n"));   
					     if(ql.count()>1)
					     qlist.append(new QCString(ql[1].data()));   			     
					  }
					  }
					 c_lval.ctype=' ';
  BEGIN(tagComment);
  }

<tagComment>B*"//%"[^\n]* {
  if (iDocLine==-1) iDocLine=yyLineNr;
  if(!g_parseCode){
   strComment+=verilogScanYYtext;
   int index =strComment.find("\\code");
    if(index>0)
    {
    startCodeBlock(index);
    }
   }
   fprintf(stderr,"[[ \n %s ]]",strComment.data());
   if(g_parseCode) 
   { 
     qlist.append(new QCString(verilogScanYYtext)); 
   } 
  BEGIN(tagComment);
}

<tagComment>.|\n {
  // found end of comment block
 int index =strComment.find("\\code");
  fprintf(stderr," %s ",strComment.data());
 // assert(false);
   if(!g_parseCode && index>0)
  {
    startCodeBlock(index);
    /*
    int ll=strComment.length();
     iCodeLen=inputVerilogString.findRev(strComment.data(),num_chars)+ll;
  fprintf(stderr,"\n startin code..%d %d %d\n",iCodeLen,num_chars,ll);
    gBlock.reset();
   int len=strComment.length();
   QCString name=strComment.right(len-index);// 
    name=VhdlDocGen::getIndexWord(name.data(),1);
    if(!name)
      gBlock.name="misc"+ VhdlDocGen::getRecordNumber(); 
    else
      gBlock.name=name;
   strComment=strComment.left(index);
    gBlock.startLine=yyLineNr+1;
    gBlock.bodyLine=yyLineNr+1;
    VhdlDocGen::prepareComment(strComment);
   gBlock.brief+=strComment;
   */
  }
  else if(!g_parseCode)
  {
   strComment+=verilogScanYYtext;
   VhdlDocGen::prepareComment(strComment);
   handleVerilogCommentBlock(strComment,FALSE,iDocLine);
   unput(*verilogScanYYtext);
   }
   
   if(g_parseCode) // && !Config_getBool("STRIP_CODE_COMMENTS"))
   { 
     qlist.append(new QCString(verilogScanYYtext)); 
   } 

   strComment.resize(0);
   BEGIN(Start);
}


<*>"//%"[^\n]* { // one line comment
  if (iDocLine==-1) iDocLine=yyLineNr;
  QCString qcs(verilogScanYYtext);
 
  bool isEndCode=qcs.contains("\\endcode");
  int index = qcs.find("\\code");

   if(isEndCode && !g_parseCode)
   {
     fprintf(stderr,"\n ending code..");
   
    int end=inputVerilogString.find(qcs.data(),iCodeLen);
    makeInlineDoc(end);
   }
   else if(index > 0 && !g_parseCode) {
  // assert(false);
   strComment=qcs;
    startCodeBlock(index);
    strComment.resize(0);
    }
  else if(!g_parseCode)
  {
   VhdlDocGen::prepareComment(qcs);
   //printf("--> handleCommentBlock line %d\n",yyLineNr);
 
  if(!checkMultiComment(qcs))
  {
    handleVerilogCommentBlock(qcs,TRUE,iDocLine);
   }
 }//if
  
  if(g_parseCode) // && !Config_getBool("STRIP_CODE_COMMENTS"))
   { 
     qlist.append(new QCString(verilogScanYYtext)); 
   } 
  
} 


<Start>{COMMENT} {
       QCString text(verilogScanYYtext); 
				//fprintf(stderr,"\n %s",text.data());
					  int b=text.contains(vlogComment);
					  if(b && !g_parseCode){  
                       strComment+=verilogScanYYtext;
                        if (iDocLine==-1) iDocLine=yyLineNr;
                         VhdlDocGen::prepareComment(strComment);
                   
                         if(multLineComment){
                          handleVerilogCommentBlock(strComment,FALSE,iDocLine);
                          multLineComment=false;
                         }
                         else{
                           if(!checkMultiComment(text))
                            handleVerilogCommentBlock(strComment,true,iDocLine);
                          }//else 
                         }
                           strComment.resize(0);      
                         
					 
					 if(g_parseCode)
					 { 
				               qlist.append(new QCString(verilogScanYYtext));
					 } 
					 c_lval.ctype=verilogScanYYtext[0];
                   }

<Start>{STRING}    {
                  //   fprintf(stderr,"\n [%s : %c %d] string\n",verilogScanYYtext,verilogScanYYtext[verilogScanYYleng-2],verilogScanYYleng);

                      if((verilogScanYYleng > 2) && verilogScanYYtext[verilogScanYYleng-2] != 92) {
                      addText(verilogScanYYtext,verilogScanYYleng);
                      if(g_parseCode) { qlist.append(new QCString(verilogScanYYtext));c_lval.ctype=verilogScanYYtext[0];}
                      return  STRING_TOK;
                      }
                      if(verilogScanYYleng == 2){ 
                         if(g_parseCode) { qlist.append(new QCString(verilogScanYYtext)); }   
                        return  STRING_TOK;
                        } 
                     unput(verilogScanYYtext[verilogScanYYleng-1]);
                     yymore();
                     }

<Start>"\t"|"\r" {
                   if(yytext[0]=='\t'){
                    if(!g_parseCode)
                    parseToken(" ");
                   else
                    parseToken(verilogScanYYtext);
                  }
                  c_lval.ctype=' ';} 

<Start,EndOfText>[\n] {
   	   		// fprintf(stderr,"\nparse code line: [line: %d]",yyLineNr);
               addToken('\n');
              
			   if(g_parseCode){
			     qlist.append(new QCString(verilogScanYYtext));
			   } 
                else
	           yyLineNr+=QCString(verilogScanYYtext).contains('\n');
	           c_lval.ctype=verilogScanYYtext[0];
               }

<Start>[ ]+  { parseToken(verilogScanYYtext);}
<Start>[0-9]+|[0-9][0-9_]+|[0-9]+{BASE}[0-9a-zA-Z_?]*|[0-9]+"."[0-9eE]+|{BASE}[0-9a-zA-Z_?]*|['][01xz] {
                                                      addText(verilogScanYYtext,verilogScanYYleng);
                                                      if(verilogScanYYleng>(VBUF_SIZE-1))
                                                        verilogScanYYleng=VBUF_SIZE;
                                                      strncpy(c_lval.cstr,verilogScanYYtext,verilogScanYYleng);
                                                      c_lval.cstr[verilogScanYYleng]='\0';
                                                      if(g_parseCode) qlist.append(new QCString(verilogScanYYtext)); 
					                                  return  DIGIT_TOK;
                                                     }

<Start>[a-zA-Z]+|[_a-zA-Z$][_a-zA-Z0-9$]+ {
						                 addText(verilogScanYYtext,verilogScanYYleng);
						   	          	
						   	          	 if(g_parseCode){ 
										   qlist.append(new QCString(verilogScanYYtext));
						                  }
						                  if(verilogScanYYleng>(VBUF_SIZE-1))
                                                        verilogScanYYleng=VBUF_SIZE;
                                                    
						                   strncpy(c_lval.cstr,verilogScanYYtext,verilogScanYYleng);
                                            c_lloc.last_line= c_lloc.first_line;

                                           c_lval.cstr[verilogScanYYleng]='\0'; 
						                //  c_lloc.last_line= c_lloc.first_line;
						                  c_lloc.first_line=yyLineNr;
						                  return  LETTER_TOK;
                                         }

 
<Start>.  {
   c_lval.ctype=verilogScanYYtext[0];
  REJECT;
 }         

<Start>"(*"   {  parseToken(verilogScanYYtext);  return   ATL_TOK;}
<Start>"*)"   {  parseToken(verilogScanYYtext);  return   ATR_TOK;}
<Start>"~^"   {  parseToken(verilogScanYYtext);  return   SNNOT_TOK;}
<Start>"^~"   {  parseToken(verilogScanYYtext);  return   NOTSN_TOK;}
<Start>"&&&"   {  parseToken(verilogScanYYtext);  return   AAAND_TOK;}
<Start>"&&"   {  parseToken(verilogScanYYtext);  return   AAND_TOK;}
<Start>"||"   {  parseToken(verilogScanYYtext);  return   OOR_TOK;}
<Start>"!"   {  parseToken(verilogScanYYtext);  return   EXCLAMATION_TOK;}
<Start>"_"   {  parseToken(verilogScanYYtext);   return   UNDERSCORE_TOK;}
<Start>";"   {  parseToken(verilogScanYYtext); return  SEM_TOK;}
<Start>"."   {  parseToken(verilogScanYYtext);  return  DOT_TOK;}
<Start>","   {  parseToken(verilogScanYYtext); return  COMMA_TOK;}
<Start>"?"   {  parseToken(verilogScanYYtext);return  QUESTION_TOK;}
<Start>"+"   {  parseToken(verilogScanYYtext);return  PLUS_TOK;}
<Start>"-"   {  parseToken(verilogScanYYtext);return  MINUS_TOK;}
<Start>":"   {   parseToken(verilogScanYYtext); return  COLON_TOK;}
<Start>"("   { parseToken(verilogScanYYtext);if(g_parseCode) { c_lval.cstr[0]=' ';} return  LBRACE_TOK;}
<Start>")"   { parseToken(verilogScanYYtext);return  RBRACE_TOK;}
<Start>"}"   { parseToken(verilogScanYYtext);return  RRAM_TOK;}
<Start>"{"   { parseToken(verilogScanYYtext);return  LRAM_TOK;}
<Start>"["   {  parseToken(verilogScanYYtext);return  LBRACKET_TOK;}
<Start>"]"   { parseToken(verilogScanYYtext);return  RBRACKET_TOK;}
<Start>"&"   { parseToken(verilogScanYYtext);return  AND_TOK;}
<Start>"|"   { parseToken(verilogScanYYtext); return  OR_TOK;}
<Start>"="   { parseToken(verilogScanYYtext);  return  EQU_TOK;}
<Start>"<"   { parseToken(verilogScanYYtext); return  GT_TOK;}
<Start>">"   { parseToken(verilogScanYYtext);return  LT_TOK;}
<Start>"^"   { parseToken(verilogScanYYtext);return  NOT_TOK;}
<Start>"~"   { parseToken(verilogScanYYtext); return  SN_TOK;}
<Start>"*"   { parseToken(verilogScanYYtext);return  MULT_TOK;}
<Start>"%"   { parseToken(verilogScanYYtext);return  PERCENTAL_TOK;}
<Start>"@" { parseToken(verilogScanYYtext);return  AT_TOK;}
<Start>"#" { parseToken(verilogScanYYtext);	return  PARA_TOK;}
<Start>"$" { if(g_parseCode) parseToken(verilogScanYYtext); return  DOLLAR_TOK;}
<Start>"/*" {
                 vbufreset(); 
				 addText(verilogScanYYtext,verilogScanYYleng);
				 if(yy_hold_char=='!') // found  comment starting with "/*!"
				  doxComment=true;
				 startComment=yyLineNr;
				 BEGIN(StartComment); 
				 }
<Start>"/" {
 					  char c=yy_hold_char;
                         if(c !='/'){ 
						 parseToken(verilogScanYYtext);
						 return  ENV_TOK;
                         }
						 unput('/');// found "//"
						 REJECT;}


<StartComment>[^*]*[*]+    {
                       QCString tt(verilogScanYYtext);
					   int len=tt.length();
					  
					   if(verilogScanYYtext[len-1]=='*' && tt.contains('\n'))
					        {
					         QCString ss=tt;
					         VhdlDocGen::deleteAllChars(ss,' ');
					         VhdlDocGen::deleteAllChars(ss,'\t');
					         if(ss.data()  && ss.at(ss.length()-2)=='\n')
					         {
					          tt=tt.left(len-1);
					          len--;
					          }
					         }
					   
					   addText(tt.data(),len);
                       char c=yy_hold_char;
                         if(c =='/'){
						   unput('*');
						   BEGIN(Commentt);
						 }
					     else BEGIN(StartComment);
					 }

<Commentt>"*/" {	 
						 
						  QCString *qq=new QCString(getVerilogString());
						  qq->append("*/");
                       
						  if(g_parseCode){ 
							   	 	qlist.append(qq);		
							}
							else{
				             if(doxComment){  
						      qq->stripPrefix("/*!");
						        *qq=qq->left(qq->length()-2);
						        handleVerilogCommentBlock(*qq,FALSE,startComment);
							    }
							   yyLineNr+=qq->contains('\n');
							 
							
							  doxComment=false;
							delete qq;
							}
                      	 vbufreset();
                         BEGIN(Start);
                }
%%

//------ -------------------------------------------------------------------------------------------------

// do parsing
 int MyParserConv::doLex(){
   int token;
    token=yylex();
 //  fprintf(stderr,"\ntoken: %d",token);
    return token;
  } 
 
 void resetScanner(const char* s,MyParserConv* parse) { }


 void vbufreset() 
 {
  int i;
  i=getVerilogToken();
  memset(&g_buf[0],'\0',iSize);
  iSize=0;
  if(i==LETTER_TOK){
   lastLetter=verilogScanYYtext;
   }
  }

 void addToken (char c)
 {
    if(iSize>inputPosition)
	  {
	  vbufreset();
	 // assert(0);
	 }
      g_buf[iSize]=c;
      iSize++;
      g_buf[iSize]='\0'; 

 } 

 QCString getLastLetter(){ return lastLetter; }

 void  addText (char *word, int len)
 {
  	  while(len-->0)
        g_buf[iSize++]=*word++;
  
      g_buf[iSize]='\0'; 
  } 

const char* getVerilogString() {if(iSize) return &g_buf[0];return NULL;}
const char* getVerilogParsingFile(){return yyFileName.data();}


int getVerilogLine() { return yyLineNr; }
int getVerilogPrevLine() { return yyPrevLine; }
int getVerilogEndLine(){ return yyEndLine; };


void VerilogScanner::resetCodeParserState(){}
bool VerilogScanner::needsPreprocessing(const QCString &extension){ return true; }
void VerilogScanner::parsePrototype(const char *text){ }

void VerilogScanner::parseInput(const char *fileName,const char *fileBuf,Entry *root)
{
        yyFileName=QCString(fileName);
	
      bool xilinx_ucf=isConstraintFile(yyFileName,".ucf");
      bool altera_qsf=isConstraintFile(yyFileName,".qsf");
   
   // support XILINX(ucf) and ALTERA (qsf) file
   //   printf("%s",fileBuf);
     if(xilinx_ucf)  {  VhdlDocGen::parseUCF(fileBuf,root,yyFileName,false);  return; }
     if(altera_qsf) { VhdlDocGen::parseUCF(fileBuf,root,yyFileName,true); return; }
    
     num_chars=0;
     QCString pPuffer(" ");
	 pPuffer+=fileBuf;
	 if(!g_lexInit)
	 buildKeyMap();
	 inputFile.setName(fileName);
	   if(g_lexInit)
		 verilogScanYYrestart( verilogScanYYin );
	   g_lexInit=TRUE;
	   curRoots=root;	
 	   initVerilogParser(curRoots,false);
       g_thisParser=this;
	   iSize=0;
       int len =inputFile.size();
       inputPosition=0;
	   g_buf=new char[len+1024];
       assert(g_buf);
       inputVerilogString=pPuffer.data();
       g_inputLines  = countLines();
	   totLines=g_inputLines;
	   yyLineNr=1;
       pconv=new MyParserConv();
       resetScanner(NULL,pconv);
          groupEnterFile(fileName,yyLineNr);
       int ok=pconv->parse(pconv);
	 //  globalMemberList.clear();
	   qlist.clear();
	   delete [] g_buf;g_buf=0;
	   delete pconv;	  	  
}


static void  parseConstraint(const QCString & input)
{
QStringList qsl=QStringList::split("\n",input);
codifyLines(input.data());
/*
for(uint j=0;j<qsl.count();j++)
{
  QCString q=(QCString)qsl[j];
  writeVWord(QCString& qcs)
}
*/
}// parseConstraint



 void VerilogScanner::parseCode(CodeOutputInterface &codeOutIntf,
                   const char *scopeName,
                   const QCString &input,
				   bool isExampleBlock,
                   const char *exampleName,
                   FileDef *fileDef,
                   int startLine,
                   int endLine,
                   bool inlineFragment,
                   MemberDef *memberDef,
                   bool showLineNumbers
                  )
				  { 
				  num_chars=0;
         
  			
				 //  Definition *di=(Definition*)fileDef;
				   QCString pPuffer(" ",1);
				   if(!fileDef)
				   {
				    fprintf(stderr," spe code << %s >> \n",input.data());
				    return;
                                     }
				   assert(fileDef);
				     yyFileName=fileDef->fileName();
                    g_code = &codeOutIntf;
                 
				  
                   QCString ff(fileDef->getDefFileName());
                   BufStr preBuf(input.length());
                        
                   if (Config_getBool("ENABLE_PREPROCESSING") && startLine==-1)
                     {
                        if(ff.data())
                        fprintf(stderr,"\nPreprocessing code of file %s...\n",ff.data());
                        preprocessVerilogFile(ff,preBuf,0,-1);
                         preBuf.addChar('\0');
                         pPuffer+=preBuf.data();              
                   }
                   else
                    pPuffer+=input.data();
                  // printf("%s",pPuffer.data());
                      initVerilogParser(0,true);
                       VerilogDocGen::buildGlobalVerilogVariableDict(fileDef,true);
                  
		
                   if(memberDef)// write code for function body
                   {
                    ClassDef *dd=memberDef->getClassDef();
	                if(dd)
	                g_CurrClass=dd->className();
                    VerilogDocGen::setCurrVerilogClass(g_CurrClass);
						startLine--;
            
                   }
                      inputVerilogString   = pPuffer.data();
                      inputPosition = 0;
					  iSize=0;
                      g_buf=new char[input.length()+1024];
                      assert(g_buf);
				  
					  g_currentFontClass = 0;
                      g_needsTermination = FALSE;
 
                      if (endLine!=-1)
                      g_inputLines  = endLine+1;
					    else
                      g_inputLines  = countLines();
                      totLines=g_inputLines;
				      if (startLine!=-1)
                        yyLineNr    = startLine;
                      else
                        yyLineNr    = 1;
                         g_exampleName   = exampleName;
                        g_sourceFileDef = fileDef;
                         if (isExampleBlock && fileDef==0)
                        {
                          // create a dummy filedef for the example
                         g_sourceFileDef = new FileDef("",exampleName);
                        }
 
                       if (g_sourceFileDef) 
                       {
                        setCurrentDoc(g_sourceFileDef->name(),g_sourceFileDef->getSourceFileBase());
                       }
 
                       g_currentDefinition = 0;
                       g_currentMemberDef = 0;
               
  
                      if (!g_exampleName.isEmpty())
                      {
                       g_exampleFile = convertNameToFile(g_exampleName+"-example");
                       }
  
                      g_includeCodeFragment = inlineFragment;
                        if(!memberDef) startCodeLine();
             
               bool xilinx_ucf=isConstraintFile(yyFileName,".ucf");
                    bool altera_qsf=isConstraintFile(yyFileName,".qsf");

                   if(xilinx_ucf || altera_qsf) 
                     {
                     parseConstraint(input);
                     return;
                     } 
				   
                     
  		             verilogScanYYrestart( verilogScanYYin );
				    g_parseCode=true;
                    MyParserConv conv;
 	                resetScanner(input.data(),&conv);
                     int ok=conv.parse(&conv);
					if (isExampleBlock && g_sourceFileDef)
                    {
                     // delete the temporary file definition used for this example
                       delete g_sourceFileDef;
                       g_sourceFileDef=0;
                    }
                   
				    printVerilogBuffer(true);
				  //  globalMemberList.clear();
				    g_parseCode=false;
				    delete [] g_buf;g_buf=0;
				   return;
                    }

//-------------------------------------------------------------------------------------------------------

//	parse 'include /'define
static void parseGlobalMember(){
        QCString tmp,args,name,comment;
		QCString qcs(getVerilogString());
        int specLine=yyLineNr;
        bool bInc=qcs.contains("`include"); 
       
        if(qcs.stripPrefix("`define") || qcs.stripPrefix("`include"))
	    {
         comment=checkComment(qcs);
           if(!comment.stripPrefix("//%"))
              comment.resize(0);
         QRegExp reg("[^a-zA-Z_0-9$]+");
		 qcs=qcs.stripWhiteSpace();
	     int ll=qcs.find(reg,0);
		 if(ll>0){
			 args=qcs.mid(ll,qcs.length());
		     name=qcs.left(ll);
			 }
		 
		 if(ll==-1)
		 {
            int len;
			QRegExp reg("[[a-zA-Z_][a-zA-Z_0-9$]+");
			int ll=reg.match(qcs,0,&len);
			int strlen=qcs.length();
			if(strlen==len)
				 name=qcs;
		 }
		  
		if(!comment.isEmpty())
        handleVerilogCommentBlock(comment,true,yyLineNr);
    
        if(bInc)
         {
          VhdlDocGen::deleteAllChars(qcs,'"');
          qcs.simplifyWhiteSpace();
          if(qcs.isEmpty())return;
          qcs=VerilogDocGen::getFileNameFromString(qcs.data());
          Entry* pTemp=VerilogDocGen::makeNewEntry(qcs.data(),Entry::VARIABLE_SEC,VerilogDocGen::INCLUDE,yyLineNr,true);
          pTemp->type="include";
          return;
        }
    
       //  VhdlDocGen::deleteAllChars(args,'\\');
         Entry* op=getCurrVerilog();
         bool bGlobal=op;
         Entry* pTemp=VerilogDocGen::makeNewEntry(name.data(),Entry::VARIABLE_SEC,VerilogDocGen::FEATURE,defineLineContinue,bGlobal);
         pTemp->args=args;
         pTemp->type="feature";
     
        //    if(getCurrVerilog()!=0) return; // found definition outside a module(not global)
       if(!bGlobal){ 
         Entry *pNew=new Entry(*pTemp);
         globalMemberList.insert(pNew->name,pNew);
         }
        }

}// parseGlobalMember


bool handleVerilogCommentBlock(const QCString &doc,bool brief,int iDoc)
{
  int position=0;
  bool needsEntry=FALSE;
   if(g_parseCode) return 0;
  Entry* curr=getCurrVerilogEntry();
  if(curr==NULL){
  assert(0);
  curr=new Entry();
   curRoots->addSubEntry(curr);
  }
  Protection protection=Public;
  if (brief) 
    curr->briefLine = iDoc; 
  else 
    curr->docLine = iDoc;

 // printf("parseCommentBlock %p [%s]\n",curr,doc.data());
  while(parseCommentBlock(
	g_thisParser,
	curr,
	doc,        // text
	yyFileName, // file
	iDocLine,   // line of block start
	brief, 
	false,
	FALSE,
	protection,
     position,
     needsEntry
     )){
         if (needsEntry)
         {
         // fprintf(stderr,"\n<<need new entry in while%s>>",doc.data());
           VerilogDocGen::makeNewEntry(curr->name.data(),curr->section,curr->spec,0,true);
           }
        }
  
  if (needsEntry)
  {
    //fprintf(stderr,"\n<<need new entry %s>>",doc.data());
    VerilogDocGen::makeNewEntry(curr->name.data(),curr->section,curr->spec,0,true);
  }

  iDocLine=-1;
  return false;
}

// returns the stored member in the global list
// file : member file

MemberDef* findGlobalMember(const QCString & file, const QCString& memName){
 MemberDef *md;
 bool ambig;
  FileDef *fd=findFileDef(Doxygen::inputNameDict,file,ambig);
  if(!fd) return NULL;
     MemberList * ml=fd->getMemberList(MemberList::allMembersList);
         
  if(ml==NULL) return NULL;
 
    MemberListIterator fmni(*ml);
     
	    for (fmni.toFirst();(md=fmni.current());++fmni)
        {
            if(md->getMemberSpecifiers()==0 || md->getMemberSpecifiers()==VerilogDocGen::FEATURE ){
             if(strcmp(md->name().data(),memName.data())==0) return md;  
		  }
		}//for
 return NULL;
}//findDefinition


MemberDef* findGlobalMember(const QCString& memName){
 QCString temp=memName;
 temp.stripPrefix("`");
  Entry* ee=globalMemberList.find(temp.data());  
		   if(ee){
	       QCString file=VerilogDocGen::getFileNameFromString(ee->fileName.data());
	        return findGlobalMember(file,temp);
	        }
	  
	  return NULL;      
  }       

 void parseLib(char *str)
{
 QRegExp ep("[\t ]");
 QCString temp=str;

 temp.stripPrefix("library");
 QCString lib=temp.simplifyWhiteSpace();
 
 if(!g_parseCode)
 {
   yyLineNr+=temp.contains('\n');
   int i=lib.find(ep);
   assert(i>0);
   Entry* pTemp=VerilogDocGen::makeNewEntry(lib.left(i).data(),Entry::VARIABLE_SEC,VerilogDocGen::LIBRARY,yyLineNr);
   pTemp->type="library";
   Entry *pNew=new Entry(*pTemp);
   globalMemberList.insert(pNew->name,pNew);
   
}
else
  {
      // qlist.append(new QCString(verilogScanYYtext)); 
      printVerilogBuffer(true);
      writeFont("vhdlkeyword","library");
      codifyLines(temp.data());
  }

}//parseLib

QCString checkComment(QCString& q)
{
  QCString comment;
  int j=q.find("//");
  if(j>0){
   comment=q.right(q.length()-j);
   q=q.left(j);
   return comment;
  }
  
  int k=q.find("/*");
  int l=q.find("*/");
  
  if((k>0) &&(l>k) )
  {
   comment=q.right(q.length()-k);
   q=q.left(k);
  }
  return comment;
}

 void composeString(QCString& q)
{
  QRegExp ep("[`a-zA-Z0-9_'?]+");
  QRegExp ep2("[\\s]+");
 //  j = reg.match(temp.data(),0,&len);
 int index=q.find("§");
 if(index>-1)
  q=q.remove(index,1);
 
 int len;
 int j=ep.match(q.data(),0,&len );
 while(j>=0){
 int hj=q.length();
 QCString left=q.left(len);
  qlist.append(new QCString(left.data())); 
  q=q.right(q.length()-len);
  
  j=ep2.match(q.data(),0,&len);
  
  if(j>=0)
  {
   left=q.left(len);
   qlist.append(new QCString(left.data())); 
   q=q.right(q.length()-len);
  }
  
 j=ep.match(q.data(),0,&len);
 if(j>0)
  len=1;
 }
if(!q.isEmpty()) 
 qlist.append(new QCString(q.data())); 
}

static void writeInclude(QCString inc)
{
   if(inc.isEmpty())  return;
   int i=inc.find("\"");
   int j=inc.findRev("\"");
   
   if(i>=0 && j>i)
   {
    QCString first=inc.left(i+1);
    QCString third=inc.right(inc.length()-j);
    QCString mid=inc.mid(i+1,j-i-1);
    QCString ff=VerilogDocGen::getFileNameFromString(mid.data());
    bool ambig;
     FileDef *fd=findFileDef(Doxygen::inputNameDict,ff,ambig);
     if(fd)
     {
       g_code->codify(first.data());
       g_code->writeCodeLink(fd->getReference(),
	                      fd->getOutputFileBase(),
			              fd->fileName(),
			              mid.data(),0
			              );
       g_code->codify(third.data());  
     }
     else
      writeWord(inc.data());
 
   }
}
