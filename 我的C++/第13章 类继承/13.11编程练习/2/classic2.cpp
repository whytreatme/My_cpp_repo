#include"classic2.h"
#include<iostream>


Cd::Cd()
{
	performers = nullptr;
	label = nullptr;
	selecttions = 0;
	playtime = 0.0;
}

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int len = 0;
	len = strlen(s1);
	performers = new char[len + 1];
	strcpy_s(performers, len + 1, s1);
	len = strlen(s2);
	label = new char[len + 1];
	strcpy_s(label, len + 1, s2);
	selecttions = n;
	playtime = x;
}

Cd::Cd(const Cd& d)
{
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selecttions = d.selecttions;
	playtime = d.playtime;
}

const Cd& Cd::operator=(const Cd& d)
{
	if (this == &d)
		return*this;

	delete[] performers;
	delete[]label;
	performers = new char[strlen(d.performers) + 1];
	strcpy_s(performers, strlen(d.performers) + 1, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy_s(label, strlen(d.label) + 1, d.label);
	selecttions = d.selecttions;
	playtime = d.playtime;
	return*this;
}

Cd::~Cd()
{
	delete[] performers;
	delete[] label;
}

void Cd::Report()const
{
	using namespace std;

	cout << "The performers are: " << performers << endl
		<< "Label is: " << label << endl
		<< "selections: " << selecttions << '\n' << "playtimes: " << playtime << endl;
}

Classic::Classic() :Cd()
{
	str = nullptr;
}

Classic::Classic(const char* sr, const char* pf, const char* lb,
	int sl, double pt) :Cd(pf, lb, sl, pt)
{
	int len = 0;
	len = strlen(sr);
	str = new char[len + 1];
	strcpy_s(str, len + 1, sr);
}

Classic::Classic(const char* sr, const Cd& d) :Cd(d)
{
	int len = 0;
	len = strlen(sr);
	str = new char[len + 1];
	strcpy_s(str, len + 1, sr);
}

Classic::Classic(const Classic& cl):Cd(cl)
{
	str = new char[strlen(cl.str) + 1];
	strcpy_s(str, strlen(cl.str) + 1, cl.str);
}

const Classic& Classic::operator=(const Classic& cl)
{
	if (this == &cl)
		return*this;

	delete[]str;
	Cd::operator=(cl);
	str = new char[strlen(cl.str) + 1];
	strcpy_s(str, strlen(cl.str) + 1, cl.str);
}

Classic::~Classic()
{
	delete[]str;
}

void Classic::Report()const
{
	using std::cout;
	cout << "Information: " << str << '\n';
	Cd::Report();
}