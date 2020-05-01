#include "Hex.h"
#include <fstream>
using namespace std;
int main() {
	string a_data[1];
	string b_data[1];
	a_data[0] = "F1";
	b_data[0] = "1F";
	
	Hex a(a_data,1);
	Hex b(b_data,1);
	Hex sum;
	Hex razn;
	sum = a + b;
	razn = a - b;

	cout << "Razn a=" << a.GetString() << " and b=" << b.GetString() << " is " << razn.GetString() << endl;
	cout << "Sum a=" << a.GetString() << " and b=" << b.GetString() << " is "<< sum.GetString() << endl;

	string c_data[1];
	string d_data[1];
	c_data[0] = "1";
	d_data[0] = "1";

	Hex c(c_data, 1);
	Hex d(d_data, 1);
	sum = c + d;
	razn = c - d;
	cout << "Sum c=" << c.GetString() << " and d=" << d.GetString() << " is " << sum.GetString() << endl;
	cout << "Razn c=" << c.GetString() << " and d=" << d.GetString() << " is " << razn.GetString() << endl;

	if (a > b)
		cout << "a is bigger!" << endl;
	else
		cout << "b is bigger!" << endl;

	if (a < b)
		cout << "b is bigger!" << endl;
	else
		cout << "a is bigger!" << endl;
	
	
	ofstream fout;
	fout.open("file.txt");
	fout << a << endl;
	fout.close();


	ifstream fin;
	fin.open("file.txt");
	fin >> b;
	cout << b << endl;

	Hex bb = b[0];
	cout<< bb << "  " << b << endl;
	
	
}