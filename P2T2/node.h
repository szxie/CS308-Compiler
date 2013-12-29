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
		a->spec_rec = "i32";
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
		a->regid = 0;
		a->callnum = a->ifnum = a->cmpid = a->addid = a->remid = a->xorid = a->subid = 0;
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		string st3 = s3.codeGen(a);
		string re = "";
		
		re += "\ndefine "+st1+" "+st2+" "+st3;
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
				a->par->push_back(tmpi);
			
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
		cout << "***NDEFS\n";
		string st1 = s1.codeGen(a);
		a->spec->push_back(a->spec_rec);
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
		if (a->NSTSPEC_f) {
			a->structElem->back()->push_back(st1);
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
		if (a->NSTSPEC_f) {
			a->structElem->back()->push_back(st1);
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
		string srT1 = a->exp_reT;
		string re = "";
		if (a->exp_id) {
			int regid = a->regid++;
			re += "\t%"+int2str(regid)+" = load i32* "+srT1+", align 4\n";
			re += "\tret i32 %"+int2str(regid)+"\n";
		}
		else{
			if (!a->exp_intf) re += st1;
			re += "\tret i32 "+srT1+"\n";
		}
		a->stmt_ret = true;		
		return re;
	}
};

/*
class NEXPint : public Node {
public:
	int value;
	NEXPint(int value) : value(value) {}
	string codeGen(content* a) {
		cout << "value: " << value << endl;
		a->exp_int = "i32";
		stringstream ss;
		ss << value;
		string st1 = ss.str();
		
		
		a->exp_intf = true;
		a->exp_id = false;
		a->expre = st1;
		a->exp_reT = st1;
		return st1;
	}
};
*/

class NEXPint : public Node {
public:
	string value;
	NEXPint(const string &value) : value(value) {}
	string codeGen(content* a) {
		cout << "value: " << value << endl;
		cout << value.length() << endl;
		string st1 = value;
		int num;
		if (value.length()>1){
			if (value[0] == '0' && value[1] != 'x' && value[1] != 'X'){
				cout << "8!!\n";
				num = strtol(value.c_str(), NULL, 8);
				st1 = int2str(num);
			}
			if (value.length()>2){
				if (value[0]=='0' &&(value[1]=='x'||value[1]=='X')) {
					cout << "16!!\n";
					num = strtol(value.c_str(), NULL, 16);
					st1 = int2str(num);
				}
			}
		}
		
		a->exp_int = "i32";
		
		a->exp_intf = true;
		a->exp_id = false;
		a->expre = st1;
		a->exp_reT = st1;
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
		string st2;
		string srT2;
		string re = "";
		string sc;
		if (st1=="read") {
			a->call_notload = true;
			st2 = s2.codeGen(a);
			srT2 = a->exp_reT;
			int c = a->callnum++;
			sc = int2str(c);
				
			//re += "\t%call"+sc+" = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %"+st2+")\n";
			re += "\t%call"+sc+" = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* "+srT2+")\n";
			return re;
		}
		
		if (st1=="write"){
			a->call_notload = true;
			st2 = s2.codeGen(a);
			srT2 = a->exp_reT;
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
					re += "\t%call"+sc+" = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 "+srT2+")\n";	
				}
				else {
					re += "\t%call"+sc+" = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 "+srT2+")\n";	
				}
			}
			return re;
		}
		
		a->call_notload = false;
		a->callpar->clear();
		st2 = s2.codeGen(a);
		re += st2;
		sc = int2str(a->callnum++);
		re += "\t%call"+sc+" = call i32 @"+st1+"(";
		for (int i=0; i<a->callpar->size(); i++){
			string tmp = a->callpar->at(i);
			if (i!=a->callpar->size()-1)
				re += "i32 "+tmp+", ";
			else
				re += "i32 "+tmp+")\n";
		}
		
		a->expre = "call"+sc;
		a->exp_reT = "%call"+sc;
		a->exp_id = false;
		a->exp_intf = false;
		return re;
	}
};

class NARGSexp : public Node {
public:
	Node &s1;
	NARGSexp(Node& s1) : s1(s1) {}
	string codeGen(content *a) {
		cout <<"***NARGSexp\n";
		string st1 = s1.codeGen(a);
		//need the result of the experision
		string re = "";
		
		string cpr;
		if (!a->call_notload) {
			if (a->exp_id){
				int regid = a->regid++;
				re += "\t%"+int2str(regid)+" = load i32* "+a->exp_reT+", align 4\n";
				cpr = "%"+int2str(regid);
			}
			else{
				if (!a->exp_intf) re += st1;
				cpr = a->exp_reT;
			}
		}
		else{
			if (!a->exp_id) re += st1;
			cpr = a->exp_reT;
		}
		a->callpar->push_back(cpr);
		cout << "cpr " << cpr << endl;
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
		
		num = find(a->par, id);
		if (num!= -1)
			a->exp_reT += ".addr";
		
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
		string srT1 = a->exp_reT;
		bool fs1 = a->exp_id;
		bool fsint1 = a->exp_intf;
		
		string st2 = s2.codeGen(a);
		string sr2 = a->expre;
		string srT2 = a->exp_reT;
		bool fs2 = a->exp_id;
		bool fsint2 = a->exp_intf;
		
		string re = "";
		string op1, op2;
		
		if (op == 278) {//ADD
			if (!fs1 && !fsint1) re += st1;
			
			int addid = a->addid++;
			string sadd = int2str(addid);
			int regid;
			string sreg;
			
			if (fs1) {
				regid = a->regid++;
				sreg = int2str(regid);
			//re += "\t%"+sreg+" = load i32* %"+st1+", align 4\n";
				//re += "\t%"+sreg+" = load i32* %"+sr1+", align 4\n";
				re += "\t%"+sreg+" = load i32* "+srT1+", align 4\n";
				//op1 = sreg;
				op1 = "%"+sreg;
			}
			else {
				//op1 = sr1;
				op1 = srT1;
			}
			if (fs2) {
				regid = a->regid++;
				sreg = int2str(regid);
				//re += "\t%"+sreg+" = load i32* %"+sr2+", align 4\n";
				re += "\t%"+sreg+" = load i32* "+srT2+", align 4\n";
				//op2 = sreg;
				op2 = "%"+sreg;
			}
			else {
				//op2 = sr2;
				op2 = srT2;
			}
			
			if (!fsint1) {
				//re += "\t%add"+sadd+" = add nsw i32 %"+op1;
				re += "\t%add"+sadd+" = add nsw i32 "+op1;
			}
			else
				re += "\t%add"+sadd+" = add nsw i32 "+op1;
			if (!fsint2)
				//re += ", %"+op2+"\n";
				re += ", "+op2+"\n";
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
		if (op == 276) {//euqal
			string sreg;
			if (fs1) {
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* "+srT1+", align 4\n";
				op1 = "%"+sreg;			
			}
			else {
				op1 = srT1;
			}
			if (fs2) {
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* "+srT2+", align 4\n";
				op2 = "%"+sreg;				
			}
			else {
				op2 = srT2;
			}
			
			int cmpid = a->cmpid++;
			if (!fsint1)
				re += "\t%cmp"+int2str(cmpid)+" = icmp eq i32 "+op1;
			else
				re += "\t%cmp"+int2str(cmpid)+" = icmp eq i32 "+op1;
			if (!fsint2)
				re += ", "+op2+"\n";
			else
				re += ", "+op2+"\n";
			a->exp_id = false;
			a->exp_intf = false;
			a->exp_op = "equal";
			a->expre = "cmp"+int2str(cmpid);
			a->exp_reT = "%"+a->expre;
			return re;
		}
		
		if (op == 277) {//MOD
			if (fs1) {
				re += "\t%"+int2str(a->regid++)+" = load i32* "+srT1+", align 4\n";
				op1 = "%"+int2str(a->regid-1);
			}
			else
				op1 = srT1;
			if (fs2) {
				re += "\t%"+int2str(a->regid++)+" = load i32* "+srT2+", align 4\n";
				op2 = "%"+int2str(a->regid-1);
			}
			else
				op2 = srT2;
			int remid = a->remid++;
			re += "\t%rem"+int2str(remid)+" = srem i32 "+op1+", "+op2+"\n";
			a->exp_id = a->exp_intf = false;
			a->exp_op = "mod";
			a->exp_reT = "%rem"+int2str(remid);
			return re;
		}
		
		if (op == 275) {//BITXOR
			if (fs1) {
				re += "\t%"+int2str(a->regid++)+" = load i32* "+srT1+", align 4\n";
				op1 = "%"+int2str(a->regid-1);
			}
			else
				op1 = srT1;
			if (fs2) {
				re += "\t%"+int2str(a->regid++)+" = load i32* "+srT2+", align 4\n";
				op2 = "%"+int2str(a->regid-1);
			} 
			else
				op2 = srT2;
			int xorid = a->xorid++;
			re += "\t%xor"+int2str(xorid)+" = xor i32 "+op1+", "+op2+"\n";
			a->exp_id = a->exp_intf = false;
			a->exp_op = "bitxor";
			a->exp_reT = "%xor"+int2str(xorid);
			return re;
		}
		
		if (op == 274) {//assignop
			if (!fsint2 && !fs2) re += st2;
			op1 = srT1;
			if (fs2) {
				re += "\t%"+int2str(a->regid++)+" = load i32* "+srT2+", align 4\n";
				op2 = "%"+int2str(a->regid-1);
			}
			else
				op2 = srT2; 
			re += "\tstore i32 "+op2+", i32* "+op1+", align 4\n";
			a->exp_id = true;
			a->exp_intf = false;
			a->exp_op = "assignop";
			a->exp_reT = op1;
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
		string srT1 = a->exp_reT;
		string sop1 = a->exp_op;
		string st2;
		string st3;
		string re = "";
		
		if (sop1 == "equal" || sop1 == "loginot") {
			re += st1;
		}
		else {
			if (a->exp_id) {
				int regid = a->regid++;
				re += "\t%"+int2str(regid)+" = load i32* "+a->exp_reT+", align 4\n";
				int cmp = a->cmpid++;
				re += "\t%cmp"+int2str(cmp)+" = icmp ne i32 %"+int2str(regid)+", 0\n";
				a->exp_reT = "%cmp"+int2str(cmp);
				srT1 = a->exp_reT;
				a->exp_id = false;
				a->exp_intf = false;
			}
		}
		
		re += "\tbr i1 "+srT1+", label %if.then"+int2str(ifnum)+", label %if.else"+int2str(ifnum)+"\n\n";
		re += "if.then"+int2str(ifnum)+":\n";
		st2 = s2.codeGen(a);
		re += st2;
		if (!a->stmt_ret)
			re += "\tbr label %if.end"+int2str(ifnum)+"\n";
		re += "\n";
		a->stmt_ret = false;
		re += "if.else"+int2str(ifnum)+":\n";
		st3 = s3.codeGen(a);
		re += st3;
		if (!a->stmt_ret)
			re += "\tbr label %if.end"+int2str(ifnum)+"\n\n";
		
		re += "if.end"+int2str(ifnum)+":\n";
		a->stmt_ret = false;
		return re;
	}
};

class NESTMT : public Node {
public:
	Node &s1;
	NESTMT(Node &s1) : s1(s1) {}
	string codeGen(content *a) {
		a->stmt_ret = false;
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
		string srT1 = a->exp_reT;
		bool fs1 = a->exp_id;
		bool fsint1 = a->exp_intf;
		string re = "";
		if (op== 280) {//loginot
			string op1;
			string sreg;
			if (fs1){
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* "+srT1+", align 4\n";
				op1 = "%"+sreg;
			}
			else
				op1 = srT1;	
			
			int cmpid = a->cmpid++;
			//re +=  "\t%cmp"+int2str(cmpid)+" = icmp ne i32 %"+op1+", 0\n";
			re +=  "\t%cmp"+int2str(cmpid)+" = icmp eq i32 "+op1+", 0\n";//different from c
			a->exp_op = "loginot";
			a->expre = "cmp"+int2str(cmpid);
			a->exp_reT = "%"+a->expre;
			a->exp_id = false;
			a->exp_intf= false;
			return re;
		}
		if (op == 279) {//UMINUS
			string op1;
			string sreg;
			if (fs1){
				sreg = int2str(a->regid++);
				re += "\t%"+sreg+" = load i32* "+srT1+", align 4\n";
				op1 = "%"+sreg;
			}
			else
				op1 = srT1;	
			int subid = a->subid++;
			re +=  "\t%sub"+int2str(subid)+" = sub nsw i32 0, "+op1+"\n";
			a->exp_op = "uminus";
			a->expre = "sub"+int2str(subid);
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
		cout << "****NEXTVARS1\n";
		string st1 = s1.codeGen(a);
		string re="";
		if (a->def_spec=="i32") {
			if (!a->assignop)
				re +="@"+a->varS->top()+" = common global i32 0, align 4\n";
			else
				re +="@"+a->varS->top()+" = global i32 "+st1+", align 4\n";
			a->globalVar->push_back(a->varS->top());
			a->globalVarType->push_back("i32");
			a->varS->pop();
			a->assignop = false;
			return re;	
		}
		if (a->spec_rec != "i32") {
			if (!a->struct_f){
				re += "@"+a->varS->top()+" = common global "+a->spec_rec+" zeroinitializer, align 4\n";
				a->globalVar->push_back(a->varS->top());
				a->varS->pop();
				a->globalVarType->push_back(a->spec_rec);
				return re;
			}
		}
		return re;
	}
};

class NEXTVARS2 : public Node {
public:
	Node &s1, &s2;
	NEXTVARS2(Node &s1, Node &s2) : s1(s1), s2(s2) {}
	string codeGen(content *a) {
		cout << "****NEXTVARS2\n";
		string st1 = s1.codeGen(a);
		cout << "**s1\n";
		string re = "";
		if (a->def_spec=="i32") {
			if (!a->assignop)
				re +="@"+a->varS->top()+" = common global i32 0, align 4\n";
			else
				re +="@"+a->varS->top()+" = global i32 "+st1+", align 4\n";
			a->globalVar->push_back(a->varS->top());
			a->globalVarType->push_back("i32");
			a->varS->pop();
			a->assignop = false;
		}
		if (a->spec_rec != "i32") {
			if (!a->struct_f){
				re += "@"+a->varS->top()+" = common global "+a->spec_rec+" zeroinitializer, align 4\n";
				a->globalVar->push_back(a->varS->top());
				a->globalVarType->push_back(a->spec_rec);
				a->varS->pop();
			}
		}
		cout << "**s2\n";
		string st2 = s2.codeGen(a);
		re += st2;
		cout << "****end NEXTVARS2\n";
		return re;
	}
};

class NEXTDEF1 : public Node {
public:
	Node &s1, &s2;
	NEXTDEF1(Node &s1, Node &s2) : s1(s1),s2(s2) {}
	string codeGen(content *a) {
		cout << "****NEXTDEF1\n";
		a->def_global = true;
		string st1 = s1.codeGen(a);
		a->def_spec = st1;
		string st2 = s2.codeGen(a);
		string re = "";
		if (a->spec_rec != "i32"){
			if (a->struct_f)
				re += st1;
		}
		re +=  st2;
		return re;
	}
};

class NARGS1 : public Node {
public:
	Node &s1, &s2;
	NARGS1(Node &s1, Node &s2) : s1(s1),s2(s2) {}
	string codeGen(content *a) {
		cout <<"***NARGS1\n";
		string st1 = s1.codeGen(a);
		string srT1 = a->exp_reT;
		string re = "";
		string cpr = srT1;
		if (!a->call_notload) {
			if (a->exp_id) {
				int regid = a->regid++;
				re +="\t%"+int2str(regid)+" = load i32* "+a->exp_reT+", align 4\n";
				cpr = "%"+int2str(regid);
			}
			else {
				if (!a->exp_intf) re += st1;
			}
		}
		else
			if (!a->exp_id) re += st1;
		a->callpar->push_back(cpr);
		cout <<"cpr "<< cpr << endl;
		string st2 = s2.codeGen(a);
		re += st2;
		return re;
	}
};

class NSTSPEC1 : public Node {
public:
	Node &s1, &s2;
	NSTSPEC1(Node &s1, Node &s2) : s1(s1),s2(s2) {}
	string codeGen(content *a){
		cout << "***NSTSPEC1\n";
		a->NSTSPEC_f = true;
		a->spec->clear();
		string st1 = s1.codeGen(a);
		a->structElem->push_back(new vector<string>);
		a->structName->push_back("%struct."+st1);
		
		string st2 = s2.codeGen(a);
		cout << "****c s1\n";
		string re ="";
		re += "%struct."+st1+" = type {";
		for (int i=0; i<a->spec->size(); i++) {
			if (i!=a->spec->size()-1)
				re += " "+a->spec->at(i)+",";
			else
				re += " "+a->spec->at(i)+" }\n";
		}
		a->spec_rec = "%struct."+st1;
		a->struct_f = true;
		a->NSTSPEC_f = false;
		return re;
	}
};

class NSTSPEC2 : public Node {
public:
	string id;
	NSTSPEC2(const string &id) : id(id) {}
	string codeGen(content *a){
		cout << "***NSTSPEC2\n";
		a->NSTSPEC_f =true;
		string re = "";
		a->spec_rec = "%struct."+id;
		a->struct_f = false;
		a->NSTSPEC_f = false;
		return re;
	}
};

class NOPTTAG : public Node {
public:
	string id;
	NOPTTAG(const string &id) : id(id) {}
	string codeGen(content *a){
		cout << "***NOPTTAG\n";
		string re = "";
		re += id;
		return re;
	}
	
};

class NEXPdot : public Node {
public:
	Node &s1;
	string id;
	NEXPdot(Node &s1, const string &id) : s1(s1), id(id) {}
	string codeGen(content *a){
		cout << "***NEXPdot\n";
		string st1 = s1.codeGen(a);
		cout << "dot " << st1 << "." << id << endl;
		string re = "";
		int num = find(a->globalVar, st1);
		int typ = find(a->structName, a->globalVarType->at(num));
		int fnum = find(a->structElem->at(typ), id);
		cout << num <<" " <<  typ <<" " <<  fnum << endl;
		cout << "*****s1\n";
		//cout << a->structElem->size() << endl;
		//cout << a->structElem->at(num)->size() << endl;
		//doubt?
		a->exp_reT = "getelementptr inbounds ("+a->globalVarType->at(num)+"* @"+st1+", i32 0, i32 "+int2str(fnum)+")";
		a->exp_id = true;
		return re;
	}
};
#endif
