#include<iostream>
#include<cstring>
#include"plorg.h"

Plorg::Plorg(const char* ps, int Ci)
{
	strcpy_s(plorg, MAX, ps);
	CI = Ci;
}

void Plorg::set_CI(int change)
{
	CI = change;
}

void Plorg::show_plorg() const
{
	using namespace std;

	cout << "Plorg is: " << plorg << "\n";
	cout << "CI is: " << CI << endl;
}
