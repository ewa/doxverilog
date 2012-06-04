#
# This file was generated from Makefile.in on Sun May 20 00:09:24 CEST 2012
#

DOXYGEN   = /Users/dimitri/doxygen
TMAKEPATH = /Users/dimitri/doxygen/tmake/lib/macosx-c++
ENV       = env TMAKEPATH=$(TMAKEPATH)
TMAKE     = /Users/dimitri/doxygen/tmake/bin/tmake
MAKE      = /opt/local/bin/gmake
PERL      = /opt/local/bin/perl
RM        = rm -f
CP        = cp
VERSION   = 1.8.1
INSTALL   = /usr/local
INSTTOOL  = /opt/local/bin/ginstall
DOXYDOCS  = ..
DOCDIR    = $(INSTALL)/share/doc/packages/doxygen
QTDIR     = /usr
HAVE_DOT  = /usr/local/bin/dot
MKSPECS   = -spec macx-g++

#
# $Id: Makefile.in,v 1.4 2001/03/19 19:27:39 root Exp $
#
# Copyright (C) 1997-2012 by Dimitri van Heesch.
# 
# Permission to use, copy, modify, and distribute this software and its
# documentation under the terms of the GNU General Public License is hereby 
# granted. No representations are made about the suitability of this software 
# for any purpose. It is provided "as is" without express or implied warranty.
# See the GNU General Public License for more details.
# 
# Documents produced by Doxygen are derivative works derived from the
# input used in their production; they are not affected by this license.
# 

all: Makefile.libdoxygen Makefile.libdoxycfg Makefile.doxygen Makefile
	$(MAKE) -f Makefile.libdoxycfg PERL=$(PERL) $@
	$(MAKE) -f Makefile.libdoxygen PERL=$(PERL) $@
	$(MAKE) -f Makefile.doxygen    PERL=$(PERL) $@

Makefile.libdoxygen: libdoxygen.pro libdoxygen.t 
	$(ENV) $(PERL) $(TMAKE) libdoxygen.pro >Makefile.libdoxygen

Makefile.libdoxycfg: libdoxycfg.pro libdoxycfg.t 
	$(ENV) $(PERL) $(TMAKE) libdoxycfg.pro >Makefile.libdoxycfg

Makefile.doxygen: doxygen.pro 
	$(ENV) $(PERL) $(TMAKE) doxygen.pro >Makefile.doxygen

tmake: 
	$(ENV) $(PERL) $(TMAKE) libdoxygen.pro >Makefile.libdoxygen
	$(ENV) $(PERL) $(TMAKE) libdoxycfg.pro >Makefile.libdoxycfg
	$(ENV) $(PERL) $(TMAKE) doxygen.pro >Makefile.doxygen

clean: Makefile.libdoxygen Makefile.libdoxycfg Makefile.doxygen 
	$(MAKE) -f Makefile.libdoxygen clean 
	$(MAKE) -f Makefile.libdoxycfg clean 
	$(MAKE) -f Makefile.doxygen    clean 

distclean: clean
	-$(RM) scanner.cpp code.cpp config.cpp pre.cpp ce_lex.cpp \
               ce_parse.cpp ce_parse.h tag.cpp commentscan.cpp \
	       declinfo.cpp defargs.cpp commentcnv.cpp doctokenizer.cpp \
	       pycode.cpp pyscanner.cpp fortrancode.cpp fortranscanner.cpp \
	       vhdlscanner.cpp vhdlcode.cpp tclscanner.cpp vhdlparser.h \
	       vhdlparser.cpp

FORCE:
