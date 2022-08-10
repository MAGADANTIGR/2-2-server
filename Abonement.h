#pragma once
#include "Header.h"

class Abonement {
protected:
	string Name;
	string day;
	string mon;
	string date;
	string time;
	string year;
public:
	string getName();
	string getDay();
	string getMon();
	string getDate();
	string getTime();
	string getYear();
	void setName(const string);
	void setDay(const string);
	void setMon(const string);
	void setDate(const string);
	void setTime(const string);
	void setYear(const string);
	friend ifstream& operator>>(ifstream& in, Abonement& obj);
};