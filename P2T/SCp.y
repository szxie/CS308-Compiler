%{
#include "node.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
NBlock *programBlock;
extern int yylex();
void yyerror(const char *s) 
{ 
	std::printf("Error:%s\n", s);
	std::exit(1);
}

%}

%union {
	Node *node;
	NBlock *block;
	NExpression *expr;
	NStatement *stmt;
	std::string *string;
	int token;
}

%token <token> ADD
%token <string> INT

%type <expr> EXP

%start	EXP

%%
DEC :	VAR ASSIGNOP INIT
	;
	
EXP	:	EXP ADD EXP{
		$$ = new NBinaryOperator(*$1, $2, *$3);			
	}
	|	INT{
		$$ = new NInteger(atol($1->c_str()));
		delete $1;			
	}
	;
		
%%
