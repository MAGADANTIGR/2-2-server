#include "Users.h"

void User::setlogin(const string login)
{
	this->login = login;
}
void User::setpassword(const string password)
{
	this->password = password;
}

string User::getlogin() {
	return  login;
}
string User::getpassword() {
	return  password;
}