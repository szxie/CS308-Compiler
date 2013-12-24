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
{int}	SAVE_TOKEN;	return INT;

"+"		return TOKEN(ADD);

%%

