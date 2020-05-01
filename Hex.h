#pragma once

#include <string>
#include <iostream>
using namespace std;
class Hex {
private:
	unsigned char *hexdata;
	unsigned int _size;
public:
	Hex();
	Hex(string number);
	Hex(unsigned int N);
	Hex(string* a,unsigned int size);
	~Hex();
	unsigned char GetAt(unsigned int i);
	void SetAt(unsigned char value, unsigned int i);
	unsigned int Size();
	Hex& operator=(Hex& right);
	friend  Hex& operator+( Hex& left,  Hex& right);
	friend  Hex& operator-( Hex& left,  Hex& right);
	string GetString();
	const Hex& operator [](unsigned int i);
	friend bool operator>(Hex& left,Hex& right);
	friend bool operator<(Hex& left, Hex& right);
	friend std::ostream& operator<<(std::ostream &out, Hex &date);
	friend std::istream& operator>>(std::istream &in, Hex &date);


	//Hex& operator=(unsigned char a& right);
	//Hex& operator=(unsigned short b& right);
	//Hex& operator=(unsigned long c& right);



};