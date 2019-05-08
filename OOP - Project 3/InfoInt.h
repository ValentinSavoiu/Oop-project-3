#pragma once
#include "Info.h"
#include "ComplexNumber.h"
class InfoInt : public Info {
	int value;
public:
	InfoInt(string N, int val) : Info(N) {
		value = val;
	}
	virtual Info* operator+= (string S) {
		throw "invalid addition";
	}
	virtual Info* operator+= (int x) {
		value += x;
		return this;
	}
	virtual Info* operator+= (ComplexNumber c) {
		value = c.getReal() + value;
		return this;
	}
	virtual void print_value(ostream &out) {
		out << value;
	}
	~InfoInt() {};
};


