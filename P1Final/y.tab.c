/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "SmallC.y"

/*
	SmallC.y for yacc
	tmp to keep return node, when one rule is matched
	pa is just the parent node
	stack to store the return node
	stackID to store the identifiers we get in sequence
	stackINT to store the integers we get in sequence
	flag to record whether there is error
	tmpS is the input string we get from lex
	
	For every rules, I mainly create a new syntax tree with it's left as parent node and add all the children node.
	For children node, if it's nonterminal, pop from the stack; if it's terminal, just create it.
	
	by Jinyi
*/
#include "tree.c"
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
PNode tmp=NULL;
PNode pa;
PStack stack;
PStack stackID;
PStack stackINT;
int flag = 0;
extern char *tmpS;


/* Line 268 of yacc.c  */
#line 101 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT = 258,
     TYPE = 259,
     STRUCT = 260,
     RETURN = 261,
     IF = 262,
     ELSE = 263,
     BREAK = 264,
     CONT = 265,
     FOR = 266,
     ID = 267,
     SEMI = 268,
     COMMA = 269,
     LC = 270,
     RC = 271,
     BINARYOP = 272,
     UNARYOP = 273,
     BITORASSIGN = 274,
     BITXORASSIGN = 275,
     BITANDASSIGN = 276,
     DIVASSIGN = 277,
     RSHIFTASSIGN = 278,
     LSHIFTASSIGN = 279,
     MULTASSIGN = 280,
     MINUSASSIGN = 281,
     ADDASSIGN = 282,
     ASSIGNOP = 283,
     LOGIOR = 284,
     LOGIAND = 285,
     BITOR = 286,
     BITXOR = 287,
     BITAND = 288,
     NOTEQUAL = 289,
     EQUAL = 290,
     NOLESSTHAN = 291,
     NOGREATERTHAN = 292,
     LESS = 293,
     GREATER = 294,
     RSHIFT = 295,
     LSHIFT = 296,
     MINUS = 297,
     ADD = 298,
     MOD = 299,
     DIV = 300,
     MULT = 301,
     UMINUS = 302,
     DECR = 303,
     INCR = 304,
     BITNOT = 305,
     LOGINOT = 306,
     LP = 307,
     LB = 308,
     DOT = 309,
     RP = 310,
     RB = 311
   };
#endif
/* Tokens.  */
#define INT 258
#define TYPE 259
#define STRUCT 260
#define RETURN 261
#define IF 262
#define ELSE 263
#define BREAK 264
#define CONT 265
#define FOR 266
#define ID 267
#define SEMI 268
#define COMMA 269
#define LC 270
#define RC 271
#define BINARYOP 272
#define UNARYOP 273
#define BITORASSIGN 274
#define BITXORASSIGN 275
#define BITANDASSIGN 276
#define DIVASSIGN 277
#define RSHIFTASSIGN 278
#define LSHIFTASSIGN 279
#define MULTASSIGN 280
#define MINUSASSIGN 281
#define ADDASSIGN 282
#define ASSIGNOP 283
#define LOGIOR 284
#define LOGIAND 285
#define BITOR 286
#define BITXOR 287
#define BITAND 288
#define NOTEQUAL 289
#define EQUAL 290
#define NOLESSTHAN 291
#define NOGREATERTHAN 292
#define LESS 293
#define GREATER 294
#define RSHIFT 295
#define LSHIFT 296
#define MINUS 297
#define ADD 298
#define MOD 299
#define DIV 300
#define MULT 301
#define UMINUS 302
#define DECR 303
#define INCR 304
#define BITNOT 305
#define LOGINOT 306
#define LP 307
#define LB 308
#define DOT 309
#define RP 310
#define RB 311




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 255 "y.tab.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   768

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  175

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    13,    17,    19,    23,
      24,    26,    28,    34,    37,    39,    40,    42,    43,    49,
      50,    56,    60,    62,    63,    66,    71,    74,    75,    78,
      80,    84,    91,   101,   104,   107,   110,   111,   114,   115,
     119,   123,   125,   127,   131,   133,   137,   141,   145,   149,
     153,   157,   161,   165,   169,   173,   177,   181,   185,   189,
     193,   197,   201,   205,   209,   213,   217,   221,   225,   229,
     233,   237,   241,   245,   249,   253,   256,   259,   262,   265,
     268,   271,   275,   276,   282,   283,   287,   291,   293,   294,
     299,   300,   304
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    -1,    60,    59,    -1,    -1,    62,
      61,    13,    -1,    62,    67,    71,    -1,    78,    -1,    78,
      14,    61,    -1,    -1,     4,    -1,    63,    -1,     5,    64,
      15,    75,    16,    -1,     5,    12,    -1,    12,    -1,    -1,
      12,    -1,    -1,    65,    53,     3,    66,    56,    -1,    -1,
      12,    68,    52,    69,    55,    -1,    70,    14,    69,    -1,
      70,    -1,    -1,    62,    65,    -1,    15,    75,    72,    16,
      -1,    73,    72,    -1,    -1,    80,    13,    -1,    71,    -1,
       6,    80,    13,    -1,     7,    52,    80,    55,    73,    74,
      -1,    11,    52,    80,    13,    80,    13,    80,    55,    73,
      -1,    10,    13,    -1,     9,    13,    -1,     8,    73,    -1,
      -1,    76,    75,    -1,    -1,    62,    77,    13,    -1,    78,
      14,    77,    -1,    78,    -1,    65,    -1,    65,    28,    79,
      -1,    80,    -1,    15,    84,    16,    -1,    80,    17,    80,
      -1,    80,    28,    80,    -1,    80,    46,    80,    -1,    80,
      45,    80,    -1,    80,    44,    80,    -1,    80,    43,    80,
      -1,    80,    42,    80,    -1,    80,    41,    80,    -1,    80,
      40,    80,    -1,    80,    39,    80,    -1,    80,    36,    80,
      -1,    80,    38,    80,    -1,    80,    37,    80,    -1,    80,
      35,    80,    -1,    80,    24,    80,    -1,    80,    23,    80,
      -1,    80,    34,    80,    -1,    80,    30,    80,    -1,    80,
      29,    80,    -1,    80,    27,    80,    -1,    80,    26,    80,
      -1,    80,    25,    80,    -1,    80,    22,    80,    -1,    80,
      21,    80,    -1,    80,    20,    80,    -1,    80,    19,    80,
      -1,    80,    33,    80,    -1,    80,    32,    80,    -1,    80,
      31,    80,    -1,    18,    80,    -1,    51,    80,    -1,    49,
      80,    -1,    48,    80,    -1,    50,    80,    -1,    42,    80,
      -1,    52,    80,    55,    -1,    -1,    12,    81,    52,    84,
      55,    -1,    -1,    12,    82,    83,    -1,    80,    54,    12,
      -1,     3,    -1,    -1,    53,    80,    56,    83,    -1,    -1,
      80,    14,    84,    -1,    80,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    55,    62,    69,    77,    86,    92,   100,
     107,   113,   120,   131,   139,   145,   152,   158,   158,   172,
     172,   186,   194,   200,   207,   215,   226,   233,   240,   247,
     253,   261,   273,   289,   296,   304,   311,   318,   325,   332,
     341,   349,   356,   362,   371,   377,   386,   396,   406,   416,
     426,   436,   446,   456,   466,   476,   486,   496,   506,   516,
     526,   536,   546,   556,   566,   576,   586,   596,   606,   616,
     626,   636,   646,   656,   666,   676,   683,   690,   697,   704,
     711,   718,   728,   728,   743,   743,   753,   761,   766,   773,
     783,   790,   798
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "TYPE", "STRUCT", "RETURN", "IF",
  "ELSE", "BREAK", "CONT", "FOR", "ID", "SEMI", "COMMA", "LC", "RC",
  "BINARYOP", "UNARYOP", "BITORASSIGN", "BITXORASSIGN", "BITANDASSIGN",
  "DIVASSIGN", "RSHIFTASSIGN", "LSHIFTASSIGN", "MULTASSIGN", "MINUSASSIGN",
  "ADDASSIGN", "ASSIGNOP", "LOGIOR", "LOGIAND", "BITOR", "BITXOR",
  "BITAND", "NOTEQUAL", "EQUAL", "NOLESSTHAN", "NOGREATERTHAN", "LESS",
  "GREATER", "RSHIFT", "LSHIFT", "MINUS", "ADD", "MOD", "DIV", "MULT",
  "UMINUS", "DECR", "INCR", "BITNOT", "LOGINOT", "LP", "LB", "DOT", "RP",
  "RB", "$accept", "PROGRAM", "EXTDEFS", "EXTDEF", "EXTVARS", "SPEC",
  "STSPEC", "OPTTAG", "VAR", "$@1", "FUNC", "$@2", "PARAS", "PARA",
  "STMTBLOCK", "STMTS", "STMT", "ESTMT", "DEFS", "DEF", "DECS", "DEC",
  "INIT", "EXP", "$@3", "$@4", "ARRS", "ARGS", 0
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    66,    65,    68,
      67,    69,    69,    69,    70,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    75,    75,    76,
      77,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    80,    82,    80,    80,    80,    80,    83,
      83,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     3,     1,     3,     0,
       1,     1,     5,     2,     1,     0,     1,     0,     5,     0,
       5,     3,     1,     0,     2,     4,     2,     0,     2,     1,
       3,     6,     9,     2,     2,     2,     0,     2,     0,     3,
       3,     1,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     3,     0,     5,     0,     3,     3,     1,     0,     4,
       0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,    15,     0,     2,     4,     9,    11,    13,     0,
       1,     3,    16,     0,    42,     0,     7,    38,     0,     5,
      88,     0,    38,     6,     9,     0,     0,    38,    23,    87,
      84,    88,    88,    88,    88,    88,    88,    88,    88,    43,
      44,    17,    88,    16,     8,     0,    41,    12,    37,     0,
       0,    22,     0,    90,    92,     0,    75,    80,    78,    77,
      79,    76,     0,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,     0,     0,    88,     0,     0,     0,     0,    29,
       0,    88,     0,    39,     0,    24,    20,    23,    88,    88,
      85,    88,    45,    81,    46,    71,    70,    69,    68,    61,
      60,    67,    66,    65,    47,    64,    63,    74,    73,    72,
      62,    59,    56,    58,    57,    55,    54,    53,    52,    51,
      50,    49,    48,    86,    18,     0,    88,    34,    33,    88,
      25,    26,    28,    40,    21,     0,     0,    91,    30,     0,
       0,    83,    90,    88,    88,    89,    36,     0,    88,    31,
      88,    35,     0,    88,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    25,     7,     9,    14,    93,
      15,    18,    50,    51,    99,   100,   101,   169,    26,    27,
      45,    16,    39,   102,    52,    53,   110,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -105
static const yytype_int16 yypact[] =
{
       4,  -105,     8,    21,  -105,     4,    10,  -105,    11,    12,
    -105,  -105,   -29,    15,   -18,    22,    24,     4,   -27,  -105,
     131,    33,     4,  -105,    27,    27,    25,     4,     4,  -105,
      23,   144,   144,   144,   144,   144,   144,   144,   144,  -105,
     519,  -105,    89,  -105,  -105,    60,    62,  -105,  -105,    27,
      28,    64,    32,    26,   328,    69,   519,   -14,   -14,   -14,
     -14,   -14,   402,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,    68,    30,   144,    35,    77,    80,    42,  -105,
      81,    89,   184,  -105,    27,    49,  -105,     4,   144,   144,
    -105,   144,  -105,  -105,   519,   519,   519,   519,   519,   519,
     519,   519,   519,   519,   519,   549,   579,   609,   639,   669,
     699,   699,   714,   714,   714,   714,   -12,   -12,   113,   113,
     -14,   -14,   -14,  -105,  -105,   220,   144,  -105,  -105,   144,
    -105,  -105,  -105,  -105,  -105,    48,   364,  -105,  -105,   441,
     256,  -105,    26,   103,   144,  -105,   108,   292,   103,  -105,
     144,  -105,   480,   103,  -105
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -105,  -105,   106,  -105,    93,     1,  -105,  -105,    70,  -105,
    -105,  -105,    13,  -105,   107,    31,   -91,  -105,    -3,  -105,
      19,   -23,  -105,   -20,  -105,  -105,   -38,  -104
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -83
static const yytype_int16 yytable[] =
{
      40,     6,    46,    63,   155,    63,     6,   157,     1,     2,
      20,    54,    56,    57,    58,    59,    60,    61,    62,    42,
       8,    10,    12,   -19,    48,    28,   -14,    17,    19,    49,
      87,    88,    89,    90,    91,    21,    41,    22,    24,    43,
      92,    47,    92,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   166,   103,   145,   -82,   104,   171,   107,   109,
     143,    46,   174,   106,   108,   112,   144,   146,    54,   156,
     147,    54,    29,   148,   149,    94,    95,   150,    96,    97,
      98,    30,    21,   161,    22,   -27,    29,    32,    49,    94,
      95,    11,    96,    97,    98,    30,   168,    44,    22,   105,
     154,    32,    23,   153,   165,     0,   159,     0,     0,   160,
      63,    33,   151,     0,    29,     0,     0,    34,    35,    36,
      37,    38,     0,    30,   167,    33,    31,    29,     0,    32,
     172,    34,    35,    36,    37,    38,    30,    89,    90,    91,
       0,     0,    32,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,    34,
      35,    36,    37,    38,     0,     0,    33,     0,     0,     0,
       0,     0,    34,    35,    36,    37,    38,   152,     0,     0,
       0,    63,     0,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,   158,     0,     0,     0,    63,    92,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,   164,
       0,     0,     0,    63,    92,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,   170,     0,     0,     0,    63,
      92,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,   111,     0,     0,    63,    92,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
       0,    63,    92,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    92,    63,
     162,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,     0,     0,    92,   113,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,     0,     0,
       0,     0,     0,     0,     0,    92,   163,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,     0,     0,    92,   173,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    63,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    63,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    63,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    63,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    63,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    63,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,    63,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    92
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-105))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      20,     0,    25,    17,   108,    17,     5,   111,     4,     5,
      28,    31,    32,    33,    34,    35,    36,    37,    38,    22,
      12,     0,    12,    52,    27,    52,    15,    15,    13,    28,
      42,    43,    44,    45,    46,    53,     3,    15,    14,    12,
      54,    16,    54,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   163,    13,    94,    52,    14,   168,    14,    53,
      12,   104,   173,    55,    52,    16,    56,    52,   108,   109,
      13,   111,     3,    13,    52,     6,     7,    16,     9,    10,
      11,    12,    53,    55,    15,    16,     3,    18,   107,     6,
       7,     5,     9,    10,    11,    12,     8,    24,    15,    49,
     107,    18,    15,   104,   162,    -1,   146,    -1,    -1,   149,
      17,    42,   101,    -1,     3,    -1,    -1,    48,    49,    50,
      51,    52,    -1,    12,   164,    42,    15,     3,    -1,    18,
     170,    48,    49,    50,    51,    52,    12,    44,    45,    46,
      -1,    -1,    18,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    48,
      49,    50,    51,    52,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    48,    49,    50,    51,    52,    13,    -1,    -1,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    13,    -1,    -1,    -1,    17,    54,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    13,
      -1,    -1,    -1,    17,    54,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    -1,    -1,    13,    -1,    -1,    -1,    17,
      54,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    14,    -1,    -1,    17,    54,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    54,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    17,
      56,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    17,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    17,    -1,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    55,    17,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,    58,    59,    60,    62,    63,    12,    64,
       0,    59,    12,    61,    65,    67,    78,    15,    68,    13,
      28,    53,    15,    71,    14,    62,    75,    76,    52,     3,
      12,    15,    18,    42,    48,    49,    50,    51,    52,    79,
      80,     3,    75,    12,    61,    77,    78,    16,    75,    62,
      69,    70,    81,    82,    80,    84,    80,    80,    80,    80,
      80,    80,    80,    17,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    54,    66,     6,     7,     9,    10,    11,    71,
      72,    73,    80,    13,    14,    65,    55,    14,    52,    53,
      83,    14,    16,    55,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    12,    56,    80,    52,    13,    13,    52,
      16,    72,    13,    77,    69,    84,    80,    84,    13,    80,
      80,    55,    56,    55,    13,    83,    73,    80,     8,    74,
      13,    73,    80,    55,    73
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 2:

/* Line 1806 of yacc.c  */
#line 48 "SmallC.y"
    {
			pa=create("PROGRAM");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 55 "SmallC.y"
    {
			pa=create("EXTDEFS");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 62 "SmallC.y"
    {
			pa=create("EXTDEFS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 69 "SmallC.y"
    {
			pa=create("EXTDEF");
			PNode c3 = create("SEMI");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 77 "SmallC.y"
    {
			pa=create("EXTDEF");
			PNode c3 = pop(stack);
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 86 "SmallC.y"
    {
			pa=create("EXTVARS");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 92 "SmallC.y"
    {
			pa=create("EXTVARS");
			PNode c3 = pop(stack);
			PNode c2 = create("COMMA");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 100 "SmallC.y"
    {
			pa=create("EXTVARS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 107 "SmallC.y"
    {
			pa=create("SPEC");
			PNode c1 = create("TYPE");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 113 "SmallC.y"
    {
			pa=create("SPEC");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 120 "SmallC.y"
    {
			pa=create("STSPEC");
			PNode c5 = create("RC");
			PNode c4 = pop(stack);
			PNode c3 = create("LC");
			PNode c2 = pop(stack);
			PNode c1 = create("STRUCT");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4); link(pa, c5);
			push(stack, pa);
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 131 "SmallC.y"
    {
			pa=create("STSPEC");
			PNode c2 = create(tmpS);
			PNode c1 = create("STRUCT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 139 "SmallC.y"
    {
			pa=create("OPTTAG");
			PNode c1 = create(tmpS);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 145 "SmallC.y"
    {
			pa=create("OPTTAG");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 152 "SmallC.y"
    {
			pa=create("VAR");
			PNode c1 = create(tmpS);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 158 "SmallC.y"
    {
			PNode c=create(tmpS);
			push(stackINT, c);
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 161 "SmallC.y"
    {
			pa=create("VAR");
			PNode c4 = create("RB");
			PNode c3 = pop(stackINT);
			PNode c2 = create("LB");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 172 "SmallC.y"
    {
			PNode c1 = create(tmpS); 
			push(stackID, c1);			
		}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 175 "SmallC.y"
    {
			pa=create("FUNC");
			PNode c4 = create("RP");
			PNode c3 = pop(stack);
			PNode c2 = create("LP");
			PNode c1 = pop(stackID);
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 186 "SmallC.y"
    {
			pa=create("PARAS");
			PNode c3 = pop(stack);
			PNode c2 = create("COMMA");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 194 "SmallC.y"
    {
			pa=create("PARAS");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 200 "SmallC.y"
    {
			pa=create("PARAS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 207 "SmallC.y"
    {
			pa=create("PARA");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 215 "SmallC.y"
    {
			pa=create("STMTBLOCK");
			PNode c4 = create("RC");
			PNode c3 = pop(stack);
			PNode c2 = pop(stack);
			PNode c1 = create("LC");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 226 "SmallC.y"
    {
			pa=create("STMTS");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 233 "SmallC.y"
    {
			pa=create("STMTS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 240 "SmallC.y"
    {
			pa=create("STMT");
			PNode c2 = create("SEMI");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 247 "SmallC.y"
    {
			pa=create("STMT");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 253 "SmallC.y"
    {
			pa=create("STMT");
			PNode c3 = create("SEMI");
			PNode c2 = pop(stack);
			PNode c1 = create("RETURN");
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 261 "SmallC.y"
    {
			pa=create("STMT");
			PNode c6 = pop(stack);
			PNode c5 = pop(stack);
			PNode c4 = create("RP");
			PNode c3 = pop(stack);
			PNode c2 = create("LP");
			PNode c1 = create("IF");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4); link(pa, c5); link(pa, c6);
			push(stack, pa);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 273 "SmallC.y"
    {
			pa=create("STMT");
			PNode c9 = pop(stack);
			PNode c8 = create("RP");
			PNode c7 = pop(stack);
			PNode c6 = create("SEMI");
			PNode c5 = pop(stack);
			PNode c4 = create("SEMI");
			PNode c3 = pop(stack);
			PNode c2 = create("LP");
			PNode c1 = create("FOR");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4); link(pa, c5); link(pa, c6);
			link(pa, c7); link(pa, c8); link(pa, c9);
			push(stack, pa);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 289 "SmallC.y"
    {
			pa=create("STMT");
			PNode c2 = create("SEMI");
			PNode c1 = create("CONT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 296 "SmallC.y"
    {
			pa=create("STMT");
			PNode c2 = create("SEMI");
			PNode c1 = create("BREAK");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 304 "SmallC.y"
    {
			pa=create("ESTMT");
			PNode c2 = pop(stack);
			PNode c1 = create("ELSE");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 311 "SmallC.y"
    {
			pa=create("ESTMT");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 318 "SmallC.y"
    {
			pa=create("DEFS");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 325 "SmallC.y"
    {
			pa=create("DEFS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 332 "SmallC.y"
    {
			pa=create("DEF");
			PNode c3 = create("SEMI");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 341 "SmallC.y"
    {
			pa=create("DECS");
			PNode c3 = pop(stack);
			PNode c2 = create("COMMA");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 349 "SmallC.y"
    {
			pa=create("DECS");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 356 "SmallC.y"
    {
			pa=create("DEC");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 362 "SmallC.y"
    {
			pa=create("DEC");
			PNode c3 = pop(stack);
			PNode c2 = create("ASSIGNOP");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 371 "SmallC.y"
    {
			pa=create("INIT");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 377 "SmallC.y"
    {
			pa=create("INIT");
			PNode c3 = create("RC");
			PNode c2 = pop(stack);
			PNode c1 = create("LC");
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 386 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BINARYOP");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 396 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("ASSIGNOP");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 406 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MULT");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 416 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("DIV");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 426 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MOD");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 436 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("ADD");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 446 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BINMINUS");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 456 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LSHIFT");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 466 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("RSHIFT");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 476 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("GREATER");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 486 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("NOLESSTHAN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 496 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LESS");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 506 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("NOGREATERTHAN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 516 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("EQUAL");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 526 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LSHIFTASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 536 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("RSHIFTASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 546 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("NOTEQUAL");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 556 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LOGIAND");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 566 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LOGIOR");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 576 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("ADDASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 586 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MINUSASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 67:

/* Line 1806 of yacc.c  */
#line 596 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MULTASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 606 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("DIVASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 616 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITANDASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 626 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITXORASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 636 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITORASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 646 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITAND");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 656 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITXOR");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 666 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITOR");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 676 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("UNARYOP");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 683 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("LOGINOT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 690 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("INCR");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 697 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("DECR");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 704 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("BITNOT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 711 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("UNARYMINUS");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 718 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = create("RP");
			PNode c2 = pop(stack);
			PNode c1 = create("LP");
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 728 "SmallC.y"
    {
			PNode c1 = create(tmpS); 
			push(stackID, c1);			
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 731 "SmallC.y"
    {
			pa=create("EXP");
			PNode c4 = create("RP");
			PNode c3 = pop(stack);
			PNode c2 = create("LP");
			PNode c1 = pop(stackID);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 743 "SmallC.y"
    {
			PNode c1 = create(tmpS); 
			push(stackID, c1);			
		}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 746 "SmallC.y"
    {
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = pop(stackID);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 753 "SmallC.y"
    {
			pa=create("EXP");
			PNode c3 = create(tmpS);
			PNode c2 = create("DOT");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 761 "SmallC.y"
    { 
			pa=create("EXP");
			PNode c1 = create(tmpS);
			if (link(pa, c1) == 1) push(stack, pa);
		}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 766 "SmallC.y"
    {
			pa=create("EXP");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 773 "SmallC.y"
    {
			pa=create("ARRS");
			PNode c4 = pop(stack);
			PNode c3 = create("RB");
			PNode c2 = pop(stack);
			PNode c1 = create("LB");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 783 "SmallC.y"
    {
			pa=create("ARRS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 790 "SmallC.y"
    {
				pa=create("ARGS");
				PNode c3 = pop(stack);
				PNode c2 = create("COMMA");
				PNode c1 = pop(stack);
				link(pa,c1); link(pa,c2); link(pa,c3);
				push(stack, pa);
			}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 798 "SmallC.y"
    {
			pa=create("ARGS");
			PNode c1 = pop(stack);
			link(pa,c1);
			push(stack, pa);
		}
    break;



/* Line 1806 of yacc.c  */
#line 3042 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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
      if (!yypact_value_is_default (yyn))
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 805 "SmallC.y"

int main(int argc, char *argv[])
{
	stack = (PStack)malloc(sizeof(Stack));
	stackID = (PStack)malloc(sizeof(Stack));
	stackINT = (PStack)malloc(sizeof(Stack));
	extern char* yytext;
	extern FILE *yyin, *yyout;
	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w+");
	yyparse();
	tmp = top(stack);
	printT(tmp, 0, yyout, flag);
	return 0;
}

int yyerror(char *msg)
{
	printf("Errorencountered: %s \n", msg);
	flag = 1;
}

