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
%token <token> TYPE
%token <token> LP RP LC RC COMMA SEMI ASSIGNOP

%type <node> EXTDEF SPEC VAR FUNC PARAS PARA STMTBLOCK DEFS DEF DECS DEC

%start	EXTDEF

%%
EXTDEF	:	SPEC FUNC STMTBLOCK{
			$$ = new NExtdef(*$1, *$2, *$3);
			program = $$;
		}
		;

SPEC	:	TYPE{
			$$ = new NType($1);
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
STMTBLOCK	:	LC DEFS RC{
				$$ = new NSBlock(*$2);
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

%%
