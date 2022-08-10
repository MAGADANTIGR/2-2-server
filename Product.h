#pragma once
#include "Header.h"

class Product {
protected:
	string Name;
	string price;
	string grams;
	string kkal;
	string art;
public:
	string getName();
	string getprice();
	string getgrams();
	string getkkal();
	string getnum();
	void setName(const string);
	void setprice(const string);
	void setgrams(const string);
	void setkkal(const string);
	void setnum(const string);
	friend ifstream& operator>>(ifstream& in, Product& obj);
	friend ofstream& operator<<(ofstream& out, Product& obj);
};