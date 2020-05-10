#pragma once

#include <vector>
using namespace std;

enum SROK
{
	YEAR_1 = 1,
	YEAR_2 = 2,
	YEAR_3 = 3,
	YEAR_5 = 5,
	YEAR_15 = 15
};

enum SUMM {
	SUMM_LESS_100=1,
	SUMM_LESS_500=2,
	SUMM_LESS_1000=3,
	SUMM_LESS_3000=4,
	SUMM_INVALID=5
};

class CreditVariant
{
public:
    SROK srok;
	SUMM summ;
	unsigned int max_summ;

    vector<CreditVariant> AllVariants();
	vector<CreditVariant> SelectedVariants;

};

class Credit {
private:
	SROK _srok;
	SUMM _type;
	unsigned long _summ;
	const double koef_k = 10;
	const double koef_l = 5;

public:
	Credit(unsigned long summ, SROK srok);
	float Ratio();
	float PayMent();
	unsigned long GetSumm();
	unsigned long AddSum(unsigned long summ, int monthes);
	


};
