#include<iostream>
#include"person.h"

int main()
{
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");

	one.Show();
	std::cout << std::endl;
	one.FormalShow();

	two.FormalShow();
	three.FormalShow();

	return 0;
}