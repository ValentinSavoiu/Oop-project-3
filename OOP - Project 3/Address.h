#pragma once
using namespace std;
class Address {
	string country, county, city, street;
	int number;
public:
	Address(string Country = "", string County = "", string City = "", string Street = "", int Number = 0): country(Country), county(County), city(City), street(Street), number(Number) {}
	bool operator== (const Address& add) {
		return (country == add.country && county == add.county && city == add.city && street == add.street && number == add.number);
	}
	friend istream& operator >> (istream& in, Address& add) {
		in >> add.country >> add.county >> add.city >> add.street >> add.number;
		return in;
	}
	friend ostream& operator << (ostream& out, Address& add) {
		out << add.country << ' ' << add.county << ' '  << add.city << ' ' << add.street << ' ' << add.number;
		return out;
	}
	Address& operator += (const Address& add) {
		throw "Nu pot aduna adrese";
	}
	~Address() {};
};


