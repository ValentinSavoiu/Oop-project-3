#pragma once
#include "Info.h"
template <class T>
class InfoVal: Info {
	T value;
	friend class LibraryS;
public:
	InfoVal(string N, T val) : Info(N) {
		value = val;
	}
	virtual Info* operator += (Info* inf) {
		if (inf->type() != this->type()) {
			throw "Adunare imposibila";
		}
		InfoVal<T> *in = static_cast<InfoVal<T> * > (inf);
		this->value += in->value;
		return this;
	}
	Info* operator += (T x) {
		value += x;
		return this;
	}
	virtual void print_value(ostream &out) {
		out << value;
	}
	virtual char type() {
		T t;
		/*string u = typeid(t).name();
		if (u.find("int") != string::npos) return 'i';
		if (u.find("ComplexNumber") != string::npos) return 'c';
		if (u.find("Address") != string::npos) return 'a';
		return 's';*/
		if (typeid(t) == typeid(int)) return 'i';
		if (typeid(t) == typeid(ComplexNumber)) return 'c';
		if (typeid(t) == typeid(Address)) return 'a';
		return 's';
	}
	~InfoVal() {};
};


