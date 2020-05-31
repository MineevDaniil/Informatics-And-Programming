#pragma once
#include "Contact.h"
#include <fstream>
class Contacts_list
{
private:
	Contact** _contacts;
	unsigned int _size;

	unsigned int _size_isbr;
	Contact** _izbr;

public:
	Contacts_list();
	~Contacts_list();

	void AddNewContact(Contact* new_contact);
	Contact* Search_contact(string surname, string name, string patronymic);
	Contact* Search_contact(string number);
	Contact** Search_cotacts(string FIO, int& count);
	int Get_list_size();
	void AddIzbr(Contact* new_contact);
	Contact** Get_Izbr(unsigned int& size_isbr);
	void Delete_izbr(string surname, string name, string patronymic);
	void Delete_contact(string number);
	void AddContactFromFile(string file);
	void SaveContactToFile(string file, string surname, string name, string patronimic);
};