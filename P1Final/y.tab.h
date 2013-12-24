/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


