
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


#ifndef VerilogDocGen_h
#define VerilogDocGen_h

#include "entry.h"
#include "verilogscanner.h"
#include "vhdlscanner.h"

// wrapper class for the parser
class MyParserConv  
{
  
 public:
  uint iFileSize; 

  ~MyParserConv(){}
  MyParserConv(){}
  
 int parse(MyParserConv*);
 int doLex();
 
 
};


class VerilogDocGen  
{
public:

 // enum VerilogClasses {ENTITYCLASS,PACKBODYCLASS,ARCHITECTURECLASS,PACKAGECLASS};
 	
  enum States {STATE_FUNCTION=0x100,STATE_MODULE,STATE_UDP,STATE_TASK,STATE_GENERATE};
 
  
	enum VerilogKeyWords
	{
	  MODULE=0x1000,
	  FUNCTION,  //4097
	  FEATURE,
	  PRIMITIVE,
	  COMPONENT, //4100
	  PORT,
       PARAMETER, //4102
	  ALWAYS,          //4103
	  TASK,                //4104
	  OUTPUT,          //4105
	  INPUT,              //4106
	   INOUT,             //4107
	  DEFPARAM,
	  SPECPARAM,
	  GENERATE,
	  INCLUDE,
	  TIME,
	  SIGNAL,
	  LIBRARY,
	  CONFIGURATION
	  };

// functions for  verilog parser ---------------------

static void writeSource(MemberDef *mdef,OutputList& ol,QCString & cname);
static QCString convertTypeToString(int type,bool sing=true);

static void writeVerilogDeclarations(MemberList* ml,OutputList &ol,
               ClassDef *cd,NamespaceDef *nd,FileDef *fd,GroupDef *gd,
               const char *title,const char *subtitle,bool showEnumValues,int type);

static void writeVerilogDeclarations(MemberList* ml,OutputList& ol,GroupDef* gd,ClassDef* cd,FileDef* fd=NULL);

static void writePlainVerilogDeclarations(MemberDef* mdef,MemberList* mlist,OutputList &ol,
               ClassDef *cd,NamespaceDef *nd,FileDef *fd,GroupDef *gd,int specifier);

static void writeVerilogDeclarations(MemberDef* mdef,OutputList &ol,
                   ClassDef *cd,NamespaceDef *nd,FileDef *fd,GroupDef *gd,
                   bool inGroup);


// insert a new entry
static Entry* makeNewEntry(char* name=NULL,int sec=0,int spec=0,int line=0,bool add=true);

static MemberDef* findMember(QCString& className, QCString& memName,int type);

static MemberDef* findMemberDef(ClassDef* cd,QCString& key,MemberList::ListType type,
                                int t,bool def=false);


static void setCurrVerilogClass(QCString&);

// returns the definition which is found in class
static MemberDef* findDefinition(ClassDef* cd,  QCString& memName);

// return the module/primitve name
static QCString getClassTitle(const ClassDef*);

// returns the color of a keyword if one is found
static const QCString* findKeyWord(const char*);

static void initEntry(Entry *e);

static QCString getFileNameFromString(const char* fileName);

static void adjustMemberName(QCString& nn); 

// returns the entry found at line
static Entry* getEntryAtLine(const Entry* ce,int line);
static QList<Entry>* getEntryAtLine1(const Entry* ce,int line);
static void buildGlobalVerilogVariableDict(const FileDef* fileDef,bool clear=FALSE,int level=0);
static MemberDef* findInstMember(QCString& cl,QCString& inst,QCString& key,bool b);

};

// start prefix for each comment 

//% a one line comment

//% a 
//% multi line
//% comment 
static const char* vlogComment="//%";

#endif
