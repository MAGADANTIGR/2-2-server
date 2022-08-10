#pragma once
#include "Header.h"

class User {
protected:
	string password;
	string login;
public:
	void setlogin(const string);
	void setpassword(const string);
	string getlogin();
	string getpassword();
};
class Admin :public  User {

};
