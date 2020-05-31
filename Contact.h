#pragma once
#include <string>
#include <fstream>
using namespace std;

class Contact
{
private:
	string _surname;
	string _name;
	string _patronymic;
public:
	Contact();
	Contact(string surname,string name, string patronymic);
	~Contact();
	string number;
	string date;
	string Get_name();
	string Get_surname();
	string Get_patronymic();
};

