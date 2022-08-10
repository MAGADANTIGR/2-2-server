#include "Product.h"

void Product::setgrams(const string grams) {
	this->grams = grams;
}
void Product::setName(const string Name) {
	this->Name = Name;
}
void Product::setprice(const string price) {
	this->price = price;
}
void Product::setkkal(const string kkal) {
	this->kkal = kkal;
}
void Product::setnum(const string num) {
	this->art = num;
}
string Product::getgrams() {
	return  grams;
}
string Product::getName() {
	return  Name;
}
string Product::getprice() {
	return  price;
}
string Product::getkkal() {
	return  kkal;
}
string Product::getnum() {
	return art;
}
ifstream& operator>>(ifstream& in, Product& obj) {
	string str;

	in >> str;
	obj.setName(str);

	in >> str;
	obj.setprice(str);

	in >> str;
	obj.setgrams(str);

	in >> str;
	obj.setkkal(str);

	in >> str;
	obj.setnum(str);

	return in;
}

ofstream& operator<<(ofstream& out, Product& obj) {
	out << obj.getName() << " ";
	out << obj.getprice() << " ";
	out << obj.getgrams() << " ";
	out << obj.getkkal() << " ";
	out << obj.getnum() << " ";

	return out;
}