#pragma once
#include "Info.h"
#include "ComplexNumber.h"
class InfoString : public Info {
	string value;
public:
	InfoString(string N, string val) : Info(N) {
		value = val;
	}
	virtual Info* operator+= (string S) {
		value += S;
		return this;
	}
	virtual Info* operator+= (int x) {
		value += to_string(x);
		return this;
	}
	virtual Info* operator+= (ComplexNumber c) {
		value += to_string(c.getReal()) + " + " + to_string(c.getIm());
		return this;
	}
	virtual void print_value(ostream &out) {
		out << value;
	}
	~InfoString() {};
};


