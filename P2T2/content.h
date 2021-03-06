#ifndef CONTENT_H
#define CONTENT_H
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
using namespace std;

static string int2str(int in)
{
	stringstream ss;
	ss << in;
	string out = ss.str();
	ss.clear();
	ss.str("");
	return out;
}

static int find(vector<string>*a, string in)
{
	for (int i=0; i<a->size(); i++) {
		if (a->at(i) == in) return i;
	}
	return -1;
}

class content {
private:
	vector<string> *type;
	vector<string> *id;
	int i;
public:
	string def_spec, exp_op;
	stack<string> *varS;
	bool assignop, exp_id, exp_intf, def_global, call_notload, stmt_ret;
	bool struct_f;
	bool NSTSPEC_f;
	string exp_int;
	int callnum, ifnum;
	int regid;
	int addid, cmpid, remid, xorid, subid;
	string expre;
	string exp_reT;
	string spec_rec;
	vector<string> *globalVar;
	vector<string> *globalVarType;
	vector<string> *localVar;
	vector<string> *par;
	vector<string> *callpar;
	vector<string> *spec;
	
	vector< vector<string>* > *structElem;
	vector<string> *structName;
	
	content() { 
		type = new vector<string>; 
		id = new vector<string>;
		assignop = exp_id = exp_intf = def_global = call_notload = stmt_ret = false;
		struct_f = NSTSPEC_f = false; 
		def_spec = expre = exp_op = exp_reT = spec_rec = "";
		varS = new stack<string>;
		callnum = ifnum = cmpid = 0;
		regid = addid = remid = xorid = 0;
		globalVar = new vector<string>;
		localVar = new vector<string>;
		par = new vector<string>;
		callpar = new vector<string>;
		spec = new vector<string>;
		structName = new vector<string>;
		structElem = new vector< vector<string>* >;
		globalVarType = new vector<string>;
	}
	~content() {
		delete type, id, varS;
		delete globalVar, localVar;
		delete callpar;
	}
	void add(string t, string i) { 
		type->push_back(t);
		id->push_back(i);
	}
	int size() {
		return type->size();
	}
	string get1T(int i) {
		return type->at(i);
	}
	string get1I(int i) {
		return id->at(i);
	}
	void clear() {
		type->clear();
		id->clear();
	}
};

#endif
