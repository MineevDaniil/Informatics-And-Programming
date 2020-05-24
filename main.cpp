#include "ProCenter.h"
#include "Credit.h"
#include <iostream>

using namespace std;

int prompt_menu_item()
{
	// Выбранный вариант менюж
	int variant;
	cout << "1. Авторизация" << endl;
	cout << "2. Выход" << endl;
	cin >> variant;
	return variant;
}

int work_menu()
{
	// Выбранный вариант менюж
	int var;
	cout << "1. Информация о доступных кредитах " << endl;
	cout << "2. Проверить наличие кредитов" << endl;
	cout << "3. Получить кредит" << endl;
	cout << "4. Выход" << endl;
	cin >> var;
	return var;
}

int main() {

	setlocale(LC_ALL, "Russian");

    ProCenter p_center;

	Client CL1("0001", "Ivanov Ivan Ivanovich ", 100000, "qwerty123");
	Client CL2("0002", "Ivanov Petr Ivanovich ", 1000000, "asdfjkl");
	p_center.AddClient(CL1);
	p_center.AddClient(CL2);

	int variant = prompt_menu_item();
	string count;
	string password;

	switch (variant) {
	   case 1:
		   cout << "Введите номер счета: ";
		   cin >> count;
		   Client* client;
		   client = p_center.SearchClient(count);

		   if (client == 0) {
			   cout << "Неизвестный номер счета!"<<endl;
			   cin >> count;
			   return 0;
		   }
		   else {
			   cout << "Введите пароль: ";
			   cin >> password;
			   bool ok= client->Athtorization(count, password);

			   vector<CreditVariant> credit_variants;

			   if (ok == true) {
				   while (true) {
					   int var = work_menu();

					   vector<Credit*> client_credits;
					   

					   CreditVariant selected_credit;
					   int credit_number;
					   vector<Credit*> Credits;
					   switch (var) {
					       case 1:
		
							   credit_variants = client->Accessed_variants();

						       for (int i = 0; i < credit_variants.size(); i++) {
								   cout << i<< ". "<<"Срок: " << credit_variants[i].srok << " лет, макс. сумма: " << credit_variants[i].max_summ << " руб." << endl;
						       }
							   
							   break;
					       case 2:
							   Credits=client->GetCredits();
							   for (int i = 0; i < Credits.size(); i++) {
								   cout << i << " " << "Кредит на  " << Credits[i]->GetSumm()<< " RUB на "<<Credits[i]->GetSrok()<<" лет" <<endl;
							   }

							   break;
						   case 3:
							   credit_number = 0;
							   cout << "Выберите тарифный план" << endl;
							   cin >> credit_number;
							   selected_credit = credit_variants[credit_number];
							   unsigned long summ;
							   cout << "Введите сумму: " << endl;
							   cin >> summ;
							   if (summ > selected_credit.max_summ) {
								   cout << "Сумма слишком велика для выбранного тарифного плана " << endl;
								   break;
							   }
							   else {
								   Credit new_credit(summ, selected_credit.srok);
								   client->AddCredit(new_credit);
							   break;
							   }
							  
						   case 4:
						      return 0;
					   }
				   }

				   cout << endl;
			   }
			   else {
				   cout << "Неверный пароль" << endl;
				   cin >> count;
				   return 0;
			   }   
		   }

		   break;
	   case 2:
		   return 0;
	   }



	

	Credit cr_1(750000, YEAR_3);
	bool accept_cl1 = p_center.Accept(cr_1,CL1);
	if (accept_cl1 == true) {
		CL1.AddCredit(cr_1);
	}
	Credit cr_2(100000, YEAR_1);
	bool accept_cl2 = p_center.Accept(cr_2, CL2);
	if (accept_cl2 == true) {
		CL2.AddCredit(cr_2);
	}

	Credit cr_2_2(450000, YEAR_2);
	bool accept_cl2_2 = p_center.Accept(cr_2_2, CL2);
	if (accept_cl2_2 == true) {
		CL2.AddCredit(cr_2_2);
	}
	

	cout << accept_cl1 << endl;
	cout << accept_cl2 << endl;

	if (CL2.Athtorization("0002", "asdfjkl;") == true)
	{
		CL2.Payment(cr_2, 300000, 12);
		cout << "credit rest: " << cr_2.GetSumm() << " Free Summ: " << CL2.GetCount() << endl;

		vector<Credit*> cl2_credits = CL2.GetCredits();

		for (int i = 0; i < cl2_credits.size(); i++) {

			cout << (cl2_credits[i])->GetSumm() << endl;
		}

	}
	else {
		cout << "Incorrect login or password" << endl;
	}


	if (CL1.Athtorization("0001", "qwerty123") == true) {
		
		vector<CreditVariant> selected_vars = CL1.Accessed_variants();
		cout << "Dostypnie crediti clienta 1:" << endl;
		for (int i = 0; i < selected_vars.size(); i++) {
			cout << "Srok: " <<selected_vars[i].srok<<" MaxSumm: "<<selected_vars[i].max_summ << endl;
			
			
		}

	}
	else {
		cout << "Incorrect login or password" << endl;
	}
	
	string a;
	cin >> a;


}