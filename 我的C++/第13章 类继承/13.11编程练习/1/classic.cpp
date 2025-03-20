#include"classic.h"
#include<iostream>

Cd::Cd()
{
	performers[49] = '\0';
	label[19] = '\0';
	selecttions = 0;
	playtime = 0.0;
}

Cd::Cd(const char* s1, const char* s2, int n, double x)
{
	int len = 0;
	len = strlen(s1);
	if (len > 49)
	{
		strncpy_s(performers, 50, s1, 49);
	}
	else
		strcpy_s(performers, len + 1, s1);

	len = strlen(s2);
	if (len > 19)
	{
		strncpy_s(label, 20, s2, 19);
	}
	else
		strcpy_s(label, len + 1, s2);

	selecttions = n;
	playtime = x;
}

Cd::~Cd()
{

}

void Cd::Report()const
{
	using namespace std;

	cout << "The performers are: " << performers << endl
		<< "Label is: " << label << endl
		<< "selections: " << selecttions << '\n' << "playtimes: " << playtime << endl;
}

Classic::Classic(const char* sr, const char* pf , const char* lb ,
	int sl, double pt) :Cd(pf,lb,sl,pt)
{
	str[99] = '\0';
	int len = 0;
	len = strlen(sr);
	if (len > 99)
	{
		strncpy_s(str, 100, sr, 99);
	}
	else
		strcpy_s(str, len + 1, sr);
}

Classic::Classic(const char* sr, const Cd& d) :Cd(d)
{
	str[99] = '\0';
	int len = 0;
	len = strlen(sr);
	if (len > 99)
	{
		strncpy_s(str, 100, sr, 99);
	}
	else
		strcpy_s(str, len + 1, sr);
}

Classic::~Classic()
{

}

void Classic::Report()const
{
	using std::cout;
	cout << "Information: " << str << '\n';
	Cd::Report();
}