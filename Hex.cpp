#include <sstream>
#include "Hex.h"


#define LOW(x) (x & 0xFF)
#define HIGH(x) ((x >> 8) & 0xFF)

Hex::Hex(unsigned int N)
{
	hexdata = new  unsigned char[N];
	_size = N;

	for (unsigned int i = 0; i < _size; i++)
	{
		hexdata[i] = 0;
	}

}

Hex::Hex(string * a,unsigned int size)
{
	_size = size;
	hexdata = new unsigned char[_size];
	for (unsigned int i = _size; i > 0; i--) {
		string sym = "0x" + a[i-1];

		int buf;

		sscanf_s(sym.c_str(), "%X", &buf);
		hexdata[_size-i] = buf;
	}
}

Hex::Hex(string number) {

	std::reverse(number.begin(), number.end());

	hexdata = new  unsigned char[number.length()];
	_size = number.length();
	for (int i = 0; i < number.length(); i++) {

		string sym="0x"+ number.substr(i, 1);

		int buf;

		sscanf_s(sym.c_str(), "%X", &buf);
		hexdata[i] = buf;
	}
}

Hex::Hex(){
	_size = 0;
	hexdata = 0;
}
Hex::~Hex() {

	delete[] hexdata;
	_size = 0;
}

Hex& Hex::operator=(Hex& right) {

	_size = right.Size();
	if (hexdata != 0)delete[] hexdata;

	hexdata = new  unsigned char[_size];


	for (int i = 0; i < right.Size(); i++) {

		this->hexdata[i]=right.GetAt(i);
	}
	return *this;
}

 Hex& operator+( Hex& left,  Hex& right) {
	unsigned int leftleungths = left.Size();
	unsigned int rightleunghts = right.Size();

	unsigned int maxleunghts = rightleunghts;
	unsigned int minlength = leftleungths;

	unsigned char* max_vector = right.hexdata;
	unsigned char* min_vector = left.hexdata;
	
	if (leftleungths > rightleunghts) {

		maxleunghts = leftleungths;
		minlength = rightleunghts;
		
		max_vector = left.hexdata;
		min_vector = right.hexdata;
	}
     
	Hex* sum_vector=new Hex(maxleunghts+1);//создаем объект для суммы
	   	 
	for (unsigned int i = 0; i < maxleunghts; i++)
	{
		unsigned short sum = 0;
		unsigned char highbyte=0;
		unsigned char lowbyte = 0;

		if (i < minlength)
		{
			sum	= max_vector[i] + min_vector[i];
		}
		else
		{
			sum = max_vector[i];
		}
		highbyte = HIGH(sum);
		lowbyte = LOW(sum);

		sum_vector->SetAt(sum_vector->GetAt(i)+lowbyte,i);
		sum_vector->SetAt(highbyte, i+1);
	}

	return *sum_vector;
}
 Hex& operator-(Hex& left, Hex& right) {
	 unsigned int leftleungths = left.Size();
	 unsigned int rightleunghts = right.Size();

	 if (leftleungths < rightleunghts)
	 {
		 Hex* razn_vector = new Hex();//создаем объект для разности
		 return *razn_vector;
	 }

	 Hex* razn_vector = new Hex(leftleungths);//создаем объект для разности

	 for (unsigned int i = 0; i < leftleungths; i++)
	 {
		 int razn = 0;

		 if (i < rightleunghts)
		 {
			 razn = left.hexdata[i] - right.hexdata[i];
			 if (razn >= 0) {
				 razn_vector->SetAt(razn,i);
			 }
			 else
			 {
				unsigned char next=left.hexdata[i + 1];
				next--;
				left.hexdata[i+1]=next;
				razn = left.hexdata[i] + 10 - right.hexdata[i];
				razn_vector->SetAt(razn, i);
			 }
		 }
		 else
		 {
			 razn = left.hexdata[i];
			 razn_vector->SetAt(razn, i);
		 }
		
	 }

	 return *razn_vector;
 }

 bool operator>(Hex & left, Hex & right)
 {
	 unsigned int left_sz = left.Size();
	 unsigned int right_sz = right.Size();
	 if (left_sz > right_sz) {
		 return true;
	 }
	 else if(left_sz<right_sz) {
		 return false;
	 }
	 else {
		 for (int i = left_sz ; i > 0; i--) {

			 if (left.hexdata[i-1] > right.hexdata[i-1])
				 return true;
			 else if (left.hexdata[i-1] < right.hexdata[i-1])
				 return false;
			 else
				 continue;
		 }
	 }
 }

 bool operator<(Hex & left, Hex & right)
 {
	 unsigned int left_sz = left.Size();
	 unsigned int right_sz = right.Size();
	 if (left_sz < right_sz) {
		 return true;
	 }
	 else if (left_sz > right_sz) {
		 return false;
	 }
	 else {
		 for (int i = left_sz; i > 0; i--) {

			 if (left.hexdata[i - 1] < right.hexdata[i - 1])
				 return true;
			 else if (left.hexdata[i - 1] > right.hexdata[i - 1])
				 return false;
			 else
				 continue;
		 }
	 }
 }
 const Hex&	Hex::operator[](unsigned int i)  {
	 Hex* buf = new Hex(1);

	 buf->SetAt(hexdata[i], 0);

	 return *buf;

 }

 std::istream & operator>>(std::istream & in, Hex & date)
 {
	 string input;
	 in >> input;
	 unsigned int sz = input.size() / 3;
	 string* dt = new string[sz];

	 string sim = input.substr(0, 2);
	 dt[0] = sim;

	 if (sz > 1) {
		 for (int i = 1; i <= sz; i++) {
			 string sim = input.substr(i * 3);
			 dt[i] = sim;

		 }

	 }
	 Hex m(dt, sz);

	 delete[] dt;

	 date = m;

	 return in;
}


 std::ostream & operator<<(std::ostream & out, Hex & data)
 {
	 out <<data.GetString();
	 return out;
 }
 


 string Hex::GetString()
 {
	 string res;

	 for (unsigned int i = _size; i >0; i--)
	 {
		 char  buffer[10];

		 if(hexdata[i - 1]==0)sprintf_s(buffer, 10, "00.");
		 else if(hexdata[i-1]<0x10)sprintf_s(buffer, 10, "0%x.", hexdata[i - 1]);
		 else sprintf_s(buffer, 10, "%x.", hexdata[i-1]);
		 
		 res += buffer;
	 }


	 return res;
 }


unsigned char Hex::GetAt(unsigned int i) {

	return hexdata[i];
}

void Hex::SetAt(unsigned char value, unsigned int i) {
	hexdata[i] = value;
}

unsigned int Hex::Size() {
	return _size;

}

