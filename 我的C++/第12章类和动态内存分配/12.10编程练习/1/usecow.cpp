#include<iostream>
#include"cow.h"

int main()
{
	/*Cow* hua = new Cow("huahua", "Eat grasses", 150);
	hua->ShowCow();
	Cow mama;
	mama.ShowCow();
	mama = *hua;
	mama.ShowCow();

	Cow gouzazhong = { "LiangShuQiao","Watch mobiephone",300 };
	Cow meimei(gouzazhong);
	meimei.ShowCow();

	delete hua;
	return 0;*/

	Cow* hua = new Cow;
	delete hua;
	return 0;
}