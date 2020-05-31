#include "pch.h"
#include "Contact_list.h"
#include "Contact.h"

Contacts_list::Contacts_list()
{
	_contacts = 0;
	_size = 0;

	_izbr=0;
	_size_isbr = 0;
}

int Contacts_list::Get_list_size() {
	return _size;
}

Contacts_list::~Contacts_list()
{
	if (_contacts != 0) {
		delete[] _contacts;
	}
	if (_izbr != 0) {
		delete[] _izbr;
	}
}
void Contacts_list::AddNewContact(Contact* new_contact) {
	if (_contacts == 0) {
		_contacts = new Contact*[1];
		_contacts[0] = new_contact;
		_size = 1;
	}
	else {
		Contact** buf = new Contact*[_size + 1];

		for (unsigned int i = 0; i < _size; i++) {
			buf[i] = _contacts[i];
		}

		buf[_size] = new_contact;
		_size++;
		
		delete[] _contacts;
		_contacts = buf;
		
		for (unsigned int i = 0; i < _size; i++) {
			if (i != _size - 1) {
				string full_name_curr = _contacts[i]->Get_surname()+" "+_contacts[i]->Get_name()+" "+ _contacts[i]->Get_patronymic();
				string full_name_next= _contacts[i+1]->Get_surname() + " " + _contacts[i+1]->Get_name() + " " + _contacts[i+1]->Get_patronymic();
				if (full_name_curr > full_name_next) {
					Contact* contact_buf;
					contact_buf = _contacts[i];
					_contacts[i] = _contacts[i + 1];
					_contacts[i + 1] = contact_buf;
				}
			}
			
		}
	}

}

Contact* Contacts_list::Search_contact(string surname, string name, string patronymic) {
	for (unsigned int i = 0; i < _size;i++) {

		string full_name_curr = _contacts[i]->Get_surname() + " " + _contacts[i]->Get_name() + " " + _contacts[i]->Get_patronymic();
		string full_name = surname + " " + name + " " +patronymic;

		if (full_name_curr == full_name) {
			return _contacts[i];
		}
	}
	return 0;
}
Contact* Contacts_list::Search_contact(string number) {
	for (unsigned int i = 0; i < _size; i++) {
		
		string full_number = _contacts[i]->number;

		if (full_number == number) {
			return _contacts[i];
		}
	}
	return 0;
}

Contact** Contacts_list::Search_cotacts(string FIO, int& count) {
	Contact** selected_contacts = 0;
	int selected_contacts_size = 0;

	for (unsigned int i = 0; i < _size; i++) {

		string full_name_curr = _contacts[i]->Get_surname() + " " + _contacts[i]->Get_name() + " " + _contacts[i]->Get_patronymic();
		string buf = full_name_curr.substr(0, FIO.size());
		
		if (buf == FIO) {
			selected_contacts_size++;
		}
	}
	if (selected_contacts_size != 0) {
		selected_contacts = new Contact*[selected_contacts_size];

		for (unsigned int i = 0; i < _size; i++) {

			string full_name_curr = _contacts[i]->Get_surname() + " " + _contacts[i]->Get_name() + " " + _contacts[i]->Get_patronymic();
			string buf = full_name_curr.substr(0, FIO.size());

			if (buf == FIO) {
				selected_contacts[count] = _contacts[i];
				count++;
			}
		}
		return selected_contacts;
	}

	return 0;

}

void Contacts_list::AddIzbr(Contact* new_contact) {
	if (_izbr == 0) {
		_izbr = new Contact*[1];
		_izbr[0] = new_contact;
		_size_isbr = 1;
	}
	else {
		Contact** buf = new Contact*[_size_isbr + 1];
		for (unsigned int i = 0; i < _size_isbr; i++) {
			buf[i] = _izbr[i];
		}
		buf[_size] = new_contact;
		_size_isbr++;

		delete[] _izbr;
		_izbr = buf;

		for ( unsigned int i = 0; i < _size_isbr; i++) {
			if (i != _size_isbr - 1) {
				string full_name_curr = _izbr[i]->Get_surname() + " " + _izbr[i]->Get_name() + " " + _izbr[i]->Get_patronymic();
				string full_name_next = _izbr[i + 1]->Get_surname() + " " + _izbr[i + 1]->Get_name() + " " + _izbr[i + 1]->Get_patronymic();
				if (full_name_curr > full_name_next) {
					Contact* contact_buf;
					contact_buf = _izbr[i];
					_izbr[i] = _izbr[i + 1];
					_izbr[i + 1] = contact_buf;
				}
			}

		}
	}

}

Contact** Contacts_list::Get_Izbr(unsigned int& size_isbr) {
	size_isbr = _size_isbr;
	return _izbr;
}
void Contacts_list::Delete_izbr(string surname, string name, string patronymic) {

	int count = _size_isbr;

	for (unsigned int i = 0; i < _size_isbr; i++) {

		if (_izbr[i]->Get_surname()== surname
			&& _izbr[i]->Get_name() == name 
			&& _izbr[i]->Get_patronymic()==patronymic) {

			_izbr[i] = 0;
			count--;

		}

	}

	Contact** buf = new Contact*[count];
	count = 0;
	for (int i = 0; i < _size_isbr; i++) {

		if (_izbr[i] != 0) {

			buf[count] = _izbr[i];
			count++;
		}
		delete[] _izbr;

		_izbr = buf;

		_size_isbr=count;

	}

}

void Contacts_list::Delete_contact(string number) {

	int count = _size;

	for (unsigned int i = 0; i < _size; i++) {

		if (_contacts[i]->number==number) {

			_contacts[i] = 0;
			count--;

		}

	}

	Contact** buf = new Contact*[count];
	count = 0;
	for (int i = 0; i < _size; i++) {

		if (_contacts[i] != 0) {

			buf[count] = _contacts[i];
			count++;
		}
		delete[] _contacts;

		_contacts = buf;

		_size = count;

	}

}

void Contacts_list::AddContactFromFile(string filename) {

	ifstream fin;
	fin.open(filename);
	
	string surname;
	fin >> surname;

	string name;
	fin >> name;

	string patronimic;
	fin >> patronimic;

	string date;
	fin >> date;

	string number;
	fin >> number;

	Contact* contact = new Contact(surname, name, patronimic);
	contact->number = number;
	contact->date = date;

	AddNewContact(contact);
	
	fin.close();

}

void Contacts_list::SaveContactToFile(string filename, string surname, string name, string patronimic)
{
	Contact* contact = 0;
	contact= Search_contact(surname, name, patronimic);
	if (contact!= 0)
	{
		ofstream fout;
		fout.open(filename);
		fout << contact->Get_surname() << endl;
		fout << contact->Get_name() << endl;
		fout << contact->Get_patronymic() << endl;
		fout << contact->date << endl;
		fout << contact->number;
		fout.close();
	}







}