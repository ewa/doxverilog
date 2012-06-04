
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison GLR parsers in C
   
      Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NET_TOK = 258,
     STR0_TOK = 259,
     STR1_TOK = 260,
     GATE_TOK = 261,
     STRING_TOK = 262,
     DIGIT_TOK = 263,
     UNDERSCORE_TOK = 264,
     SEM_TOK = 265,
     DOT_TOK = 266,
     LETTER_TOK = 267,
     PLUS_TOK = 268,
     MINUS_TOK = 269,
     COLON_TOK = 270,
     LBRACE_TOK = 271,
     RBRACE_TOK = 272,
     LBRACKET_TOK = 273,
     RBRACKET_TOK = 274,
     AND_TOK = 275,
     OR_TOK = 276,
     EQU_TOK = 277,
     GT_TOK = 278,
     LT_TOK = 279,
     NOT_TOK = 280,
     MULT_TOK = 281,
     PERCENTAL_TOK = 282,
     ENV_TOK = 283,
     PARA_TOK = 284,
     CHAR_TOK = 285,
     AT_TOK = 286,
     DOLLAR_TOK = 287,
     BASE_TOK = 288,
     SN_TOK = 289,
     EXCLAMATION_TOK = 290,
     RRAM_TOK = 291,
     LRAM_TOK = 292,
     PARAMETER_TOK = 293,
     OUTPUT_TOK = 294,
     INOUT_TOK = 295,
     SMALL_TOK = 296,
     MEDIUM_TOK = 297,
     LARGE_TOK = 298,
     VEC_TOK = 299,
     SCALAR_TOK = 300,
     REG_TOK = 301,
     TIME_TOK = 302,
     REAL_TOK = 303,
     EVENT_TOK = 304,
     ASSIGN_TOK = 305,
     DEFPARAM_TOK = 306,
     MODUL_TOK = 307,
     ENDMODUL_TOK = 308,
     MACRO_MODUL_TOK = 309,
     ENDPRIMITIVE_TOK = 310,
     PRIMITIVE_TOK = 311,
     INITIAL_TOK = 312,
     TABLE_TOK = 313,
     ENDTABLE_TOK = 314,
     ALWAYS_TOK = 315,
     TASK_TOK = 316,
     ENDTASK_TOK = 317,
     FUNC_TOK = 318,
     ENDFUNC_TOK = 319,
     IF_TOK = 320,
     CASE_TOK = 321,
     CASEX_TOK = 322,
     CASEZ_TOK = 323,
     FOREVER_TOK = 324,
     REPEAT_TOK = 325,
     FOR_TOK = 326,
     JOIN_TOK = 327,
     WAIT_TOK = 328,
     FORCE_TOK = 329,
     RELEASE_TOK = 330,
     DEASSIGN_TOK = 331,
     DISABLE_TOK = 332,
     WHILE_TOK = 333,
     ELSE_TOK = 334,
     ENDCASE_TOK = 335,
     BEGIN_TOK = 336,
     DEFAULT_TOK = 337,
     FORK_TOK = 338,
     END_TOK = 339,
     SPECIFY_TOK = 340,
     ENDSPECIFY_TOK = 341,
     SPECPARAM_TOK = 342,
     DSETUP_TOK = 343,
     DHOLD_TOK = 344,
     DWIDTH_TOK = 345,
     DPERIOD_TOK = 346,
     DSKEW_TOK = 347,
     DRECOVERY_TOK = 348,
     DSETUPHOLD_TOK = 349,
     POSEDGE_TOK = 350,
     NEGEDGE_TOK = 351,
     EDGE_TOK = 352,
     COMMA_TOK = 353,
     QUESTION_TOK = 354,
     AUTO_TOK = 355,
     INPUT_TOK = 356,
     SIGNED_TOK = 357,
     LOCALPARAM_TOK = 358,
     INTEGER_TOK = 359,
     NOCHANGE_TOK = 360,
     GENERATE_TOK = 361,
     ENDGENERATE_TOK = 362,
     GENVAR_TOK = 363,
     LIBRARY_TOK = 364,
     CONFIG_TOK = 365,
     ENDCONFIG_TOK = 366,
     INCLUDE_TOK = 367,
     PULSEON_DETECT_TOK = 368,
     PULSEONE_EVENT_TOK = 369,
     USE_TOK = 370,
     LIBLIST_TOK = 371,
     INSTANCE_TOK = 372,
     CELL_TOK = 373,
     SHOWCANCEL_TOK = 374,
     NOSHOWCANCEL_TOK = 375,
     REMOVAL_TOK = 376,
     FULLSKEW_TOK = 377,
     TIMESKEW_TOK = 378,
     RECREM_TOK = 379,
     IFNONE_TOK = 380,
     REALTIME_TOK = 381,
     DESIGN_TOK = 382,
     ATL_TOK = 383,
     ATR_TOK = 384,
     OOR_TOK = 385,
     AAND_TOK = 386,
     SNNOT_TOK = 387,
     NOTSN_TOK = 388,
     AAAND_TOK = 389,
     DEFINE_TOK = 390
   };
#endif


#ifndef YYSTYPE
typedef union YYSTYPE
{

/* Line 2638 of glr.c  */
#line 99 "c:\\.Trash-1000\\doxygen-svn\\src\\\\..\\src\\verilogparser.y"

	int itype;	/* for count */
	char ctype;	/* for char */
	char cstr[VBUF_SIZE];
	


/* Line 2638 of glr.c  */
#line 193 "c:\\.Trash-1000\\doxygen-svn\\src\\\\..\\src\\verilogparser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{

  int first_line;
  int first_column;
  int last_line;
  int last_column;

} YYLTYPE;
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



extern YYSTYPE c_lval;

extern YYLTYPE c_lloc;


