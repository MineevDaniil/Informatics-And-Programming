#include "Client.h"
Client::Client(string count, string FIO, long int summ, string password) {
	_count = count;
	_FIO = FIO;
	_summ = summ;
	_password = password;
}

void Client::AddCredit(Credit& credit) {
	_credits.push_back(&credit);
	unsigned long summ = credit.GetSumm();
	_summ += summ;
}

float Client::GetCount() {
	return _summ;
}

void Client::Payment(Credit& credit, long int summ, int monthes) {
		unsigned long rest = credit.AddSum(summ, monthes);
		_summ += rest;

}

vector<Credit*> Client::GetCredits() {

	return _credits;
}

bool Client::Athtorization(string count, string password) {
	if (count == _count && password == _password) {
		return true;
	}
	else {
		return false;
	}
}

vector<CreditVariant> Client::Accessed_variants() {
	CreditVariant variant;
	vector<CreditVariant> all_variants = variant.AllVariants();
	vector<CreditVariant> selected_variants;

	for (int i = 0; i < all_variants.size();i++) {

		Credit cur_credit(all_variants[i].max_summ, all_variants[i].srok);

		if (cur_credit.PayMent() * 6 <= GetCount())
		{
			selected_variants.push_back(all_variants[i]);
		}
	}
	return selected_variants;

}