#pragma once
#include <string>
#include "Credit.h"
#include <vector>
using namespace std;

class Client {
private:
	string _count;
	string _FIO;
	long int _summ;
	vector<Credit*> _credits;
	string _password;
public:
	Client(string count,string FIO,long int summ,string password);
	void AddCredit(Credit& credit);
	float GetCount();
	void Payment(Credit& credit, long int summ, int monthes);
	vector<Credit*> GetCredits();
	bool Athtorization(string count,string password);
	vector<CreditVariant> Accessed_variants();
};
