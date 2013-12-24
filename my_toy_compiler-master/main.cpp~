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
    cout << "********1******\n";
	std::cout << programBlock << endl;
    // see http://comments.gmane.org/gmane.comp.compilers.llvm.devel/33877
    cout << "********2******\n";
	InitializeNativeTarget();
	    cout << "********3******\n";
	CodeGenContext context;
	    cout << "********4******\n";
	createCoreFunctions(context);
	    cout << "********5******\n";
	context.generateCode(*programBlock);
	    cout << "********6******\n";
	context.runCode();
	    cout << "********7******\n";
	
	return 0;
}

