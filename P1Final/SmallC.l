%{
/*
	SmallC.l for flex
	get all the tokens
	tmpS to store the integer or identifier
	integer contains "0X(0x)" or "0"

	I distinguish all the binary operators and unary operators, and consider them as different tokens. 
	
	by:Jinyi
*/
#include <stdio.h>
#include "y.tab.h"
char *tmpS;
%}

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
int	(0(X|x)?)?[0-9]+
%%

{ws}	;
{int}	{	tmpS=(char*)malloc(sizeof(char)*100);
		strcpy(tmpS, "INT: ");
		strcat(tmpS, yytext);
		return (INT);
	}
if	return (IF);
else	return (ELSE);
break	return (BREAK);
continue	return(CONT);
for	return (FOR);
struct	return (STRUCT);
return	return (RETURN);
int	return (TYPE);	
";"	return(SEMI);
","	return(COMMA);
"."	return(DOT);
"="	return(ASSIGNOP);
"("	return(LP);
")"	return(RP);
"["	return(LB);
"]"	return(RB);
"{"	return(LC);
"}"	return(RC);
{id}	{	tmpS=(char*)malloc(sizeof(char)*100);
		strcpy(tmpS, "ID: ");
		strcat(tmpS, yytext);
		return (ID);
	}
"*"	return (MULT);
"/"	return (DIV);
"%"	return (MOD);
"+"	return (ADD);
"-"	return (MINUS);
"<<"	return (LSHIFT);
">>"	return (RSHIFT);
">"	return (GREATER);
">="	return (NOLESSTHAN);
"<"	return (LESS);
"<="	return (NOGREATERTHAN);
"=="	return (EQUAL);
"<<="	return (LSHIFTASSIGN);
">>="	return (RSHIFTASSIGN);
"!="	return (NOTEQUAL);
"&&"	return (LOGIAND);
"||"	return (LOGIOR);
"+="	return (ADDASSIGN);
"-="	return (MINUSASSIGN);
"*="	return (MULTASSIGN);
"/="	return (DIVASSIGN);
"&="	return (BITANDASSIGN);
"^="	return (BITXORASSIGN);
"|="	return (BITORASSIGN);
"&"	return (BITAND);
"^"	return (BITXOR);
"|"	return (BITOR);

"!"	return (LOGINOT);
"++"	return (INCR);
"--"	return (DECR);
"~"	return (BITNOT);
%%
int yywrap()
{
	return 1;
}
