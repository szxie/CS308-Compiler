#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "codegen.h"
#include "node.h"

using namespace std;

extern int yyparse();
extern FILE *yyin;
extern NBlock* programBlock;

void createCoreFunctions(CodeGenContext& context);

int main(int argc, char **argv)
{
	yyin = fopen(argv[1], "r");
	yyparse();
	InitializeNativeTarget();
	CodeGenContext context;
	createCoreFunctions(context);
	context.generateCode(*programBlock);
	context.runCode();
	return 0;
}
