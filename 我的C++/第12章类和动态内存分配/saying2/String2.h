#include<iostream>

#ifndef STRING2_H_
#define STRING2_H_

using std::ostream;
using std::istream;

class String
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	String(const char* s);
	String(const String&);
	String();
	~String();

	int length() const { return len; }

	String& operator=(const char*);
	String& operator=(const String& st);
	char& operator[](int i);
	const char& operator[](int i)const;

	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend istream& operator>>(istream& is, String& st);
	friend ostream& operator<<(ostream& os, const String st);

	static int HowMany();
};


#endif // !STRING2_H_
