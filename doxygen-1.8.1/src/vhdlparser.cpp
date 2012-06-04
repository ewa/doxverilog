/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse vhdlScanYYparse
#define yylex   vhdlScanYYlex
#define yyerror vhdlScanYYerror
#define yylval  vhdlScanYYlval
#define yychar  vhdlScanYYchar
#define yydebug vhdlScanYYdebug
#define yynerrs vhdlScanYYnerrs


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




/* Copy the first part of user declarations.  */


#include <stdio.h>
#include <qcstring.h>
#include <qstringlist.h>

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

struct  YYMM
{
  int itype;
  QCString qstr;
};

// define struct instead of union
#define YYSTYPE YYMM

#include "membergroup.h"
#include "vhdldocgen.h"
#include "doxygen.h"
#include "searchindex.h"
#include "vhdlscanner.h"
#include "commentscan.h"
#include "entry.h"
#include "arguments.h"

//-----------------------------variables ---------------------------------------------------------------------------
static MyParserVhdl* myconv=0;

static struct s_contVhdl s_str;
static QList<Entry>instFiles;
static int yyLineNr;
static Entry* lastCompound;
static Entry* currentCompound;
static Entry* lastEntity;
static Entry* current;
static Entry* tempEntry;
static Entry* current_root;
static QCString compSpec;
static QCString currName;
static int levelCounter;
static QCString confName;
static QCString genLabels;

static QList<ConfNode> configL;
static ConfNode* currNode;

static int currP=0;

enum  { GEN_SEC=0x1, PARAM_SEC,CONTEXT_SEC,PROTECTED_SEC } ;

static int param_sec = 0;
static int parse_sec=0;


//---------------------------- function --------------------------------------------------------------------------------

int vhdlScanYYlex ();
void vhdlScanYYerror (char const *);

static void addVhdlType(const QCString &name,int startLine,
                        int section,int spec,
			const char* args,const char* type,
			Protection prot=Public);
static void addCompInst(char *n, char* instName,char* comp,int line);

static void newEntry();
static void initEntry(Entry *e);
static bool isFuncProcProced();
static void popConfig();
static void pushLabel(const QCString &label);
static void popLabel();
static void addConfigureNode(const char* a,const char*b,
                         bool isRoot,bool isLeave,bool inlineConf=FALSE);
//static bool addLibUseClause(const QCString &type);
static bool isFuncProcProced();
static void initEntry(Entry *e);
static void addProto(const char *s1,const char *s2,const char *s3,
                     const char *s4,const char *s5,const char *s6);
static void createFunction(const QCString &impure,int spec,
                           const QCString &fname);

void newVhdlEntry()
{
  newEntry();
}

Entry* getCurrentVhdlEntry()
{
  return current;
}

void initVhdlParser()
{
  lastCompound=0;
  lastEntity=0;
  currentCompound=0;
  lastEntity=0;
  current_root=s_str.root;
  current=new Entry();
  initEntry(current);
}

QList<Entry> & getVhdlInstList()
{
  return instFiles;
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */


#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2912

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  398
/* YYNRULES -- Number of rules.  */
#define YYNRULES  922
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1590

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    33,    34,    36,    39,
      41,    45,    48,    49,    52,    54,    56,    58,    60,    62,
      64,    66,    68,    70,    74,    78,    80,    84,    89,    97,
     101,   102,   104,   105,   108,   109,   112,   114,   115,   116,
     121,   122,   123,   128,   132,   140,   146,   152,   153,   155,
     158,   160,   161,   164,   166,   172,   173,   181,   187,   188,
     190,   192,   195,   196,   199,   201,   207,   213,   217,   218,
     220,   223,   225,   226,   228,   231,   233,   236,   238,   241,
     245,   251,   257,   262,   263,   265,   268,   272,   273,   276,
     278,   280,   282,   284,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   304,   306,   308,   310,   312,   314,   316,
     318,   320,   322,   324,   326,   328,   330,   332,   334,   336,
     338,   340,   342,   344,   346,   348,   351,   353,   355,   357,
     359,   361,   363,   365,   367,   369,   371,   373,   375,   377,
     379,   381,   383,   385,   387,   389,   391,   393,   395,   397,
     399,   401,   403,   405,   407,   409,   411,   413,   415,   417,
     419,   421,   423,   425,   427,   429,   434,   436,   438,   441,
     442,   447,   448,   456,   457,   464,   466,   469,   470,   474,
     475,   478,   479,   482,   484,   486,   488,   497,   504,   505,
     507,   509,   511,   514,   517,   520,   521,   524,   526,   531,
     535,   536,   539,   542,   544,   546,   549,   557,   558,   561,
     562,   564,   566,   567,   569,   570,   572,   574,   576,   578,
     580,   582,   587,   588,   591,   594,   599,   603,   607,   608,
     611,   614,   618,   620,   622,   624,   626,   630,   632,   634,
     636,   638,   641,   643,   645,   647,   649,   651,   653,   655,
     657,   661,   665,   669,   673,   677,   681,   685,   689,   693,
     697,   701,   705,   709,   712,   714,   717,   720,   723,   726,
     730,   735,   739,   743,   747,   751,   755,   759,   763,   767,
     771,   775,   779,   783,   787,   791,   795,   799,   803,   807,
     811,   814,   817,   819,   823,   825,   827,   829,   831,   835,
     837,   839,   841,   843,   845,   848,   851,   855,   857,   859,
     861,   863,   865,   869,   871,   873,   875,   877,   879,   881,
     883,   885,   889,   891,   893,   895,   898,   901,   903,   907,
     912,   916,   920,   924,   927,   933,   938,   942,   948,   952,
     957,   961,   964,   965,   967,   968,   970,   974,   976,   979,
     980,   983,   986,   988,   990,   992,   997,  1002,  1006,  1007,
    1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,  1028,
    1030,  1035,  1036,  1039,  1042,  1049,  1052,  1054,  1055,  1058,
    1060,  1063,  1068,  1076,  1077,  1080,  1083,  1087,  1092,  1093,
    1095,  1102,  1103,  1106,  1108,  1113,  1116,  1120,  1126,  1130,
    1133,  1135,  1136,  1138,  1142,  1145,  1149,  1150,  1152,  1155,
    1160,  1161,  1164,  1167,  1169,  1171,  1173,  1177,  1179,  1183,
    1185,  1187,  1194,  1195,  1198,  1206,  1207,  1210,  1211,  1213,
    1220,  1228,  1229,  1232,  1234,  1236,  1238,  1241,  1243,  1245,
    1247,  1249,  1257,  1264,  1266,  1268,  1269,  1272,  1281,  1288,
    1289,  1294,  1295,  1297,  1305,  1308,  1310,  1312,  1313,  1316,
    1319,  1325,  1333,  1338,  1341,  1343,  1345,  1346,  1349,  1352,
    1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,
    1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,
    1399,  1407,  1408,  1412,  1417,  1418,  1421,  1426,  1432,  1434,
    1436,  1438,  1443,  1449,  1452,  1454,  1455,  1458,  1460,  1462,
    1464,  1466,  1468,  1470,  1472,  1474,  1489,  1490,  1492,  1493,
    1496,  1498,  1499,  1504,  1509,  1510,  1515,  1516,  1521,  1522,
    1527,  1528,  1530,  1532,  1536,  1539,  1541,  1545,  1547,  1549,
    1551,  1552,  1562,  1563,  1572,  1581,  1591,  1592,  1596,  1600,
    1602,  1607,  1610,  1614,  1616,  1621,  1624,  1628,  1630,  1635,
    1638,  1643,  1646,  1650,  1652,  1658,  1660,  1664,  1670,  1673,
    1675,  1676,  1679,  1682,  1685,  1686,  1689,  1692,  1694,  1697,
    1699,  1701,  1704,  1705,  1707,  1711,  1713,  1714,  1716,  1725,
    1730,  1731,  1734,  1739,  1740,  1743,  1745,  1748,  1749,  1758,
    1763,  1767,  1768,  1774,  1778,  1780,  1783,  1786,  1790,  1794,
    1796,  1797,  1808,  1813,  1814,  1818,  1819,  1821,  1822,  1824,
    1825,  1827,  1830,  1832,  1833,  1837,  1841,  1844,  1845,  1848,
    1851,  1853,  1854,  1857,  1859,  1861,  1864,  1866,  1868,  1870,
    1872,  1874,  1876,  1878,  1880,  1883,  1885,  1887,  1889,  1892,
    1894,  1900,  1906,  1907,  1910,  1911,  1914,  1915,  1917,  1918,
    1920,  1922,  1933,  1945,  1952,  1953,  1956,  1958,  1963,  1968,
    1969,  1972,  1973,  1975,  1985,  1993,  1994,  1997,  1998,  2001,
    2006,  2015,  2016,  2018,  2019,  2021,  2022,  2025,  2030,  2031,
    2034,  2035,  2037,  2040,  2043,  2047,  2048,  2050,  2055,  2061,
    2068,  2074,  2076,  2078,  2081,  2083,  2086,  2088,  2091,  2095,
    2100,  2106,  2107,  2110,  2111,  2114,  2115,  2118,  2120,  2124,
    2128,  2132,  2135,  2136,  2138,  2146,  2147,  2151,  2152,  2156,
    2164,  2170,  2171,  2174,  2176,  2177,  2180,  2182,  2184,  2186,
    2188,  2196,  2197,  2199,  2200,  2204,  2209,  2213,  2218,  2226,
    2229,  2234,  2237,  2241,  2243,  2245,  2247,  2251,  2252,  2256,
    2257,  2261,  2264,  2267,  2269,  2271,  2273,  2275,  2279,  2288,
    2296,  2304,  2307,  2308,  2310,  2312,  2316,  2318,  2320,  2322,
    2324,  2326,  2328,  2330,  2335,  2340,  2341,  2344,  2346,  2348,
    2351,  2353,  2355,  2357,  2359,  2365,  2371,  2372,  2375,  2377,
    2380,  2384,  2386,  2390,  2391,  2400,  2407,  2409,  2412,  2414,
    2417,  2419,  2421,  2423,  2431,  2440,  2447,  2455,  2464,  2471,
    2472,  2476,  2479,  2482,  2484,  2488,  2490,  2493,  2496,  2506,
    2515,  2524,  2530,  2535,  2538,  2540,  2543,  2547,  2549,  2551,
    2559,  2568,  2575,  2583,  2588,  2593,  2596,  2606,  2615,  2617,
    2619,  2628,  2629,  2631,  2637,  2639,  2644,  2654,  2655,  2657,
    2659,  2661,  2665,  2667,  2673,  2678,  2683,  2689,  2692,  2700,
    2706,  2708,  2713,  2715,  2717,  2719,  2721,  2725,  2732,  2740,
    2742,  2744,  2745,  2748,  2751,  2752,  2754,  2755,  2762,  2767,
    2773,  2780,  2784,  2785,  2789,  2796,  2798,  2800,  2802,  2804,
    2806,  2808,  2812,  2815,  2819,  2822,  2825,  2829,  2831,  2836,
    2839,  2843,  2846
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     164,     0,    -1,   165,    -1,   166,    -1,   174,    -1,   166,
     174,    -1,   491,    -1,   493,    -1,   494,    -1,   495,    -1,
     492,    -1,   172,    -1,    52,    -1,   495,    -1,   491,    -1,
     171,   491,    -1,    -1,   494,    -1,   494,   491,    -1,   491,
      -1,   173,   149,   491,    -1,   175,   176,    -1,    -1,   175,
     177,    -1,   181,    -1,   196,    -1,   202,    -1,   191,    -1,
     208,    -1,   507,    -1,   512,    -1,   178,    -1,   179,    -1,
      44,   173,   152,    -1,    78,   180,   152,    -1,   271,    -1,
     180,   149,   271,    -1,   182,     1,   460,   152,    -1,   182,
     189,   187,   185,   184,   460,   152,    -1,    31,   491,    42,
      -1,    -1,   491,    -1,    -1,    17,   359,    -1,    -1,   185,
     186,    -1,   215,    -1,    -1,    -1,    60,   188,   239,   152,
      -1,    -1,    -1,    37,   190,   239,   152,    -1,    37,     1,
     152,    -1,   192,   194,    17,   359,    30,   193,   152,    -1,
     192,     1,    30,   193,   152,    -1,    13,   491,    53,   491,
      42,    -1,    -1,   491,    -1,    13,   491,    -1,    13,    -1,
      -1,   194,   195,    -1,   216,    -1,   198,     1,    30,   199,
     152,    -1,    -1,   198,   200,   465,    30,   199,   152,   197,
      -1,    24,   491,    53,   491,    42,    -1,    -1,   491,    -1,
      24,    -1,    24,   491,    -1,    -1,   200,   201,    -1,   222,
      -1,   203,     1,    30,   204,   152,    -1,   203,   205,    30,
     204,   152,    -1,    59,   491,    42,    -1,    -1,   491,    -1,
      59,   491,    -1,    59,    -1,    -1,   207,    -1,   205,   206,
      -1,   218,    -1,   549,   152,    -1,   549,    -1,   549,   548,
      -1,   549,   548,   152,    -1,   209,     1,    30,   210,   152,
      -1,   209,   211,    30,   210,   152,    -1,    59,    19,   491,
      42,    -1,    -1,   491,    -1,    59,    19,    -1,    59,    19,
     491,    -1,    -1,   211,   212,    -1,   219,    -1,   202,    -1,
     512,    -1,   208,    -1,   513,    -1,   287,    -1,   311,    -1,
     324,    -1,   336,    -1,   333,    -1,   224,    -1,   179,    -1,
     214,    -1,   235,    -1,   343,    -1,   344,    -1,   339,    -1,
     326,    -1,   329,    -1,   486,    -1,   485,    -1,   213,    -1,
     214,    -1,   235,    -1,   462,    -1,   343,    -1,   344,    -1,
     475,    -1,   339,    -1,   326,    -1,   329,    -1,   486,    -1,
     485,    -1,   213,    -1,   560,    -1,   216,    -1,   217,   216,
      -1,   214,    -1,   462,    -1,   343,    -1,   344,    -1,   339,
      -1,   326,    -1,   329,    -1,   486,    -1,   485,    -1,   202,
      -1,   512,    -1,   513,    -1,   214,    -1,   235,    -1,   329,
      -1,   486,    -1,   485,    -1,   343,    -1,   344,    -1,   213,
      -1,   214,    -1,   235,    -1,   343,    -1,   344,    -1,   329,
      -1,   486,    -1,   485,    -1,   213,    -1,   214,    -1,   235,
      -1,   343,    -1,   344,    -1,   329,    -1,   486,    -1,   485,
      -1,   213,    -1,   344,    -1,   179,    -1,   485,    -1,    78,
     118,   173,   152,    -1,    86,    -1,    85,    -1,   225,   152,
      -1,    -1,    61,   491,   226,   234,    -1,    -1,   223,    35,
     167,   227,   233,    67,   270,    -1,    -1,    35,   167,   228,
     233,    67,   270,    -1,   549,    -1,   549,   548,    -1,    -1,
     107,   231,   239,    -1,    -1,   232,   239,    -1,    -1,   229,
     230,    -1,   230,    -1,   229,    -1,   233,    -1,   225,    42,
     237,    17,   420,    30,   236,   152,    -1,   225,    42,     1,
      30,   236,   152,    -1,    -1,   167,    -1,    35,    -1,    61,
      -1,    61,   491,    -1,    35,   491,    -1,    35,     6,    -1,
      -1,   237,   238,    -1,   220,    -1,   147,   242,   240,   148,
      -1,   147,     1,   148,    -1,    -1,   240,   241,    -1,   152,
     242,    -1,   547,    -1,   540,    -1,   246,   491,    -1,   246,
     173,   151,   245,   312,   244,   243,    -1,    -1,   150,   258,
      -1,    -1,    20,    -1,    21,    -1,    -1,   247,    -1,    -1,
     331,    -1,    40,    -1,    58,    -1,    41,    -1,    20,    -1,
      45,    -1,   147,   254,   249,   148,    -1,    -1,   249,   250,
      -1,   149,   254,    -1,   147,   255,   252,   148,    -1,   147,
       1,   148,    -1,   147,    55,   148,    -1,    -1,   252,   253,
      -1,   149,   255,    -1,   256,   153,   257,    -1,   257,    -1,
     154,    -1,   102,    -1,   258,    -1,   286,   153,   258,    -1,
     321,    -1,   268,    -1,   258,    -1,    55,    -1,   105,   258,
      -1,   260,    -1,   261,    -1,    91,    -1,    92,    -1,    93,
      -1,    94,    -1,    95,    -1,    96,    -1,   261,   259,   261,
      -1,   261,    12,   261,    -1,   261,    84,   261,    -1,   261,
      56,   261,    -1,   261,    51,   261,    -1,   261,    90,   261,
      -1,   261,    48,   261,    -1,   260,    48,   261,    -1,   260,
      51,   261,    -1,   260,    90,   261,    -1,   260,    12,   261,
      -1,   260,    56,   261,    -1,   260,    84,   261,    -1,   121,
     267,    -1,   267,    -1,   136,   267,    -1,   135,   267,    -1,
     144,   267,    -1,   143,   267,    -1,   267,   145,   267,    -1,
     135,   267,   145,   267,    -1,   261,   139,   261,    -1,   261,
     138,   261,    -1,   261,   134,   261,    -1,   261,   141,   261,
      -1,   261,   136,   261,    -1,   261,   135,   261,    -1,   261,
     130,   261,    -1,   261,   128,   261,    -1,   261,   131,   261,
      -1,   261,   129,   261,    -1,   261,   133,   261,    -1,   261,
     132,   261,    -1,   261,   140,   261,    -1,   261,   127,   261,
      -1,   261,   126,   261,    -1,   261,   125,   261,    -1,   261,
     124,   261,    -1,   261,   123,   261,    -1,   261,   122,   261,
      -1,   135,   264,    -1,   136,   264,    -1,   264,    -1,   262,
     263,   264,    -1,   134,    -1,   135,    -1,   136,    -1,   266,
      -1,   266,   265,   266,    -1,   141,    -1,   138,    -1,   139,
      -1,   140,    -1,   267,    -1,   144,   267,    -1,   143,   267,
      -1,   267,   145,   267,    -1,   268,    -1,   168,    -1,   276,
      -1,   278,    -1,   279,    -1,   147,   258,   148,    -1,   270,
      -1,   269,    -1,   551,    -1,   493,    -1,   275,    -1,   273,
      -1,   491,    -1,   271,    -1,   268,   156,   272,    -1,   167,
      -1,   495,    -1,    11,    -1,   270,   251,    -1,   269,   251,
      -1,   146,    -1,   270,   274,   491,    -1,   275,   147,   258,
     148,    -1,   269,   274,   491,    -1,   270,   274,    63,    -1,
     269,   274,    63,    -1,   277,   148,    -1,   147,   283,   153,
     258,   148,    -1,   147,   282,   149,   282,    -1,   277,   149,
     282,    -1,   270,   146,   147,   258,   148,    -1,   270,   146,
     276,    -1,    49,   270,   270,   281,    -1,    49,   270,   280,
      -1,    49,   278,    -1,    -1,   251,    -1,    -1,   251,    -1,
     283,   153,   258,    -1,   258,    -1,   286,   284,    -1,    -1,
     284,   285,    -1,   155,   286,    -1,   258,    -1,   321,    -1,
      57,    -1,    75,   491,     1,   152,    -1,    75,   491,   288,
     152,    -1,    75,     1,   152,    -1,    -1,    42,   289,    -1,
     290,    -1,   316,    -1,   293,    -1,   299,    -1,   303,    -1,
     305,    -1,   309,    -1,   310,    -1,   496,    -1,   501,    -1,
     147,   169,   291,   148,    -1,    -1,   291,   292,    -1,   149,
     169,    -1,   316,    76,   297,   295,    30,   294,    -1,    76,
     491,    -1,    76,    -1,    -1,   295,   296,    -1,   298,    -1,
     491,   152,    -1,   491,   133,   170,   152,    -1,    14,   147,
     302,   300,   148,    53,   312,    -1,    -1,   300,   301,    -1,
     149,   302,    -1,   270,    63,   154,    -1,    14,   317,    53,
     312,    -1,    -1,   491,    -1,    64,   308,   306,    30,    64,
     304,    -1,    -1,   306,   307,    -1,   308,    -1,   173,   151,
     312,   152,    -1,     8,   312,    -1,    33,    53,   270,    -1,
      71,   491,    42,   312,   152,    -1,    71,     1,   152,    -1,
     270,   313,    -1,   314,    -1,    -1,   251,    -1,   270,   270,
     316,    -1,   270,   316,    -1,   270,   270,   315,    -1,    -1,
     251,    -1,    63,   322,    -1,   147,   320,   318,   148,    -1,
      -1,   318,   319,    -1,   149,   320,    -1,   312,    -1,   322,
      -1,   314,    -1,   258,   323,   258,    -1,   275,    -1,   262,
     323,   262,    -1,    73,    -1,    27,    -1,    25,   173,   151,
     312,   325,   152,    -1,    -1,   150,   258,    -1,    70,   173,
     151,   312,   328,   327,   152,    -1,    -1,   150,   258,    -1,
      -1,   332,    -1,    79,   173,   151,   312,   330,   152,    -1,
      89,    79,   173,   151,   312,   330,   152,    -1,    -1,   150,
     258,    -1,    25,    -1,    70,    -1,    79,    -1,    89,    79,
      -1,    33,    -1,    75,    -1,    21,    -1,    65,    -1,    10,
     334,   335,    42,   268,   514,   152,    -1,    10,   334,   335,
      42,     1,   152,    -1,   491,    -1,   493,    -1,    -1,   151,
     312,    -1,    33,   173,   151,   312,    42,   338,   258,   152,
      -1,    33,   173,   151,   491,   337,   152,    -1,    -1,    55,
     258,    42,   258,    -1,    -1,   247,    -1,    26,   340,   151,
     270,     9,   258,   152,    -1,   268,   341,    -1,    57,    -1,
      11,    -1,    -1,   341,   342,    -1,   149,   268,    -1,    16,
     491,   151,   270,   152,    -1,    16,   491,    53,   345,    42,
     258,   152,    -1,   346,   514,   151,   349,    -1,   167,   347,
      -1,    57,    -1,    11,    -1,    -1,   347,   348,    -1,   149,
     167,    -1,    31,    -1,    13,    -1,    59,    -1,    24,    -1,
      23,    -1,    43,    -1,    75,    -1,    71,    -1,    61,    -1,
      35,    -1,    70,    -1,    79,    -1,    25,    -1,    87,    -1,
      33,    -1,    76,    -1,   106,    -1,   114,    -1,   109,    -1,
     351,    -1,    39,   258,    36,   401,   353,   352,    -1,    39,
     454,   258,    36,   401,   353,   352,    -1,    -1,    28,    36,
     401,    -1,    28,   454,    36,   401,    -1,    -1,   353,   354,
      -1,    29,   258,    36,   401,    -1,    29,   454,   258,    36,
     401,    -1,   357,    -1,   357,    -1,   358,    -1,    34,   491,
      40,   320,    -1,    34,   454,   491,    40,   320,    -1,    82,
     258,    -1,   360,    -1,    -1,   360,   361,    -1,   362,    -1,
     363,    -1,   381,    -1,   382,    -1,   383,    -1,   377,    -1,
     402,    -1,   408,    -1,   491,   151,    18,   372,   371,   369,
     367,   365,    17,   359,    30,    18,   364,   152,    -1,    -1,
     491,    -1,    -1,   365,   366,    -1,   216,    -1,    -1,    60,
     239,   152,   368,    -1,    60,    47,   248,   152,    -1,    -1,
      37,   239,   152,   370,    -1,    -1,    37,    47,   248,   152,
      -1,    -1,   147,   258,   148,   372,    -1,    -1,    42,    -1,
     491,    -1,   373,   156,   491,    -1,   373,   375,    -1,   373,
      -1,   147,   491,   148,    -1,    24,    -1,    31,    -1,    23,
      -1,    -1,   491,   151,   268,   378,    37,    47,   248,   380,
     152,    -1,    -1,   491,   151,   268,   379,    60,    47,   248,
     152,    -1,   491,   151,   376,   374,    60,    47,   248,   152,
      -1,   491,   151,   376,   374,    37,    47,   248,   380,   152,
      -1,    -1,    60,    47,   248,    -1,   491,   151,   425,    -1,
     425,    -1,   491,   151,    88,   425,    -1,    88,   425,    -1,
     491,   151,   449,    -1,   449,    -1,   491,   151,    88,   449,
      -1,    88,   449,    -1,   491,   151,   384,    -1,   384,    -1,
     491,   151,    88,   384,    -1,    88,   384,    -1,   491,   151,
      88,   396,    -1,    88,   396,    -1,   491,   151,   396,    -1,
     396,    -1,   392,   130,   393,   385,   152,    -1,   386,    -1,
     386,    81,   258,    -1,   386,    81,   258,    28,   385,    -1,
     389,   387,    -1,    97,    -1,    -1,   387,   388,    -1,   149,
     389,    -1,   258,   390,    -1,    -1,     9,   258,    -1,    52,
     391,    -1,    52,    -1,     9,   258,    -1,   268,    -1,   276,
      -1,   395,   394,    -1,    -1,    74,    -1,   110,   258,   105,
      -1,   105,    -1,    -1,    38,    -1,    83,   258,    68,   392,
     130,   393,   397,   152,    -1,   398,   386,    81,   283,    -1,
      -1,   398,   399,    -1,   386,    81,   283,   149,    -1,    -1,
     217,    17,    -1,    17,    -1,   400,   359,    -1,    -1,   491,
     151,   403,   355,    36,   400,   359,   404,    -1,   407,    30,
     406,   152,    -1,    30,   406,   152,    -1,    -1,   491,   151,
     405,   350,   404,    -1,   491,   151,   518,    -1,    36,    -1,
      36,   491,    -1,    30,   152,    -1,    30,   491,   152,    -1,
     491,   151,   409,    -1,   409,    -1,    -1,   412,   410,    62,
     416,   414,    17,   420,    30,   411,   152,    -1,     1,    30,
     411,   152,    -1,    -1,   412,    62,   413,    -1,    -1,    88,
      -1,    -1,   491,    -1,    -1,    42,    -1,   414,   415,    -1,
     221,    -1,    -1,   147,    11,   148,    -1,   147,   417,   148,
      -1,   268,   418,    -1,    -1,   418,   419,    -1,   149,   268,
      -1,   421,    -1,    -1,   421,   422,    -1,   423,    -1,   425,
      -1,   454,   425,    -1,   430,    -1,   434,    -1,   437,    -1,
     441,    -1,   445,    -1,   448,    -1,   449,    -1,   450,    -1,
     454,   452,    -1,   452,    -1,   453,    -1,   456,    -1,   454,
     456,    -1,   424,    -1,   444,    66,   258,   426,   152,    -1,
      15,   258,   427,   426,   152,    -1,    -1,    69,   258,    -1,
      -1,    66,   258,    -1,    -1,   157,    -1,    -1,   157,    -1,
     491,    -1,    22,   428,   258,    42,   433,   431,    30,    22,
     429,   152,    -1,   454,    22,   428,   258,    42,   433,   431,
      30,    22,   429,   152,    -1,    22,     1,    30,    22,   429,
     152,    -1,    -1,   431,   432,    -1,   433,    -1,    81,   283,
     153,   420,    -1,    32,   436,   435,   152,    -1,    -1,    81,
     258,    -1,    -1,   491,    -1,    39,   258,    72,   420,   439,
     438,    30,    39,   152,    -1,    39,   258,    72,     1,    30,
      39,   152,    -1,    -1,    28,   420,    -1,    -1,   439,   440,
      -1,    29,   258,    72,   420,    -1,   444,   443,    46,   420,
      30,    46,   442,   152,    -1,    -1,   491,    -1,    -1,   356,
      -1,    -1,   491,   151,    -1,    50,   447,   446,   152,    -1,
      -1,    81,   258,    -1,    -1,   491,    -1,    52,   152,    -1,
     268,   152,    -1,    67,   451,   152,    -1,    -1,   258,    -1,
     392,   130,   386,   152,    -1,   392,   130,   533,   386,   152,
      -1,   392,   130,   104,   532,   258,   152,    -1,   392,   130,
     111,   532,   152,    -1,   526,    -1,   522,    -1,   455,   152,
      -1,   534,    -1,   454,   536,    -1,   536,    -1,   491,   151,
      -1,   392,   150,   258,    -1,   454,   392,   150,   258,    -1,
      80,   459,   458,   457,   152,    -1,    -1,    34,   258,    -1,
      -1,    77,   258,    -1,    -1,    54,   417,    -1,    30,    -1,
      30,    23,   183,    -1,    30,    13,   183,    -1,    30,    31,
     183,    -1,    30,   491,    -1,    -1,    42,    -1,    23,   491,
     461,   464,   463,   460,   152,    -1,    -1,    60,   239,   152,
      -1,    -1,    37,   239,   152,    -1,    34,   470,   468,   466,
      30,    34,   152,    -1,    34,     1,    30,    34,   152,    -1,
      -1,   466,   467,    -1,   471,    -1,    -1,   468,   469,    -1,
     179,    -1,   268,    -1,   465,    -1,   472,    -1,    34,   477,
     474,   473,    30,    34,   152,    -1,    -1,   465,    -1,    -1,
     481,   480,   152,    -1,    78,   118,   173,   152,    -1,    78,
     479,   152,    -1,    34,   477,   476,   152,    -1,    34,   477,
     476,   152,    30,    34,   152,    -1,    78,   479,    -1,    78,
     118,   173,   152,    -1,   481,   480,    -1,   478,   151,   258,
      -1,   173,    -1,    11,    -1,    57,    -1,   482,   481,   480,
      -1,    -1,    60,    47,   248,    -1,    -1,    37,    47,   248,
      -1,    31,   268,    -1,    24,   270,    -1,    55,    -1,   491,
      -1,   495,    -1,   483,    -1,   484,   149,   483,    -1,    87,
     491,   151,   490,   147,   484,   148,   152,    -1,    87,   491,
      42,   147,   489,   148,   152,    -1,    87,   491,    42,   147,
       1,   152,   148,    -1,   349,   488,    -1,    -1,   154,    -1,
     487,    -1,   489,   149,   487,    -1,   491,    -1,   493,    -1,
       7,    -1,     5,    -1,     6,    -1,     3,    -1,     4,    -1,
     108,   497,    30,   499,    -1,   108,     1,    30,   499,    -1,
      -1,   497,   498,    -1,   500,    -1,   108,    -1,   108,   491,
      -1,   179,    -1,   344,    -1,   224,    -1,   513,    -1,   108,
      19,   502,    30,   504,    -1,   108,    19,     1,    30,   504,
      -1,    -1,   502,   503,    -1,   505,    -1,   108,    19,    -1,
     108,    19,   491,    -1,   220,    -1,   100,   180,   152,    -1,
      -1,   100,   491,    42,   508,   510,    30,   509,   152,    -1,
     100,   491,    42,    30,   509,   152,    -1,   100,    -1,   100,
     491,    -1,   511,    -1,   510,   511,    -1,   179,    -1,   178,
      -1,   506,    -1,    59,   491,    42,    49,   373,   514,   152,
      -1,    59,   491,    42,    49,   373,   514,   548,   152,    -1,
      59,     1,   491,    42,    49,   152,    -1,    35,   491,    42,
      49,   373,   514,   152,    -1,    35,   491,    42,    49,   373,
     514,   548,   152,    -1,    35,   491,    42,    49,     1,   152,
      -1,    -1,   160,   515,   161,    -1,   160,   161,    -1,    67,
     270,    -1,   516,    -1,   516,    67,   270,    -1,   270,    -1,
     516,   517,    -1,   149,   270,    -1,    22,   258,    36,   520,
     521,    30,    36,   406,   152,    -1,    22,   258,    36,   520,
      30,    36,   406,   152,    -1,    22,     1,    36,     1,    30,
      36,   406,   152,    -1,    81,   454,   283,   153,   401,    -1,
      81,   283,   153,   401,    -1,   520,   519,    -1,   519,    -1,
      30,   152,    -1,    30,   491,   152,    -1,   523,    -1,   525,
      -1,   392,   130,   389,    81,   258,   524,   152,    -1,   392,
     130,   533,   389,    81,   258,   524,   152,    -1,   392,   130,
     389,    81,   258,   152,    -1,   392,   130,   533,   389,    81,
     258,   152,    -1,   392,   130,     1,   152,    -1,    28,   258,
      81,   258,    -1,    28,   258,    -1,   392,   130,   104,   532,
     258,    81,   258,   535,   152,    -1,   392,   130,   104,   532,
     258,    81,   258,   152,    -1,   527,    -1,   531,    -1,    83,
     258,    68,   428,   392,   130,   528,   529,    -1,    -1,   533,
      -1,   389,    81,   283,   149,   529,    -1,   530,    -1,   389,
      81,   283,   152,    -1,    83,   258,    68,   428,   392,   130,
     104,   532,   537,    -1,    -1,    40,    -1,    58,    -1,    74,
      -1,   110,   258,   105,    -1,   105,    -1,   455,    81,   258,
     535,   152,    -1,   455,    81,   258,   152,    -1,    28,   258,
      81,   258,    -1,   535,    28,   258,    81,   258,    -1,    28,
     258,    -1,    83,   258,    68,   428,   539,   150,   537,    -1,
     258,    81,   283,   149,   537,    -1,   538,    -1,   258,    81,
     283,   152,    -1,   268,    -1,   276,    -1,   541,    -1,   542,
      -1,    61,   491,   545,    -1,    35,   543,   545,    67,   270,
     544,    -1,   223,    35,   543,   545,    67,   270,   544,    -1,
     491,    -1,   493,    -1,    -1,    42,   491,    -1,    42,   154,
      -1,    -1,   107,    -1,    -1,   107,   546,   147,   242,   240,
     148,    -1,   147,   242,   240,   148,    -1,    59,   491,    42,
      49,   373,    -1,    59,   491,    42,    49,   373,   548,    -1,
      37,    47,   248,    -1,    -1,    37,   550,   239,    -1,   119,
     552,   553,   151,   312,   120,    -1,    25,    -1,    70,    -1,
      79,    -1,   554,    -1,   555,    -1,   559,    -1,   156,   558,
     491,    -1,   156,   491,    -1,   556,   558,   491,    -1,   556,
     491,    -1,   159,   156,    -1,   556,   159,   156,    -1,   491,
      -1,   491,   147,   258,   148,    -1,   557,   156,    -1,   558,
     557,   156,    -1,   158,   373,    -1,   162,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   347,   347,   350,   352,   353,   356,   357,   360,   361,
     362,   363,   364,   367,   368,   370,   372,   373,   375,   377,
     378,   385,   387,   388,   390,   391,   392,   393,   394,   395,
     396,   399,   400,   403,   412,   427,   428,   434,   436,   439,
     450,   451,   453,   454,   456,   457,   460,   462,   463,   463,
     465,   466,   466,   467,   471,   472,   474,   483,   484,   485,
     486,   488,   489,   491,   493,   494,   494,   500,   506,   507,
     508,   509,   510,   511,   512,   514,   515,   516,   537,   538,
     539,   540,   542,   543,   544,   545,   547,   548,   549,   550,
     552,   553,   554,   561,   562,   563,   564,   567,   568,   569,
     577,   578,   579,   580,   583,   584,   585,   586,   587,   588,
     589,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   617,   618,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   634,   635,
     636,   637,   638,   639,   640,   641,   643,   644,   645,   646,
     647,   648,   649,   650,   652,   653,   654,   655,   656,   657,
     658,   659,   661,   662,   663,   664,   669,   670,   672,   675,
     674,   678,   677,   690,   689,   701,   702,   705,   704,   708,
     708,   712,   713,   714,   715,   717,   719,   723,   727,   728,
     729,   730,   731,   732,   733,   736,   738,   739,   745,   746,
     747,   748,   749,   751,   760,   773,   781,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   812,   813,   814,   815,
     816,   818,   819,   820,   821,   823,   829,   830,   832,   833,
     834,   836,   837,   838,   839,   842,   843,   844,   846,   848,
     849,   850,   858,   859,   861,   862,   863,   864,   865,   866,
     868,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     878,   879,   880,   884,   885,   886,   887,   888,   889,   890,
     891,   895,   896,   897,   898,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   911,   912,   913,
     915,   916,   917,   918,   921,   922,   923,   926,   927,   930,
     931,   932,   933,   935,   936,   937,   938,   940,   941,   942,
     943,   944,   945,   947,   948,   949,   950,   951,   952,   954,
     955,   957,   959,   960,   961,   963,   964,   966,   969,   970,
     971,   972,   973,   975,   976,   978,   979,   981,   982,   984,
     985,   986,   987,   988,   989,   990,   997,   998,  1000,  1001,
    1002,  1003,  1005,  1006,  1007,  1012,  1013,  1017,  1019,  1020,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1034,  1035,  1036,  1037,  1039,  1048,  1049,  1051,  1052,  1053,
    1055,  1057,  1059,  1068,  1069,  1070,  1072,  1074,  1076,  1077,
    1079,  1091,  1092,  1096,  1098,  1100,  1102,  1108,  1112,  1113,
    1114,  1115,  1116,  1118,  1119,  1120,  1121,  1122,  1124,  1127,
    1130,  1131,  1133,  1135,  1136,  1138,  1139,  1141,  1142,  1144,
    1145,  1151,  1157,  1158,  1160,  1165,  1166,  1167,  1168,  1170,
    1174,  1179,  1180,  1182,  1183,  1184,  1185,  1186,  1187,  1189,
    1190,  1192,  1197,  1199,  1200,  1202,  1203,  1206,  1211,  1217,
    1218,  1221,  1222,  1224,  1226,  1227,  1228,  1229,  1230,  1231,
    1237,  1242,  1248,  1250,  1251,  1252,  1253,  1254,  1255,  1257,
    1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1273,  1274,  1275,  1283,  1285,
    1286,  1288,  1289,  1290,  1291,  1292,  1293,  1294,  1296,  1298,
    1299,  1301,  1302,  1304,  1310,  1311,  1312,  1313,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1323,  1326,  1327,  1328,  1329,
    1330,  1331,  1332,  1334,  1335,  1336,  1337,  1338,  1339,  1340,
    1341,  1342,  1344,  1345,  1348,  1349,  1351,  1353,  1354,  1355,
    1357,  1357,  1361,  1361,  1366,  1370,  1374,  1375,  1377,  1378,
    1380,  1381,  1383,  1384,  1386,  1387,  1389,  1390,  1392,  1393,
    1395,  1396,  1398,  1399,  1401,  1403,  1404,  1405,  1407,  1408,
    1409,  1410,  1411,  1413,  1414,  1415,  1416,  1417,  1418,  1420,
    1421,  1423,  1425,  1426,  1427,  1428,  1430,  1431,  1433,  1435,
    1436,  1437,  1438,  1440,  1441,  1442,  1448,  1451,  1450,  1456,
    1457,  1460,  1459,  1462,  1464,  1465,  1468,  1469,  1471,  1478,
    1486,  1485,  1492,  1494,  1495,  1497,  1498,  1500,  1501,  1503,
    1504,  1505,  1506,  1507,  1508,  1509,  1511,  1512,  1513,  1514,
    1520,  1521,  1522,  1523,  1525,  1526,  1527,  1528,  1529,  1530,
    1531,  1532,  1533,  1534,  1535,  1536,  1537,  1538,  1539,  1540,
    1542,  1544,  1545,  1546,  1547,  1548,  1550,  1551,  1553,  1554,
    1555,  1557,  1558,  1560,  1561,  1562,  1563,  1565,  1567,  1568,
    1569,  1570,  1571,  1573,  1574,  1575,  1576,  1577,  1578,  1579,
    1581,  1582,  1583,  1584,  1585,  1586,  1587,  1589,  1590,  1591,
    1592,  1593,  1595,  1597,  1599,  1600,  1601,  1603,  1604,  1605,
    1606,  1607,  1608,  1611,  1612,  1613,  1614,  1616,  1617,  1618,
    1620,  1621,  1622,  1623,  1624,  1625,  1626,  1632,  1633,  1634,
    1635,  1636,  1638,  1639,  1641,  1646,  1647,  1648,  1649,  1651,
    1656,  1657,  1658,  1659,  1660,  1661,  1662,  1664,  1674,  1675,
    1677,  1682,  1683,  1684,  1686,  1687,  1688,  1693,  1697,  1702,
    1703,  1704,  1706,  1712,  1713,  1714,  1716,  1718,  1719,  1721,
    1722,  1725,  1726,  1727,  1730,  1731,  1734,  1735,  1738,  1745,
    1751,  1753,  1755,  1756,  1758,  1759,  1763,  1764,  1766,  1771,
    1776,  1781,  1786,  1796,  1797,  1799,  1800,  1801,  1802,  1803,
    1805,  1806,  1807,  1808,  1810,  1811,  1813,  1814,  1815,  1817,
    1818,  1820,  1826,  1828,  1828,  1834,  1839,  1840,  1842,  1843,
    1845,  1846,  1847,  1849,  1857,  1862,  1864,  1869,  1874,  1876,
    1877,  1879,  1881,  1882,  1883,  1885,  1886,  1887,  1889,  1890,
    1891,  1893,  1894,  1895,  1896,  1898,  1899,  1901,  1902,  1904,
    1905,  1906,  1907,  1908,  1910,  1911,  1913,  1914,  1916,  1917,
    1919,  1922,  1923,  1925,  1926,  1928,  1930,  1933,  1934,  1935,
    1937,  1938,  1939,  1941,  1942,  1944,  1945,  1946,  1948,  1950,
    1951,  1953,  1955,  1956,  1958,  1959,  1961,  1963,  1973,  1984,
    1985,  1988,  1989,  1990,  1992,  1993,  1994,  1994,  1998,  2000,
    2005,  2011,  2014,  2013,  2024,  2031,  2032,  2033,  2035,  2036,
    2037,  2040,  2041,  2043,  2044,  2046,  2047,  2049,  2050,  2053,
    2054,  2056,  2058
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "t_ABSTRLIST", "t_CHARLIST", "t_DIGIT",
  "t_STRING", "t_LETTER", "t_ACCESS", "t_AFTER", "t_ALIAS", "t_ALL",
  "t_AND", "t_ARCHITECTURE", "t_ARRAY", "t_ASSERT", "t_ATTRIBUTE",
  "t_BEGIN", "t_BLOCK", "t_BODY", "t_BUFFER", "t_BUS", "t_CASE",
  "t_COMPONENT", "t_CONFIGURATION", "t_CONSTANT", "t_DISCONNECT",
  "t_DOWNTO", "t_ELSE", "t_ELSIF", "t_END", "t_ENTITY", "t_EXIT", "t_FILE",
  "t_FOR", "t_FUNCTION", "t_GENERATE", "t_GENERIC", "t_GUARDED", "t_IF",
  "t_IN", "t_INOUT", "t_IS", "t_LABEL", "t_LIBRARY", "t_LINKAGE", "t_LOOP",
  "t_MAP", "t_NAND", "t_NEW", "t_NEXT", "t_NOR", "t_NULL", "t_OF", "t_ON",
  "t_OPEN", "t_OR", "t_OTHERS", "t_OUT", "t_PACKAGE", "t_PORT",
  "t_PROCEDURE", "t_PROCESS", "t_RANGE", "t_RECORD", "t_REGISTER",
  "t_REPORT", "t_RETURN", "t_SELECT", "t_SEVERITY", "t_SIGNAL",
  "t_SUBTYPE", "t_THEN", "t_TO", "t_TRANSPORT", "t_TYPE", "t_UNITS",
  "t_UNTIL", "t_USE", "t_VARIABLE", "t_WAIT", "t_WHEN", "t_WHILE",
  "t_WITH", "t_XOR", "t_IMPURE", "t_PURE", "t_GROUP", "t_POSTPONED",
  "t_SHARED", "t_XNOR", "t_SLL", "t_SRA", "t_SLA", "t_SRL", "t_ROR",
  "t_ROL", "t_UNAFFECTED", "t_ASSUME_GUARANTEE", "t_ASSUME", "t_CONTEXT",
  "t_COVER", "t_DEFAULT", "t_FAIRNESS", "t_FORCE", "t_INERTIAL",
  "t_LITERAL", "t_PARAMETER", "t_PROTECTED", "t_PROPERTY", "t_REJECT",
  "t_RELEASE", "t_RESTRICT", "t_RESTRICT_GUARANTEE", "t_SEQUENCE",
  "t_STRONG", "t_VMODE", "t_VPROP", "t_VUNIT", "t_SLSL", "t_SRSR", "t_QQ",
  "t_QGT", "t_QLT", "t_QG", "t_QL", "t_QEQU", "t_QNEQU", "t_GESym",
  "t_GTSym", "t_LESym", "t_LTSym", "t_NESym", "t_EQSym", "t_Ampersand",
  "t_Minus", "t_Plus", "MED_PRECEDENCE", "t_REM", "t_MOD", "t_Slash",
  "t_Star", "MAX_PRECEDENCE", "t_NOT", "t_ABS", "t_DoubleStar",
  "t_Apostrophe", "t_LeftParen", "t_RightParen", "t_Comma", "t_VarAsgn",
  "t_Colon", "t_Semicolon", "t_Arrow", "t_Box", "t_Bar", "t_Dot", "t_Q",
  "t_At", "t_Neg", "t_LEFTBR", "t_RIGHTBR", "t_ToolDir", "$accept",
  "start", "design_file", "design_unit_list", "designator", "literal",
  "enumeration_literal", "physical_literal", "physical_literal_1",
  "physical_literal_no_default", "idf_list", "design_unit", "context_list",
  "lib_unit", "context_item", "lib_clause", "use_clause", "sel_list",
  "entity_decl", "entity_start", "entity_decl_5", "entity_decl_4",
  "entity_decl_3", "entity_decl_6", "entity_decl_2", "@1", "entity_decl_1",
  "@2", "arch_body", "arch_start", "arch_body_2", "arch_body_1",
  "arch_body_3", "config_decl", "@3", "config_start", "config_decl_2",
  "config_decl_1", "config_decl_3", "package_decl", "package_start",
  "package_decl_2", "package_decl_1", "package_decl_3", "package_decl_22",
  "package_body", "pack_body_start", "package_body_2", "package_body_1",
  "package_body_3", "common_decltve_item_1", "common_decltve_item",
  "entity_decltve_item", "block_decltve_item", "block_declarative_part",
  "package_decltve_item", "package_body_decltve_item",
  "subprog_decltve_item", "procs_decltve_item", "config_decltve_item",
  "func_prec", "subprog_decl", "subprog_spec", "@4", "@5", "@6",
  "subprog_spec_22", "subprog_spec_33", "@7", "@8", "subprog_spec_2",
  "subprog_spec_1", "subprog_body", "subprog_body_2", "subprog_body_1",
  "subprog_body_3", "interf_list", "interf_list_1", "interf_list_2",
  "interf_element", "interf_element_4", "interf_element_3",
  "interf_element_2", "interf_element_1", "mode", "association_list",
  "association_list_1", "association_list_2", "gen_association_list",
  "gen_association_list_1", "gen_association_list_2",
  "association_element", "gen_association_element", "formal_part",
  "actual_part", "expr", "shift_op", "and_relation", "relation",
  "simple_exp", "adding_op", "term", "multiplying_operator", "factor",
  "primary", "name", "name2", "mark", "sel_name", "suffix", "ifts_name",
  "sigma", "attribute_name", "aggregate", "element_association_list2",
  "qualified_expr", "allocator", "allocator_2", "allocator_1",
  "element_association", "choices", "choices_1", "choices_2", "choice",
  "type_decl", "type_decl_1", "type_definition",
  "enumeration_type_definition", "enumeration_type_definition_1",
  "enumeration_type_definition_2", "physical_type_definition", "unit_stat",
  "physical_type_definition_1", "physical_type_definition_2",
  "base_unit_decl", "secondary_unit_decl",
  "unconstrained_array_definition", "unconstrained_array_definition_1",
  "unconstrained_array_definition_2", "index_subtype_definition",
  "constrained_array_definition", "record_type_simple_name",
  "record_type_definition", "record_type_definition_1",
  "record_type_definition_2", "element_decl", "access_type_definition",
  "file_type_definition", "subtype_decl", "subtype_indic",
  "subtype_indic_1", "subtype_indic1", "subtype_indic1_1",
  "range_constraint", "index_constraint", "index_constraint_1",
  "index_constraint_2", "discrete_range", "discrete_range1", "range_spec",
  "direction", "constant_decl", "constant_decl_1", "signal_decl",
  "signal_decl_2", "signal_decl_1", "variable_decl", "variable_decl_1",
  "object_class", "signal_kind", "alias_decl", "alias_name_stat",
  "alias_spec", "file_decl", "fi_dec", "file_decl_1", "disconnection_spec",
  "signal_list", "signal_list_1", "signal_list_2", "attribute_decl",
  "attribute_spec", "entity_spec", "entity_name_list",
  "entity_name_list_1", "entity_name_list_2", "entity_class",
  "if_generation_scheme", "if_scheme", "if_scheme_2", "if_scheme_1",
  "if_scheme_3", "generation_scheme", "iteration_scheme", "for_scheme",
  "while_scheme", "concurrent_stats", "concurrent_stats_1",
  "concurrent_stats_2", "concurrent_stat", "block_stat", "block_stat_5",
  "block_stat_4", "block_stat_6", "block_stat_3", "block_stat_7",
  "block_stat_2", "block_stat_8", "block_stat_1", "block_stat_0",
  "dot_name", "mark_comp", "comp_1", "vcomp_stat", "comp_inst_stat", "@9",
  "@10", "comp_inst_stat_1", "concurrent_assertion_stat",
  "concurrent_procedure_call", "concurrent_signal_assign_stat",
  "condal_signal_assign", "condal_wavefrms", "wavefrm", "wavefrm_1",
  "wavefrm_2", "wavefrm_element", "wavefrm_element_1", "wavefrm_element_2",
  "target", "opts", "opts_2", "opts_1", "sel_signal_assign",
  "sel_wavefrms", "sel_wavefrms_1", "sel_wavefrms_2", "gen_stat1",
  "generate_statement_body", "generate_stat", "@11", "opstat", "@12",
  "generate_stat_1", "end_stats", "procs_stat", "procs_stat1", "@13",
  "procs_stat1_3", "procs_stat1_5", "procs_stat1_6", "procs_stat1_2",
  "procs_stat1_4", "procs_stat1_1", "sensitivity_list",
  "sensitivity_list_1", "sensitivity_list_2", "seq_stats", "seq_stats_1",
  "seq_stats_2", "seq_stat", "report_statement", "assertion_stat",
  "assertion_stat_2", "assertion_stat_1", "choice_stat", "choice_stat_1",
  "case_stat", "case_stat_1", "case_stat_2", "case_stat_alternative",
  "exit_stat", "exit_stat_2", "exit_stat_1", "if_stat", "if_stat_2",
  "if_stat_1", "if_stat_3", "loop_stat", "loop_stat_3", "loop_stat_2",
  "loop_stat_1", "next_stat", "next_stat_2", "next_stat_1", "null_stat",
  "procedure_call_stat", "return_stat", "return_stat_1",
  "signal_assign_stat", "variable_assign_stat", "lable",
  "variable_assign_stat_1", "wait_stat", "wait_stat_3", "wait_stat_2",
  "wait_stat_1", "comp_end_dec", "iss", "comp_decl", "comp_decl_2",
  "comp_decl_1", "block_config", "block_config_2", "block_config_3",
  "block_config_1", "block_config_4", "block_spec", "config_item",
  "comp_config", "comp_config_2", "comp_config_1", "config_spec",
  "comp_spec_stat", "comp_spec", "inst_list", "binding_indic",
  "binding_indic_2", "binding_indic_1", "entity_aspect",
  "group_constituent", "group_constituent_list", "group_declaration",
  "group_template_declaration", "entity_class_entry", "tbox",
  "entity_class_entry_list", "group_name", "t_Identifier",
  "t_BitStringLit", "t_StringLit", "t_AbstractLit", "t_CharacterLit",
  "protected_type_declaration", "protected_stats", "protected_stat_decl_1",
  "protected_stat_1", "protected_type_declaration_item",
  "protected_type_body", "protected_body_stats",
  "protected_body_stat_decl_1", "protected_body_stat_1",
  "protected_type_body_declaration_item", "context_ref", "context_decl",
  "@14", "context_stat_1", "libustcont_stats", "libustcont_stat",
  "package_instantiation_decl", "subprogram_instantiation_decl",
  "signature", "signature1", "mark_stats", "mark_stats_1", "case_scheme",
  "when_stats_1", "when_stats", "ttend", "conditional_signal_assignment",
  "conditional_waveform_assignment", "else_wave_list",
  "conditional_force_assignment", "selected_signal_assignment",
  "selected_waveform_assignment", "delay_stat", "sel_wave_list",
  "sel_wave_list_1", "selected_force_assignment", "inout_stat",
  "delay_mechanism", "conditional_variable_assignment", "else_stat",
  "selected_variable_assignment", "sel_var_list", "sel_var_list_1",
  "select_name", "interface_subprogram_decl", "iproc", "ifunc",
  "func_name", "return_is", "param", "@15", "interface_package_decl",
  "gen_assoc_list", "gen_interface_list", "@16", "external_name",
  "sig_stat", "external_pathname", "absolute_pathname",
  "relative_pathname", "neg_list", "pathname_element",
  "pathname_element_list", "package_path_name", "tool_directive", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   163,   164,   165,   166,   166,   167,   167,   168,   168,
     168,   168,   168,   169,   169,   170,   171,   171,   172,   173,
     173,   174,   175,   175,   176,   176,   176,   176,   176,   176,
     176,   177,   177,   178,   179,   180,   180,   181,   181,   182,
     183,   183,   184,   184,   185,   185,   186,   187,   188,   187,
     189,   190,   189,   189,   191,   191,   192,   193,   193,   193,
     193,   194,   194,   195,   196,   197,   196,   198,   199,   199,
     199,   199,   200,   200,   201,   202,   202,   203,   204,   204,
     204,   204,   205,   205,   205,   206,   207,   207,   207,   207,
     208,   208,   209,   210,   210,   210,   210,   211,   211,   212,
     213,   213,   213,   213,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   217,   217,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   219,   219,
     219,   219,   219,   219,   219,   219,   220,   220,   220,   220,
     220,   220,   220,   220,   221,   221,   221,   221,   221,   221,
     221,   221,   222,   222,   222,   222,   223,   223,   224,   226,
     225,   227,   225,   228,   225,   229,   229,   231,   230,   232,
     230,   233,   233,   233,   233,   234,   235,   235,   236,   236,
     236,   236,   236,   236,   236,   237,   237,   238,   239,   239,
     240,   240,   241,   242,   242,   242,   242,   243,   243,   244,
     244,   244,   245,   245,   246,   246,   247,   247,   247,   247,
     247,   248,   249,   249,   250,   251,   251,   251,   252,   252,
     253,   254,   254,   254,   254,   255,   255,   255,   256,   257,
     257,   257,   258,   258,   259,   259,   259,   259,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     262,   262,   262,   262,   263,   263,   263,   264,   264,   265,
     265,   265,   265,   266,   266,   266,   266,   267,   267,   267,
     267,   267,   267,   268,   268,   268,   269,   269,   269,   270,
     270,   271,   272,   272,   272,   273,   273,   274,   275,   275,
     275,   275,   275,   276,   276,   277,   277,   278,   278,   279,
     279,   279,   280,   280,   281,   281,   282,   282,   283,   284,
     284,   285,   286,   286,   286,   287,   287,   287,   288,   288,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     290,   291,   291,   292,   293,   294,   294,   295,   295,   296,
     297,   298,   299,   300,   300,   301,   302,   303,   304,   304,
     305,   306,   306,   307,   308,   309,   310,   311,   311,   312,
     312,   313,   313,   314,   314,   314,   315,   315,   316,   317,
     318,   318,   319,   320,   320,   321,   321,   322,   322,   323,
     323,   324,   325,   325,   326,   327,   327,   328,   328,   329,
     329,   330,   330,   331,   331,   331,   331,   331,   331,   332,
     332,   333,   333,   334,   334,   335,   335,   336,   336,   337,
     337,   338,   338,   339,   340,   340,   340,   341,   341,   342,
     343,   344,   345,   346,   346,   346,   347,   347,   348,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   350,   351,
     351,   352,   352,   352,   353,   353,   354,   354,   355,   356,
     356,   357,   357,   358,   359,   360,   360,   361,   362,   362,
     362,   362,   362,   362,   362,   363,   364,   364,   365,   365,
     366,   367,   367,   368,   369,   369,   370,   370,   371,   371,
     372,   372,   373,   373,   374,   374,   375,   376,   376,   376,
     378,   377,   379,   377,   377,   377,   380,   380,   381,   381,
     381,   381,   382,   382,   382,   382,   383,   383,   383,   383,
     383,   383,   383,   383,   384,   385,   385,   385,   386,   386,
     387,   387,   388,   389,   390,   390,   390,   390,   391,   392,
     392,   393,   394,   394,   394,   394,   395,   395,   396,   397,
     398,   398,   399,   400,   400,   400,   401,   403,   402,   404,
     404,   405,   402,   402,   406,   406,   407,   407,   408,   408,
     410,   409,   409,   411,   411,   412,   412,   413,   413,   414,
     414,   414,   415,   416,   416,   416,   417,   418,   418,   419,
     420,   421,   421,   422,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   423,   423,   423,   423,   423,
     424,   425,   426,   426,   427,   427,   428,   428,   429,   429,
     429,   430,   430,   430,   431,   431,   432,   433,   434,   435,
     435,   436,   436,   437,   437,   438,   438,   439,   439,   440,
     441,   442,   442,   443,   443,   444,   444,   445,   446,   446,
     447,   447,   448,   449,   450,   451,   451,   452,   452,   452,
     452,   452,   452,   453,   453,   453,   453,   454,   455,   455,
     456,   457,   457,   458,   458,   459,   459,   460,   460,   460,
     460,   460,   461,   461,   462,   463,   463,   464,   464,   465,
     465,   466,   466,   467,   468,   468,   469,   470,   471,   471,
     472,   473,   473,   474,   474,   474,   474,   475,   475,   476,
     476,   476,   477,   478,   478,   478,   479,   480,   480,   481,
     481,   482,   482,   482,   483,   483,   484,   484,   485,   486,
     486,   487,   488,   488,   489,   489,   490,   490,   491,   492,
     493,   494,   495,   496,   496,   497,   497,   498,   499,   499,
     500,   500,   500,   500,   501,   501,   502,   502,   503,   504,
     504,   505,   506,   508,   507,   507,   509,   509,   510,   510,
     511,   511,   511,   512,   512,   512,   513,   513,   513,   514,
     514,   514,   515,   515,   515,   516,   516,   517,   518,   518,
     518,   519,   519,   520,   520,   521,   521,   522,   522,   523,
     523,   523,   523,   523,   524,   524,   525,   525,   526,   526,
     527,   528,   528,   529,   529,   530,   531,   532,   532,   532,
     533,   533,   533,   534,   534,   535,   535,   535,   536,   537,
     537,   538,   539,   539,   540,   540,   541,   542,   542,   543,
     543,   544,   544,   544,   545,   545,   546,   545,   545,   547,
     547,   548,   550,   549,   551,   552,   552,   552,   553,   553,
     553,   554,   554,   555,   555,   556,   556,   557,   557,   558,
     558,   559,   560
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     1,     2,     1,
       3,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     4,     7,     3,
       0,     1,     0,     2,     0,     2,     1,     0,     0,     4,
       0,     0,     4,     3,     7,     5,     5,     0,     1,     2,
       1,     0,     2,     1,     5,     0,     7,     5,     0,     1,
       1,     2,     0,     2,     1,     5,     5,     3,     0,     1,
       2,     1,     0,     1,     2,     1,     2,     1,     2,     3,
       5,     5,     4,     0,     1,     2,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     2,     0,
       4,     0,     7,     0,     6,     1,     2,     0,     3,     0,
       2,     0,     2,     1,     1,     1,     8,     6,     0,     1,
       1,     1,     2,     2,     2,     0,     2,     1,     4,     3,
       0,     2,     2,     1,     1,     2,     7,     0,     2,     0,
       1,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     4,     0,     2,     2,     4,     3,     3,     0,     2,
       2,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     1,     2,     2,     2,     2,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     2,     2,     1,     3,     4,
       3,     3,     3,     2,     5,     4,     3,     5,     3,     4,
       3,     2,     0,     1,     0,     1,     3,     1,     2,     0,
       2,     2,     1,     1,     1,     4,     4,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     2,     2,     6,     2,     1,     0,     2,     1,
       2,     4,     7,     0,     2,     2,     3,     4,     0,     1,
       6,     0,     2,     1,     4,     2,     3,     5,     3,     2,
       1,     0,     1,     3,     2,     3,     0,     1,     2,     4,
       0,     2,     2,     1,     1,     1,     3,     1,     3,     1,
       1,     6,     0,     2,     7,     0,     2,     0,     1,     6,
       7,     0,     2,     1,     1,     1,     2,     1,     1,     1,
       1,     7,     6,     1,     1,     0,     2,     8,     6,     0,
       4,     0,     1,     7,     2,     1,     1,     0,     2,     2,
       5,     7,     4,     2,     1,     1,     0,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       7,     0,     3,     4,     0,     2,     4,     5,     1,     1,
       1,     4,     5,     2,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,    14,     0,     1,     0,     2,
       1,     0,     4,     4,     0,     4,     0,     4,     0,     4,
       0,     1,     1,     3,     2,     1,     3,     1,     1,     1,
       0,     9,     0,     8,     8,     9,     0,     3,     3,     1,
       4,     2,     3,     1,     4,     2,     3,     1,     4,     2,
       4,     2,     3,     1,     5,     1,     3,     5,     2,     1,
       0,     2,     2,     2,     0,     2,     2,     1,     2,     1,
       1,     2,     0,     1,     3,     1,     0,     1,     8,     4,
       0,     2,     4,     0,     2,     1,     2,     0,     8,     4,
       3,     0,     5,     3,     1,     2,     2,     3,     3,     1,
       0,    10,     4,     0,     3,     0,     1,     0,     1,     0,
       1,     2,     1,     0,     3,     3,     2,     0,     2,     2,
       1,     0,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     2,     1,
       5,     5,     0,     2,     0,     2,     0,     1,     0,     1,
       1,    10,    11,     6,     0,     2,     1,     4,     4,     0,
       2,     0,     1,     9,     7,     0,     2,     0,     2,     4,
       8,     0,     1,     0,     1,     0,     2,     4,     0,     2,
       0,     1,     2,     2,     3,     0,     1,     4,     5,     6,
       5,     1,     1,     2,     1,     2,     1,     2,     3,     4,
       5,     0,     2,     0,     2,     0,     2,     1,     3,     3,
       3,     2,     0,     1,     7,     0,     3,     0,     3,     7,
       5,     0,     2,     1,     0,     2,     1,     1,     1,     1,
       7,     0,     1,     0,     3,     4,     3,     4,     7,     2,
       4,     2,     3,     1,     1,     1,     3,     0,     3,     0,
       3,     2,     2,     1,     1,     1,     1,     3,     8,     7,
       7,     2,     0,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     0,     2,     1,     1,     2,
       1,     1,     1,     1,     5,     5,     0,     2,     1,     2,
       3,     1,     3,     0,     8,     6,     1,     2,     1,     2,
       1,     1,     1,     7,     8,     6,     7,     8,     6,     0,
       3,     2,     2,     1,     3,     1,     2,     2,     9,     8,
       8,     5,     4,     2,     1,     2,     3,     1,     1,     7,
       8,     6,     7,     4,     4,     2,     9,     8,     1,     1,
       8,     0,     1,     5,     1,     4,     9,     0,     1,     1,
       1,     3,     1,     5,     4,     4,     5,     2,     7,     5,
       1,     4,     1,     1,     1,     1,     3,     6,     7,     1,
       1,     0,     2,     2,     0,     1,     0,     6,     4,     5,
       6,     3,     0,     3,     6,     1,     1,     1,     1,     1,
       1,     3,     2,     3,     2,     2,     3,     1,     4,     2,
       3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      22,     0,     2,    22,     4,     0,     1,     5,     0,     0,
       0,     0,     0,     0,     0,    21,    23,    31,    32,    24,
       0,    27,     0,    25,     0,    26,     0,    28,     0,    29,
      30,   788,     0,     0,     0,     0,    19,     0,     0,     0,
     790,     0,     0,     0,   324,   323,   330,   328,   327,   329,
     326,   325,     0,     0,     0,    47,     0,     0,     0,     0,
       0,   902,     0,    83,    87,     0,     0,     0,     0,    39,
       0,    33,     0,     0,    77,   905,   906,   907,     0,     0,
      34,     0,   337,     0,   336,     0,   335,     0,     0,   813,
     727,     0,     0,     0,    48,    44,    57,     0,     0,   515,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   177,   176,     0,     0,   922,   110,    62,   100,   102,
     132,   121,    63,     0,   109,     0,   122,   104,   105,   106,
     128,   129,   108,   107,   127,   124,   125,   123,   126,   131,
     130,   101,   103,   133,    68,     0,     0,     0,     0,   173,
      73,    74,   172,     0,   174,    78,     0,    78,     0,   145,
      84,   136,    85,     0,   141,   142,   140,   138,   139,   137,
     144,   143,   146,   147,     0,    86,    88,    93,    93,    98,
     155,   148,    99,   149,   150,   153,   154,   152,   151,     0,
       0,    20,     0,    92,     0,     0,     0,     0,     0,   908,
     909,     0,   910,   330,   792,   334,   332,   331,     6,     7,
     333,     0,   791,   789,     0,    12,     0,   364,     0,     0,
       0,     0,     0,     0,   318,    11,   238,   245,   252,   253,
     274,   317,   323,   330,   319,     0,   320,   321,     0,   425,
     247,    10,     8,     9,   342,   340,   341,   338,     0,   323,
       0,     0,    40,    40,    40,   731,    37,    53,     0,     0,
       0,    42,    60,     0,    58,   455,   453,   454,     0,     0,
       0,   732,     0,   466,   465,   467,     0,     0,   764,   765,
     763,   769,     0,   183,     6,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   178,    70,     0,    69,
       0,     0,   747,   744,     0,     0,    68,    81,     0,    79,
     903,     0,     0,    89,     0,     0,    94,     0,    56,    67,
       0,   829,   542,   912,     0,     0,   921,   915,     0,     0,
     914,     0,   236,   352,   351,   237,   273,   276,   275,   278,
     277,   362,     0,     0,   359,   363,     0,   430,   429,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   254,   255,   256,   257,   258,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     337,   416,   414,   343,     0,     0,    18,   339,   816,     0,
       0,   821,   820,   822,     0,   818,   729,    41,   728,   730,
       0,   443,   447,     0,     0,     0,   444,   448,   445,     0,
       0,   210,     0,   225,   214,   884,   885,   213,    52,     0,
     515,     0,    45,   120,   111,    46,   112,   116,   117,   115,
     113,   114,   119,   118,    59,    55,     0,     0,     0,     0,
      57,     0,     0,     0,   626,     0,   589,   590,   516,   517,
     518,   522,   519,   520,   521,   567,     0,   573,   523,   524,
     619,   620,   559,   563,   329,   733,   737,     0,   464,     0,
       0,     0,     0,     0,   767,     0,   189,     0,   191,     0,
     408,     0,   367,     0,     0,     0,     0,     0,     0,     0,
     181,     0,     0,    71,    64,     0,   741,     0,     0,    80,
      75,    76,     0,   901,    95,    90,    91,   825,     0,     0,
       0,     0,   919,   911,     0,   411,     0,   410,   916,   913,
     353,   354,   350,     0,   322,     0,     0,   358,   235,     0,
     239,   426,   270,   267,   268,   271,   272,   269,   261,   266,
     264,   263,   262,   265,   299,   298,   297,   296,   295,   294,
     288,   290,   287,   289,   292,   291,   283,   286,   285,   282,
     281,   293,   284,   260,   279,     0,     0,     0,     0,     0,
     302,   307,   313,   427,   418,     0,   348,   417,   415,   413,
     357,   346,     0,   246,   817,   815,     0,     0,   819,   209,
     889,   890,   894,     0,   894,   446,     0,     0,     0,    19,
      49,    43,     0,   456,     0,   475,   474,   476,     0,   829,
     323,     0,   623,   664,     0,   569,   571,   561,   565,   703,
     596,     0,     0,     0,   735,   432,     0,   468,   323,     0,
     329,     0,     0,     0,   773,     0,   759,   769,   757,     0,
     761,   762,   187,   194,   193,     0,     0,   185,     0,   195,
     180,   437,     0,   365,     0,     0,     0,     0,     0,     0,
     369,   370,   372,   373,   374,   375,   376,   377,   371,   378,
     379,   366,   441,     0,     0,   786,   787,     0,   189,   198,
     641,   163,   156,   207,   157,   206,   160,   158,   159,   162,
     161,     0,   746,     0,   745,   175,    65,   250,   244,     0,
     243,   232,     0,   242,   249,   317,    96,   543,     0,   831,
     835,     0,   833,   823,     0,     0,   920,   335,   409,   904,
     355,   349,   280,   345,   356,     0,   360,   240,   300,   301,
     315,   314,   304,   305,   306,     0,     0,   310,   311,   312,
     309,     0,     0,   362,     0,   812,     0,   895,   224,     0,
       0,   886,   894,   208,   224,   211,   222,    38,     0,   829,
     473,     0,     0,   470,    54,   626,     0,     0,     0,   662,
       0,   597,     0,   592,   633,   540,     0,   549,   547,   548,
     626,   550,     0,   566,   572,     0,     0,   618,   558,   562,
     613,     0,     0,     0,     0,     0,   469,     0,   461,     0,
       0,   770,   772,   771,     0,   767,     0,     0,     0,   192,
     190,     0,   186,     0,   829,   449,   450,   435,   438,   407,
     405,     0,     0,     0,     0,   401,     0,     0,     0,   381,
      14,    13,     0,     0,     0,     0,   480,   483,   482,   491,
     479,   493,   488,   484,   481,   487,   489,   486,   485,   494,
     490,   492,   495,   497,   496,   782,   784,     0,     0,   441,
       0,   200,   201,   199,     0,     0,   640,   740,     0,     0,
     748,   742,   743,   749,    66,   251,     0,     0,   323,   830,
       0,     0,   836,   824,   918,   344,   362,   361,   303,   428,
     308,   316,   347,   356,   814,     0,   210,     0,     0,     0,
     212,   229,   226,   228,   230,   227,     0,   223,   452,     0,
       0,   477,     0,     0,   622,   627,   665,     0,     0,   589,
       0,   579,   584,     0,   575,   580,   593,   595,     0,   591,
       0,   629,   541,   538,     0,     0,   568,   570,   560,   564,
       0,     0,   545,     0,     0,     0,   508,     0,     0,   498,
     738,     0,     0,   433,   431,     0,   462,     0,     0,   458,
     760,   766,     0,   768,   188,   184,   828,     0,     0,     0,
     323,   393,   423,   420,   424,     0,   323,     0,     0,     0,
       0,     0,     0,   800,   802,   801,   796,   797,   803,     0,
     387,     0,   442,   439,     0,   783,   781,     0,     0,   776,
       0,   774,   775,     0,     0,   204,   203,   202,   197,   198,
       0,   681,     0,   700,     0,   705,   725,     0,     0,   642,
     643,   659,   644,   646,   647,   648,   649,   693,   650,   651,
     652,   653,   655,   656,     0,     0,   657,   329,   712,   847,
     848,   711,   858,   859,   714,   716,     0,   753,   329,   231,
       0,   233,   241,   323,   837,   224,     0,   891,   899,     0,
     219,   451,   478,   471,   472,   624,   628,   663,   661,   596,
       0,   587,   583,   574,     0,   578,     0,     0,   637,     0,
     630,     0,     0,   534,     0,     0,     0,     0,     0,   544,
       0,     0,     0,     0,   603,     0,     0,   329,     0,   612,
       0,   736,   734,   463,     0,     0,   758,   826,     0,   436,
     434,     0,     0,     0,   397,     0,     0,   402,   403,   798,
     794,     0,     0,   811,   807,   808,   793,   380,     0,   382,
       0,   390,   780,   779,   785,     0,     0,   440,   182,     0,
       0,   667,     0,   679,   682,     0,   698,   701,   702,   706,
       0,     0,   723,     0,     0,     0,     0,     0,   694,   509,
     510,     0,   666,     0,   645,   654,   658,   715,     0,   713,
     717,   739,     0,   751,   767,   234,   210,   898,     0,   887,
     900,   891,   220,   221,   217,   600,   585,     0,   586,   576,
       0,   581,   594,   634,   636,   635,   641,   171,   164,   632,
     165,   168,   166,   167,   631,   170,   169,     0,     0,   531,
       0,     0,   844,     0,     0,     0,     0,     0,     0,     0,
       0,   717,   605,   134,     0,   515,   603,     0,   614,   616,
       0,     0,     0,   457,   460,   827,   396,     0,     0,   394,
     419,     0,   421,   404,   398,   799,     0,   805,   804,   383,
       0,   388,   389,     0,   778,   777,   196,     0,     0,     0,
       0,     0,     0,     0,   704,   726,     0,   721,   666,     0,
     870,   867,   872,     0,   867,     0,   580,     0,   718,   662,
     513,   641,     0,     0,     0,     0,     0,   752,     0,     0,
       0,   893,   892,   888,     0,   216,     0,     0,   588,     0,
     582,     0,   638,     0,   540,     0,     0,   528,     0,     0,
       0,     0,   843,     0,   556,     0,   546,   556,     0,     0,
     323,   511,   604,   135,     0,   515,   504,   603,   615,   610,
     617,     0,     0,   323,   395,   422,   400,   399,   809,   386,
     384,    16,   668,     0,   680,   678,     0,   687,   699,   697,
     724,     0,     0,     0,   853,   868,   869,     0,     0,     0,
     707,     0,     0,   580,     0,     0,     0,   719,     0,   874,
       0,     0,   756,     0,   754,   897,   218,   598,     0,   601,
     577,   639,   623,   539,   536,     0,     0,     0,   603,     0,
       0,   845,     0,     0,     0,     0,   553,     0,   554,   512,
     608,   606,   501,   504,   609,   392,     0,   810,   385,     0,
       0,    17,   669,     0,   670,     0,   674,     0,   685,   722,
     720,   589,   590,     0,     0,     0,   871,   710,     0,   708,
       0,   660,     0,     0,   877,     0,   873,   755,     0,     0,
       0,     0,   535,     0,   515,   530,   529,     0,   842,   603,
       0,   846,     0,     0,   551,   555,     0,     0,   499,   505,
     501,   391,    15,   673,     0,     0,     0,   641,     0,     0,
     688,   861,     0,     0,   709,     0,   851,     0,     0,   691,
     674,     0,     0,   750,   599,   621,     0,     0,   532,     0,
     840,   841,   839,     0,   557,   603,     0,     0,     0,     0,
     500,   641,     0,   675,   676,   684,   686,     0,     0,   867,
       0,   862,     0,   878,   880,     0,   855,   849,   852,     0,
       0,   692,     0,   875,     0,   602,     0,     0,     0,   838,
     502,   603,   603,     0,   677,   668,   641,     0,     0,     0,
     860,   864,     0,   857,     0,     0,   850,   690,     0,   876,
     537,     0,   526,   503,   506,   603,     0,   689,   683,   866,
       0,     0,   856,   854,   668,   533,     0,   527,   507,   671,
       0,     0,   881,     0,   525,     0,   865,   879,   672,   863
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,   873,   224,   839,  1419,  1420,   225,
     280,     4,     5,    15,    16,   401,   116,    42,    19,    20,
     406,   431,   261,   432,    95,   260,    55,    93,    21,    22,
     263,    57,   117,    23,   884,    24,   298,    59,   150,   118,
      26,   308,    62,   160,    63,   119,    28,   315,    66,   179,
     120,   121,   435,  1233,  1234,   162,   182,   693,  1209,   151,
     123,   124,   125,   488,   688,   486,   653,   654,   818,   655,
     656,   660,   126,   874,   502,   695,   259,   607,   765,   421,
    1305,  1194,   916,   422,   917,   513,   886,  1061,    86,   346,
     540,   711,   226,   712,   713,   932,   387,   228,   229,   579,
     745,   580,   751,   581,   230,   231,    44,   249,   233,   207,
      47,    87,    48,   234,   235,   236,   237,   532,   731,   342,
     343,   537,   736,   344,   127,   495,   670,   671,   999,  1139,
     672,  1350,  1140,  1261,  1000,  1262,   673,  1122,  1249,   981,
     674,  1346,   675,   988,  1127,   835,   676,   677,   128,   982,
     728,   527,   588,   392,   832,  1123,  1252,   983,   345,   984,
     349,   129,   805,   130,   979,   827,   131,   844,   423,   828,
     132,   265,   447,   133,   810,   967,   134,   276,   478,   637,
     135,   136,   618,   619,   770,   921,   865,   958,   959,  1468,
    1412,  1469,   955,  1168,   956,  1170,   269,   270,   458,   459,
     460,  1576,  1396,  1456,  1317,  1498,  1219,  1452,  1093,   943,
     321,   953,  1099,   792,   461,   950,   951,  1405,   462,   463,
     464,   465,   933,   934,  1085,  1201,   935,  1082,  1198,   466,
     782,   939,   783,   467,  1306,  1307,  1389,  1335,  1336,   468,
     795,  1109,   796,  1240,  1110,   469,   470,   631,   776,   471,
    1075,  1091,  1214,   941,  1089,  1204,  1312,   875,   876,  1029,
    1030,  1031,   472,   928,   779,  1152,  1423,  1033,  1475,  1513,
    1514,  1034,  1270,  1153,  1035,  1479,  1428,  1480,  1036,  1530,
    1171,  1037,  1038,  1273,  1156,  1039,   473,  1041,  1160,  1042,
    1043,  1044,  1045,  1046,  1362,  1277,  1162,    91,   476,   137,
     803,   634,   153,   703,   881,   506,   704,   303,   882,   883,
    1298,  1183,   138,   483,   281,   282,   646,   650,   484,   647,
    1009,  1010,   139,   140,   866,  1006,   867,   684,    49,   241,
      50,   242,   243,   679,   838,   996,  1130,   997,   680,   991,
    1134,  1257,  1135,   403,    29,   251,   399,   404,   405,   141,
     142,   520,   721,   722,   892,   800,  1222,  1223,  1323,  1048,
    1049,  1487,  1050,  1051,  1052,  1520,  1550,  1551,  1053,  1367,
    1287,  1054,  1380,  1055,  1523,  1524,  1434,   424,   425,   426,
     602,  1189,   759,   905,   427,   176,   657,   156,    51,    78,
     198,   199,   200,   201,   324,   325,   202,   143
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1403
static const yytype_int16 yypact[] =
{
   -1403,   173, -1403,   185, -1403,   676, -1403, -1403,   402,   402,
     402,   402,   648,   303,   402, -1403, -1403, -1403, -1403, -1403,
    2417, -1403,  1192, -1403,   417, -1403,  2456, -1403,  2489, -1403,
   -1403, -1403,   323,   438,   487,   289, -1403,   402,   402,   530,
   -1403,   369,   499,   360,   204,   204,   601, -1403,   435, -1403,
   -1403, -1403,   550,   586,    82,   569,   606,  1545,   634,   492,
     647, -1403,  2594, -1403,    81,   692,  2666,   402,   402, -1403,
     402, -1403,   664,   685,   691, -1403, -1403, -1403,   747,   303,
   -1403,   829, -1403,  1313, -1403,   341, -1403,   365,  2084,   718,
     708,   623,   630,   673, -1403, -1403,   723,   681,   402, -1403,
     402,   402,   546,   402,   335,   681,   402,   402,   744,   841,
     402, -1403, -1403,   402,   758, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403,   838, -1403,   161, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   617,   402,   211,   188,   402, -1403,
   -1403, -1403, -1403,   867, -1403,   442,   673,   442,   848, -1403,
   -1403, -1403, -1403,   707, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   857, -1403,   779,   540,   540, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   893,
     902, -1403,   877, -1403,   402,   402,   402,   792,   812, -1403,
   -1403,    77, -1403,   678, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403,   852, -1403, -1403,   303, -1403,   859, -1403,   374,   374,
     374,   374,   374,  2013, -1403, -1403, -1403,   107,   628,  2186,
     840,   360,   381, -1403, -1403,   615, -1403, -1403,   844, -1403,
     861, -1403,   402, -1403, -1403, -1403, -1403, -1403,   878,   645,
     918,   507,   402,   402,   402, -1403, -1403, -1403,  1341,   876,
     673,  2633,   402,   888, -1403,   842, -1403, -1403,    71,   959,
     837,   988,   803, -1403, -1403,   360,   891,   824, -1403, -1403,
     895,    93,   897, -1403,  1004, -1403,   832,   904,  1019,   912,
      90,   839,   142,   402,   681,  2522, -1403,   402,   914, -1403,
    1016,  1047,   360, -1403,   402,   927,   617,   402,   929, -1403,
   -1403,   932,   936, -1403,  1066,   935, -1403,   937, -1403, -1403,
     939,   563, -1403,   214,   941,   402,   942, -1403,   303,   943,
     214,   402, -1403,   168, -1403, -1403, -1403,   947, -1403, -1403,
   -1403,   298,   944,   948, -1403, -1403,   663, -1403, -1403,  2084,
    2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,
    2084,  2084, -1403, -1403, -1403, -1403, -1403, -1403,  2084,  2084,
    2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,
    2084,  2084,  2084,  2084,  2084,  2084,  2084,  2084,   374,  2121,
     955,   392, -1403, -1403,  2013,  2084, -1403, -1403,   402,   952,
     303, -1403, -1403, -1403,   616, -1403, -1403, -1403, -1403, -1403,
     940, -1403, -1403,   681,   402,   402, -1403, -1403, -1403,  1029,
    1060, -1403,   402, -1403, -1403, -1403, -1403, -1403, -1403,   958,
   -1403,   586, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   303,  1067,   736,   303,
     723,  1082,  2084,  2084,   334,  2013,   610, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,   989, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   969, -1403,  1085,   303,   974,   303,
     303,  1077,   463,   973,  1068,  2084,   468,  1084,   284,   303,
   -1403,   303, -1403,   975,   394,   979,   303,   987,   681,   845,
   -1403,  1096,  2699, -1403, -1403,  1102,  1062,   732,   990, -1403,
   -1403, -1403,  1439, -1403,   402, -1403, -1403, -1403,   402,   100,
      86,  2084, -1403,   214,   985,   207,  1024, -1403, -1403,   214,
     643,   670, -1403,   374, -1403,  2013,  2084,   991, -1403,  2013,
   -1403, -1403,  2161,  2161,  2161,  2161,  2161,  2161,  2161,  2161,
    2161,  2161,  2161,  2161,  2771,  2771,  2771,  2771,  2771,  2771,
    2771,  2771,  2771,  2771,  2771,  2771,   751,   751,   751, -1403,
   -1403, -1403, -1403,  2161, -1403,   539,   539,   374,   374,   498,
   -1403,   755,  1000,   557, -1403,  2013, -1403,   643, -1403, -1403,
     178, -1403,   997, -1403, -1403, -1403,   759,   918, -1403, -1403,
   -1403, -1403,    59,  1110,    59, -1403,   681,   661,   850,   709,
   -1403, -1403,  1002, -1403,   361, -1403, -1403, -1403,  1113,   996,
     677,  1007,   272,  1094,  1093, -1403, -1403, -1403, -1403, -1403,
    1124,  1103,  1914,   673,  1106,  1021,   303, -1403,   102,  1130,
     113,   936,   303,   303, -1403,   402, -1403,  1138,  1148,  1132,
   -1403, -1403, -1403,   470, -1403,   673,  1114,  1145,   849, -1403,
   -1403,   545,  1031, -1403,   303,  1038,  1133,   402,   931,   915,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,  1115, -1403,
   -1403, -1403,  1039,  2322,  1045, -1403, -1403,   303,   468,   155,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403,  1042, -1403,   828, -1403, -1403, -1403, -1403, -1403,  2084,
   -1403, -1403,  1037, -1403, -1403,   774, -1403, -1403,   303, -1403,
     670,  1034,    58, -1403,  1044,  1049, -1403,   966, -1403, -1403,
     643, -1403, -1403, -1403,  1051,  2013, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403,   539,  2121, -1403, -1403, -1403,
   -1403,   539,   374,   312,  2084, -1403,  1048,  1054,  1078,  1137,
    1156, -1403,    59, -1403,  1078, -1403,   761, -1403,  1055,   714,
    1057,  2084,  1059, -1403, -1403, -1403,  1064,  1149,  2084,  1143,
     148, -1403,  1976,   655,  1072,  1172,  1963, -1403, -1403, -1403,
     334,   424,   402, -1403, -1403,  1186,  1182, -1403, -1403, -1403,
   -1403,  1070,   673,   586,  2084,  1071,   360,  2084,   761,  2084,
    1076, -1403,   670,   360,   784,  1068,  1190,   936,   673, -1403,
   -1403,   303, -1403,  1080,   563, -1403, -1403,  1079, -1403, -1403,
   -1403,  2121,  1181,   303,   870, -1403,  1205,  2555,   722, -1403,
   -1403, -1403,   402,  2084,  1086,  1087, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403,  1083, -1403,   810,   915,  1039,
    1173,   908,   402, -1403,  1089,  1213,  2156, -1403,  1210,   358,
   -1403, -1403, -1403, -1403, -1403, -1403,   855,  1936,   510, -1403,
     303,   303, -1403, -1403, -1403, -1403,   410, -1403, -1403,   836,
   -1403, -1403, -1403, -1403, -1403,  1105, -1403,   303,   402,  1183,
   -1403, -1403, -1403, -1403, -1403, -1403,   303, -1403, -1403,  1097,
     681, -1403,  1104,  2335, -1403,   402, -1403,  2084,  1107,   360,
    1125, -1403,   129,  1108,  1176, -1403, -1403, -1403,  2084, -1403,
     508,  1212, -1403,  1117,  1225,  1229, -1403, -1403, -1403, -1403,
    1231,  1206,   554,   541,   402,  1233, -1403,  2084,  1242, -1403,
   -1403,  1121,  1122, -1403, -1403,  1123, -1403,  2084,  1234, -1403,
   -1403, -1403,  1131, -1403, -1403,   670, -1403,    98,  2084,  1134,
     413, -1403, -1403, -1403, -1403,   303,   699,   303,   583,  1174,
    1254,  2732,  1174, -1403, -1403, -1403, -1403, -1403, -1403,   884,
   -1403,  1136, -1403, -1403,  1141, -1403, -1403,  1140,  2335, -1403,
     887, -1403, -1403,  1142,   303, -1403, -1403, -1403, -1403,   155,
     766,   402,  2084,   402,  1144,  2084,  1236,  2084,    48, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,   400, -1403, -1403,
   -1403, -1403, -1403, -1403,   543,    40, -1403,  1146, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,  1147,   122,   874, -1403,
    1439, -1403, -1403,   649,   670,  1078,   731,   182,   146,   303,
     957, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,  1124,
    2084,  1276, -1403, -1403,  2084,  1152,  1188,  1150,   360,  1157,
   -1403,  2765,  2084,  1258,  1305,  1226,  1261,  1262,   402, -1403,
    1263,  1264,   402,   108,  1717,  1279,  2084,  1170,   106, -1403,
    1292, -1403, -1403, -1403,  1171,  2084, -1403, -1403,  1175, -1403,
   -1403,   590,   889,   906, -1403,  1177,  1260, -1403, -1403,   402,
   -1403,  1217,  1217, -1403, -1403, -1403, -1403, -1403,   915, -1403,
     595, -1403, -1403, -1403, -1403,  1178,   915, -1403,   670,  1179,
    1298, -1403,  2084,  1251, -1403,  1265,  1252, -1403, -1403, -1403,
    1184,   303,  1257,  1270,  1903,  2084,  2084,  2084, -1403, -1403,
   -1403,  1293,  1194,   456, -1403, -1403, -1403, -1403,  2084, -1403,
     712, -1403,   500,  1309,  1068, -1403, -1403, -1403,    87, -1403,
   -1403,   182, -1403, -1403,  1195, -1403, -1403,  2084, -1403,  1319,
    2084, -1403, -1403, -1403,  1207, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403,  1211,   673,  1295,
    1328,  2013, -1403,   314,   936,   936,  1215,   936,   936,  1320,
    2121, -1403, -1403, -1403,  1795, -1403,  1717,  1325,   402, -1403,
    1219,  1221,  1331, -1403, -1403, -1403, -1403,  1311,   303, -1403,
   -1403,  2121, -1403, -1403,   402, -1403,  1350, -1403, -1403, -1403,
    1299, -1403, -1403,  1245, -1403, -1403, -1403,  1357,  1339,  2084,
    1232,  1634,  2084,  1237, -1403, -1403,  2084,  1354,  1194,  1238,
   -1403,   564, -1403,  2084,   564,  1239,  1312,  1976, -1403,  1143,
   -1403, -1403,  2084,  2084,   111,   402,  1243, -1403,  1366,  1249,
     734, -1403, -1403, -1403,  2084, -1403,  1253,  1976, -1403,  1976,
   -1403,   303, -1403,  1367,  1172,  1255,   673, -1403,  1368,  1250,
    2013,   121, -1403,  1376,  1348,  1266, -1403,  1348,  1269,  2121,
     350, -1403, -1403, -1403,  1242, -1403, -1403,  1717, -1403, -1403,
   -1403,  1271,   303,   474, -1403, -1403, -1403, -1403,   402,   402,
   -1403,  1406,    69,  1332, -1403, -1403,  1384, -1403, -1403, -1403,
   -1403,  2084,  1272,   148, -1403, -1403, -1403,  2084,  1324,  1273,
   -1403,  2084,  1281,  1355,  1283,  1401,  1396, -1403,  2084, -1403,
     117,   788, -1403,  1405, -1403, -1403, -1403, -1403,  1369, -1403,
   -1403,   360,   272, -1403,  1410,  1300,  1816,  1331,  1717,  1301,
    1331, -1403,  1303,  1415,  1414,  1310, -1403,  1314, -1403, -1403,
   -1403, -1403,  1030, -1403, -1403, -1403,  1315, -1403, -1403,  1316,
     402, -1403, -1403,  1318, -1403,  2013, -1403,  1424,  1043, -1403,
   -1403,   719,  1317,  1323,  1321,   264, -1403, -1403,   124, -1403,
    2084, -1403,  1418,  1332,  1391,  2084, -1403, -1403,  1322,  2013,
    1326,  1426, -1403,  1416, -1403, -1403, -1403,  1327, -1403,  1717,
    1330, -1403,  1331,   936, -1403, -1403,   172,  2084, -1403, -1403,
    1030, -1403, -1403, -1403,  1333,   344,  1335, -1403,  2084,  1435,
   -1403,   675,  2084,  2084, -1403,  2084, -1403,  1338,   128,   402,
   -1403,  2084,  1394, -1403,  1334, -1403,   936,  1430, -1403,  1454,
   -1403, -1403, -1403,  1343, -1403,  1717,  1449,  1170,  1457,  2084,
   -1403, -1403,  1475, -1403, -1403, -1403, -1403,  1427,  1462,   564,
    2084, -1403,  1421, -1403, -1403,   130,  1423, -1403, -1403,  1353,
    1356, -1403,   506, -1403,  2084, -1403,  1358,   936,  1488, -1403,
   -1403,  1717,  1717,  1471, -1403,    69, -1403,  1359,  2084,  1433,
   -1403, -1403,  2013, -1403,   136,  2084, -1403, -1403,  1493, -1403,
   -1403,  1364,   402, -1403, -1403,  1717,  1370, -1403, -1403, -1403,
    2013,   815, -1403, -1403,    69, -1403,  1371, -1403, -1403, -1403,
     816,  2084, -1403,  1373, -1403,  2084, -1403, -1403, -1403, -1403
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1403, -1403, -1403, -1403,   -66, -1403,   382, -1403, -1403, -1403,
       7,  1518, -1403, -1403, -1403,  1521,    50,  1127, -1403, -1403,
     822, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
    1088, -1403, -1403, -1403, -1403, -1403,  1222, -1403, -1403,   115,
   -1403,  1372, -1403, -1403, -1403,  1525, -1403,  1365, -1403, -1403,
     -57,   -52, -1403,   -50, -1403, -1403, -1403,   542, -1403, -1403,
    -224,   694,   -24, -1403, -1403, -1403, -1403,   881, -1403, -1403,
    -417, -1403,   -34,   517, -1403, -1403,  -148,  -839, -1403,  -692,
   -1403, -1403, -1403, -1403,   739,  -616, -1403, -1403,   -39, -1403,
   -1403,   482,  1009, -1403,   662,   220, -1403, -1403,  2505,   804,
   -1403,  -489, -1403,   800,  -178,   903, -1403,   189,    52, -1403,
   -1403,  1509,  -353,  -257, -1403,  1342, -1403, -1403, -1403,  -278,
    -382, -1403, -1403,   -36, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   309,
   -1403, -1403, -1403, -1403, -1403,   571, -1403, -1403, -1403,  -199,
   -1403,   -72, -1403,  -269, -1403, -1403, -1403,  -893,   -27,  -344,
     984, -1403, -1403,    16, -1403, -1403,   -46,   695, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,    18, -1403, -1403, -1403,
     -31,   -40, -1403, -1403, -1403, -1403,   642, -1403, -1403,    99,
     159, -1403, -1403, -1403,   536, -1403,  -407, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,   262,
    -147, -1403, -1403, -1403, -1403, -1403, -1403,   250, -1403, -1403,
   -1403,  -380,   275, -1023, -1403, -1403, -1096, -1403, -1403,  -732,
     509, -1403, -1403,  -379, -1403, -1403, -1403,   481, -1222, -1403,
   -1403,   255, -1403, -1157, -1403, -1403,   960, -1403,   202,  -595,
   -1403, -1403, -1403, -1403,   434, -1403, -1403, -1145, -1403, -1403,
   -1403, -1403,  -397,   307, -1403, -1012, -1402, -1403,   109, -1403,
   -1188, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403, -1403, -1403,  -401, -1403, -1403,   553,
   -1403,  -903, -1403,   556, -1403, -1403, -1403,  -373, -1403,  1539,
   -1403, -1403,  -653, -1403, -1403, -1403, -1403, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   724, -1403,   420,  -752,  -583, -1403,
     459, -1403,   -38,   -29,   599, -1403, -1403, -1403,    -8, -1403,
      22,   257,   -64, -1403, -1403, -1403,   618, -1403, -1403, -1403,
   -1403,   477, -1403, -1403, -1403, -1403,  1014, -1403,  1208,   322,
     -16,  -549, -1403, -1403, -1403, -1403,   390, -1403, -1403, -1403,
   -1403,   131, -1403, -1403, -1403, -1403,    32, -1403, -1403, -1215,
     137, -1403,    97,   581, -1385, -1403, -1403, -1403, -1403, -1403,
    1020,   436,  -523, -1403, -1403,  -468,  1602, -1403, -1403, -1403,
   -1403, -1403, -1403, -1403,   547,  1428, -1403, -1403
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -918
static const yytype_int16 yytable[] =
{
      32,    33,    34,    36,    39,    84,    52,   122,   310,   180,
     161,   239,   592,   457,   181,   206,   165,   210,    35,   152,
     184,   154,   168,   611,   170,   811,   186,   777,   187,    72,
      73,   167,   183,   171,   420,   185,   583,   188,   163,   283,
     336,   337,   338,   339,   340,   584,   173,   238,   930,   326,
     880,  1102,   724,   628,  1106,    18,   240,   627,   612,   189,
     190,  1313,   191,   971,   815,    46,   906,  1066,  1286,  1369,
     772,   659,   910,   208,   625,   626,    31,   245,   164,   247,
     166,   761,   255,    92,    31,  1341,   738,   739,   264,   266,
     268,   493,   271,    36,    31,    36,    36,   284,   285,    36,
     288,   290,    36,   209,  1310,   292,    40,    31,   272,   149,
     277,   807,   429,    31,   286,  1413,   591,   291,   174,   267,
      25,  1178,   589,   174,   448,   890,  1357,   209,    31,   526,
     481,   203,   494,   586,   347,   174,   299,   300,  1080,  1378,
     305,  1285,  1238,  1566,  1028,  1445,  1375,   309,  1230,   309,
      39,   239,  1485,   592,    40,    31,  1485,  1400,  1378,   481,
    1292,    40,    31,  1569,  1445,  1426,   757,   718,   809,   316,
     316,   482,  1583,     6,    40,    31,  1458,   159,  1164,    31,
     348,  1081,  -769,   174,   497,    -3,   322,   323,   322,   822,
     871,  1373,  1179,   330,    40,    31,  1587,   457,  1165,    46,
    1182,   973,    45,   295,   433,   347,   758,   891,  1505,   434,
     574,   582,   301,    40,    31,   438,   872,    40,    31,    41,
     919,   441,   449,   442,  1188,   678,  1422,   436,   500,   -51,
     440,   799,   443,   175,   396,   798,   329,  1501,   723,   909,
    1457,  1301,  -368,  1460,   407,   407,   407,   613,    82,    83,
    1117,   348,   793,   794,   444,  1490,   898,   733,  1239,  1231,
    -362,   719,   474,  1379,  1372,  -459,  1363,    41,    45,  1446,
     389,   870,   232,  1401,  -769,   977,  1486,   437,   635,   439,
    1528,   639,  1553,  1540,  1388,    36,   208,    41,  1572,   503,
     661,    45,   662,   498,   530,   455,    36,   682,   299,   509,
     499,   402,   518,   227,  1548,  1503,   304,    41,   248,    40,
      31,   507,  1173,   296,   390,    83,   209,   523,  1320,  1563,
    1564,    61,   239,   529,  -323,   347,    41,    30,    82,    83,
      41,  -362,  1516,  -362,  -625,    45,    45,  1331,  -323,   347,
      40,    31,    31,  1578,  1321,  1483,   278,  1300,    31,   452,
      82,    83,   587,    82,    83,   732,    40,    31,  1345,   301,
     775,   521,   768,  -323,    40,    31,  1544,    40,    31,   278,
    -917,   348,    31,  1186,  1512,   457,    67,   212,   204,   213,
      40,    31,   617,   239,   172,   348,  -411,    40,    31,   949,
     594,   652,   279,   948,    75,  1221,  -411,   582,   582,   740,
     741,  1567,   664,   333,   244,   600,   603,   604,   665,    31,
     946,   947,   232,   389,   609,   279,  1484,   453,    58,    40,
      31,   391,    41,   214,  1549,  1425,   215,   666,   246,   608,
     962,  -189,  1299,   -72,   954,   601,  1409,   347,    70,    76,
     208,    71,   264,   341,   389,   691,   534,  -357,    77,    31,
     692,   -72,    46,    41,   402,   389,   696,   389,   667,    45,
     902,  -357,   698,   239,   699,   830,  1166,   239,   694,    41,
     209,   697,   640,   700,  1184,  1040,  1121,    41,   583,  1032,
      41,   455,  1167,   348,  -552,   801,   727,   642,   869,  1549,
     685,    68,   730,    41,   643,   -72,   390,    83,  -411,  -411,
      41,   307,   668,   238,   -72,    61,   716,   820,   145,  1118,
     717,   824,   240,   239,    40,    31,    81,   525,   644,  1087,
     686,   223,   531,   457,   642,   347,   146,   390,    83,    69,
    1297,   643,    41,   457,   420,  -191,  1558,  1416,    82,    83,
     420,   669,   212,   204,   213,    40,    31,    31,  -323,    40,
      31,    11,    40,    31,  -589,   644,   702,   273,   452,   390,
      83,  -411,  -411,  1506,  1509,  1172,   825,   582,   582,   541,
     147,   348,    74,   582,   901,   652,   629,   652,  1100,   148,
      81,   645,    88,   232,  -327,    13,  1164,  1425,   214,    45,
      31,   215,    89,   212,   204,   213,    40,    31,   600,   314,
    1190,  1101,    31,   274,  1365,   841,  1293,   400,  1324,  1325,
     826,  1327,  1328,  1126,   590,   593,    90,  -189,  1295,   457,
      82,    83,  1366,  1026,    31,  1260,  1027,    41,   601,    94,
    -327,  1433,   742,   743,   744,   525,    96,    36,   620,   214,
     350,   297,   215,    45,   232,   952,   597,  1174,    79,    37,
     322,    80,   814,   582,   961,    31,    82,    83,    41,    36,
      11,   840,    41,   239,   144,    41,   525,    38,   638,   525,
     974,  -832,   623,   624,   834,   590,   351,   155,   525,   352,
     525,   208,   577,   578,   353,   525,   223,    40,    31,     8,
     455,  -327,  -327,  -327,    13,  -327,  -327,  -327,  -327,   897,
       9,  1098,  -327,  -327,    88,   651,   192,    10,   720,    41,
     518,   209,   354,  -327,   391,    31,   400,  1070,   355,   518,
      11,   252,   177,   519,   232,   575,   576,   193,   232,   936,
      31,   253,   714,   577,   578,    12,   262,   223,   145,   254,
     194,   725,    40,    31,  1246,   287,  -696,   615,   250,  1280,
     -35,    31,   992,   -35,    13,   590,   734,   105,  -696,   227,
     937,  1068,   629,   393,   394,   938,    81,  1150,   583,  -666,
    -666,  -666,  -666,  -666,   232,   256,    14,   584,  -696,  1519,
    1282,   911,   257,   106,   322,  1283,  1124,   457,  1125,  -335,
    -335,   390,    83,   616,  -696,    82,    83,   777,   995,  -335,
      13,   912,   913,    45,  1012,   753,   914,   111,   112,   763,
    -834,   538,   539,   764,   163,  -666,    82,    83,  -666,   915,
     258,    45,   998,    82,    83,    45,  -323,   -36,  1334,   773,
     -36,   812,    45,   204,  1001,    40,    31,   293,   451,  1319,
     205,   420,   289,    40,    31,    82,    83,  1504,    31,    37,
     823,  -406,   452,   525,  1072,    31,    31,  -215,   878,   296,
    1011,  -215,   879,  1016,  1017,  -514,  -514,  -514,  1047,  -882,
      81,  1058,   524,   294,   519,    81,   525,   583,   524,  1187,
    1536,    70,  1385,   764,   705,  -666,   764,  -666,   993,   383,
     384,   385,   386,   747,   748,   749,   750,   306,   583,  -625,
     322,  -666,  -666,   195,   312,   196,   197,   888,    79,  -666,
    -666,   755,   208,  -666,  1015,    31,    43,  1076,  -514,   204,
     453,  1561,    31,  1151,   232,   454,   320,  -248,  1411,   885,
      81,   313,   836,    70,   691,   318,   970,    70,  1399,   692,
    1447,   727,   209,   582,   319,   696,  1103,  -795,   327,  1107,
     837,   698,    70,   699,   477,   896,    41,   694,  1007,  1008,
     697,  -795,   700,   328,  1581,  1585,  -795,  1582,  1586,    45,
     742,   743,   744,    70,   903,   480,   583,  1192,  1193,    45,
      36,    70,    43,   489,   455,   388,  -412,  -412,    70,   450,
     496,   922,  -795,   446,    70,   834,   687,   395,   926,    70,
     332,   766,  -412,  1059,  1060,   275,   945,   335,  -412,  -795,
     975,   208,  -412,  1154,  -363,  1157,  -795,  -795,   398,    70,
     980,   987,   986,   -19,   963,   -19,   397,   965,   428,   968,
     475,  -412,  1137,  1138,  1207,  1145,  1146,  1247,  1248,  1208,
     445,   209,   479,  1474,    70,  1211,   487,  1499,   485,   302,
      43,  1213,   582,  1215,  1250,  1251,   490,  1210,  1466,  1467,
    1212,   491,  1216,  1002,   492,    45,   504,  1494,    45,   448,
    1315,  1477,  1478,   582,   841,   408,   409,   505,   498,  1063,
    1064,   510,  1012,   512,   511,   514,  -412,   515,   599,   516,
    1226,   517,   533,   535,  1229,   606,  1067,   522,   518,   528,
    1241,   536,   585,   411,   595,   525,  1432,   714,   605,   614,
     610,   412,   622,   413,  -412,  -412,  -412,    43,  -412,   630,
     632,  1255,   633,   636,   641,   648,   689,   663,   649,    45,
     840,   681,  1263,   658,   683,    43,   701,   414,  1011,   415,
      13,   726,   706,  1415,   729,   752,   735,  1077,   416,   239,
     754,   582,   760,   417,   767,   771,   519,   418,  1086,   774,
     778,   780,   781,   111,   112,   784,   802,   419,  1395,   391,
    1571,   804,   808,   456,   525,   481,   525,  1105,   816,   817,
    1302,   821,   174,   829,  1333,   831,   833,  1114,  1580,   843,
     887,   842,   868,    56,   877,   889,   893,   894,  1119,   895,
     904,  -896,   -61,  1148,   907,   908,   920,   918,   -61,   -61,
     923,   925,   927,  1107,   942,   -61,   924,   -61,   -61,   940,
     954,   957,   960,   964,   972,   -61,   -61,   -61,   969,   978,
    1338,    43,   976,    45,   985,   989,    43,  1005,  1003,  1004,
    1014,  1018,  1155,  1019,  1056,  1159,  1347,  1163,   239,  1071,
    1069,   -61,  1065,   -61,  1090,  1079,  1073,  1084,  1191,  1078,
    1083,  1094,   -61,   -61,  1092,  1095,  1097,   -61,  1096,  1104,
     -61,   -61,  1108,  1111,  1112,  1113,  1115,   -61,   -61,   -61,
     714,   -61,  1129,  1116,  1131,  1197,  1120,    36,  1141,  1142,
    1161,   727,  1143,  1202,  1147,  1218,  1158,  1180,  1203,  1181,
    1196,  1200,  1381,    43,  1199,  1205,  1220,  1221,  1224,  1225,
    1227,  1228,  1217,  1402,   211,  1236,   212,   204,   213,    40,
      31,  1231,  1242,  1243,  1254,  1256,  1237,  1245,  1267,  1253,
    1264,  1266,  1269,  1272,  1276,  1244,  1274,  1271,  1278,  1291,
    1417,  1418,   410,   146,  1424,  1304,  1455,  1309,  -224,    43,
      45,  1151,    43,   239,   -61,  1316,  1311,   456,  1318,  1314,
    1329,  1337,   214,  1326,  1342,   215,   411,  1238,   216,  1348,
     217,  1339,  1268,  1340,   412,  1349,   413,   239,  1351,  1352,
      43,  1353,    43,    43,  1355,  1288,  1289,  1290,  1361,  1359,
    1364,  1370,    43,  1371,    43,  1382,  1383,  1392,  1294,    43,
     414,  1384,   415,  1398,  1397,  1387,  1403,  1394,  1404,   212,
     232,   416,  1472,  1425,  1427,   715,   417,  1308,  1406,  1330,
     418,  1408,    43,  1414,  1430,  1437,   111,   112,    43,  1436,
     419,  1442,    41,  1439,   218,  1441,  1440,  1343,  1443,  1448,
    1330,   896,   212,   204,   213,    40,    31,  1451,   219,   220,
    1449,  1462,  1453,  1481,  1459,  1461,   221,   222,  1507,  1107,
     223,  1463,  1464,  1476,  1489,  1518,  1465,  -883,  1471,  1246,
    1473,  1482,  1491,  1496,  1493,  1534,  1497,  1537,  1495,  1500,
     239,  1531,  1502,  1535,  1538,  1541,  1511,  1515,   214,  1354,
    1527,   215,  1358,  1542,   707,  1539,  1360,  1545,   239,  1546,
      45,  1547,  1552,  1368,  1555,  1556,  1562,  1565,  1557,   232,
    1560,  1568,  1376,  1377,  1570,  1574,  1575,   769,  1330,   391,
    1259,     7,  1579,  1584,  1386,  1588,    17,   596,   508,   311,
      27,   525,   994,  1133,   819,   791,  1149,  1424,   621,   806,
     896,   708,  1185,   317,   709,    43,   813,   966,   737,  1062,
     899,   900,    45,    85,  1577,    97,   334,  1344,    41,  1128,
     218,    98,    99,   746,  1013,  1074,  1424,    43,   100,  1510,
     101,   102,  1470,  1169,   219,   220,  1393,  1407,   103,   104,
     105,  1429,   221,   222,  1390,  1235,   223,  1435,  1195,  1410,
      43,  1438,   797,   710,  1450,  1275,  1374,  1175,  1444,  1532,
    1176,   169,  1296,  1057,    12,  1265,   106,  1144,  1421,  1258,
    1136,   756,   598,  1322,   232,   107,   108,  1589,  1521,  1529,
     109,    43,  1554,    13,   110,  1177,   762,  1303,    64,   331,
     111,   112,   113,     0,   114,  1356,     0,     0,   232,     0,
    -641,  -641,     0,     0,     0,   896,     0,     0,     0,  -641,
       0,     0,     0,     0,     0,     0,  -641,     0,     0,     0,
    1488,     0,  -641,  -641,  -641,  1492,  -641,     0,  -641,   896,
       0,     0,     0,  -641,     0,     0,     0,     0,     0,     0,
    -641,     0,     0,   929,  -641,     0,  -641,  1508,     0,     0,
       0,     0,     0,   456,     0,     0,     0,     0,  1517,     0,
    -641,  -641,  1522,  1525,     0,  1526,     0,   115,     0,     0,
       0,  1533,     0,     0,  -641,     0,  -641,  -641,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    97,     0,  1543,
       0,     0,     0,    98,  1232,     0,    43,     0,     0,     0,
     100,   232,   101,   102,     0,     0,     0,     0,     0,     0,
     103,   104,   105,  -641,  1559,     0,     0,     0,     0,   232,
       0,     0,     0,     0,     0,     0,     0,     0,  1522,     0,
       0,     0,   896,     0,     0,  1573,    12,     0,   106,   456,
       0,  -641,   302,     0,     0,     0,     0,   107,   108,     0,
     896,     0,   109,    43,    43,    13,   110,     0,     0,     0,
       0,  1522,   111,   112,   113,    97,   114,     0,     0,     0,
      43,    98,  1332,     0,     0,     0,     0,     0,   100,    43,
     101,   102,     0,     0,     0,     0,    97,     0,   103,   104,
     105,     0,    98,  1454,     0,     0,     0,     0,     0,   100,
       0,   101,   102,  1088,     0,     0,     0,     0,     0,   103,
     104,   105,     0,     0,    12,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
     109,     0,     0,    13,   110,    12,     0,   106,     0,   115,
     111,   112,   113,    43,   114,     0,   107,   108,    43,     0,
      43,   109,     0,     0,    13,   110,     0,     0,     0,     0,
       0,   111,   112,   113,  1279,   114,   212,   204,   213,    40,
      31,     0,     0,     0,     0,   451,     0,    43,     0,     0,
      40,    31,     0,     0,     0,     0,     0,     0,     0,   452,
       0,     0,   785,     0,     0,     0,   786,   787,   788,   212,
     204,   213,    40,    31,     0,   789,     0,   929,  -607,     0,
       0,     0,   214,  -611,     0,   215,     0,   115,     0,     0,
       0,     0,     0,   715,   944,     0,   212,   204,   213,    40,
      31,     0,    43,     0,     0,     0,  -625,  1280,   115,   212,
     204,   213,    40,    31,     0,   214,     0,     0,   215,     0,
       0,   707,     0,     0,     0,     0,     0,   453,     0,     0,
     931,     0,   790,     0,     0,     0,     0,  1281,  1282,     0,
       0,     0,   214,  1283,  1284,   215,   212,   204,   213,    40,
      31,     0,    41,     0,   218,   214,     0,     0,   215,     0,
       0,     0,     0,    41,     0,     0,     0,     0,   219,   220,
       0,   709,     0,     0,     0,     0,   221,   222,     0,     0,
     223,     0,     0,     0,     0,    41,     0,   218,     0,     0,
       0,   455,   214,     0,  1088,   215,     0,     0,     0,     0,
     217,   219,   220,   931,     0,     0,     0,     0,     0,   221,
     222,     0,    41,   223,   218,     0,     0,   212,   204,   213,
      40,    31,     0,     0,     0,    41,     0,   218,   219,   220,
       0,     0,     0,     0,     0,     0,   221,   222,     0,     0,
     223,   219,   220,     0,     0,     0,     0,     0,     0,   221,
     222,     0,     0,   223,   212,   204,   213,    40,    31,     0,
       0,     0,    41,   214,   218,     0,   215,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,   220,
       0,    43,     0,     0,     0,     0,   221,   222,     0,     0,
     223,     0,    40,    31,     0,     0,     0,     0,     0,     0,
     214,   452,     0,   215,     0,     0,     0,     0,  1020,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1021,     0,
    -695,     0,     0,     0,     0,  1022,     0,     0,   356,     0,
       0,     0,  -695,    41,     0,   218,  1023,     0,  1024,     0,
       0,     0,     0,     0,  1391,     0,     0,     0,     0,   219,
     220,     0,  -695,  1025,     0,     0,     0,   221,   222,     0,
       0,   223,     0,    43,   357,     0,  1026,   358,  -695,  1027,
      41,     0,   359,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   575,   576,     0,     0,
       0,     0,     0,     0,   577,   578,  1431,     0,   223,     0,
     360,     0,     0,     0,     0,    41,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,     0,   383,
     384,   385,   386,   455,     0,     0,     0,     0,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   845,   383,   384,   385,   386,     0,     0,
       0,     0,     0,     0,     0,   846,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   847,   848,   849,   846,     0,
       0,     0,     0,   850,     0,   851,     0,   852,   847,   848,
     849,     0,     0,     0,     0,   853,   850,     0,   851,     0,
     852,     0,     0,     0,     0,     0,     0,     0,   853,     0,
       0,   854,     0,   855,     0,     0,     0,     0,     0,     0,
       0,     0,   856,   857,   854,     0,   855,   858,   859,     0,
       0,   860,     0,     0,     0,   856,   857,     0,     0,   861,
     858,   859,     0,     0,   860,     0,     0,     0,    53,     0,
       0,     0,   861,     0,     0,     0,     0,   -50,   862,     0,
       0,   863,     0,   -50,   -50,     0,   864,     0,     0,     0,
       0,   862,   -50,   -50,   863,     0,     0,   -50,     0,   864,
     -50,     0,   -50,     0,    54,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,   -82,     0,     0,     0,
       0,     0,   -82,     0,     0,     0,   -50,   -50,   -50,   -82,
       0,   -82,   -82,     0,     0,     0,   -82,   -50,   -50,   -82,
      65,   -82,   -50,    61,     0,   -50,   -50,     0,     0,   -97,
       0,     0,   -50,   -50,   -50,   -97,   -50,     0,     0,     0,
       0,     0,     0,     0,   -97,   -82,     0,   -82,     0,   -97,
       0,     0,   -97,   501,   -97,     0,   -82,   -82,     0,     0,
       0,   -82,  -205,     0,   -82,   -82,     0,     0,  -205,  -205,
       0,   -82,   -82,   -82,     0,   -82,     0,  -205,   -97,     0,
     -97,     0,     0,     0,     0,  -205,   990,  -205,     0,     0,
     -97,     0,     0,     0,   -97,  -806,     0,   -97,   -97,     0,
       0,  -806,     0,     0,   -97,   -97,   -97,     0,   -97,     0,
    -806,  -205,     0,  -205,     0,  -806,     0,     0,  -806,     0,
    -806,     0,     0,  -205,     0,     0,     0,  -205,     0,     0,
    -205,  -205,     0,     0,    97,     0,     0,  -205,  -205,  -205,
      98,  -205,     0,     0,  -806,     0,  -806,   100,     0,   101,
     102,     0,     0,     0,   157,     0,  -806,   103,     0,   105,
    -806,     0,     0,  -806,  -806,     0,     0,     0,     0,     0,
    -806,  -806,  -806,    97,  -806,     0,     0,     0,     0,    98,
     430,     0,     0,   158,     0,   106,     0,     0,   101,   102,
       0,     0,     0,     0,   107,   108,   103,     0,   105,   109,
       0,     0,    13,   110,     0,     0,    97,     0,     0,   111,
     112,   113,    98,   114,     0,     0,     0,     0,     0,     0,
       0,   101,    12,     0,   106,     0,   178,     0,     0,   103,
       0,   105,     0,   107,   108,     0,     0,     0,   109,    97,
       0,    13,   110,     0,     0,    98,   690,     0,   111,   112,
     113,     0,   114,     0,   101,    12,     0,   106,     0,     0,
       0,     0,   103,     0,   105,     0,     0,   108,     0,     0,
       0,   109,    97,     0,    13,   110,     0,     0,    98,     0,
       0,   111,   112,   113,     0,   114,     0,   101,    12,     0,
     106,     0,  1132,     0,     0,   103,     0,   105,     0,     0,
     108,     0,     0,     0,   109,    97,     0,    13,   110,     0,
       0,    98,  1206,     0,   111,   112,   113,     0,   114,     0,
     101,    12,     0,   106,     0,     0,     0,     0,   103,     0,
     105,     0,     0,   108,     0,     0,     0,   109,     0,     0,
      13,   110,     0,     0,     0,     0,     0,   111,   112,   113,
       0,   114,     0,     0,    12,     0,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
     109,     0,     0,    13,   110,     0,     0,     0,     0,     0,
     111,   112,   113,     0,   114,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,  -918,  -918,  -918,  -918,  -918,  -918,  -918,
    -918,  -918,  -918,  -918,  -918,   380,   381,   382,     0,   383,
     384,   385,   386
};

static const yytype_int16 yycheck[] =
{
       8,     9,    10,    11,    12,    44,    14,    57,   156,    66,
      62,    83,   394,   270,    66,    81,    62,    81,    11,    59,
      66,    59,    62,   430,    62,   641,    66,   622,    66,    37,
      38,    62,    66,    62,   258,    66,   389,    66,    62,   105,
     218,   219,   220,   221,   222,   389,    62,    83,   780,   196,
     703,   954,   520,   454,   957,     5,    83,   454,   431,    67,
      68,  1206,    70,   815,   647,    13,   758,   906,  1164,  1284,
     619,   488,   764,    81,   454,   454,     7,    85,    62,    87,
      62,   604,    90,     1,     7,  1242,   575,   576,    96,    97,
      98,     1,   100,   101,     7,   103,   104,   105,   106,   107,
     108,   109,   110,    81,  1200,   113,     6,     7,   101,    59,
     103,     9,   260,     7,   107,  1337,   394,   110,    37,    97,
       5,    81,   391,    37,    53,    67,  1271,   105,     7,   328,
      37,    79,    42,   390,    27,    37,   144,   145,     9,    28,
     148,  1164,    36,  1545,   876,    28,  1291,   155,    40,   157,
     158,   223,    28,   535,     6,     7,    28,    36,    28,    37,
    1172,     6,     7,  1548,    28,  1353,   107,    67,    55,   177,
     178,    78,  1574,     0,     6,     7,  1398,    62,   130,     7,
      73,    52,    60,    37,    42,     0,   194,   195,   196,   657,
      35,  1287,   152,   201,     6,     7,  1581,   454,   150,   147,
      78,   817,    13,    42,   261,    27,   147,   149,    36,   261,
     388,   389,     1,     6,     7,   261,    61,     6,     7,   119,
     769,   261,   151,   261,    42,   494,   157,   261,   294,   147,
     261,   632,   261,   152,   242,   632,   159,  1459,   152,   762,
    1397,   154,   152,  1400,   252,   253,   254,   446,   146,   147,
     152,    73,   632,   632,   262,  1443,   745,   535,   152,   151,
     153,   161,   270,   152,  1287,   152,  1278,   119,    79,   152,
      63,   688,    83,   152,   152,   824,   152,   261,   477,   261,
     152,   480,   152,  1505,  1307,   293,   294,   119,   152,   297,
     489,   102,   491,   151,   333,   147,   304,   496,   306,   307,
     293,   251,   156,    83,  1519,  1462,   118,   119,    88,     6,
       7,   304,  1044,   152,   146,   147,   294,   325,  1221,  1541,
    1542,    37,   394,   331,   156,    27,   119,     5,   146,   147,
     119,   153,  1477,   155,    62,   146,   147,  1230,   156,    27,
       6,     7,     7,  1565,    30,    81,    11,  1186,     7,    15,
     146,   147,   391,   146,   147,   533,     6,     7,  1251,     1,
      88,   147,     1,   156,     6,     7,  1511,     6,     7,    11,
     156,    73,     7,  1065,    30,   632,    53,     3,     4,     5,
       6,     7,   448,   455,    62,    73,    36,     6,     7,   790,
     398,   107,    57,   790,    25,    81,    46,   575,   576,   577,
     578,  1546,     8,   214,    63,   413,   414,   415,    14,     7,
     790,   790,   223,    63,   422,    57,   152,    83,     1,     6,
       7,   232,   119,    49,  1520,    81,    52,    33,    63,   422,
     803,   147,  1184,    16,    34,   413,  1329,    27,   149,    70,
     448,   152,   450,   223,    63,   502,   148,   149,    79,     7,
     502,    34,   400,   119,   404,    63,   502,    63,    64,   270,
     148,   149,   502,   535,   502,   664,    66,   539,   502,   119,
     448,   502,   480,   502,  1057,   876,    63,   119,   831,   876,
     119,   147,    82,    73,    60,   633,   525,    24,   687,  1585,
     498,    53,   531,   119,    31,    78,   146,   147,   148,   149,
     119,    59,   108,   539,    87,    37,   514,   655,    16,   977,
     518,   658,   539,   585,     6,     7,   156,   328,    55,    11,
     498,   147,   333,   780,    24,    27,    34,   146,   147,    42,
    1183,    31,   119,   790,   758,    67,    30,    63,   146,   147,
     764,   147,     3,     4,     5,     6,     7,     7,   156,     6,
       7,    44,     6,     7,   130,    55,   506,    11,    15,   146,
     147,   148,   149,  1466,  1467,    22,    21,   745,   746,   349,
      78,    73,    42,   751,   752,   107,   152,   107,    37,    87,
     156,   118,   147,   394,    27,    78,   130,    81,    49,   400,
       7,    52,    42,     3,     4,     5,     6,     7,   606,    59,
    1068,    60,     7,    57,    40,   669,   150,   100,  1224,  1225,
      65,  1227,  1228,    30,   394,   395,    30,   147,   118,   876,
     146,   147,    58,    80,     7,    30,    83,   119,   606,    60,
      73,  1363,   134,   135,   136,   446,    30,   645,   449,    49,
      12,    24,    52,   454,   455,   792,    30,  1044,   149,     1,
     658,   152,   645,   831,   802,     7,   146,   147,   119,   667,
      44,   669,   119,   735,    30,   119,   477,    19,   479,   480,
     818,   161,   452,   453,   667,   455,    48,    30,   489,    51,
     491,   689,   143,   144,    56,   496,   147,     6,     7,    13,
     147,   134,   135,   136,    78,   138,   139,   140,   141,   735,
      24,   147,   145,   146,   147,   485,    42,    31,   519,   119,
     156,   689,    84,   156,   525,     7,   100,   916,    90,   156,
      44,    13,    30,   160,   535,   135,   136,    42,   539,    74,
       7,    23,   512,   143,   144,    59,    13,   147,    16,    31,
      49,   521,     6,     7,   154,     1,    34,    11,    30,    74,
     149,     7,    30,   152,    78,   535,   536,    35,    46,   539,
     105,   908,   152,   148,   149,   110,   156,     1,  1121,     3,
       4,     5,     6,     7,   585,   152,   100,  1121,    66,   104,
     105,    20,   152,    61,   792,   110,   985,  1044,   987,   146,
     147,   146,   147,    57,    82,   146,   147,  1392,   838,   156,
      78,    40,    41,   614,   868,   585,    45,    85,    86,   148,
     161,   148,   149,   152,   838,    49,   146,   147,    52,    58,
     147,   632,   838,   146,   147,   636,   156,   149,  1235,   152,
     152,   642,   643,     4,   842,     6,     7,    79,     1,  1221,
      11,  1065,     1,     6,     7,   146,   147,  1463,     7,     1,
       1,   152,    15,   664,   920,     7,     7,   148,    30,   152,
     868,   152,    34,   871,   872,    28,    29,    30,   876,   150,
     156,   879,   325,    35,   160,   156,   687,  1230,   331,   148,
    1496,   149,   148,   152,   152,   119,   152,   121,   838,   138,
     139,   140,   141,   138,   139,   140,   141,    30,  1251,    62,
     908,   135,   136,   156,    47,   158,   159,   718,   149,   143,
     144,   152,   920,   147,     6,     7,    13,   925,    81,     4,
      83,  1537,     7,   157,   735,    88,    49,   153,  1335,   709,
     156,   152,     1,   149,   991,    42,   152,   149,  1320,   991,
     152,   980,   920,  1121,    42,   991,   954,    16,   156,   957,
      19,   991,   149,   991,   151,   735,   119,   991,   148,   149,
     991,    30,   991,   151,   149,   149,    35,   152,   152,   780,
     134,   135,   136,   149,   754,   151,  1329,    20,    21,   790,
     988,   149,    79,   151,   147,   145,    20,    21,   149,    30,
     151,   771,    61,   151,   149,   988,   151,   153,   778,   149,
     148,   151,    36,   148,   149,   102,   786,   148,    42,    78,
     821,  1019,    46,  1021,   153,  1023,    85,    86,   100,   149,
     831,   151,   833,   149,   804,   151,   148,   807,   152,   809,
      42,    65,   148,   149,  1091,   148,   149,   148,   149,  1091,
     152,  1019,   151,  1425,   149,  1091,    42,  1454,   151,   146,
     147,  1091,  1230,  1091,   148,   149,   152,  1091,    28,    29,
    1091,    42,  1091,   843,   152,   876,   152,  1449,   879,    53,
    1218,    28,    29,  1251,  1138,   253,   254,    30,   151,   890,
     891,   152,  1146,   147,   152,    19,   120,   152,   148,   152,
    1098,   152,   145,   149,  1102,    35,   907,   156,   156,   156,
    1108,   153,   147,    25,   152,   916,  1363,   887,    79,    42,
     152,    33,    30,    35,   148,   149,   150,   214,   152,   130,
     151,  1129,    37,   149,    47,   152,    30,   152,    60,   940,
    1138,   152,  1140,    49,   147,   232,    34,    59,  1146,    61,
      78,   156,   152,  1342,   120,   145,   155,   927,    70,  1221,
     153,  1329,    42,    75,   152,    42,   160,    79,   938,   152,
      66,    68,    38,    85,    86,    62,    60,    89,  1316,   980,
    1552,   150,    42,   270,   985,    37,   987,   957,    30,    47,
    1188,    67,    37,   152,  1234,   147,    53,   967,  1570,   150,
     153,    76,   147,     1,   152,   161,   152,   148,   978,   148,
     152,   147,    10,  1014,    67,    49,   149,   152,    16,    17,
     151,    62,    69,  1221,    42,    23,   152,    25,    26,   147,
      34,    39,   152,   152,    34,    33,    34,    35,   152,   150,
    1238,   328,   152,  1044,    53,    30,   333,   154,   152,   152,
      67,   152,  1022,    30,    34,  1025,  1254,  1027,  1320,   152,
      67,    59,   147,    61,    42,   130,   152,    81,  1069,   152,
     152,    36,    70,    71,   147,    36,    60,    75,    37,    36,
      78,    79,    30,   152,   152,   152,    42,    85,    86,    87,
    1060,    89,   108,   152,    30,     9,   152,  1295,   152,   148,
      54,  1330,   152,   105,   152,    37,   152,   151,   148,   152,
    1080,   149,  1295,   400,  1084,   148,     1,    81,    47,    47,
      47,    47,  1092,  1321,     1,    36,     3,     4,     5,     6,
       7,   151,    30,   152,    64,   108,  1106,   152,    30,   152,
     152,   152,    81,    81,    77,  1115,   152,    72,    68,    46,
    1348,  1349,     1,    34,  1352,   150,  1396,    28,     7,   446,
    1161,   157,   449,  1425,   162,    60,   149,   454,    30,   148,
      40,    36,    49,   148,    53,    52,    25,    36,    55,    19,
      57,   152,  1152,   152,    33,    76,    35,  1449,   133,    22,
     477,    42,   479,   480,   152,  1165,  1166,  1167,    34,   152,
     152,   152,   489,    81,   491,   152,    30,    30,  1178,   496,
      59,   152,    61,   153,    36,   152,    30,   152,    60,     3,
    1221,    70,  1420,    81,    30,   512,    75,  1197,   152,  1230,
      79,   152,   519,   152,   152,   152,    85,    86,   525,   105,
      89,    30,   119,   152,   121,   152,    81,  1248,    42,    34,
    1251,  1221,     3,     4,     5,     6,     7,    37,   135,   136,
      81,    36,   152,   130,   153,   152,   143,   144,  1466,  1467,
     147,    47,   152,    39,    46,    30,   152,   150,   152,   154,
     152,   150,    81,    47,   152,    81,    60,    47,   152,   152,
    1552,  1489,   152,   149,    30,    36,   153,   152,    49,  1269,
     152,    52,  1272,    36,    55,   152,  1276,    22,  1570,    72,
    1311,    39,    81,  1283,    81,   152,    18,    36,   152,  1320,
     152,   152,  1292,  1293,    81,    22,   152,   614,  1329,  1330,
    1138,     3,   152,   152,  1304,   152,     5,   400,   306,   157,
       5,  1342,   838,   991,   653,   632,  1019,  1545,   450,   636,
    1320,   102,  1060,   178,   105,   642,   643,   808,   539,   887,
     746,   751,  1363,    44,  1562,    10,   214,  1248,   119,   988,
     121,    16,    17,   579,   869,   923,  1574,   664,    23,  1470,
      25,    26,  1413,  1037,   135,   136,  1314,  1327,    33,    34,
      35,  1361,   143,   144,  1309,  1104,   147,  1367,  1079,  1334,
     687,  1371,   632,   154,  1392,  1161,  1289,  1044,  1378,  1490,
    1044,    62,  1182,   879,    59,  1146,    61,  1008,  1351,  1132,
     992,   597,   404,  1223,  1425,    70,    71,  1585,  1481,  1488,
      75,   718,  1525,    78,    79,  1044,   606,  1191,    26,   201,
      85,    86,    87,    -1,    89,     1,    -1,    -1,  1449,    -1,
       6,     7,    -1,    -1,    -1,  1425,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
    1440,    -1,    28,    29,    30,  1445,    32,    -1,    34,  1449,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,   780,    50,    -1,    52,  1467,    -1,    -1,
      -1,    -1,    -1,   790,    -1,    -1,    -1,    -1,  1478,    -1,
      66,    67,  1482,  1483,    -1,  1485,    -1,   162,    -1,    -1,
      -1,  1491,    -1,    -1,    80,    -1,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,   821,    -1,    -1,    10,    -1,  1509,
      -1,    -1,    -1,    16,    17,    -1,   833,    -1,    -1,    -1,
      23,  1552,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,   119,  1534,    -1,    -1,    -1,    -1,  1570,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1548,    -1,
      -1,    -1,  1552,    -1,    -1,  1555,    59,    -1,    61,   876,
      -1,   147,   879,    -1,    -1,    -1,    -1,    70,    71,    -1,
    1570,    -1,    75,   890,   891,    78,    79,    -1,    -1,    -1,
      -1,  1581,    85,    86,    87,    10,    89,    -1,    -1,    -1,
     907,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,   916,
      25,    26,    -1,    -1,    -1,    -1,    10,    -1,    33,    34,
      35,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    23,
      -1,    25,    26,   940,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    -1,    -1,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    59,    -1,    61,    -1,   162,
      85,    86,    87,   980,    89,    -1,    70,    71,   985,    -1,
     987,    75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      -1,    85,    86,    87,     1,    89,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,     1,    -1,  1014,    -1,    -1,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    18,    -1,    -1,    -1,    22,    23,    24,     3,
       4,     5,     6,     7,    -1,    31,    -1,  1044,    34,    -1,
      -1,    -1,    49,    39,    -1,    52,    -1,   162,    -1,    -1,
      -1,    -1,    -1,  1060,     1,    -1,     3,     4,     5,     6,
       7,    -1,  1069,    -1,    -1,    -1,    62,    74,   162,     3,
       4,     5,     6,     7,    -1,    49,    -1,    -1,    52,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      97,    -1,    88,    -1,    -1,    -1,    -1,   104,   105,    -1,
      -1,    -1,    49,   110,   111,    52,     3,     4,     5,     6,
       7,    -1,   119,    -1,   121,    49,    -1,    -1,    52,    -1,
      -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,   135,   136,
      -1,   105,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
     147,    -1,    -1,    -1,    -1,   119,    -1,   121,    -1,    -1,
      -1,   147,    49,    -1,  1161,    52,    -1,    -1,    -1,    -1,
      57,   135,   136,    97,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,   119,   147,   121,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,   119,    -1,   121,   135,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
     147,   135,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,    -1,   147,     3,     4,     5,     6,     7,    -1,
      -1,    -1,   119,    49,   121,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,   136,
      -1,  1248,    -1,    -1,    -1,    -1,   143,   144,    -1,    -1,
     147,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    15,    -1,    52,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      34,    -1,    -1,    -1,    -1,    39,    -1,    -1,    12,    -1,
      -1,    -1,    46,   119,    -1,   121,    50,    -1,    52,    -1,
      -1,    -1,    -1,    -1,  1311,    -1,    -1,    -1,    -1,   135,
     136,    -1,    66,    67,    -1,    -1,    -1,   143,   144,    -1,
      -1,   147,    -1,  1330,    48,    -1,    80,    51,    82,    83,
     119,    -1,    56,    -1,    -1,  1342,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   135,   136,    -1,    -1,
      -1,    -1,    -1,    -1,   143,   144,  1363,    -1,   147,    -1,
      84,    -1,    -1,    -1,    -1,   119,    90,    91,    92,    93,
      94,    95,    96,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,    -1,   138,
     139,   140,   141,   147,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,     1,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    24,    25,    13,    -1,
      -1,    -1,    -1,    31,    -1,    33,    -1,    35,    23,    24,
      25,    -1,    -1,    -1,    -1,    43,    31,    -1,    33,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,
      -1,    59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    59,    -1,    61,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    70,    71,    -1,    -1,    87,
      75,    76,    -1,    -1,    79,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    10,   106,    -1,
      -1,   109,    -1,    16,    17,    -1,   114,    -1,    -1,    -1,
      -1,   106,    25,    26,   109,    -1,    -1,    30,    -1,   114,
      33,    -1,    35,    -1,    37,    -1,    -1,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    59,    60,    61,    23,
      -1,    25,    26,    -1,    -1,    -1,    30,    70,    71,    33,
       1,    35,    75,    37,    -1,    78,    79,    -1,    -1,    10,
      -1,    -1,    85,    86,    87,    16,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    59,    -1,    61,    -1,    30,
      -1,    -1,    33,     1,    35,    -1,    70,    71,    -1,    -1,
      -1,    75,    10,    -1,    78,    79,    -1,    -1,    16,    17,
      -1,    85,    86,    87,    -1,    89,    -1,    25,    59,    -1,
      61,    -1,    -1,    -1,    -1,    33,     1,    35,    -1,    -1,
      71,    -1,    -1,    -1,    75,    10,    -1,    78,    79,    -1,
      -1,    16,    -1,    -1,    85,    86,    87,    -1,    89,    -1,
      25,    59,    -1,    61,    -1,    30,    -1,    -1,    33,    -1,
      35,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    -1,    10,    -1,    -1,    85,    86,    87,
      16,    89,    -1,    -1,    59,    -1,    61,    23,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    71,    33,    -1,    35,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    10,    89,    -1,    -1,    -1,    -1,    16,
      17,    -1,    -1,    59,    -1,    61,    -1,    -1,    25,    26,
      -1,    -1,    -1,    -1,    70,    71,    33,    -1,    35,    75,
      -1,    -1,    78,    79,    -1,    -1,    10,    -1,    -1,    85,
      86,    87,    16,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    59,    -1,    61,    -1,    30,    -1,    -1,    33,
      -1,    35,    -1,    70,    71,    -1,    -1,    -1,    75,    10,
      -1,    78,    79,    -1,    -1,    16,    17,    -1,    85,    86,
      87,    -1,    89,    -1,    25,    59,    -1,    61,    -1,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    71,    -1,    -1,
      -1,    75,    10,    -1,    78,    79,    -1,    -1,    16,    -1,
      -1,    85,    86,    87,    -1,    89,    -1,    25,    59,    -1,
      61,    -1,    30,    -1,    -1,    33,    -1,    35,    -1,    -1,
      71,    -1,    -1,    -1,    75,    10,    -1,    78,    79,    -1,
      -1,    16,    17,    -1,    85,    86,    87,    -1,    89,    -1,
      25,    59,    -1,    61,    -1,    -1,    -1,    -1,    33,    -1,
      35,    -1,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    79,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      -1,    89,    -1,    -1,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    -1,
      85,    86,    87,    -1,    89,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,    -1,    -1,    -1,
      -1,    -1,    -1,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,    -1,   138,
     139,   140,   141
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   164,   165,   166,   174,   175,     0,   174,    13,    24,
      31,    44,    59,    78,   100,   176,   177,   178,   179,   181,
     182,   191,   192,   196,   198,   202,   203,   208,   209,   507,
     512,     7,   491,   491,   491,   173,   491,     1,    19,   491,
       6,   119,   180,   268,   269,   270,   271,   273,   275,   491,
     493,   551,   491,     1,    37,   189,     1,   194,     1,   200,
       1,    37,   205,   207,   549,     1,   211,    53,    53,    42,
     149,   152,   491,   491,    42,    25,    70,    79,   552,   149,
     152,   156,   146,   147,   251,   274,   251,   274,   147,    42,
      30,   460,     1,   190,    60,   187,    30,    10,    16,    17,
      23,    25,    26,    33,    34,    35,    61,    70,    71,    75,
      79,    85,    86,    87,    89,   162,   179,   195,   202,   208,
     213,   214,   216,   223,   224,   225,   235,   287,   311,   324,
     326,   329,   333,   336,   339,   343,   344,   462,   475,   485,
     486,   512,   513,   560,    30,    16,    34,    78,    87,   179,
     201,   222,   344,   465,   485,    30,   550,    30,    59,   202,
     206,   214,   218,   225,   326,   329,   339,   343,   344,   462,
     485,   486,   512,   513,    37,   152,   548,    30,    30,   212,
     213,   214,   219,   235,   329,   343,   344,   485,   486,   491,
     491,   491,    42,    42,    49,   156,   158,   159,   553,   554,
     555,   556,   559,   271,     4,    11,   167,   272,   491,   493,
     495,     1,     3,     5,    49,    52,    55,    57,   121,   135,
     136,   143,   144,   147,   168,   172,   255,   258,   260,   261,
     267,   268,   270,   271,   276,   277,   278,   279,   286,   314,
     321,   492,   494,   495,    63,   491,    63,   491,   258,   270,
      30,   508,    13,    23,    31,   491,   152,   152,   147,   239,
     188,   185,    13,   193,   491,   334,   491,   493,   491,   359,
     360,   491,   173,    11,    57,   268,   340,   173,    11,    57,
     173,   477,   478,   167,   491,   491,   173,     1,   491,     1,
     491,   173,   491,    79,    35,    42,   152,    24,   199,   491,
     491,     1,   268,   470,   118,   491,    30,    59,   204,   491,
     239,   204,    47,   152,    59,   210,   491,   210,    42,    42,
      49,   373,   491,   491,   557,   558,   373,   156,   151,   159,
     491,   558,   148,   270,   278,   148,   267,   267,   267,   267,
     267,   258,   282,   283,   286,   321,   252,    27,    73,   323,
      12,    48,    51,    56,    84,    90,    12,    48,    51,    56,
      84,    90,    91,    92,    93,    94,    95,    96,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   138,   139,   140,   141,   259,   145,    63,
     146,   270,   316,   148,   149,   153,   491,   148,   100,   509,
     100,   178,   179,   506,   510,   511,   183,   491,   183,   183,
       1,    25,    33,    35,    59,    61,    70,    75,    79,    89,
     223,   242,   246,   331,   540,   541,   542,   547,   152,   239,
      17,   184,   186,   213,   214,   215,   235,   326,   329,   339,
     343,   344,   485,   486,   491,   152,   151,   335,    53,   151,
      30,     1,    15,    83,    88,   147,   268,   276,   361,   362,
     363,   377,   381,   382,   383,   384,   392,   396,   402,   408,
     409,   412,   425,   449,   491,    42,   461,   151,   341,   151,
     151,    37,    78,   476,   481,   151,   228,    42,   226,   151,
     152,    42,   152,     1,    42,   288,   151,    42,   151,   173,
     167,     1,   237,   491,   152,    30,   468,   173,   199,   491,
     152,   152,   147,   248,    19,   152,   152,   152,   156,   160,
     514,   147,   156,   491,   557,   270,   312,   314,   156,   491,
     251,   270,   280,   145,   148,   149,   153,   284,   148,   149,
     253,   258,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   267,   135,   136,   143,   144,   262,
     264,   266,   267,   275,   322,   147,   276,   251,   315,   316,
     258,   282,   283,   258,   491,   152,   180,    30,   511,   148,
     491,   493,   543,   491,   491,    79,    35,   240,   173,   491,
     152,   359,   460,   312,    42,    11,    57,   167,   345,   346,
     270,   193,    30,   258,   258,   384,   396,   425,   449,   152,
     130,   410,   151,    37,   464,   312,   149,   342,   270,   312,
     491,    47,    24,    31,    55,   118,   479,   482,   152,    60,
     480,   258,   107,   229,   230,   232,   233,   549,    49,   233,
     234,   312,   312,   152,     8,    14,    33,    64,   108,   147,
     289,   290,   293,   299,   303,   305,   309,   310,   316,   496,
     501,   152,   312,   147,   490,   491,   493,   151,   227,    30,
      17,   213,   214,   220,   235,   238,   329,   343,   344,   485,
     486,    34,   179,   466,   469,   152,   152,    55,   102,   105,
     154,   254,   256,   257,   258,   268,   491,   491,    67,   161,
     270,   515,   516,   152,   548,   258,   156,   251,   313,   120,
     251,   281,   267,   282,   258,   155,   285,   255,   264,   264,
     267,   267,   134,   135,   136,   263,   323,   138,   139,   140,
     141,   265,   145,   258,   153,   152,   509,   107,   147,   545,
      42,   545,   543,   148,   152,   241,   151,   152,     1,   268,
     347,    42,   514,   152,   152,    88,   411,   412,    66,   427,
      68,    38,   393,   395,    62,    18,    22,    23,    24,    31,
      88,   268,   376,   384,   396,   403,   405,   409,   425,   449,
     518,   239,    60,   463,   150,   325,   268,     9,    42,    55,
     337,   248,   270,   268,   173,   481,    30,    47,   231,   230,
     239,    67,   548,     1,   373,    21,    65,   328,   332,   152,
     312,   147,   317,    53,   173,   308,     1,    19,   497,   169,
     491,   495,    76,   150,   330,     1,    13,    23,    24,    25,
      31,    33,    35,    43,    59,    61,    70,    71,    75,    76,
      79,    87,   106,   109,   114,   349,   487,   489,   147,   312,
     233,    35,    61,   167,   236,   420,   421,   152,    30,    34,
     465,   467,   471,   472,   197,   258,   249,   153,   270,   161,
      67,   149,   517,   152,   148,   148,   258,   286,   264,   262,
     266,   267,   148,   258,   152,   546,   242,    67,    49,   545,
     242,    20,    40,    41,    45,    58,   245,   247,   152,   514,
     149,   348,   258,   151,   152,    62,   258,    69,   426,   268,
     392,    97,   258,   385,   386,   389,    74,   105,   110,   394,
     147,   416,    42,   372,     1,   258,   384,   396,   425,   449,
     378,   379,   373,   374,    34,   355,   357,    39,   350,   351,
     152,   239,   460,   258,   152,   258,   247,   338,   258,   152,
     152,   480,    34,   248,   239,   270,   152,   514,   150,   327,
     270,   302,   312,   320,   322,    53,   270,   151,   306,    30,
       1,   502,    30,   179,   224,   344,   498,   500,   513,   291,
     297,   491,   258,   152,   152,   154,   488,   148,   149,   483,
     484,   491,   495,   330,    67,     6,   491,   491,   152,    30,
      22,    32,    39,    50,    52,    67,    80,    83,   392,   422,
     423,   424,   425,   430,   434,   437,   441,   444,   445,   448,
     449,   450,   452,   453,   454,   455,   456,   491,   522,   523,
     525,   526,   527,   531,   534,   536,    34,   477,   491,   148,
     149,   250,   257,   270,   270,   147,   240,   270,   373,    67,
     312,   152,   167,   152,   349,   413,   491,   258,   152,   130,
       9,    52,   390,   152,    81,   387,   258,    11,   268,   417,
      42,   414,   147,   371,    36,    36,    37,    60,   147,   375,
      37,    60,   454,   491,    36,   258,   454,   491,    30,   404,
     407,   152,   152,   152,   258,    42,   152,   152,   548,   258,
     152,    63,   300,   318,   312,   312,    30,   307,   308,   108,
     499,    30,    30,   220,   503,   505,   499,   148,   149,   292,
     295,   152,   148,   152,   487,   148,   149,   152,   270,   236,
       1,   157,   428,   436,   491,   258,   447,   491,   152,   258,
     451,    54,   459,   258,   130,   150,    66,    82,   356,   357,
     358,   443,    22,   392,   425,   452,   456,   536,    81,   152,
     151,   152,    78,   474,   481,   254,   242,   148,    42,   544,
     548,   270,    20,    21,   244,   393,   258,     9,   391,   258,
     149,   388,   105,   148,   418,   148,    17,   213,   214,   221,
     235,   329,   343,   344,   415,   485,   486,   258,    37,   369,
       1,    81,   519,   520,    47,    47,   491,    47,    47,   491,
      40,   151,    17,   216,   217,   400,    36,   258,    36,   152,
     406,   491,    30,   152,   258,   152,   154,   148,   149,   301,
     148,   149,   319,   152,    64,   491,   108,   504,   504,   169,
      30,   296,   298,   491,   152,   483,   152,    30,   258,    81,
     435,    72,    81,   446,   152,   417,    77,   458,    68,     1,
      74,   104,   105,   110,   111,   386,   389,   533,   258,   258,
     258,    46,   428,   150,   258,   118,   479,   465,   473,   480,
     240,   154,   491,   544,   150,   243,   397,   398,   258,    28,
     389,   149,   419,   420,   148,   239,    60,   367,    30,   283,
     454,    30,   519,   521,   248,   248,   148,   248,   248,    40,
     270,   320,    17,   216,   359,   400,   401,    36,   491,   152,
     152,   406,    53,   270,   302,   320,   304,   491,    19,    76,
     294,   133,    22,    42,   258,   152,     1,   420,   258,   152,
     258,    34,   457,   428,   152,    40,    58,   532,   258,   532,
     152,    81,   386,   389,   426,   420,   258,   258,    28,   152,
     535,   173,   152,    30,   152,   148,   258,   152,   386,   399,
     385,   268,    30,   372,   152,   239,   365,    36,   153,   283,
      36,   152,   491,    30,    60,   380,   152,   380,   152,   320,
     404,   359,   353,   401,   152,   312,    63,   491,   491,   170,
     171,   494,   157,   429,   491,    81,   433,    30,   439,   258,
     152,   268,   276,   392,   539,   258,   105,   152,   258,   152,
      81,   152,    30,    42,   258,    28,   152,   152,    34,    81,
     411,    37,   370,   152,    17,   216,   366,   406,   401,   153,
     406,   152,    36,    47,   152,   152,    28,    29,   352,   354,
     353,   152,   491,   152,   283,   431,    39,    28,    29,   438,
     440,   130,   150,    81,   152,    28,   152,   524,   258,    46,
     433,    81,   258,   152,   283,   152,    47,    60,   368,   359,
     152,   401,   152,   406,   248,    36,   454,   491,   258,   454,
     352,   153,    30,   432,   433,   152,   420,   258,    30,   104,
     528,   533,   258,   537,   538,   258,   258,   152,   152,   524,
     442,   491,   431,   258,    81,   149,   248,    47,    30,   152,
     401,    36,    36,   258,   420,    22,    72,    39,   532,   389,
     529,   530,    81,   152,   535,    81,   152,   152,    30,   258,
     152,   248,    18,   401,   401,    36,   429,   420,   152,   537,
      81,   283,   152,   258,    22,   152,   364,   491,   401,   152,
     283,   149,   152,   429,   152,   149,   152,   537,   152,   529
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;


  /* User initialization code.  */

{ yydebug=0; }
/* Line 1078 of yacc.c.  */

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 7:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 8:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 9:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 10:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 11:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 12:

    { (yyval.qstr)="null"; ;}
    break;

  case 13:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 14:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 15:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 16:

    { (yyval.qstr)=""; ;}
    break;

  case 17:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 18:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 19:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 20:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+","+(yyvsp[(3) - (3)].qstr);}
    break;

  case 33:

    {
                   if ( parse_sec == 0)
                   {
                    addVhdlType((yyvsp[(2) - (3)].qstr),getParsedLine(t_LIBRARY),Entry::VARIABLE_SEC,VhdlDocGen::LIBRARY,(yyvsp[(2) - (3)].qstr).data(),"_library_");
                   }
                   (yyval.qstr)="library "+(yyvsp[(2) - (3)].qstr);
                 ;}
    break;

  case 34:

    {
                   QStringList ql1=QStringList::split(",",(yyvsp[(2) - (3)].qstr),FALSE);
                   for (uint j=0;j<ql1.count();j++)
                   {
                     QStringList ql=QStringList::split(".",ql1[j],FALSE);
                     QCString it=ql[1].utf8();
                     if ( parse_sec == 0 )
                     {
                       addVhdlType(it,getParsedLine(t_USE),Entry::VARIABLE_SEC,VhdlDocGen::USE,it.data(),"_use_");
                     }
                   }
                   (yyval.qstr)="use "+(yyvsp[(2) - (3)].qstr);
                 ;}
    break;

  case 35:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 36:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+","+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 39:

    {
                (yyval.qstr)=(yyvsp[(2) - (3)].qstr);
                lastEntity=current;
                lastCompound=0;
                /*int k=*/ getParsedLine(t_ENTITY);
                addVhdlType((yyval.qstr),getParsedLine(t_ENTITY),Entry::CLASS_SEC,VhdlDocGen::ENTITY,0,0,Public);
                //fprintf(stderr,"\n entiy %s : at line %d",$$.data(),s_str.yyLineNr);
              ;}
    break;

  case 47:

    { (yyval.qstr)=""; ;}
    break;

  case 48:

    { currP=VhdlDocGen::PORT; ;}
    break;

  case 49:

    { currP=0; ;}
    break;

  case 50:

    { (yyval.qstr)=""; ;}
    break;

  case 51:

    { currP=VhdlDocGen::GENERIC;parse_sec=GEN_SEC;}
    break;

  case 52:

    { currP=0;parse_sec=0; ;}
    break;

  case 53:

    { currP=0; ;}
    break;

  case 56:

    {
                  (yyval.qstr)=(yyvsp[(4) - (5)].qstr);
                  (yyval.qstr)+="::";
                  (yyval.qstr)+=(yyvsp[(2) - (5)].qstr);
                  pushLabel((yyvsp[(2) - (5)].qstr));
                  lastCompound=current;
                  addVhdlType((yyval.qstr),getParsedLine(t_ARCHITECTURE),Entry::CLASS_SEC,VhdlDocGen::ARCHITECTURE,0,0,Private);
                ;}
    break;

  case 61:

    { (yyval.qstr)=""; ;}
    break;

  case 64:

    { genLabels.resize(0); ;}
    break;

  case 65:

    { genLabels.resize(0); ;}
    break;

  case 66:

    {
                  confName="";
                ;}
    break;

  case 67:

    {
                  confName=(yyvsp[(2) - (5)].qstr)+"::"+(yyvsp[(4) - (5)].qstr);
                  addVhdlType((yyvsp[(2) - (5)].qstr).data(),getParsedLine(t_CONFIGURATION),Entry::VARIABLE_SEC,VhdlDocGen::CONFIG,"configuration",(yyvsp[(4) - (5)].qstr).data());
                ;}
    break;

  case 68:

    { (yyval.qstr)=""; ;}
    break;

  case 69:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 70:

    { (yyval.qstr)="configuration"; ;}
    break;

  case 71:

    { (yyval.qstr)=(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 72:

    { (yyval.qstr)=""; ;}
    break;

  case 73:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 74:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 77:

    {
                          lastCompound=current;


         Entry *clone=new Entry(*current);
         clone->section=Entry::NAMESPACE_SEC;
         clone->spec=VhdlDocGen::PACKAGE;
           clone->name=(yyvsp[(2) - (3)].qstr);
           int line=s_str.iLine;
         clone->startLine=line;
           clone->bodyLine=line;

         clone->protection=Package;
             current_root->addSubEntry(clone);


                        addVhdlType((yyvsp[(2) - (3)].qstr),line,Entry::CLASS_SEC,VhdlDocGen::PACKAGE,0,0,Package);
                        //fprintf(stderr,"\n entiy %s : at line %d",$$.data(),s_str.yyLineNr);
                       ;}
    break;

  case 79:

    { lastCompound=0; ;}
    break;

  case 80:

    { lastCompound=0; ;}
    break;

  case 81:

    { lastCompound=0; ;}
    break;

  case 92:

    {
                        (yyval.qstr)=(yyvsp[(3) - (4)].qstr);
                        lastCompound=current;
                        (yyval.qstr).prepend("_");
                        addVhdlType((yyval.qstr),getParsedLine(t_PACKAGE) ,Entry::CLASS_SEC,VhdlDocGen::PACKAGE_BODY,0,0,Protected);
                      ;}
    break;

  case 93:

    { (yyval.qstr)="";lastCompound=0; ;}
    break;

  case 94:

    { lastCompound=0; ;}
    break;

  case 95:

    { lastCompound=0; ;}
    break;

  case 96:

    { lastCompound=0; ;}
    break;

  case 97:

    { (yyval.qstr)=""; ;}
    break;

  case 172:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 173:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 174:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 175:

    { (yyval.qstr)=(yyvsp[(3) - (4)].qstr); ;}
    break;

  case 176:

    { (yyval.qstr)="pure"; ;}
    break;

  case 177:

    { (yyval.qstr)="impure"; ;}
    break;

  case 178:

    { currP=0; ;}
    break;

  case 179:

    { currP=VhdlDocGen::PROCEDURE; createFunction((yyvsp[(2) - (2)].qstr),currP,0); ;}
    break;

  case 180:

    {  newEntry(); ;}
    break;

  case 181:

    {
                currP=VhdlDocGen::FUNCTION;
                createFunction((yyvsp[(1) - (3)].qstr),currP,(yyvsp[(3) - (3)].qstr).data());
              ;}
    break;

  case 182:

    {
                tempEntry=current;
                current->type=(yyvsp[(7) - (7)].qstr);
                newEntry();
              ;}
    break;

  case 183:

    {
                currP=VhdlDocGen::FUNCTION;
                createFunction(0,currP,(yyvsp[(2) - (2)].qstr).data());
              ;}
    break;

  case 184:

    {
                tempEntry=current;
                current->type=(yyvsp[(6) - (6)].qstr);
                newEntry();
              ;}
    break;

  case 187:

    { param_sec=PARAM_SEC; ;}
    break;

  case 188:

    { param_sec= 0; ;}
    break;

  case 189:

    { param_sec=PARAM_SEC; ;}
    break;

  case 190:

    { param_sec= 0; ;}
    break;

  case 196:

    {
      currP=0;
    ;}
    break;

  case 197:

    {
      currP=0;
    ;}
    break;

  case 208:

    { (yyval.qstr)=""; ;}
    break;

  case 209:

    { (yyval.qstr)=""; ;}
    break;

  case 213:

    {
                    // adding generic :  [ package foo  is new bar]
                    if (parse_sec==GEN_SEC)
                    {
                      QCString n=current->name;
                      addVhdlType(n.data(),getParsedLine(t_PACKAGE),Entry::VARIABLE_SEC,VhdlDocGen::GENERIC,(yyvsp[(1) - (1)].qstr).data(),0);
                    }
                  ;}
    break;

  case 214:

    {
                    if (parse_sec==GEN_SEC)
                    {
                      int a=getParsedLine(t_FUNCTION);
                      int b=getParsedLine(t_PROCEDURE);

                      if (a>b) b=a;

                      QCString n=current->name;
                      addVhdlType(n.data(),b,Entry::VARIABLE_SEC,VhdlDocGen::GENERIC,(yyvsp[(1) - (1)].qstr).data(),0);
                    }
                  ;}
    break;

  case 215:

    {
                    if (parse_sec==GEN_SEC)
                    {
                      QCString v= (yyvsp[(1) - (2)].qstr);
                      addVhdlType((yyvsp[(2) - (2)].qstr),s_str.iLine,Entry::VARIABLE_SEC,currP,(yyvsp[(1) - (2)].qstr).data(),0);
                    }
                  ;}
    break;

  case 216:

    {
                    QCString b=(yyvsp[(2) - (7)].qstr);
                    (yyval.qstr)=(yyvsp[(2) - (7)].qstr)+":"+(yyvsp[(4) - (7)].qstr)+(yyvsp[(5) - (7)].qstr)+(yyvsp[(6) - (7)].qstr)+(yyvsp[(7) - (7)].qstr);
                    if (currP!=VhdlDocGen::COMPONENT)
                    {
                      if (currP==VhdlDocGen::FUNCTION || currP==VhdlDocGen::PROCEDURE)
                      {
                        addProto((yyvsp[(1) - (7)].qstr).data(),(yyvsp[(2) - (7)].qstr).data(),(yyvsp[(4) - (7)].qstr).data(),(yyvsp[(5) - (7)].qstr).data(),(yyvsp[(6) - (7)].qstr).data(),(yyvsp[(7) - (7)].qstr).data());
                      }
                      else
                      {
                        QCString i=(yyvsp[(5) - (7)].qstr)+(yyvsp[(6) - (7)].qstr)+(yyvsp[(7) - (7)].qstr);
                        if (currP==VhdlDocGen::GENERIC)
                          addVhdlType((yyvsp[(2) - (7)].qstr),s_str.iLine,Entry::VARIABLE_SEC,currP,i.data(),(yyvsp[(4) - (7)].qstr).data());
                        else if(parse_sec != GEN_SEC)
                          addVhdlType((yyvsp[(2) - (7)].qstr),s_str.iLine,Entry::VARIABLE_SEC,currP,i.data(),(yyvsp[(4) - (7)].qstr).data());
                      }
                      //   fprintf(stderr,"\n\n <<port  %s  >>\n",$$.data());
                    } // if component
                  ;}
    break;

  case 217:

    { (yyval.qstr)=""; ;}
    break;

  case 218:

    { (yyval.qstr)=":="+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 219:

    { (yyval.qstr)=""; ;}
    break;

  case 220:

    { (yyval.qstr)="buffer"; ;}
    break;

  case 221:

    { (yyval.qstr)="bus"; ;}
    break;

  case 222:

    { (yyval.qstr)=""; ;}
    break;

  case 223:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 224:

    { (yyval.qstr)=""; ;}
    break;

  case 225:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 226:

    { (yyval.qstr)="in"; ;}
    break;

  case 227:

    { (yyval.qstr)="out"; ;}
    break;

  case 228:

    { (yyval.qstr)="inout"; ;}
    break;

  case 229:

    { (yyval.qstr)="buffer"; ;}
    break;

  case 230:

    { (yyval.qstr)="link"; ;}
    break;

  case 231:

    { (yyval.qstr)="("+(yyvsp[(2) - (4)].qstr)+")"; ;}
    break;

  case 232:

    { (yyval.qstr)=""; ;}
    break;

  case 233:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 234:

    { (yyval.qstr)=", "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 235:

    {
      QCString str="( "+(yyvsp[(2) - (4)].qstr);
      str.append(" )");
      (yyval.qstr)=str;
    ;}
    break;

  case 236:

    { (yyval.qstr)=""; ;}
    break;

  case 237:

    { (yyval.qstr)=" ( open ) "; ;}
    break;

  case 238:

    { (yyval.qstr)=""; ;}
    break;

  case 239:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+"?? "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 240:

    { (yyval.qstr)=","+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 241:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"=>"+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 242:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 243:

    { (yyval.qstr)="<>"; ;}
    break;

  case 244:

    { (yyval.qstr)="default"; ;}
    break;

  case 245:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 247:

    {  (yyval.qstr)=(yyvsp[(1) - (1)].qstr) ; ;}
    break;

  case 248:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 249:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 250:

    { (yyval.qstr)="open"; ;}
    break;

  case 251:

    { (yyval.qstr)="inertial"; ;}
    break;

  case 252:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 253:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 273:

    { (yyval.qstr)=" ?? "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 274:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 275:

    { (yyval.qstr)="+"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 276:

    { (yyval.qstr)="-"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 277:

    { (yyval.qstr)="abs"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 278:

    { (yyval.qstr)="not "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 279:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ** "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 280:

    { (yyval.qstr)=(yyvsp[(2) - (4)].qstr)+" ** "+(yyvsp[(4) - (4)].qstr); ;}
    break;

  case 281:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" mod  "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 282:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" rem "+(yyvsp[(3) - (3)].qstr);  ;}
    break;

  case 283:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" & "+(yyvsp[(3) - (3)].qstr);    ;}
    break;

  case 284:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" * "+(yyvsp[(3) - (3)].qstr);    ;}
    break;

  case 285:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" + "+(yyvsp[(3) - (3)].qstr);    ;}
    break;

  case 286:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" -  "+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 287:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" <= "+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 288:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" >= "+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 289:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" <  "+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 290:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" >  "+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 291:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ==  "+(yyvsp[(3) - (3)].qstr);  ;}
    break;

  case 292:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" != "+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 293:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" /"+(yyvsp[(3) - (3)].qstr);     ;}
    break;

  case 294:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ?/="+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 295:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ?="+(yyvsp[(3) - (3)].qstr);    ;}
    break;

  case 296:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ?<"+(yyvsp[(3) - (3)].qstr);    ;}
    break;

  case 297:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ?>"+(yyvsp[(3) - (3)].qstr);    ;}
    break;

  case 298:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ?<="+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 299:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" ?>="+(yyvsp[(3) - (3)].qstr);   ;}
    break;

  case 300:

    { (yyval.qstr) = "-"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 301:

    { (yyval.qstr) = "+"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 302:

    { (yyval.qstr) = (yyvsp[(1) - (1)].qstr); ;}
    break;

  case 303:

    { (yyval.qstr) = (yyvsp[(1) - (3)].qstr)+" "+(yyvsp[(2) - (3)].qstr)+" "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 304:

    { (yyval.qstr) = "&"; ;}
    break;

  case 305:

    { (yyval.qstr) = "-"; ;}
    break;

  case 306:

    { (yyval.qstr) = "+"; ;}
    break;

  case 307:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 308:

    { (yyval.qstr) = (yyvsp[(1) - (3)].qstr)+" "+(yyvsp[(2) - (3)].qstr)+" "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 309:

    { (yyval.qstr) = "*";   ;}
    break;

  case 310:

    { (yyval.qstr) = "rem"; ;}
    break;

  case 311:

    { (yyval.qstr) = "mod"; ;}
    break;

  case 312:

    { (yyval.qstr) = "/";   ;}
    break;

  case 313:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 314:

    { (yyval.qstr)="abs "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 315:

    { (yyval.qstr)="not  "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 316:

    { (yyval.qstr) = (yyvsp[(1) - (3)].qstr)+" ** "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 317:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 318:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 319:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 320:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 321:

    { (yyval.qstr)=""; ;}
    break;

  case 322:

    { (yyval.qstr)="("+(yyvsp[(2) - (3)].qstr)+")"; ;}
    break;

  case 323:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 324:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 325:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 326:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 327:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 328:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 329:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 330:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 331:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"."+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 332:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 333:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 334:

    { (yyval.qstr)="all"; ;}
    break;

  case 335:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 336:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 337:

    { (yyval.qstr)="'"; ;}
    break;

  case 338:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"' "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 340:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" '"+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 341:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"' range "; ;}
    break;

  case 342:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"' range "; ;}
    break;

  case 343:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" ) "; ;}
    break;

  case 344:

    { (yyval.qstr)="( "+(yyvsp[(2) - (5)].qstr)+ "=>"+(yyvsp[(4) - (5)].qstr)+" ) "; ;}
    break;

  case 345:

    { (yyval.qstr)=" ( "+(yyvsp[(2) - (4)].qstr)+","+(yyvsp[(4) - (4)].qstr); ;}
    break;

  case 346:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+","+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 347:

    { (yyval.qstr)=(yyvsp[(1) - (5)].qstr)+"'("+(yyvsp[(4) - (5)].qstr)+" ) "; ;}
    break;

  case 348:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"'"+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 356:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"=> "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 357:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 358:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 359:

    { (yyval.qstr)="";        ;}
    break;

  case 360:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 361:

    { (yyval.qstr)=" | "+(yyvsp[(2) - (2)].qstr);  ;}
    break;

  case 362:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 363:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 364:

    { (yyval.qstr)="others"; ;}
    break;

  case 365:

    { (yyval.qstr)=""; ;}
    break;

  case 366:

    {
             addVhdlType((yyvsp[(2) - (4)].qstr),getParsedLine(t_TYPE),Entry::VARIABLE_SEC,VhdlDocGen::TYPE,0,(yyvsp[(3) - (4)].qstr).data());
           ;}
    break;

  case 367:

    { (yyval.qstr)=""; ;}
    break;

  case 368:

    { (yyval.qstr)=""; ;}
    break;

  case 369:

    { (yyval.qstr)="is "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 370:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 371:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 372:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 373:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 374:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 375:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 376:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 377:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 378:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 379:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 380:

    { (yyval.qstr)="( "+(yyvsp[(2) - (4)].qstr)+" "+(yyvsp[(3) - (4)].qstr)+" )"; ;}
    break;

  case 381:

    { (yyval.qstr)=""; ;}
    break;

  case 382:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 383:

    { (yyval.qstr)=","+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 384:

    {
                             (yyval.qstr)=(yyvsp[(1) - (6)].qstr);
                             current->args=(yyvsp[(3) - (6)].qstr)+"#"+(yyvsp[(4) - (6)].qstr);
                             current->args.prepend("units");
                             current->spec=VhdlDocGen::UNITS;
                           ;}
    break;

  case 387:

    { (yyval.qstr)=""; ;}
    break;

  case 388:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 389:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr)+"#"; ;}
    break;

  case 390:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr); ;}
    break;

  case 391:

    { (yyval.qstr)=(yyvsp[(1) - (4)].qstr)+"="+(yyvsp[(3) - (4)].qstr) ;}
    break;

  case 392:

    {
      QCString sr1=" array ( "+(yyvsp[(3) - (7)].qstr)+" "+(yyvsp[(4) - (7)].qstr);
      QCString sr2=" ) of "+(yyvsp[(7) - (7)].qstr);
      (yyval.qstr)=sr1+sr2;
    ;}
    break;

  case 393:

    { (yyval.qstr)=""; ;}
    break;

  case 394:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+"  "+(yyvsp[(2) - (2)].qstr) ;}
    break;

  case 395:

    { (yyval.qstr)=", "+(yyvsp[(2) - (2)].qstr) ;}
    break;

  case 396:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" range<> "; ;}
    break;

  case 397:

    { (yyval.qstr)=" array "+(yyvsp[(2) - (4)].qstr)+" of "+(yyvsp[(4) - (4)].qstr); ;}
    break;

  case 398:

    { (yyval.qstr)=""; ;}
    break;

  case 399:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 400:

    {
      QRegExp reg("[\\s]");
      QCString oo=(yyvsp[(2) - (6)].qstr)+" "+(yyvsp[(3) - (6)].qstr);
      current->spec=VhdlDocGen::RECORD;
      current->args=oo;
      current->args.replace(reg,"%");
      current->args.prepend("record");
      (yyval.qstr)=(yyvsp[(2) - (6)].qstr)+" "+(yyvsp[(3) - (6)].qstr);
    ;}
    break;

  case 401:

    { (yyval.qstr)=""; ;}
    break;

  case 402:

    {
      (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr);
    ;}
    break;

  case 403:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 404:

    { (yyval.qstr)=(yyvsp[(1) - (4)].qstr)+":"+(yyvsp[(3) - (4)].qstr)+"#"; ;}
    break;

  case 405:

    { (yyval.qstr)="access "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 406:

    { (yyval.qstr)="file of "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 407:

    {
      addVhdlType((yyvsp[(2) - (5)].qstr),getParsedLine(t_SUBTYPE),Entry::VARIABLE_SEC,VhdlDocGen::SUBTYPE,0,(yyvsp[(4) - (5)].qstr).data());
    ;}
    break;

  case 408:

    { (yyval.qstr)=""; ;}
    break;

  case 409:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 410:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 411:

    { (yyval.qstr)=""; ;}
    break;

  case 412:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 413:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" "+(yyvsp[(2) - (3)].qstr)+" "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 414:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 415:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" "+(yyvsp[(2) - (3)].qstr)+" "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 416:

    { (yyval.qstr)=""; ;}
    break;

  case 417:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 418:

    { (yyval.qstr)="range "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 419:

    { (yyval.qstr)="("+(yyvsp[(2) - (4)].qstr)+" "+(yyvsp[(3) - (4)].qstr)+")"; ;}
    break;

  case 420:

    { (yyval.qstr)=""; ;}
    break;

  case 421:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 422:

    { (yyval.qstr)=","+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 423:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 424:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 425:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 426:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"  "+(yyvsp[(2) - (3)].qstr)+"  "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 427:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 428:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"  "+(yyvsp[(2) - (3)].qstr)+"  "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 429:

    { (yyval.qstr)=" to "; ;}
    break;

  case 430:

    { (yyval.qstr)=" downto "; ;}
    break;

  case 431:

    {
                                    QCString it=(yyvsp[(4) - (6)].qstr)+" "+(yyvsp[(5) - (6)].qstr);
                                    //  fprintf(stderr,"\n currP %d \n",currP);
                                    addVhdlType((yyvsp[(2) - (6)].qstr),getParsedLine(t_CONSTANT),Entry::VARIABLE_SEC,VhdlDocGen::CONSTANT,0,it.data());
                                  ;}
    break;

  case 432:

    { (yyval.qstr)="";      ;}
    break;

  case 433:

    { (yyval.qstr)=":="+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 434:

    {
                                    QCString s=(yyvsp[(4) - (7)].qstr)+" "+(yyvsp[(6) - (7)].qstr);
                                    addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_SIGNAL),Entry::VARIABLE_SEC,VhdlDocGen::SIGNAL,0,s.data());
                                  ;}
    break;

  case 435:

    { (yyval.qstr)=""; ;}
    break;

  case 436:

    { (yyval.qstr)=":="+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 437:

    { (yyval.qstr)=""; ;}
    break;

  case 438:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 439:

    {
                                    (yyval.qstr)=(yyvsp[(2) - (6)].qstr)+":"+(yyvsp[(4) - (6)].qstr)+" "+(yyvsp[(5) - (6)].qstr);
                                  ;}
    break;

  case 440:

    {
                                    (yyval.qstr)=(yyvsp[(5) - (7)].qstr)+" "+(yyvsp[(6) - (7)].qstr);
                                    addVhdlType((yyvsp[(3) - (7)].qstr),getParsedLine(t_VARIABLE),Entry::VARIABLE_SEC,VhdlDocGen::SHAREDVARIABLE,0,(yyval.qstr).data());
                                  ;}
    break;

  case 441:

    { (yyval.qstr)=""; ;}
    break;

  case 442:

    { (yyval.qstr)=":="+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 443:

    { (yyval.qstr)="constant"; ;}
    break;

  case 444:

    { (yyval.qstr)="signal"; ;}
    break;

  case 445:

    { (yyval.qstr)="variable"; ;}
    break;

  case 446:

    { (yyval.qstr)="shared"; ;}
    break;

  case 447:

    { (yyval.qstr)="file"; ;}
    break;

  case 448:

    { (yyval.qstr)="type"; ;}
    break;

  case 449:

    { (yyval.qstr)="bus"; ;}
    break;

  case 450:

    { (yyval.qstr)="register"; ;}
    break;

  case 451:

    {
                                    QCString s=(yyvsp[(3) - (7)].qstr)+" is "+(yyvsp[(5) - (7)].qstr)+(yyvsp[(6) - (7)].qstr);
                                    addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_ALIAS),Entry::VARIABLE_SEC,VhdlDocGen::ALIAS,0,s.data());
                                  ;}
    break;

  case 452:

    { (yyval.qstr)=""; ;}
    break;

  case 453:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 454:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 455:

    { (yyval.qstr)=""; ;}
    break;

  case 456:

    { (yyval.qstr)=","+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 457:

    {
             addVhdlType((yyvsp[(2) - (8)].qstr),getParsedLine(t_FILE),Entry::VARIABLE_SEC,VhdlDocGen::VFILE,0,(yyvsp[(4) - (8)].qstr).data());
           ;}
    break;

  case 458:

    {
             QCString s=(yyvsp[(4) - (6)].qstr)+" "+(yyvsp[(5) - (6)].qstr);
             addVhdlType((yyvsp[(2) - (6)].qstr),getParsedLine(t_FILE),Entry::VARIABLE_SEC,VhdlDocGen::VFILE,0,s.data());
           ;}
    break;

  case 459:

    { (yyval.qstr)=""; ;}
    break;

  case 460:

    { (yyval.qstr)="open "+(yyvsp[(2) - (4)].qstr)+" is "+s_str.qstr; ;}
    break;

  case 461:

    { (yyval.qstr)=""; ;}
    break;

  case 462:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 470:

    {
                  addVhdlType((yyvsp[(2) - (5)].qstr),getParsedLine(t_ATTRIBUTE),Entry::VARIABLE_SEC,VhdlDocGen::ATTRIBUTE,0,(yyvsp[(4) - (5)].qstr).data());
                ;}
    break;

  case 471:

    {
                  QCString oo=(yyvsp[(4) - (7)].qstr)+" is "+(yyvsp[(6) - (7)].qstr);
                  addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_ATTRIBUTE),Entry::VARIABLE_SEC,VhdlDocGen::ATTRIBUTE,0,oo.data());
                ;}
    break;

  case 473:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 474:

    { (yyval.qstr)="others";  ;}
    break;

  case 475:

    { (yyval.qstr)="all";     ;}
    break;

  case 476:

    { (yyval.qstr)="";        ;}
    break;

  case 477:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 478:

    { (yyval.qstr)=","+(yyvsp[(2) - (2)].qstr);    ;}
    break;

  case 479:

    { (yyval.qstr)="entity";        ;}
    break;

  case 480:

    { (yyval.qstr)="architecture";  ;}
    break;

  case 481:

    { (yyval.qstr)="package";       ;}
    break;

  case 482:

    { (yyval.qstr)="configuration"; ;}
    break;

  case 483:

    { (yyval.qstr)="component";     ;}
    break;

  case 484:

    { (yyval.qstr)="label";         ;}
    break;

  case 485:

    { (yyval.qstr)="type";          ;}
    break;

  case 486:

    { (yyval.qstr)="subtype";       ;}
    break;

  case 487:

    { (yyval.qstr)="procedure";     ;}
    break;

  case 488:

    { (yyval.qstr)="";              ;}
    break;

  case 489:

    { (yyval.qstr)="signal";        ;}
    break;

  case 490:

    { (yyval.qstr)="variable";      ;}
    break;

  case 491:

    { (yyval.qstr)="constant";      ;}
    break;

  case 492:

    { (yyval.qstr)="group";         ;}
    break;

  case 493:

    { (yyval.qstr)="file";          ;}
    break;

  case 494:

    { (yyval.qstr)="units";         ;}
    break;

  case 495:

    { (yyval.qstr)="literal";       ;}
    break;

  case 496:

    { (yyval.qstr)="sequence";      ;}
    break;

  case 497:

    { (yyval.qstr)="property";      ;}
    break;

  case 542:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 543:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"."+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 544:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 545:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 546:

    { (yyval.qstr)="("+(yyvsp[(2) - (3)].qstr)+")"; ;}
    break;

  case 547:

    { (yyval.qstr)="configurátion";yyLineNr=s_str.iLine; ;}
    break;

  case 548:

    { (yyval.qstr)="entity";yyLineNr=s_str.iLine; ;}
    break;

  case 549:

    { (yyval.qstr)="component";yyLineNr=s_str.iLine; ;}
    break;

  case 550:

    { yyLineNr=s_str.iLine; ;}
    break;

  case 551:

    {
                                addCompInst((yyvsp[(1) - (9)].qstr).data(),(yyvsp[(3) - (9)].qstr).data(),0,yyLineNr);
                               ;}
    break;

  case 552:

    { yyLineNr=s_str.iLine; ;}
    break;

  case 553:

    {
                               addCompInst((yyvsp[(1) - (8)].qstr).data(),(yyvsp[(3) - (8)].qstr).data(),0,yyLineNr);
                             ;}
    break;

  case 554:

    {
                                  addCompInst((yyvsp[(1) - (8)].qstr).data(),(yyvsp[(4) - (8)].qstr).data(),(yyvsp[(3) - (8)].qstr).data(),yyLineNr);
                              ;}
    break;

  case 555:

    {
                                addCompInst((yyvsp[(1) - (9)].qstr).data(),(yyvsp[(4) - (9)].qstr).data(),(yyvsp[(3) - (9)].qstr).data(),yyLineNr);
                              ;}
    break;

  case 607:

    { pushLabel((yyvsp[(1) - (2)].qstr)); ;}
    break;

  case 609:

    { popLabel(); ;}
    break;

  case 610:

    { popLabel(); ;}
    break;

  case 611:

    { pushLabel((yyvsp[(1) - (2)].qstr)); ;}
    break;

  case 614:

    { (yyval.qstr)=""; ;}
    break;

  case 615:

    { (yyval.qstr)=(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 618:

    {
                 current->name=(yyvsp[(1) - (3)].qstr);
                 current->endBodyLine=s_str.yyLineNr;
                 newEntry();
               ;}
    break;

  case 619:

    {
                 current->name=VhdlDocGen::getProcessNumber();
                 current->endBodyLine=s_str.yyLineNr;
                 newEntry();
               ;}
    break;

  case 620:

    { currP=VhdlDocGen::PROCESS; ;}
    break;

  case 621:

    { currP=0;
                 createFunction(currName,VhdlDocGen::PROCESS,(yyvsp[(4) - (10)].qstr).data());
               ;}
    break;

  case 622:

    { currP=0; ;}
    break;

  case 625:

    { (yyval.qstr)=""; ;}
    break;

  case 626:

    { (yyval.qstr)="postponed"; ;}
    break;

  case 627:

    { (yyval.qstr)=""; ;}
    break;

  case 628:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 633:

    { (yyval.qstr)=""; ;}
    break;

  case 634:

    { (yyval.qstr)="all"; ;}
    break;

  case 635:

    { (yyval.qstr)=(yyvsp[(2) - (3)].qstr); ;}
    break;

  case 636:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 637:

    { (yyval.qstr)=""; ;}
    break;

  case 638:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 639:

    { (yyval.qstr)=","+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 727:

    { lastEntity=0; lastCompound=0; genLabels.resize(0); ;}
    break;

  case 729:

    { lastCompound=0; genLabels.resize(0); ;}
    break;

  case 730:

    { lastEntity=0; genLabels.resize(0); ;}
    break;

  case 731:

    { lastEntity=0; lastCompound=0; genLabels.resize(0); ;}
    break;

  case 732:

    { currP=VhdlDocGen::COMPONENT; ;}
    break;

  case 733:

    { currP=VhdlDocGen::COMPONENT; ;}
    break;

  case 734:

    {
             addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_COMPONENT),Entry::VARIABLE_SEC,VhdlDocGen::COMPONENT,0,0);
             currP=0;
           ;}
    break;

  case 735:

    { (yyval.qstr)=""; ;}
    break;

  case 736:

    { (yyval.qstr)=(yyvsp[(2) - (3)].qstr); ;}
    break;

  case 737:

    { (yyval.qstr)=""; ;}
    break;

  case 738:

    { (yyval.qstr)=(yyvsp[(2) - (3)].qstr); ;}
    break;

  case 739:

    {
           popConfig();
          ;}
    break;

  case 740:

    { (yyval.qstr)=""; ;}
    break;

  case 741:

    { (yyval.qstr)=""; ;}
    break;

  case 742:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+"  "; ;}
    break;

  case 743:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 744:

    { (yyval.qstr)=""; ;}
    break;

  case 745:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr); ;}
    break;

  case 746:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 747:

    {
      (yyval.qstr)=(yyvsp[(1) - (1)].qstr);

      if (levelCounter==0)
        addConfigureNode((yyvsp[(1) - (1)].qstr).data(),NULL,TRUE,FALSE);
      else
        addConfigureNode((yyvsp[(1) - (1)].qstr).data(),NULL,FALSE,FALSE);
    ;}
    break;

  case 748:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 749:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 750:

    {
               (yyval.qstr)=(yyvsp[(2) - (7)].qstr)+" "+(yyvsp[(3) - (7)].qstr)+" "+(yyvsp[(4) - (7)].qstr);
               popConfig();
             ;}
    break;

  case 751:

    { (yyval.qstr)=""; ;}
    break;

  case 752:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 753:

    { (yyval.qstr)=""; ;}
    break;

  case 754:

    { (yyval.qstr)=""; ;}
    break;

  case 755:

    { (yyval.qstr)=""; ;}
    break;

  case 756:

    {
               addConfigureNode(compSpec.data(),(yyvsp[(2) - (3)].qstr).data(),FALSE,FALSE);
             ;}
    break;

  case 757:

    { 
               addConfigureNode((yyvsp[(2) - (4)].qstr).data(),(yyvsp[(3) - (4)].qstr).data(),TRUE,FALSE,TRUE);currNode->confVhdl=lastCompound->name; 
             ;}
    break;

  case 758:

    { 
               addConfigureNode((yyvsp[(2) - (7)].qstr).data(),(yyvsp[(3) - (7)].qstr).data(),TRUE,FALSE,TRUE);currNode->confVhdl=lastCompound->name; 
             ;}
    break;

  case 759:

    { (yyval.qstr)=(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 760:

    { (yyval.qstr)=""; ;}
    break;

  case 761:

    { (yyval.qstr)=""; ;}
    break;

  case 762:

    {
               (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+":"+(yyvsp[(3) - (3)].qstr);
               compSpec=(yyval.qstr);
             ;}
    break;

  case 763:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 764:

    { (yyval.qstr)="all"; ;}
    break;

  case 765:

    { (yyval.qstr)="others"; ;}
    break;

  case 766:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr); ;}
    break;

  case 771:

    { (yyval.qstr)="entity "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 772:

    { (yyval.qstr)="configuration "+ (yyvsp[(2) - (2)].qstr); ;}
    break;

  case 773:

    { (yyval.qstr)="open "; ;}
    break;

  case 774:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 775:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 776:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 777:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+","+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 778:

    {
                      // $$=$2+":"+$4+$6;
                      (yyval.qstr)="("+(yyvsp[(4) - (8)].qstr)+(yyvsp[(6) - (8)].qstr)+")";
                      addVhdlType((yyvsp[(2) - (8)].qstr),getParsedLine(t_GROUP),Entry::VARIABLE_SEC,VhdlDocGen::GROUP,(yyval.qstr).data(),0);
                    ;}
    break;

  case 779:

    {
                      (yyval.qstr)=(yyvsp[(2) - (7)].qstr)+":"+(yyvsp[(5) - (7)].qstr);
                      addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_GROUP),Entry::VARIABLE_SEC,VhdlDocGen::GROUP,(yyvsp[(5) - (7)].qstr).data(),0);
                    ;}
    break;

  case 780:

    { (yyval.qstr)=""; ;}
    break;

  case 782:

    { (yyval.qstr)="";   ;}
    break;

  case 783:

    { (yyval.qstr)="<>"; ;}
    break;

  case 784:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 785:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+","+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 786:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 787:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 788:

    {
      (yyval.qstr)=s_str.qstr;
    ;}
    break;

  case 789:

    {
      (yyval.qstr)=s_str.qstr;
    ;}
    break;

  case 790:

    {
      (yyval.qstr)=s_str.qstr;
    ;}
    break;

  case 791:

    {
      (yyval.qstr)=s_str.qstr;
    ;}
    break;

  case 792:

    {
      (yyval.qstr)=s_str.qstr;
    ;}
    break;

  case 793:

    { (yyval.qstr)=""; ;}
    break;

  case 794:

    { (yyval.qstr)=""; ;}
    break;

  case 804:

    { (yyval.qstr)=""; ;}
    break;

  case 805:

    { (yyval.qstr)=""; ;}
    break;

  case 812:

    { (yyval.qstr)="context "+(yyvsp[(2) - (3)].qstr); ;}
    break;

  case 813:

    { parse_sec=CONTEXT_SEC; ;}
    break;

  case 814:

    {
                          parse_sec=0;
                          QCString v=(yyvsp[(5) - (8)].qstr);
                          addVhdlType((yyvsp[(2) - (8)].qstr),getParsedLine(t_LIBRARY),Entry::VARIABLE_SEC,VhdlDocGen::LIBRARY,"context",(yyvsp[(5) - (8)].qstr).data());
                        ;}
    break;

  case 815:

    {
                          addVhdlType((yyvsp[(2) - (6)].qstr),getParsedLine(t_LIBRARY),Entry::VARIABLE_SEC,VhdlDocGen::LIBRARY,"context",0);
                        ;}
    break;

  case 818:

    { (yyval.qstr) = (yyvsp[(1) - (1)].qstr); ;}
    break;

  case 819:

    { (yyval.qstr) = (yyvsp[(1) - (2)].qstr)+"#"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 820:

    { (yyval.qstr) = (yyvsp[(1) - (1)].qstr); ;}
    break;

  case 821:

    { (yyval.qstr) = (yyvsp[(1) - (1)].qstr); ;}
    break;

  case 822:

    { (yyval.qstr) = (yyvsp[(1) - (1)].qstr); ;}
    break;

  case 823:

    {
      (yyval.qstr)=" is new "+(yyvsp[(5) - (7)].qstr)+(yyvsp[(6) - (7)].qstr);
      //Entry * pp=lastCompound;
      //Entry * pps=lastEntity  ;
      //assert(false);
      addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_PACKAGE),Entry::VARIABLE_SEC,VhdlDocGen::INSTANTIATION,"package",(yyval.qstr).data());
    ;}
    break;

  case 824:

    {
      (yyval.qstr)=" is new "+(yyvsp[(5) - (8)].qstr)+(yyvsp[(6) - (8)].qstr);
      addVhdlType((yyvsp[(2) - (8)].qstr),getParsedLine(t_PACKAGE),Entry::VARIABLE_SEC,VhdlDocGen::INSTANTIATION,"package",(yyval.qstr).data());
    ;}
    break;

  case 825:

    { (yyval.qstr)=""; ;}
    break;

  case 826:

    {
      (yyval.qstr)= " is new "+(yyvsp[(5) - (7)].qstr)+(yyvsp[(6) - (7)].qstr);
      addVhdlType((yyvsp[(2) - (7)].qstr),getParsedLine(t_FUNCTION),Entry::VARIABLE_SEC,VhdlDocGen::INSTANTIATION,"function ",(yyval.qstr).data());
    ;}
    break;

  case 827:

    {
      (yyval.qstr)=" is new "+(yyvsp[(5) - (8)].qstr)+(yyvsp[(6) - (8)].qstr);
      addVhdlType((yyvsp[(2) - (8)].qstr),getParsedLine(t_FUNCTION),Entry::VARIABLE_SEC,VhdlDocGen::INSTANTIATION,"function ",(yyval.qstr).data());
    ;}
    break;

  case 828:

    { (yyval.qstr)=""; ;}
    break;

  case 829:

    { (yyval.qstr)=""; ;}
    break;

  case 830:

    { (yyval.qstr)="["+(yyvsp[(2) - (3)].qstr)+" ]"; ;}
    break;

  case 831:

    { (yyval.qstr)="[ ]"; ;}
    break;

  case 832:

    { (yyval.qstr)="return "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 833:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 834:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+" return "+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 835:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 836:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+" "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 837:

    { (yyval.qstr)=" , "+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 884:

    { (yyval.qstr) = (yyvsp[(1) - (1)].qstr); ;}
    break;

  case 885:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 886:

    { (yyval.qstr) = "procedure "+(yyvsp[(2) - (3)].qstr)+(yyvsp[(3) - (3)].qstr); current->name=(yyvsp[(2) - (3)].qstr); ;}
    break;

  case 887:

    {
      QCString s=(yyvsp[(6) - (6)].qstr);
      if (!s.isEmpty())
      {
        s.prepend(" is ");
      }
      (yyval.qstr)=" function "+(yyvsp[(2) - (6)].qstr)+(yyvsp[(3) - (6)].qstr)+(yyvsp[(5) - (6)].qstr)+s;
      current->name=(yyvsp[(2) - (6)].qstr);
    ;}
    break;

  case 888:

    {
      QCString s=(yyvsp[(7) - (7)].qstr);
      if (!s.isEmpty())
      {
        s.prepend(" is ");
      }
      (yyval.qstr)=(yyvsp[(1) - (7)].qstr)+" function "+(yyvsp[(3) - (7)].qstr)+(yyvsp[(4) - (7)].qstr)+" return "+(yyvsp[(6) - (7)].qstr)+s;
      current->name=(yyvsp[(3) - (7)].qstr);
    ;}
    break;

  case 889:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 890:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 891:

    { (yyval.qstr)="";   ;}
    break;

  case 892:

    { (yyval.qstr)=(yyvsp[(2) - (2)].qstr);   ;}
    break;

  case 893:

    { (yyval.qstr)="<>"; ;}
    break;

  case 894:

    { (yyval.qstr)=""; ;}
    break;

  case 895:

    { (yyval.qstr)="parameter "; ;}
    break;

  case 896:

    { parse_sec=PARAM_SEC; ;}
    break;

  case 897:

    { parse_sec=0; ;}
    break;

  case 898:

    { (yyval.qstr)="("+(yyvsp[(2) - (4)].qstr)+")"; ;}
    break;

  case 899:

    {
                          (yyval.qstr)="package "+(yyvsp[(2) - (5)].qstr)+" is new "+(yyvsp[(5) - (5)].qstr);
                          current->name=(yyvsp[(2) - (5)].qstr);
                        ;}
    break;

  case 900:

    { 
                          (yyval.qstr)="package "+(yyvsp[(2) - (6)].qstr)+" is new "+(yyvsp[(5) - (6)].qstr)+"( ... )" ; 
                          current->name=(yyvsp[(2) - (6)].qstr); 
                        ;}
    break;

  case 902:

    {
                          //int u=s_str.iLine;
                          parse_sec=GEN_SEC;
                        ;}
    break;

  case 903:

    {
                          QCString vo=(yyvsp[(3) - (3)].qstr);
                          parse_sec=0;
                        ;}
    break;

  case 904:

    {
                          QCString s="<<"+(yyvsp[(2) - (6)].qstr);
                          QCString s1=(yyvsp[(3) - (6)].qstr)+":"+(yyvsp[(5) - (6)].qstr)+">>";
                          (yyval.qstr)=s+s1;
                        ;}
    break;

  case 905:

    { (yyval.qstr)="constant "; ;}
    break;

  case 906:

    { (yyval.qstr)="signal ";   ;}
    break;

  case 907:

    { (yyval.qstr)="variable "; ;}
    break;

  case 908:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 909:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 910:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 911:

    { (yyval.qstr)="."+(yyvsp[(2) - (3)].qstr)+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 912:

    { (yyval.qstr)="."+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 913:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+(yyvsp[(2) - (3)].qstr)+(yyvsp[(3) - (3)].qstr); ;}
    break;

  case 914:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 915:

    { (yyval.qstr)="^."; ;}
    break;

  case 916:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+"^."; ;}
    break;

  case 917:

    { (yyval.qstr)=(yyvsp[(1) - (1)].qstr); ;}
    break;

  case 918:

    { (yyval.qstr)=(yyvsp[(1) - (4)].qstr)+"("+(yyvsp[(3) - (4)].qstr)+")"; ;}
    break;

  case 919:

    { (yyval.qstr)=(yyvsp[(1) - (2)].qstr)+"."; ;}
    break;

  case 920:

    { (yyval.qstr)=(yyvsp[(1) - (3)].qstr)+(yyvsp[(2) - (3)].qstr)+"."; ;}
    break;

  case 921:

    { (yyval.qstr)="@"+(yyvsp[(2) - (2)].qstr); ;}
    break;

  case 922:

    {
// fprintf(stderr,"\n  tooldir %s",s_str.qstr.data() );
;}
    break;


/* Line 1267 of yacc.c.  */

      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}




extern FILE* yyout;
extern YYSTYPE vhdlScanYYlval;

void vhdlScanYYerror(const char* /*str*/)
{
//  fprintf(stderr,"\n<---error at line %d  : [ %s]   in file : %s ---->",s_str.yyLineNr,s_str.qstr.data(),s_str.fileName);
 // exit(0);
}

int MyParserVhdl::parse(MyParserVhdl* conv)
{
  myconv=conv;
  return vhdlScanYYparse();
}

int lex(void)
{
  return myconv->doLex();
}

struct s_contVhdl*  getVhdlCont()
{
  return &s_str;
}

Entry* getVhdlCompound()
{
  if (lastEntity) return lastEntity;
  if (lastCompound) return lastCompound;
  return NULL;
}

QList<ConfNode>& getVhdlConfiguration() { return  configL; }

static void addCompInst(char *n, char* instName, char* comp,int iLine)
{

  current->spec=VhdlDocGen::INSTANTIATION;
  current->section=Entry::VARIABLE_SEC;
  current->startLine=iLine;
  current->bodyLine=iLine;
  current->type=instName;                       // foo:instname e.g proto or work. proto(ttt)
  current->exception=genLabels;                 // |arch|label1:label2...
  current->name=n;                              // foo
  current->args=lastCompound->name;             // architecture name
  current->includeName=comp;                    // component/enity/configuration

  //printf(" \n genlable: [%s]  inst: [%s]  name: [%s] \n",genLabels.data(),instName,n);

  if (lastCompound)
  {
    current->args=lastCompound->name;
    if (true) // !findInstant(current->type))
    {
      initEntry(current);
      instFiles.append(new Entry(*current));
    }
  
    Entry *temp=current;  // hold  current pointer  (temp=oldEntry)
    current=new Entry;     // (oldEntry != current)
    delete  temp;
   
  }
  else
  {
    newEntry();
  }
}

static void pushLabel(const QCString &label)
{
  genLabels+="|"+label;
}

static void popLabel()
{
  int u=genLabels.findRev("|");
  if (u<0) return;
  genLabels=genLabels.left(u);
}

static void popConfig()
{
  assert(currNode);
  currNode=currNode->prevNode;
  // printf("\n pop arch %s ",currNode->arch.data());
}

static void addConfigureNode(const char* a,const char*b, bool isRoot,bool isLeave,bool inlineConf)
{
  struct ConfNode* co;
  QCString ent,arch,lab;
  ent=a;
  lab =  VhdlDocGen::parseForConfig(ent,arch);

  if (b)
  {
    ent=b;
    lab=VhdlDocGen::parseForBinding(ent,arch);
  }

  co=new ConfNode(a,b,confName.data());
  if (inlineConf)
  {
    co->isInlineConf=TRUE;
  }

  if (isRoot)
  {
    co->isRoot=TRUE;
    configL.append(co);
    currNode=co;
    currNode->prevNode=currNode;
  }
  else if (!isLeave)
  {
    currNode->addNode(co);
    co->prevNode=currNode;
    currNode=co;
  }
  else
  {
    assert(0);
    co=new ConfNode(a,b,confName.data());
    currNode->addNode(co);
  }
}// addConfigure

//------------------------------------------------------------------------------------------------------------

static bool isFuncProcProced()
{
  if (currP==VhdlDocGen::FUNCTION ||
      currP==VhdlDocGen::PROCEDURE ||
      currP==VhdlDocGen::PROCESS
     )
  {
    return TRUE;
  }
  return FALSE;
}

static void initEntry(Entry *e)
{
  e->fileName = s_str.fileName;
  e->lang=SrcLangExt_VHDL;
  isVhdlDocPending();
  initGroupInfo(e);
}

static void addProto(const char *s1,const char *s2,const char *s3,
                     const char *s4,const char *s5,const char *s6)
{
 // (void)s3; // avoid unused warning
  (void)s5; // avoid unused warning
  static QRegExp reg("[\\s]");
  QCString name=s2;
  QStringList ql=QStringList::split(",",name,FALSE);

  for (uint u=0;u<ql.count();u++)
  {
    Argument *arg=new Argument;
    arg->name=ql[u].utf8();
    if (s3)
    {
      arg->type=s3;
    }
    arg->type+=" ";
    arg->type+=s4;
    if (s6)
    {
      arg->type+=s6;
    }
    if (parse_sec==GEN_SEC && param_sec==0)
    {
      arg->defval="gen!";
    }

    if (parse_sec==PARAM_SEC)
    {
      assert(false);
    }

    arg->defval+=s1;
    arg->attrib="";//s6;

    current->argList->append(arg);
    current->args+=s2;
    current->args+=",";
  }
}

static void createFunction(const QCString &impure,int spec,
                           const QCString &fname)
{
  int it=0;
  current->bodyLine=getParsedLine(spec);
  current->spec=spec;
  current->section=Entry::FUNCTION_SEC;
  current->exception=impure;

  if (parse_sec==GEN_SEC)
  {
    current->spec= VhdlDocGen::GENERIC;
    current->section=Entry::FUNCTION_SEC;
  }

  if (currP==VhdlDocGen::PROCEDURE)
  {
    current->name=impure;
    current->exception="";
    it=t_PROCEDURE;
  }
  else
  {
    current->name=fname;
    it=t_FUNCTION;
  }

  if (spec==VhdlDocGen::PROCESS)
  {
    it=t_PROCESS;
    current->args=fname;
    current->name=impure;
    if (!fname.isEmpty())
    {
      QStringList q1=QStringList::split(',',fname);
      for (uint ii=0;ii<q1.count();ii++)
      {
        Argument *arg=new Argument;
        arg->name=q1[ii].utf8();
        current->argList->append(arg);
      }
    }
  }

  current->startLine=getParsedLine(it);
  current->bodyLine=getParsedLine(it);
}

static void addVhdlType(const QCString &name,int startLine,int section,int spec,
                        const char* args,const char* type,Protection prot)
{
  static QRegExp reg("[\\s]");

  //int startLine=getParsedLine(spec);

  if (isFuncProcProced())
  {
    return;
  }

  if (parse_sec==GEN_SEC)
  {
    spec= VhdlDocGen::GENERIC;
  }

  // more than one name   ?
  QStringList ql=QStringList::split(",",name,FALSE);

  for (uint u=0;u<ql.count();u++)
  {
    current->name=ql[u].utf8();
 //   if (section==Entry::VARIABLE_SEC &&  !(spec == VhdlDocGen::USE || spec == VhdlDocGen::LIBRARY) )
 //   {
 //     current->name.prepend(VhdlDocGen::getRecordNumber());
 //   }
   
    current->startLine=startLine;
    current->bodyLine=startLine;
    current->section=section;
    current->spec=spec;
    current->fileName=s_str.fileName;
    if (current->args.isEmpty())
    {
      current->args=args;
      current->args.replace(reg,"%"); // insert dummy chars because wihte spaces are removed
    }
    current->type=type;
    current->type.replace(reg,"%"); // insert dummy chars because white spaces are removed
    current->protection=prot;
    newEntry();
  }
}

static void newEntry()
{
  if (current->spec==VhdlDocGen::ENTITY       ||
      current->spec==VhdlDocGen::PACKAGE      ||
      current->spec==VhdlDocGen::ARCHITECTURE ||
      current->spec==VhdlDocGen::PACKAGE_BODY
     )
  {
    current_root->addSubEntry(current);
  }
  else
  {
    if (lastCompound)
    {
      lastCompound->addSubEntry(current);
    }
    else
    {
      if (lastEntity)
      {
        lastEntity->addSubEntry(current);
      }
      else
      {
        current_root->addSubEntry(current);
      }
    }
  }
  current = new Entry ;
  initEntry(current);
}


