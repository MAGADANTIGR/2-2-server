#pragma once
#include "Header.h"

class Trainer {
	string name;
	string surname;
	string age;

public:
	string getName();
	string getSur();
	string getAge();
	void setName(const string);
	void setSur(const string);
	void setAge(const string);
	friend ifstream& operator>>(ifstream& in, Trainer& obj);
	friend ofstream& operator<<(ofstream& out, Trainer& obj);
};
