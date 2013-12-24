#include <iostream>
#include <vector>
using namespace std;

class content {
private:
	vector<string> *type;
	vector<string> *id;
	int i;
public:
	string def_spec;
	string var;
	bool assignop;
	
	content() { 
		type = new vector<string>; 
		id = new vector<string>;
		assignop = false; 
	}
	~content() {
		delete type, id;
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
