#include "Abonement.h"

void Abonement::setName(const string Name) {
	this->Name = Name;
}
void Abonement::setDay(const string day) {
	this->day = day;
}
void Abonement::setMon(const string m) {
	this->mon = m;
}
void Abonement::setDate(const string d) {
	this->date = d;
}
void Abonement::setTime(const string t) {
	this->time = t;
}
void Abonement::setYear(const string y) {
	this->year = y;
}

string Abonement::getName() {
	return  Name;
}
string Abonement::getDay() {
	return  day;
}
string Abonement::getMon() {
	return  mon;
}
string Abonement::getDate() {
	return  date;
}
string Abonement::getTime() {
	return  time;
}
string Abonement::getYear() {
	return  year;
}

ifstream& operator>>(ifstream& in, Abonement& obj) {
	string str;


	in >> str;
	obj.setName(str);

	in >> str;
	obj.setDay(str);

	in >> str;
	obj.setMon(str);

	in >> str;
	obj.setDate(str);

	in >> str;
	obj.setTime(str);

	in >> str;
	obj.setYear(str);

	return in;
}