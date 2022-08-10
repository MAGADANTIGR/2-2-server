#include "Order.h"

ifstream& operator>>(ifstream& in, Order& obj) {
	string str;

	in >> str;
	obj.setNameP(str);

	in >> str;
	obj.setprice(str);

	in >> str;
	obj.setLog(str);

	return in;
}
ofstream& operator<<(ofstream& out, Order& obj) {
	out << obj.getNameP() << " ";
	out << obj.getprice() << " ";
	out << obj.getLog() << " ";
	return out;
}


void Order::setNameP(const string name) {
	this->NameP = name;
}
void Order::setprice(const string price) {
	this->price = price;
}
void Order::setLog(const string log) {
	this->log = log;
}

string Order::getNameP() {
	return  NameP;
}
string Order::getprice() {
	return  price;
}
string Order::getLog() {
	return  log;
}