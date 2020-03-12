#pragma once


#include <string>
#include <iostream>
using namespace std;

class Date {

public:
	Date();

	~Date();

	string toString();

	Date(string date);

	Date& operator=(Date& right);

	friend const Date operator+(const Date& left, const Date& right);
	friend const Date operator-(const Date& left, const Date& right);
	friend const bool operator>(const Date& left, const Date& right);
	friend std::ostream& operator<< (std::ostream &out, Date &date);
	friend std::istream& operator>>(std::istream &in, Date &date);

private:
	int _year;
	int _month;
	int _day;
};
