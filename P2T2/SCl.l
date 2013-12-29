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
mix	[A-F0-9]+
les	[0-7]+
id	{letter}({letter}|{digit})*
ints	0(X|x){mix}
inte	0{les}
intt	[0-9]+
int		{ints}|{intt}|{inte}
%%

{ws}	;
{int}	SAVE_TOKEN; return INT;
if		return TOKEN(IF);
else	return TOKEN(ELSE);
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
"%"		return TOKEN(MOD);
"+"		return TOKEN(ADD);
"-"		return TOKEN(MINUS);
"=="	return TOKEN(EQUAL);
"^"		return TOKEN(BITXOR);
"!"		return TOKEN(LOGINOT);
%%

