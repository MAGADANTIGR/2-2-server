#pragma once
#include "Header.h"

class Order {
protected:
	string NameP;
	string price;
	string log;
public:
	string getNameP();
	string getprice();
	string getLog();
	void setNameP(const string);
	void setprice(const string);
	void setLog(const string);
	friend ifstream& operator>>(ifstream& in, Order& obj);
	friend ofstream& operator<<(ofstream& out, Order& obj);
};
