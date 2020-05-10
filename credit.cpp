#include "Credit.h"

Credit::Credit(unsigned long summ, SROK srok) {
	_summ = summ;
	_srok = srok;

	if (_summ <=100000) {
		_type = SUMM_LESS_100;
	}
	else if ((_summ > 100000) && (_summ <= 500000)) {
		_type=SUMM_LESS_500;
	}
	else if ((_summ > 500000) && (_summ <= 1000000)) {
		_type = SUMM_LESS_1000;
	}
	else if ((_summ > 1000000) && (_summ <= 3000000)) {
		_type = SUMM_LESS_3000;
	}
	else {
		_type = SUMM_INVALID;
		_summ = 0;
	}

}

float Credit::Ratio() {
	if (_type == SUMM_INVALID) {
		return 0;
	}
	float x = (koef_k / _srok) + (koef_l / _type);
	return x;
}

float Credit::PayMent() {
	float monthpay = ((Ratio() / 100 * _srok) + _summ) / (_srok * 12);
	return monthpay;
}

unsigned long Credit::GetSumm() {

	return _summ;
}

unsigned long Credit::AddSum(unsigned long summ,int monthes) {
	long int procent = monthes * PayMent();
	long int result = summ - procent;

	if (result < 0) {
		return 0;
	}

	long int ostatok = _summ - result;
	if (ostatok >= 0) {

		_summ = ostatok;
	}
	else {
		_summ = 0;
		return ostatok * (-1);
	}

}


vector<CreditVariant> CreditVariant::AllVariants()
{
	vector<CreditVariant> all_variants;

	CreditVariant variant;

	variant.srok = YEAR_1;
	variant.summ = SUMM_LESS_100;
	variant.max_summ = 99999;

	all_variants.push_back(variant);

	variant.srok = YEAR_1;
	variant.summ = SUMM_LESS_500;
	variant.max_summ = 499999;


	all_variants.push_back(variant);
	
	variant.srok = YEAR_1;
	variant.summ = SUMM_LESS_1000;
	variant.max_summ = 999999;

	all_variants.push_back(variant);

	variant.srok = YEAR_1;
	variant.summ = SUMM_LESS_3000;
	variant.max_summ = 2999999;

	all_variants.push_back(variant);

	variant.srok = YEAR_2;
	variant.summ = SUMM_LESS_100;
	variant.max_summ = 99999;
	all_variants.push_back(variant);

	variant.srok = YEAR_2;
	variant.summ = SUMM_LESS_500;
	variant.max_summ = 499999;
	all_variants.push_back(variant);

	variant.srok = YEAR_2;
	variant.summ = SUMM_LESS_1000;
	variant.max_summ = 999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_2;
	variant.summ = SUMM_LESS_3000;
	variant.max_summ = 2999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_3;
	variant.summ = SUMM_LESS_100;
	variant.max_summ = 99999;
	all_variants.push_back(variant);

	variant.srok = YEAR_3;
	variant.summ = SUMM_LESS_500;
	variant.max_summ = 499999;
	all_variants.push_back(variant);

	variant.srok = YEAR_3;
	variant.summ = SUMM_LESS_1000;
	variant.max_summ = 999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_3;
	variant.summ = SUMM_LESS_3000;
	variant.max_summ = 2999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_5;
	variant.summ = SUMM_LESS_100;
	variant.max_summ = 99999;
	all_variants.push_back(variant);

	variant.srok = YEAR_5;
	variant.summ = SUMM_LESS_500;
	variant.max_summ = 499999;
	all_variants.push_back(variant);

	variant.srok = YEAR_5;
	variant.summ = SUMM_LESS_1000;
	variant.max_summ = 999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_5;
	variant.summ = SUMM_LESS_3000;
	variant.max_summ = 2999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_15;
	variant.summ = SUMM_LESS_100;
	variant.max_summ = 99999;
	all_variants.push_back(variant);

	variant.srok = YEAR_15;
	variant.summ = SUMM_LESS_500;
	variant.max_summ = 499999;
	all_variants.push_back(variant);

	variant.srok = YEAR_15;
	variant.summ = SUMM_LESS_1000;
	variant.max_summ = 999999;
	all_variants.push_back(variant);

	variant.srok = YEAR_15;
	variant.summ = SUMM_LESS_3000;
	variant.max_summ = 2999999;
	all_variants.push_back(variant);

	return all_variants;
}