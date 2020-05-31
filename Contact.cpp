#include "pch.h"
#include "Contact.h"


Contact::Contact(string surname, string name, string patronymic)
{
	_surname = surname;
	_name = name;
	_patronymic = patronymic;
}


Contact::~Contact()
{
}

string Contact::Get_name() {
	return _name;
}

string Contact::Get_surname() {
	return _surname;
}

string Contact::Get_patronymic() {
	return _patronymic;
}

Contact::Contact() {

}