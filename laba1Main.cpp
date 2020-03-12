#include "laba1.h"

int main() {

	setlocale(LC_ALL, "Russian");

	Date d1;
	Date d2("05.03.2020");
	Date d3Err("500.500.2020");
	Date d4 = d2;
	Date d5("01.01.0000");
	Date d6 = d2 + d5;
	Date d7 = d2 - d5;
	Date d8;

	if (d2 > d5) {
		cout << d2.toString() << " > " << d5.toString() << endl;
	}


	cout << d1 << endl;
	cout << d2 << endl;
	cout << d3Err << endl;
	cout << d4 << endl;
	cout << d6 << endl;
	cout << d7 << endl;

	cin >> d8;

	cout << d8 << endl;

	system("pause");
}