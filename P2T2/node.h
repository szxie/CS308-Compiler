#include <iostream>
#include <sstream>
#include "content.h"
using namespace std;


class NType;
class NDECS2;

class Node {
public:
	Node() {}
	virtual string codeGen(content* a) { return NULL; }
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
		a->var = id;
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
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		string st3 = s3.codeGen(a);
		return "define "+st1+" "+st2+" "+st3; 
	}
};

class NSBlock : public Node {
public:
	Node& s1;
	NSBlock(Node& s1) : s1(s1) {}
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
		re += st1;
		return re+"}"; 	
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
		if (a->def_spec=="i32") {
			re = "\tstore i32 "+st2+", i32* %"+st1+", align 4\n";	
		}
		return re;
	}
};

class NDECS1 : public Node {
public:
	Node& s1, s2;
	NDECS1(Node& s1, Node& s2) : s1(s1), s2(s2) {}
	string codeGen(content* a) {
		cout << "\n****NDECS1\n";
		string st1 = s1.codeGen(a);
		string st2 = s2.codeGen(a);
		string re="";
		
		if (a->def_spec=="i32") {
			re ="\t%"+a->var+" = alloca i32, align 4\n";	
		}
		if (a->assignop) {
			re += st1;
		}
		//re += st2;
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
			re ="\t%"+a->var+" = alloca i32, align 4\n";	
		}
		if (a->assignop) {
			re += st1;
		}
		return re;
	}
};