#include<iostream>
#include"vector.h"

int main()
{
	using namespace VECTOR;

	Vector as(12.54, 99.99);
	std::cout << as << ": as";

	Vector ad(144.44, 34.7,Vector::POL);
	ad.rect_mode();
	std::cout << ad << ": ad";
	return 0;
}