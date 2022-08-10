#include "Trainer.h"

string Trainer::getName() {
	return name;
}

string Trainer::getSur() {
	return surname;
}

string Trainer::getAge() {
	return age;
}

void Trainer::setName(const string name) {
	this->name = name;
}

void Trainer::setSur(const string sur) {
	this->surname = sur;
}

void Trainer::setAge(const string age) {
	this->age = age;
}

ifstream& operator>>(ifstream& in, Trainer& obj) {
	string str;

	in >> str;
	obj.setSur(str);

	in >> str;
	obj.setName(str);

	in >> str;
	obj.setAge(str);

	return in;
}
ofstream& operator<<(ofstream& out, Trainer& obj) {
	out << obj.getSur() << " ";
	out << obj.getName() << " ";
	out << obj.getAge() << " ";

	return out;
}