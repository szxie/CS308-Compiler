%{
/*
	SmallC.l for flex
	get all the tokens
	tmpS to store the integer or identifier
	integer contains "0X(0x)" or "0"

	I distinguish all the binary operators and unary operators, and consider them as different tokens. 
	
	by:Jinyi
*/
#include <string>
#include "node.h"
#include "SCp.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)


%}

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
int	(0(X|x)?)?[0-9]+
%%

{ws}	;
{int}	SAVE_TOKEN;	return INT;
if		return TOKEN(IF);
else	return TOKEN(ELSE);
break	return TOKEN(BREAK);
continue	return TOKEN(CONT);
for		return TOKEN(FOR);
struct	return TOKEN(STRUCT);
return	return TOKEN(RETURN);
int		return TOKEN(TYPE);	
";"		return TOKEN(SEMI);
","		return TOKEN(COMMA);
"."		return TOKEN(DOT);
"="		return TOKEN(ASSIGNOP);
"("		return TOKEN(LP);
")"		return TOKEN(RP);
"["		return TOKEN(LB);
"]"		return TOKEN(RB);
"{"		return TOKEN(LC);
"}"		return TOKEN(RC);
{id}	SAVE_TOKEN; return ID;
"*"		return TOKEN(MULT);
"/"		return TOKEN(DIV);
"%"		return TOKEN(MOD);
"+"		return TOKEN(ADD);
"-"		return TOKEN(MINUS);
"<<"	return TOKEN(LSHIFT);
">>"	return TOKEN(RSHIFT);
">"		return TOKEN(GREATER);
">="	return TOKEN(NOLESSTHAN);
"<"		return TOKEN(LESS);
"<="	return TOKEN(NOGREATERTHAN);
"=="	return TOKEN(EQUAL);
"<<="	return TOKEN(LSHIFTASSIGN);
">>="	return TOKEN(RSHIFTASSIGN);
"!="	return TOKEN(NOTEQUAL);
"&&"	return TOKEN(LOGIAND);
"||"	return TOKEN(LOGIOR);
"+="	return TOKEN(ADDASSIGN);
"-="	return TOKEN(MINUSASSIGN);
"*="	return TOKEN(MULTASSIGN);
"/="	return TOKEN(DIVASSIGN);
"&="	return TOKEN(BITANDASSIGN);
"^="	return TOKEN(BITXORASSIGN);
"|="	return TOKEN(BITORASSIGN);
"&"		return TOKEN(BITAND);
"^"		return TOKEN(BITXOR);
"|"		return TOKEN(BITOR);

"!"		return TOKEN(LOGINOT);
"++"	return TOKEN(INCR);
"--"	return TOKEN(DECR);
"~"		return TOKEN(BITNOT);
%%
int yywrap()
{
	return 1;
}
