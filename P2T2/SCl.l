%{
#include <string>
#include "node.h"
#include "SCp.hpp"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
%}
%option noyywrap

delim	[ \t\n]
ws	{delim}+
letter	[A-Za-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
int	(0(X|x)?)?[0-9]+
%%

{ws}	;
{int}	SAVE_TOKEN; return INT;
int		return TOKEN(TYPE);
";"		return TOKEN(SEMI);
","		return TOKEN(COMMA);
"="		return TOKEN(ASSIGNOP);
"("		return TOKEN(LP);
")"		return TOKEN(RP);
"{"		return TOKEN(LC);
"}"		return TOKEN(RC);
{id}	SAVE_TOKEN; return ID;

%%
