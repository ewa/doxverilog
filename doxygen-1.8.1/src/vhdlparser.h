/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     t_ABSTRLIST = 258,
     t_CHARLIST = 259,
     t_DIGIT = 260,
     t_STRING = 261,
     t_LETTER = 262,
     t_ACCESS = 263,
     t_AFTER = 264,
     t_ALIAS = 265,
     t_ALL = 266,
     t_AND = 267,
     t_ARCHITECTURE = 268,
     t_ARRAY = 269,
     t_ASSERT = 270,
     t_ATTRIBUTE = 271,
     t_BEGIN = 272,
     t_BLOCK = 273,
     t_BODY = 274,
     t_BUFFER = 275,
     t_BUS = 276,
     t_CASE = 277,
     t_COMPONENT = 278,
     t_CONFIGURATION = 279,
     t_CONSTANT = 280,
     t_DISCONNECT = 281,
     t_DOWNTO = 282,
     t_ELSE = 283,
     t_ELSIF = 284,
     t_END = 285,
     t_ENTITY = 286,
     t_EXIT = 287,
     t_FILE = 288,
     t_FOR = 289,
     t_FUNCTION = 290,
     t_GENERATE = 291,
     t_GENERIC = 292,
     t_GUARDED = 293,
     t_IF = 294,
     t_IN = 295,
     t_INOUT = 296,
     t_IS = 297,
     t_LABEL = 298,
     t_LIBRARY = 299,
     t_LINKAGE = 300,
     t_LOOP = 301,
     t_MAP = 302,
     t_NAND = 303,
     t_NEW = 304,
     t_NEXT = 305,
     t_NOR = 306,
     t_NULL = 307,
     t_OF = 308,
     t_ON = 309,
     t_OPEN = 310,
     t_OR = 311,
     t_OTHERS = 312,
     t_OUT = 313,
     t_PACKAGE = 314,
     t_PORT = 315,
     t_PROCEDURE = 316,
     t_PROCESS = 317,
     t_RANGE = 318,
     t_RECORD = 319,
     t_REGISTER = 320,
     t_REPORT = 321,
     t_RETURN = 322,
     t_SELECT = 323,
     t_SEVERITY = 324,
     t_SIGNAL = 325,
     t_SUBTYPE = 326,
     t_THEN = 327,
     t_TO = 328,
     t_TRANSPORT = 329,
     t_TYPE = 330,
     t_UNITS = 331,
     t_UNTIL = 332,
     t_USE = 333,
     t_VARIABLE = 334,
     t_WAIT = 335,
     t_WHEN = 336,
     t_WHILE = 337,
     t_WITH = 338,
     t_XOR = 339,
     t_IMPURE = 340,
     t_PURE = 341,
     t_GROUP = 342,
     t_POSTPONED = 343,
     t_SHARED = 344,
     t_XNOR = 345,
     t_SLL = 346,
     t_SRA = 347,
     t_SLA = 348,
     t_SRL = 349,
     t_ROR = 350,
     t_ROL = 351,
     t_UNAFFECTED = 352,
     t_ASSUME_GUARANTEE = 353,
     t_ASSUME = 354,
     t_CONTEXT = 355,
     t_COVER = 356,
     t_DEFAULT = 357,
     t_FAIRNESS = 358,
     t_FORCE = 359,
     t_INERTIAL = 360,
     t_LITERAL = 361,
     t_PARAMETER = 362,
     t_PROTECTED = 363,
     t_PROPERTY = 364,
     t_REJECT = 365,
     t_RELEASE = 366,
     t_RESTRICT = 367,
     t_RESTRICT_GUARANTEE = 368,
     t_SEQUENCE = 369,
     t_STRONG = 370,
     t_VMODE = 371,
     t_VPROP = 372,
     t_VUNIT = 373,
     t_SLSL = 374,
     t_SRSR = 375,
     t_QQ = 376,
     t_QGT = 377,
     t_QLT = 378,
     t_QG = 379,
     t_QL = 380,
     t_QEQU = 381,
     t_QNEQU = 382,
     t_GESym = 383,
     t_GTSym = 384,
     t_LESym = 385,
     t_LTSym = 386,
     t_NESym = 387,
     t_EQSym = 388,
     t_Ampersand = 389,
     t_Minus = 390,
     t_Plus = 391,
     MED_PRECEDENCE = 392,
     t_REM = 393,
     t_MOD = 394,
     t_Slash = 395,
     t_Star = 396,
     MAX_PRECEDENCE = 397,
     t_NOT = 398,
     t_ABS = 399,
     t_DoubleStar = 400,
     t_Apostrophe = 401,
     t_LeftParen = 402,
     t_RightParen = 403,
     t_Comma = 404,
     t_VarAsgn = 405,
     t_Colon = 406,
     t_Semicolon = 407,
     t_Arrow = 408,
     t_Box = 409,
     t_Bar = 410,
     t_Dot = 411,
     t_Q = 412,
     t_At = 413,
     t_Neg = 414,
     t_LEFTBR = 415,
     t_RIGHTBR = 416,
     t_ToolDir = 417
   };
#endif
/* Tokens.  */
#define t_ABSTRLIST 258
#define t_CHARLIST 259
#define t_DIGIT 260
#define t_STRING 261
#define t_LETTER 262
#define t_ACCESS 263
#define t_AFTER 264
#define t_ALIAS 265
#define t_ALL 266
#define t_AND 267
#define t_ARCHITECTURE 268
#define t_ARRAY 269
#define t_ASSERT 270
#define t_ATTRIBUTE 271
#define t_BEGIN 272
#define t_BLOCK 273
#define t_BODY 274
#define t_BUFFER 275
#define t_BUS 276
#define t_CASE 277
#define t_COMPONENT 278
#define t_CONFIGURATION 279
#define t_CONSTANT 280
#define t_DISCONNECT 281
#define t_DOWNTO 282
#define t_ELSE 283
#define t_ELSIF 284
#define t_END 285
#define t_ENTITY 286
#define t_EXIT 287
#define t_FILE 288
#define t_FOR 289
#define t_FUNCTION 290
#define t_GENERATE 291
#define t_GENERIC 292
#define t_GUARDED 293
#define t_IF 294
#define t_IN 295
#define t_INOUT 296
#define t_IS 297
#define t_LABEL 298
#define t_LIBRARY 299
#define t_LINKAGE 300
#define t_LOOP 301
#define t_MAP 302
#define t_NAND 303
#define t_NEW 304
#define t_NEXT 305
#define t_NOR 306
#define t_NULL 307
#define t_OF 308
#define t_ON 309
#define t_OPEN 310
#define t_OR 311
#define t_OTHERS 312
#define t_OUT 313
#define t_PACKAGE 314
#define t_PORT 315
#define t_PROCEDURE 316
#define t_PROCESS 317
#define t_RANGE 318
#define t_RECORD 319
#define t_REGISTER 320
#define t_REPORT 321
#define t_RETURN 322
#define t_SELECT 323
#define t_SEVERITY 324
#define t_SIGNAL 325
#define t_SUBTYPE 326
#define t_THEN 327
#define t_TO 328
#define t_TRANSPORT 329
#define t_TYPE 330
#define t_UNITS 331
#define t_UNTIL 332
#define t_USE 333
#define t_VARIABLE 334
#define t_WAIT 335
#define t_WHEN 336
#define t_WHILE 337
#define t_WITH 338
#define t_XOR 339
#define t_IMPURE 340
#define t_PURE 341
#define t_GROUP 342
#define t_POSTPONED 343
#define t_SHARED 344
#define t_XNOR 345
#define t_SLL 346
#define t_SRA 347
#define t_SLA 348
#define t_SRL 349
#define t_ROR 350
#define t_ROL 351
#define t_UNAFFECTED 352
#define t_ASSUME_GUARANTEE 353
#define t_ASSUME 354
#define t_CONTEXT 355
#define t_COVER 356
#define t_DEFAULT 357
#define t_FAIRNESS 358
#define t_FORCE 359
#define t_INERTIAL 360
#define t_LITERAL 361
#define t_PARAMETER 362
#define t_PROTECTED 363
#define t_PROPERTY 364
#define t_REJECT 365
#define t_RELEASE 366
#define t_RESTRICT 367
#define t_RESTRICT_GUARANTEE 368
#define t_SEQUENCE 369
#define t_STRONG 370
#define t_VMODE 371
#define t_VPROP 372
#define t_VUNIT 373
#define t_SLSL 374
#define t_SRSR 375
#define t_QQ 376
#define t_QGT 377
#define t_QLT 378
#define t_QG 379
#define t_QL 380
#define t_QEQU 381
#define t_QNEQU 382
#define t_GESym 383
#define t_GTSym 384
#define t_LESym 385
#define t_LTSym 386
#define t_NESym 387
#define t_EQSym 388
#define t_Ampersand 389
#define t_Minus 390
#define t_Plus 391
#define MED_PRECEDENCE 392
#define t_REM 393
#define t_MOD 394
#define t_Slash 395
#define t_Star 396
#define MAX_PRECEDENCE 397
#define t_NOT 398
#define t_ABS 399
#define t_DoubleStar 400
#define t_Apostrophe 401
#define t_LeftParen 402
#define t_RightParen 403
#define t_Comma 404
#define t_VarAsgn 405
#define t_Colon 406
#define t_Semicolon 407
#define t_Arrow 408
#define t_Box 409
#define t_Bar 410
#define t_Dot 411
#define t_Q 412
#define t_At 413
#define t_Neg 414
#define t_LEFTBR 415
#define t_RIGHTBR 416
#define t_ToolDir 417




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE vhdlScanYYlval;

