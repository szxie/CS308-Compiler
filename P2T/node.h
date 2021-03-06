#include <iostream>
#include <vector>
#include <llvm/IR/Value.h>

class CodeGenContext;
class NStatement;
class NExpression;

typedef std::vector<NStatement*> StatementList;

class Node {
public:
	virtual ~Node() {}
	virtual llvm::Value* codeGen(CodeGenContext& context) 
	{ return NULL; }
};

class NExpression : public Node {

};

class NStatement : public Node {

};

class NInteger : public NExpression {
public:
	long long value;
	NInteger(long long value) : value(value) 
	{ std::cout << value << std::endl; }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBinaryOperator : public NExpression {
public:
	int op;
	NExpression& lhs;
	NExpression& rhs;
	NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
		lhs(lhs), rhs(rhs), op(op) 
	{ std::cout<< op << std::endl;  }
	virtual llvm::Value* codeGen(CodeGenContext& context);
};

class NBlock : public NExpression {
public:
	StatementList statements;
	NBlock() {}
	virtual llvm::Value* codeGen(CodeGenContext& context);
};
