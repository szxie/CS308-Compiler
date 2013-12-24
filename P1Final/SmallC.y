%{
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
%}

%token	INT TYPE STRUCT RETURN IF ELSE BREAK CONT 
	FOR ID SEMI COMMA LC RC BINARYOP UNARYOP
%right 	ASSIGNOP ADDASSIGN MINUSASSIGN MULTASSIGN LSHIFTASSIGN RSHIFTASSIGN DIVASSIGN BITANDASSIGN BITXORASSIGN BITORASSIGN
%left	LOGIOR
%left 	LOGIAND
%left	BITOR 
%left	BITXOR
%left	BITAND
%left	EQUAL NOTEQUAL
%left	GREATER LESS NOGREATERTHAN NOLESSTHAN
%left	LSHIFT RSHIFT
%left  	ADD MINUS
%left 	MULT DIV MOD
%right	UMINUS
%right 	LOGINOT BITNOT INCR DECR
%right 	LB LP
%left   RB RP DOT
%%
PROGRAM	:	EXTDEFS{
			pa=create("PROGRAM");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	;
EXTDEFS	:	EXTDEF EXTDEFS{
			pa=create("EXTDEFS");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	{
			pa=create("EXTDEFS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
EXTDEF	:	SPEC EXTVARS SEMI{
			pa=create("EXTDEF");
			PNode c3 = create("SEMI");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	|	SPEC FUNC STMTBLOCK{
			pa=create("EXTDEF");
			PNode c3 = pop(stack);
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	;
EXTVARS	:	DEC{
			pa=create("EXTVARS");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	|	DEC COMMA EXTVARS{
			pa=create("EXTVARS");
			PNode c3 = pop(stack);
			PNode c2 = create("COMMA");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	|	{
			pa=create("EXTVARS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
SPEC	:	TYPE{
			pa=create("SPEC");
			PNode c1 = create("TYPE");
			link(pa, c1);
			push(stack, pa);
		}
	|	STSPEC{
			pa=create("SPEC");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}	
	;
STSPEC	:	STRUCT OPTTAG LC DEFS RC{
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
	|	STRUCT ID{
			pa=create("STSPEC");
			PNode c2 = create(tmpS);
			PNode c1 = create("STRUCT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	;
OPTTAG	:	ID{
			pa=create("OPTTAG");
			PNode c1 = create(tmpS);
			link(pa, c1);
			push(stack, pa);
		}
	|	{
			pa=create("OPTTAG");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
VAR	:	ID{
			pa=create("VAR");
			PNode c1 = create(tmpS);
			link(pa, c1);
			push(stack, pa);
		}
	|	VAR LB INT{
			PNode c=create(tmpS);
			push(stackINT, c);
		} RB{
			pa=create("VAR");
			PNode c4 = create("RB");
			PNode c3 = pop(stackINT);
			PNode c2 = create("LB");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
	;
FUNC	:	ID{
			PNode c1 = create(tmpS); 
			push(stackID, c1);			
		} LP PARAS RP{
			pa=create("FUNC");
			PNode c4 = create("RP");
			PNode c3 = pop(stack);
			PNode c2 = create("LP");
			PNode c1 = pop(stackID);
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
	;
PARAS	:	PARA COMMA PARAS{
			pa=create("PARAS");
			PNode c3 = pop(stack);
			PNode c2 = create("COMMA");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	|	PARA{
			pa=create("PARAS");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	|	{
			pa=create("PARAS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
PARA	:	SPEC VAR{
			pa=create("PARA");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	;
STMTBLOCK	:	LC DEFS STMTS RC{
			pa=create("STMTBLOCK");
			PNode c4 = create("RC");
			PNode c3 = pop(stack);
			PNode c2 = pop(stack);
			PNode c1 = create("LC");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
		;
STMTS	:	STMT STMTS{
			pa=create("STMTS");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	{
			pa=create("STMTS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}	
	;
STMT	:	EXP SEMI{
			pa=create("STMT");
			PNode c2 = create("SEMI");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	STMTBLOCK{
			pa=create("STMT");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	|	RETURN EXP SEMI{
			pa=create("STMT");
			PNode c3 = create("SEMI");
			PNode c2 = pop(stack);
			PNode c1 = create("RETURN");
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	|	IF LP EXP RP STMT ESTMT{
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
	|	FOR LP EXP SEMI EXP SEMI EXP RP STMT{
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
	|	CONT SEMI{
			pa=create("STMT");
			PNode c2 = create("SEMI");
			PNode c1 = create("CONT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	BREAK SEMI{
			pa=create("STMT");
			PNode c2 = create("SEMI");
			PNode c1 = create("BREAK");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	;
ESTMT	:	ELSE STMT{
			pa=create("ESTMT");
			PNode c2 = pop(stack);
			PNode c1 = create("ELSE");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	{
			pa=create("ESTMT");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
DEFS	:	DEF DEFS{
			pa=create("DEFS");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	{
			pa=create("DEFS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
DEF	:	SPEC DECS SEMI{
			pa=create("DEF");
			PNode c3 = create("SEMI");
			PNode c2 = pop(stack);
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	;
DECS	:	DEC COMMA DECS{
			pa=create("DECS");
			PNode c3 = pop(stack);
			PNode c2 = create("COMMA");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	|	DEC{
			pa=create("DECS");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	;
DEC	:	VAR{
			pa=create("DEC");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	|	VAR ASSIGNOP INIT{
			pa=create("DEC");
			PNode c3 = pop(stack);
			PNode c2 = create("ASSIGNOP");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	;
INIT	:	EXP{
			pa=create("INIT");
			PNode c1 = pop(stack);
			link(pa, c1);
			push(stack, pa);
		}
	|	LC ARGS RC{
			pa=create("INIT");
			PNode c3 = create("RC");
			PNode c2 = pop(stack);
			PNode c1 = create("LC");
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	;
EXP	:	EXP BINARYOP EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BINARYOP");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP ASSIGNOP EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("ASSIGNOP");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP MULT EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MULT");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP DIV EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("DIV");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP MOD EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MOD");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP ADD EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("ADD");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP MINUS EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BINMINUS");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP LSHIFT EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LSHIFT");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP RSHIFT EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("RSHIFT");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP GREATER EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("GREATER");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP NOLESSTHAN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("NOLESSTHAN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP LESS EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LESS");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP NOGREATERTHAN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("NOGREATERTHAN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP EQUAL EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("EQUAL");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP LSHIFTASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LSHIFTASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP RSHIFTASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("RSHIFTASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP NOTEQUAL EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("NOTEQUAL");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP LOGIAND EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LOGIAND");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP LOGIOR EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("LOGIOR");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP ADDASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("ADDASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP MINUSASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MINUSASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP MULTASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("MULTASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP DIVASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("DIVASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP BITANDASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITANDASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP BITXORASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITXORASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP BITORASSIGN EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITORASSIGN");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP BITAND EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITAND");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP BITXOR EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITXOR");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	EXP BITOR EXP{
			pa=create("EXP");
			PNode c3 = pop(stack);
			PNode c2 = create("BITOR");
			PNode c1 = pop(stack);
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	UNARYOP EXP{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("UNARYOP");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	LOGINOT EXP{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("LOGINOT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	INCR EXP{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("INCR");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	DECR EXP{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("DECR");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	BITNOT EXP{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("BITNOT");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	MINUS EXP	%prec UMINUS{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = create("UNARYMINUS");
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	LP EXP RP{
			pa=create("EXP");
			PNode c3 = create("RP");
			PNode c2 = pop(stack);
			PNode c1 = create("LP");
			link(pa, c1);
			link(pa, c2);
			link(pa, c3);
			push(stack, pa);
		}
	|	ID{
			PNode c1 = create(tmpS); 
			push(stackID, c1);			
		} LP ARGS RP{
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
	|	ID{
			PNode c1 = create(tmpS); 
			push(stackID, c1);			
		}  ARRS{
			pa=create("EXP");
			PNode c2 = pop(stack);
			PNode c1 = pop(stackID);
			link(pa, c1); link(pa, c2);
			push(stack, pa);
		}
	|	EXP DOT ID{
			pa=create("EXP");
			PNode c3 = create(tmpS);
			PNode c2 = create("DOT");
			PNode c1 = pop(stack);
			link(pa, c1); link(pa, c2); link(pa, c3);
			push(stack, pa);
		}
	|	INT{ 
			pa=create("EXP");
			PNode c1 = create(tmpS);
			if (link(pa, c1) == 1) push(stack, pa);
		}
	|	{
			pa=create("EXP");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
ARRS	:	LB EXP RB ARRS{
			pa=create("ARRS");
			PNode c4 = pop(stack);
			PNode c3 = create("RB");
			PNode c2 = pop(stack);
			PNode c1 = create("LB");
			link(pa, c1); link(pa, c2); link(pa, c3);
			link(pa, c4);
			push(stack, pa);
		}
	|	{
			pa=create("ARRS");
			PNode c1 = create("EMPTY");
			link(pa, c1);
			push(stack, pa);
		}
	;
ARGS	:	EXP COMMA ARGS{
				pa=create("ARGS");
				PNode c3 = pop(stack);
				PNode c2 = create("COMMA");
				PNode c1 = pop(stack);
				link(pa,c1); link(pa,c2); link(pa,c3);
				push(stack, pa);
			}
	|	EXP{
			pa=create("ARGS");
			PNode c1 = pop(stack);
			link(pa,c1);
			push(stack, pa);
		}
	;
%%
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
