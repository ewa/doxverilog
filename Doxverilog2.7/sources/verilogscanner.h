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

#ifndef verilogscanner_h
#define verilogscanner_h

#include "parserintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <ctype.h>

#include <qarray.h>
#include <qstack.h>
#include <unistd.h>
#include <qfile.h>
#include <qdict.h>

#include "entry.h"
#include "qcstring.h"
#include "qlist.h"
#include "qstringlist.h"

#include "filedef.h"
#include "classlist.h"
#include "classdef.h"

#include "translator.h"

#include "qregexp.h"
#include "outputlist.h"
#include "membername.h"
#include "memberdef.h"
#include "memberlist.h"
#include "verilogdocgen.h"
//#include "verilogparser.hpp"

#define  VBUF_SIZE 1024

class VerilogScanner : public ParserInterface
{
  public:
    virtual ~VerilogScanner() {}
    void parseInput(const char * fileName, 
                    const char *fileBuf, 
                    Entry *root);
    bool needsPreprocessing(const QCString &extension);
    void parseCode(CodeOutputInterface &codeOutIntf,
                   const char *scopeName,
                   const QCString &input,
                   bool isExampleBlock,
                   const char *exampleName=0,
                   FileDef *fileDef=0,
                   int startLine=-1,
                   int endLine=-1,
                   bool inlineFragment=FALSE,
                   MemberDef *memberDef=0,
				   bool showLineNumbers=TRUE
                  );
    void resetCodeParserState();
    void parsePrototype(const char *text);
};

//------ wrapper functions for parsing code ---------------------------------
 
void codifyVerilogString(char* c,char* color=NULL);
bool generateVerilogMemLink(QCString &clName,QCString& memberName,int type);
bool generateVerilogClassOrGlobalLink(char *clName);
void writeVerilogFont(const char *s,const char* text);

//void generateVerilogMemLink(QCString &clName,QCString& memberName);
bool generateVerilogCompMemLink(QCString &cl,QCString& inst,QCString & key, bool b);

bool writeVerilogColoredWord(const QCString& word );
void printVerilogBuffer(bool b=false);
void printVerilogStringList();
void writePrevVerilogWords(const QCString& qcs);



//------ functions for getting the parser states and parsed lines ---------------------------------


// clears the string buffer
void  vbufreset();

// returns a pointer to the buffer in which the parsed strings are stored
const char* getVerilogString();

int getVerilogLine();

int getVerilogPrevLine();

// returns the line in which the ENDMODULE_TOKEN/ENDPRIMITIVE_TOKEN is found
int getVerilogEndLine();

// returns the last parsed token
int getVerilogToken(); 

// returns the current parsing file
const char* getVerilogParsingFile();

// returns the last parsed letter
QCString getLastLetter();

 // return the current Entry = (current module/primitive)
 Entry* getCurrVerilogEntry();
 
 // returns the current Entry
 Entry* getCurrVerilog();

void initVerilogParser(Entry* ee,bool pc);

// function for parsing and assigning comments
bool handleVerilogCommentBlock(const QCString &doc,bool brief,int iDocLine);

// returns the current module name when code parsing
QCString getCurrVerilogParsingClass();

// finds global `define/`includes 
MemberDef* findGlobalMember(const QCString& file, const QCString& memName);

// finds global `define/`includes
MemberDef* findGlobalMember(const QCString& memName);

 void addGlobalVerilogMember(const Entry *e);

 void resetVerilogBrief();
#endif
