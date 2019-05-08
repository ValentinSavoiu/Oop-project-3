#pragma once
#include <string>
#include "ComplexNumber.h"
using namespace std;
//template <class T>
class Info {
	friend class LibraryS;
private:
	static int currID;
	int id;
	string name;
	//T value;
public:
	Info(string S) {
		name = S;
		id = currID++;
	}
	virtual char type() = 0;
	virtual void print_value(ostream &out) = 0;
	virtual Info* operator += (Info* inf) = 0;
	friend ostream& operator << ( ostream& out, Info& inf ) {
		out << inf.id << ' ' << inf.name << ' ';
		inf.print_value(out);
		return out;
	}
	~Info() {};
};

int Info::currID = 1;