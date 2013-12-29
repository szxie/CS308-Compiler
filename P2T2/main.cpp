#include <iostream>
#include <fstream>
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
	ofstream fout("test.s");
	yyparse();
	
	content* a = new content();
	a->clear();
	string re = program->codeGen(a);
	cout << re;
	fout << re;
	fout.close();
	return 0;
}
