#include "laba1.h"

Date::Date() {
		_year = 0;
		_month = 0;
		_day = 0;
}

Date::~Date() {
		cout << "Hello from destructor\n";
}

string Date::toString() {
		char str[10];
		sprintf_s(str, "%d.%d.%d", _day, _month, _year);
		return string(str);
}

Date::Date(string date) {
		sscanf_s(date.c_str(), "%d.%d.%d", &_day, &_month, &_year);
		if (_day > 31 || _day<1) {
			_day = 0;
		}
		if (_month > 12 || _month<1) {
			_month = 0;
		}
}

Date& Date::operator=(Date& right) {
		Date d(right.toString());
		return d;
}


std::istream& operator>>(std::istream &in, Date &date) {
	
	string input;
	in >> input;
	Date newDate(input);

	date._year = newDate._year;
	date._month = newDate._month;
	date._day = newDate._day;

	return in;
}

std::ostream& operator<< (std::ostream &out, Date &date) {
	out << date.toString();
	return out;
}


const bool  operator>(const Date& left, const Date& right) {
	long int leftdays = 0;
	long int rightdays = 0;

	leftdays += ((left._year - 1) * 365) + (left._month - 1) * 30 + left._day;
	rightdays += ((right._year - 1) * 365) + (right._month - 1) * 30 + right._day;

	if (leftdays > rightdays) {
		return true;
	}
	else {
		return false;
	}

}

const Date operator+(const Date& left, const Date& right) {

	Date res;

	int add_month = 0;
	int add_year = 0;

	res._day = left._day + right._day;

	res._month = left._month + right._month;

	res._year = left._year + right._year;

	if (res._day > 31)
	{
		res._day -= 31;
		add_month = 1;
	}

	res._month += add_month;

	if (res._month > 12)
	{
		res._month -= 12;
		add_year = 1;
	}

	res._year += add_year;

	return res;
}
const Date operator-(const Date& left, const Date& right) {

	Date res;

	int del_month = 0;
	int del_year = 0;

	res._day = left._day - right._day;

	res._month = left._month - right._month;

	res._year = left._year - right._year;

	if (res._day < 1)
	{
		res._day += 31;
		del_month = 1;
	}

	res._month -= del_month;

	if (res._month < 1)
	{
		res._month += 12;
		del_year = 1;
	}

	res._year -= del_year;
	return res;
}