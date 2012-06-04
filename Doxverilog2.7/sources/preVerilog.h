/******************************************************************************
 *
 * $Id: pre.h,v 1.10 2001/03/19 19:27:41 root Exp $
 *
 * Copyright (C) 1997-2008 by Dimitri van Heesch.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation under the terms of the GNU General Public License is hereby 
 * granted. No representations are made about the suitability of this software 
 * for any purpose. It is provided "as is" without express or implied warranty.
 * See the GNU General Public License for more details.
 *  
 * Documents produced by Doxygen are derivative works derived from the
 * input used in their production; they are not affected by this license.
 *
 */

#ifndef PREVERILOG_H
#define PREVERILOG_H

#include "qtbc.h"
#include <stdio.h>
//#include <qfile.h>
#include "define.h"

class BufStr;


DefineDict* getFileDefineDictVerilog();
void initVerilogPreprocessor();
void cleanUpVerilogPreprocessor();
void addSearchVerilogDir(const char *dir);
void preprocessVerilogFile(const char *fileName,BufStr &output,const char* codeFragment, int startLine);
void preFreeVerilogScanner();

#endif
