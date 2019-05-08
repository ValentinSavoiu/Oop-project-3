#pragma once
#pragma once
#include "Info.h"
#include "ComplexNumber.h"
class InfoComplexNumber : public Info {
	ComplexNumber value;
public:
	InfoComplexNumber(string N, ComplexNumber val) : Info(N) {
		value = val;
	}
	virtual Info* operator+= (string S) {
		throw "invalid addition";
	}
	virtual Info* operator+= (int x) {
		value = value + x;
		return this;
	}
	virtual Info* operator+= (ComplexNumber c) {
		value = c + value;
		return this;
	}
	virtual void print_value(ostream &out) {
		out << value;
	}
	~InfoComplexNumber() {};
};


