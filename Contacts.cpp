// Contacts.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>

#include "Contact.h"
#include "Contact_list.h"
int promt_menu() {
	int variant;
	cout << "1. Сохранить контакт в файл"  << endl;
	cout << "2. Вывести контакт из файла" << endl;
	cout << "3. Создать новый контакт" << endl;
	cout << "4. Найти контакт по ФИО" << endl;
	cout << "5. Изменить контакт, выбранный по ФИО" << endl;
	cout << "6. Найти контакт по телефону" << endl;
	cout << "7. Выдать все контакты на заданную начальную букву ФИО" << endl;
	cout << "8. Узнать текущее число контактов" << endl;
	cout << "9. Внести контакт, выбранный по ФИО в список избранных" << endl;
	cout << "10. Удалить контакт, выбранный по ФИО из списка избранных" << endl;
	cout << "11. Выдать все избранные контакты" << endl;
	cout << "12. Удалить контакт, выбранный по телефону" << endl;
	cout << "13. Выход" << endl;
	cout << endl;

	cin >> variant;
	return variant;
}

int main()
{
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	
	Contacts_list contacts_list;

while (true) {
	int var = promt_menu();

	string surname;
    string name;
	string patronymic;
	string number;
	string date;

	int count = 0;

	Contact* contact = 0;
	Contact* new_contact = 0;
	Contact** selected_contacts=0;

	unsigned int size_isbr=0;
	Contact** izbr=0;

	string file_name;

	switch (var) {
		case 1:
			cout << "Введите имя файла: ";
			cin >> file_name;

			cout << "Введите фамилию: ";// << endl;
			cin >> surname;
			cout << "Введите имя ";// << endl;
			cin >> name;
			cout << "Введите отчество: ";// << endl;
			cin >> patronymic;

			contacts_list.SaveContactToFile(file_name, surname, name, patronymic);

			break;

		case 2:

			cout << "Введите имя файла: ";
			cin >> file_name;
			contacts_list.AddContactFromFile(file_name);
			break;

		case 3:

			cout << "Введите фамилию: ";// << endl;
			cin >> surname;
			cout << "Введите имя ";// << endl;
			cin >> name;
			cout << "Введите отчество: ";// << endl;
			cin >> patronymic;
			cout << "Введите номер телефона: ";// << endl;
			cin >> number;
			cout << "Введите дату рождения: ";// << endl;
			cin >> date;
			cout << endl;


			new_contact = new Contact(surname, name, patronymic);
			new_contact->number = number;
			new_contact->date = date;

			contacts_list.AddNewContact(new_contact);
			break;

		case 4:
			cout << "Введите фамилию " << endl;
			cin >> surname;
			cout << "Введите имя " << endl;
			cin >> name;
			cout << "Введите отчество " << endl;
			cin >> patronymic;
			cout <<endl;
			
			contact = contacts_list.Search_contact(surname,name,patronymic);

			if (contact != 0) {
				cout << contact->Get_surname() << " " << contact->Get_name() << " " << contact->Get_patronymic() << endl;
				cout <<"Дата раождения: "<< contact->date << "  " << " Номер телефона: "<<contact->number << endl << endl;
			}
			else {
				cout << "Контакт не найден" << endl << endl;
			}
			break;

		case 5:
			cout << "Введите фамилию " << endl;
			cin >> surname;
			cout << "Введите имя " << endl;
			cin >> name;
			cout << "Введите отчество " << endl << endl;
			cin >> patronymic;

			contact = contacts_list.Search_contact(surname, name, patronymic);

			if (contact != 0) {
				cout << "Введите новый номер " << endl;
				cin >> number;
				cout << "Введите новую дату рождения " << endl;
				cin >> date;
				
				contact->number = number;
				contact->date = date;


			}
			else {
				cout << "Контакт не найден" << endl << endl;
			}
			break;

		case 6:
			cout << "Введите номер " << endl;
			cin >> number;

			contact = contacts_list.Search_contact(number);

			if (contact != 0) {
				cout << contact->Get_surname() << " " << contact->Get_name() << " " << contact->Get_patronymic() << endl;
				cout << "Дата раождения: " << contact->date << "  " << " Номер телефона: " << contact->number << endl << endl;
			}
			else {
				cout << "Контакт не найден" << endl << endl;
			}
			break;
		case 7:
			cout << "Введите первые символы ФИО: ";
			cin >> surname;
			cout << endl;
			selected_contacts = contacts_list.Search_cotacts(surname, count);

			if (selected_contacts != 0) {
				for (int i = 0; i < count; i++) {
					cout << selected_contacts[i]->Get_surname() << " " << selected_contacts[i]->Get_name() << " " << selected_contacts[i]->Get_patronymic() << endl;
					cout << "Дата раождения: " << selected_contacts[i]->date << "  " << " Номер телефона: " << selected_contacts[i]->number << endl << endl;
				}
			}
			else {
				cout << "Ни один контакт не найден" << endl << endl;
			}

			delete[] selected_contacts;
			count = 0;
			break;

		
		case 8:
			count = contacts_list.Get_list_size();
			cout << "Общее кол-во контактов: " << count << endl<<endl;
			count = 0;
			break;
		case 9:
			cout << "Введите фамилию " << endl;
			cin >> surname;
			cout << "Введите имя " << endl;
			cin >> name;
			cout << "Введите отчество " << endl;
			cin >> patronymic;
			cout << endl;

			contact = contacts_list.Search_contact(surname, name, patronymic);
			if (contact != 0) {
				contacts_list.AddIzbr(contact);
			}
			else {
				cout << "Контакт не найден: " << endl;
				
			}
			break;
		case 10:
			cout << "Введите фамилию " << endl;
			cin >> surname;
			cout << "Введите имя " << endl;
			cin >> name;
			cout << "Введите отчество " << endl << endl;
			cin >> patronymic;

			contacts_list.Delete_izbr(surname, name, patronymic);
			break;
		case 11:
			izbr = contacts_list.Get_Izbr(size_isbr);
			if (izbr != 0) {
				for (int i = 0; i < size_isbr; i++) {
					cout << izbr[i]->Get_surname() << " " <<izbr[i]->Get_name() << " " << izbr[i]->Get_patronymic() << endl;
					cout << "Дата рождения: " << izbr[i]->date << "  " << " Номер телефона: " << izbr[i]->number << endl << endl;
				}
			}
			break;
		case 12:
			cout << "Введите номер " << endl;
			cin >> number;

			contacts_list.Delete_contact(number);

			break;
		case 13:
			return 0;
		}
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
