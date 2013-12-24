#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "node.h"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern Node *program;

int main(int argc, char **argv)
{
	yyin = fopen(argv[1], "r");
	yyparse();
	
	content* a = new content();
	a->clear();
	
	cout << program->codeGen(a) << endl;
	return 0;
}