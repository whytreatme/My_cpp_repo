#include<iostream>
#include"plorg.h"

int main()
{
	using namespace std;
	Plorg as;
	as.show_plorg();

	as.set_CI(67);
	as.show_plorg();

	
	int ci;
	cout << "Input CI you of objection B: ";
	while (!(cin >> ci))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Bad input; Enter a value,please: ";
		continue;
	}
	
	Plorg Ba("Ohmygod", ci);
	Ba.show_plorg();

	return 0;
}