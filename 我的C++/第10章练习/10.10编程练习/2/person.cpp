#include<iostream>
#include<cstring>
#include"person.h"

Person::Person(const std::string& ln, const char* fn )
{
	lname = ln;
	strcpy_s(fname, LIMITS, fn);
}

Person::~Person()
{}

void Person::Show() const
{
	using namespace std;

	if (lname == "" && fname[0] =='\0')
		cout << "No Name." << endl;
	cout << "Name: " << fname << "." << lname << endl;
}

void Person::FormalShow() const
{
	using namespace std;
	if (lname == " " && fname[0] == '\0')
		cout << "No Name." << endl;

	cout << "Person Name: " << lname << "." << fname << endl;
}