#include "ProCenter.h"
#include "Credit.h"
#include <iostream>
using namespace std;

int main() {
	ProCenter p_center;

	Client CL1("0001", "Ivanov Ivan Ivanovich ", 100000, "qwerty123");
	Client CL2("0002", "Ivanov Petr Ivanovich ", 1000000, "asdfjkl;");
	p_center.AddClient(CL1);
	p_center.AddClient(CL2);

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