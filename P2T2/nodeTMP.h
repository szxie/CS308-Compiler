#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <sstream>
#include "content.h"
using namespace std;

class NType;
class NDECS2;

class Node {
public:
	virtual string codeGen(content* a) = 0;
};


class NType : public Node {
public:
	int type;
	NType(int type) : type(type) { }
	string codeGen(content* a) { 
		cout << "\n******NType\n";
		return "i32"; 
	}
};

class NFunc : public Node {
public:
	string name;
	Node& paras;
	NFunc(const string& name, Node& paras) : name(name), paras(paras) {}
	string codeGen(content* a) { 
		cout << "\n******NFunc\n";
		return "@"+name + "(" + paras.codeGen(a) + ")"; 
	}
};

class NPar : public Node {
public:
	Node& s1;
	Node& s2;
	NPar(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) {
		cout << "\n***NPar\n";
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a); 
		a->add(st1, st2);
		return st1 + " %" + st2; 
	}
};

class NID : public Node {
public:
	string id;
	NID(const string& id) : id(id) {}
	string codeGen(content* a) { 
		a->varS->push(id);
		return id; 
	}
};

class NParas : public Node {
public:
	Node& s1;
	Node& s2;
	NParas(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) { 
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		return st1 + ", " + st2; 
	}
};

class NEmpty : public Node {
public:
	NEmpty() {}
	string codeGen(content* a) { return ""; }
};

class NExtdef : public Node {
public:
	Node& s1;
	Node& s2;
	Node& s3;
	NExtdef(Node& s1, Node& s2, Node& s3) : s1(s1), s2(s2), s3(s3) {}
	string codeGen(content* a) { 
		cout <<"\n****NExtdef\n";
		a->def_global = false;
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		string st3 = s3.codeGen(a);
		string re = "";
		
		re += "define "+st1+" "+st2+" "+st3;
		return re;
	}
};

class NSBlock : public Node {
public:
	Node& s1, &s2;
	NSBlock(Node& s1, Node& s2) : s1(s1),s2(s2) {}
	string codeGen(content* a) {
		cout << "\n****NSB\n";
		string re = "{\nentry:\n";
		string tmpt;
		string tmpi;
		for(int i=0; i<a->size(); i++) {
			tmpt = a->get1T(i);
			tmpi = a->get1I(i);
			if (tmpt=="i32") {
				re += "\t%"+tmpi+".addr = alloca i32, align 4\n\tstore i32 %"+tmpi+", i32* %"+tmpi+".addr, align 4\n";
			}
		}
		a->clear();
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		re += st1;
		re += st2;
		return re+"}\n\n"; 	
	}
};

class NDEF : public Node {
public:
	Node& s1, &s2;
	NDEF(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) {
		string st1 = s1.codeGen(a);
		a->def_spec = st1;
		string st2 = s2.codeGen(a);
		string re = "";
		re += st2;
		return re;
	}
};

class NDEFS : public Node {
public:
	Node& s1, &s2;
	NDEFS(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) {
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		return st1+st2;
	}
};

class NDEC : public Node {
public:
	Node& s1;
	int value;
	NDEC(Node& s1, int value) : s1(s1),value(value) {}
	string codeGen(content* a) {
		a->assignop = true;
		stringstream ss;
		ss << value;
		string st1 = s1.codeGen(a);
		string st2 = ss.str();
		string re="";
		if (a->def_spec=="i32" ) {
			if (a->def_global==false)
				re = "\tstore i32 "+st2+", i32* %"+st1+", align 4\n";
			else
				re = st2;	
		}
		
		return re;
	}
};

class NDECS2 : public Node {
public:
	Node& s1;
	NDECS2(Node& s1) : s1(s1) {}
	string codeGen(content* a) {
		cout <<"\n***NDECS2\n";
		string st1 = s1.codeGen(a);
		string re="";
		if (a->def_spec=="i32") {
			re ="\t%"+a->varS->top()+" = alloca i32, align 4\n";
			a->varS->pop();	
		}
		if (a->assignop) {
			re += st1;
		}
		a->assignop = false;
		return re;
	}
};

class NDECS1 : public Node {//may be some improvement change the when to gen the code for the s2
public:
	Node& s1, &s2;
	NDECS1(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) {
		cout << "\n****NDECS1\n";
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);

		string re="";
		
		if (a->def_spec=="i32") {
			re ="\t%"+a->varS->top()+" = alloca i32, align 4\n";
			a->varS->pop();	
		}
		if (a->assignop) {
			re += st1;
		}
		re += st2;
		a->assignop = false;
		return re;
	}
};

class NSTMTS1 : public Node {
public:
	Node &s1, &s2;
	NSTMTS1(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) {
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		string re = "";
		re += st1;
		re += st2;
		return re;
	
	
	}
};

class NSTMTre : public Node {
public:
	Node &s1;
	NSTMTre(Node& s1) : s1(s1) {}
	string codeGen(content* a) {
		cout << "\n**NSTMTre\n";
		string st1 = s1.codeGen(a);
		string re = "";
		if (a->exp_int=="i32") {
			re += "\tret i32 " + st1 + "\n";
		}
		return re;
	}
};

class NEXPint : public Node {
public:
	int value;
	NEXPint(int value) : value(value) {}
	string codeGen(content* a) {
		a->exp_int = "i32";
		stringstream ss;
		ss << value;
		string st1 = ss.str();
		a->exp_intf = true;
		a->exp_id = false;
		a->expre = st1;
		return st1;
	}
};

class NSTMTexp : public Node {
public:
	Node &s1;
	NSTMTexp(Node& s1) : s1(s1) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		return st1;
	}
};

class NEXPfun : public Node {
public:
	string st1;
	Node &s2;
	NEXPfun(const string &st1, Node& s2) : st1(st1), s2(s2) {}
	string codeGen(content *a) {
		string st2 = s2.codeGen(a);
		string srT2 = a->exp_reT;
		string re = "";
		string sc;
		if (st1=="read") {
			int c = a->callnum++;
			sc = int2str(c);
				
			//re += "\t%call"+sc+" = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %"+st2+")\n";
			//re += "\t%call"+sc+" = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* "+srT2+")\n";
			return re;
		}
		
		if (st1=="write"){
			int c = a->callnum++;
			sc = int2str(c);
			if (a->exp_id) {
				int reg = a->regid++;
				string sreg = int2str(reg);
				re += "\t%"+sreg+" = load i32* "+srT2+", align 4\n";			
				re += "\t%call"+sc+" = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %"+sreg+")\n";	
			}
			else {
				if (!a->exp_intf) {
					re += st2;
					re += "\t%call"+sc+" = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %"+srT2+")\n";	
				}
				else {
					re += "\t%call"+sc+" = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 "+srT2+")\n";	
				}
			}
			return re;
		}
		a->expre = "call"+sc;
		a->exp_reT = "%call"+sc;
		return re;
	}
};

class NARGSexp : public Node {
public:
	Node &s1;
	NARGSexp(Node& s1) : s1(s1) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		//need the result of the experision
		string re = "";
		re += st1;
		return re;
	}
};

class NEXPid : public Node {
public:
	string id;
	Node& s2;
	NEXPid(const string &id, Node& s2) : id(id),s2(s2) {}
	string codeGen(content *a) {
		a->exp_id=true; // address flag for fun call
		a->expre = id;
		string st2 = s2.codeGen(a);
		string re = "";
		re += id + st2;
		a->exp_id = true;
		a->exp_intf = false;
		int num = find(a->globalVar, id);
		if (num!=-1) 
			a->exp_reT = "@"+id;
		else
			a->exp_reT = "%"+id;
		
		return id;
	}
};

class NEXPbinop : public Node {
public:
	Node &s1, &s2;
	int op;
	NEXPbinop(Node &s1, int op, Node &s2) : s1(s1),op(op),s2(s2) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		string sr1 = a->expre;
		bool fs1 = a->exp_id;
		bool fsint1 = a->exp_intf;
		
		string st2 = s2.codeGen(a);
		string sr2 = a->expre;
		bool fs2 = a->exp_id;
		bool fsint2 = a->exp_intf;
		
		string re = "";
		string op1, op2;
		
		if (op == 272) {//ADD
			if (!fs1 && !fsint1) re += st1;
			
			int addid = a->addid++;
			string sadd = int2str(addid);
			int regid;
			string sreg;
			
			if (fs1) {
				regid = a->regid++;
				sreg = int2str(regid);
			//re += "\t%"+sreg+" = load i32* %"+st1+", align 4\n";
				re += "\t%"+sreg+" = load i32* %"+sr1+", align 4\n";
				op1 = sreg;
			}
			else {
				op1 = sr1;
			}
			if (fs2) {
				regid = a->regid++;
				sreg = int2str(regid);
			//re += "\t%"+sreg+" = load i32* %"+st1+", align 4\n";
				re += "\t%"+sreg+" = load i32* %"+sr2+", align 4\n";
				op2 = sreg;
			}
			else {
				op2 = sr2;
			}
			
			if (!fsint1) {
				re += "\t%add"+sadd+" = add nsw i32 %"+op1;
			}
			else
				re += "\t%add"+sadd+" = add nsw i32 "+op1;
			if (!fsint2)
				re += ", %"+op2+"\n";
			else
				re += ", "+op2+"\n";
				
			//re += "\t%add"+sadd+" = add nsw i32 %"+op1+", %"+op2+"\n";
			a->expre = "add"+sadd;
			a->exp_reT = "%"+a->expre;
			a->exp_id = false;
			a->exp_intf = false;
			a->exp_op = "add";
			return re;
		}
		if (op == 271) {//euqal
			string sreg;
			if (fs1) {
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* %"+sr1+", align 4\n";
				op1 = sreg;			
			}
			else {
				op1 = sr1;
			}
			if (fs2) {
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* %"+sr2+", align 4\n";
				op2 = sreg;				
			}
			else {
				op2 = sr2;
			}
			
			int cmpid = a->cmpid++;
			if (!fsint1)
				re += "\t%cmp"+int2str(cmpid)+" = icmp eq i32 %"+op1;
			else
				re += "\t%cmp"+int2str(cmpid)+" = icmp eq i32 "+op1;
			if (!fsint2)
				re += ", %"+op2+"\n";
			else
				re += ", "+op2+"\n";
			a->exp_id = false;
			a->exp_intf = false;
			a->exp_op = "equal";
			a->expre = "cmp"+int2str(cmpid);
			a->exp_reT = "%"+a->expre;
			return re;
		}
		return re;
	}
};


class NSTMTif : public Node {
public:
	Node &s1, &s2, &s3;
	NSTMTif(Node &s1, Node &s2, Node &s3) : s1(s1),s2(s2),s3(s3) {}
	string codeGen(content *a) {
		int ifnum = a->ifnum++;
		string st1 = s1.codeGen(a);
		string sr1 = a->expre;
		string sop1 = a->exp_op;
		string st2 = s2.codeGen(a);
		string st3 = s3.codeGen(a);
		string re = "";
		
		if (sop1 == "equal" || sop1 == "loginot") {
			re += st1;
		}
		
		re += "\tbr i1 %"+sr1+", label %if.then"+int2str(ifnum)+", label %if.else"+int2str(ifnum)+"\n\n";
		re += "if.then"+int2str(ifnum)+":\n";
		re += st2;
		re += "br label %if.end"+int2str(ifnum)+"\n\n";
		re += "if.else"+int2str(ifnum)+":\n";
		re += st3;
		re += "br label %if.end"+int2str(ifnum)+"\n\n";
		re += "if.end"+int2str(ifnum)+":\n";
		return re;
	}
};

class NESTMT : public Node {
public:
	Node &s1;
	NESTMT(Node &s1) : s1(s1) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		return st1;
	}
};

class NEXPunaryop : public Node {
public:
	int op;
	Node &s1;
	NEXPunaryop(int op, Node &s1) : op(op),s1(s1) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		string sr1 = a->expre;
		bool fs1 = a->exp_id;
		bool fsint1 = a->exp_intf;
		string re = "";
		if (op== 273) {//loginot
			string op1;
			string sreg;
			if (fs1){
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* %"+sr1+", align 4\n";
				op1 = sreg;
			}
			else
				op1 = sr1;	
			
			int cmpid = a->cmpid++;
			//re +=  "\t%cmp"+int2str(cmpid)+" = icmp ne i32 %"+op1+", 0\n";
			re +=  "\t%cmp"+int2str(cmpid)+" = icmp eq i32 %"+op1+", 0\n";//different from c
			a->exp_op = "loginot";
			a->expre = "cmp"+int2str(cmpid);
			a->exp_reT = "%"+a->expre;
			a->exp_id = false;
			a->exp_intf= false;
			return re;
		}
		return re;
	}
};

class NEXTDEFS : public Node {
public:
	Node &s1, &s2;
	NEXTDEFS(Node &s1, Node &s2) : s1(s1),s2(s2) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		string re = "";
		re += st1 + st2;
		return re;
	}
};

class NPROGRAM : public Node {
public:
	Node &s1;
	NPROGRAM(Node &s1) : s1(s1) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		string re = "";
		re += "@.str = private unnamed_addr constant [3 x i8] c\"%d\\00\", align 1\n\n";
		re += "@.str1 = private unnamed_addr constant [4 x i8] c\"%d\\0A\\00\", align 1\n\n";
		re +="declare i32 @__isoc99_scanf(i8*, ...)\n\ndeclare i32 @printf(i8*, ...)\n\n";
		re += st1;
		return re;
	}
};

class NEXTVARS1 : public Node {
public:
	Node &s1;
	NEXTVARS1(Node &s1) : s1(s1) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		string re="";
		if (a->def_spec=="i32") {
			if (!a->assignop)
				re +="@"+a->varS->top()+" = common global i32 0, align 4\n";
			else
				re +="@"+a->varS->top()+" = global i32 "+st1+", align 4\n";
			a->globalVar->push_back(a->varS->top());
			a->varS->pop();
			a->assignop = false;	
		}
		return re;
	}
};

class NEXTVARS2 : public Node {
public:
	Node &s1, &s2;
	NEXTVARS2(Node &s1, Node &s2) : s1(s1), s2(s2) {}
	string codeGen(content *a) {
		string st1 = s1.codeGen(a);
		string re = "";
		if (a->def_spec=="i32") {
			if (!a->assignop)
				re +="@"+a->varS->top()+" = common global i32 0, align 4\n";
			else
				re +="@"+a->varS->top()+" = global i32 "+st1+", align 4\n";
			a->varS->pop();
			a->assignop = false;
		}
		a->globalVar->push_back(a->varS->top());
		string st2 = s2.codeGen(a);
		re += st2;
		return re;
	}
};

class NEXTDEF1 : public Node {
public:
	Node &s1, &s2;
	NEXTDEF1(Node &s1, Node &s2) : s1(s1),s2(s2) {}
	string codeGen(content *a) {
		a->def_global = true;
		string st1 = s1.codeGen(a);
		a->def_spec = st1;
		string st2 = s2.codeGen(a);
		string re = "";
		re +=  st2;
		return re;
	}
};
#endif
