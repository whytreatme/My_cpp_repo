#include<cstring>
#include"stringbad.h"
using std::cout;

int Stringbad::num_strings = 0;

Stringbad::Stringbad(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len, s);
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\"object created\n";
}

Stringbad::Stringbad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str, 3, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str
		<< "\" default object created\n";
}

Stringbad::~Stringbad()
{
	cout << "\"" << str << "\"object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const Stringbad st)
{
	os << st.str;
	return os;
}