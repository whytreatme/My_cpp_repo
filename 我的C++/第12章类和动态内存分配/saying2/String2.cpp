#include<cstring>
#include"String2.h"
using std::cout;
using std::cin;

int String::num_strings = 0;

int String::HowMany()
{
	return String::num_strings;
}

String::String(const char* s)
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_strings++;

}

String::String(const String& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
}

String::String()
{
	len = 0;
	str = new char[1];
	str = nullptr;
	num_strings++;

}

String::~String()
{
	--num_strings;
	delete[] str;
}

String& String::operator=(const String& st)
{
	if (this == &st)
		return *this;

	len = st.len;
	delete[] str;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}

String& String::operator=(const char* s)
{
	len = strlen(s);
	delete[]str;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

char& String::operator[](int i)
{
	return str[i];
}

const char& String::operator[](int i) const
{
	return str[i];
}

bool operator<(const String& st, const String& st2)
{
	return (strcmp(st.str, st2.str) < 0);
}

bool operator>(const String& st, const String& st2)
{
	return (st2 < st);
}

bool operator==(const String& st, const String& st2)
{
	return (strcmp(st.str, st2.str) == 0);
}

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

std::ostream& operator<<(std::ostream& os, const String st)
{
	os << st.str;
	return os;
}