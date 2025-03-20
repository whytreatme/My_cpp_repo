#include<iostream>
#include"namesp.h"

void another(void);
void other(void);

int main()
{
	using debts::Debt;

	using debts::showDebt;
	Debt golf = { {"Benny","Goatsniff"},120.0 };
	showDebt(golf);

	other();
	another();

	return 0;
}

void other()
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dg = { "Doodles","Glister" };
	showPerson(dg);

	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++)
		getDebt(zippy[i]);
	for (i = 0; i < 3; i++)
		showDebt(zippy[i]);

	cout << "Total debt: $" << sumDebts(zippy, 3) << endl;

	return;
}

void another()
{
	using pers::Person;
	Person collector = { "Millo","Rightshift" };
	pers::showPerson(collector);//只有用尖括号括起来的头文件才能放入标准命名空间
	std::cout << std::endl;
}