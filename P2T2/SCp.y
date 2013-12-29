%{
#include "node.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

Node *program;

extern int yylex();
void yyerror(const char *s) 
{ 
	std::printf("Error:%s\n", s);
	std::exit(1);
}

%}

%union {
	Node *node;
		
	std::string *string;
	int token;
}
%token <string> INT ID
%token <token> RETURN IF ELSE STRUCT TYPE
%token <token> LP RP LB RB LC RC COMMA DOT SEMI ASSIGNOP
%token <token> BITXOR EQUAL MOD ADD MINUS LOGINOT

%right 	ASSIGNOP
%left	BITXOR
%left	EQUAL
%left	ADD MINUS
%left 	MOD
%right	UMINUS
%right 	LOGINOT

%type <node> PROGRAM EXTDEFS EXTDEF EXTVARS SPEC STSPEC OPTTAG VAR FUNC PARAS PARA STMTBLOCK STMTS STMT ESTMT DEFS DEF DECS DEC EXP ARRS ARGS

%start	PROGRAM

%%
PROGRAM	:	EXTDEFS{
			$$ = new NPROGRAM(*$1);
			program = $$;
		}
		;
EXTDEFS	:	EXTDEF EXTDEFS{
			$$ = new NEXTDEFS(*$1, *$2);
		}
		|	{
			$$ = new NEmpty();			
		}
		;
EXTDEF	:	SPEC EXTVARS SEMI{
			$$ = new NEXTDEF1(*$1, *$2);
		}
		|	SPEC FUNC STMTBLOCK{
			$$ = new NExtdef(*$1, *$2, *$3);
		}
		;
EXTVARS	:	DEC{
			$$ = new NEXTVARS1(*$1);
		}
		|	DEC COMMA EXTVARS{
			$$ = new NEXTVARS2(*$1, *$3);
		}
		|	{
			$$ = new NEmpty();
		}
		;
SPEC	:	TYPE{
			$$ = new NType($1);
		}
		|	STSPEC{
			$$ = $1;
		}
		;
STSPEC	:	STRUCT OPTTAG LC DEFS RC{
			$$ = new NSTSPEC1(*$2, *$4);
		}
		|	STRUCT ID{
			$$ = new NSTSPEC2(*$2);
		}
		;
OPTTAG	:	ID{
			$$ = new NOPTTAG(*$1);
		}
		|	{
			$$ = new NEmpty();
		}
		;
VAR		:	ID{
			$$ = new NID(*$1);
			delete $1;
		}
		;
FUNC	:	ID LP PARAS RP{
			$$ = new NFunc(*$1, *$3);
			delete $1;
		}
		;
PARAS	:	PARA COMMA PARAS{
			$$ = new NParas(*$1, *$3);
		}
		|	PARA{
			$$ = $1;
		}
		|	{
			$$ = new NEmpty();
		}
		;
PARA	:	SPEC VAR{
			$$ = new NPar(*$1, *$2);
		}
		;
STMTBLOCK	:	LC DEFS STMTS RC{
				$$ = new NSBlock(*$2, *$3);
			}
			;
STMTS	:	STMT STMTS{
			$$ = new NSTMTS1(*$1, *$2);
		}
		|	{
			$$ = new NEmpty();
		}
		;
STMT	:	EXP SEMI{
			$$ = new NSTMTexp(*$1);
		}
		|	RETURN EXP SEMI{
			$$ = new NSTMTre(*$2);
		}
		|	IF LP EXP RP STMT ESTMT{
			$$ = new NSTMTif(*$3, *$5, *$6);
		}
		;
ESTMT	:	ELSE STMT{
			$$ = new NESTMT(*$2);
		}
		|	{
			$$ = new NEmpty();
		}
		;	
DEFS	:	DEF DEFS{
			$$ = new NDEFS(*$1, *$2);
		}
		|	{
			$$ = new NEmpty();
		}
		;
DEF		:	SPEC DECS SEMI{
			$$ = new NDEF(*$1, *$2);
		}
		;
DECS	:	DEC COMMA DECS{
			$$ = new NDECS1(*$1, *$3);
		}	
		|	DEC{
			$$ = new NDECS2(*$1);
		}
		;
DEC		:	VAR{
			$$ = $1;
		}
		|	VAR ASSIGNOP INT{
			$$ = new NDEC(*$1,atol($3->c_str()));
		}
		;
EXP		:	EXP ASSIGNOP EXP{
			$$ = new NEXPbinop(*$1, $2, *$3);
		}
		|	EXP MOD EXP{
			$$ = new NEXPbinop(*$1, $2, *$3);
		}
		|	EXP ADD EXP{
			$$ = new NEXPbinop(*$1, $2, *$3);
		}
		|	EXP EQUAL EXP{
			$$ = new NEXPbinop(*$1, $2, *$3);
		}
		|	EXP BITXOR EXP{
			$$ = new NEXPbinop(*$1, $2, *$3);
		}
		|	LOGINOT EXP{
			$$ = new NEXPunaryop($1, *$2);
		}
		|	MINUS EXP	%prec UMINUS{
			$$ = new NEXPunaryop($1, *$2);
		}
		|	LP EXP RP{
			$$ = $2;
		}
		|	ID LP ARGS RP{
			$$ = new NEXPfun(*$1, *$3);
		}
		|	ID ARRS{
			$$  = new NEXPid(*$1, *$2);
		}
		|	EXP DOT ID{
			$$ = new NEXPdot(*$1, *$3);
		}
		|	INT{
			//$$ = new NEXPint(atol($1->c_str()));
			$$ = new NEXPint(*$1);
		}
		|	{
			$$ = new NEmpty();
		}
		;
ARRS	:	{
			$$ = new NEmpty();
		}
		;
ARGS	:	EXP COMMA ARGS{
			$$ = new NARGS1(*$1, *$3);
		}
		|	EXP{
			$$ = new NARGSexp(*$1);
		}
		;

%%
