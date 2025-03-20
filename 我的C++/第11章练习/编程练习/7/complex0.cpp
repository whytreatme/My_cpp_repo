#include"complex0.h"

using namespace std;


complex::complex()
{
	real = imaginary = 0.0;
}

complex::complex(double shi, double xu)
{
	real = shi;
	imaginary = xu;
}

complex complex::operator+(const complex& co)const
{
	complex temp((real + co.real), (imaginary + co.imaginary));
	return temp;
}

complex complex::operator-(const complex& co)const
{
	complex temp((real - co.real), (imaginary - co.imaginary));
	return temp;
}

complex complex::operator*(const complex& co)const
{
	complex temp((real * co.real - imaginary * co.imaginary), (real * co.imaginary + imaginary * co.real));
	return temp;
}

complex complex::operator*(double x)const
{
	complex temp((x * real), (x * imaginary));
	return temp;
}

complex complex::operator~()const
{
	complex temp(real, -imaginary);
	return temp;
}

bool operator>>(std::istream& is, complex& co)
{
	cout << "real: ";
	if (!(is >> co.real))
		return false;

	cout << "imaginary: ";
	while (!(is >> co.imaginary))
	{
		cout << "Error! Try again: " << endl;
		is.clear();
		while (is.get() != '\n')
			continue;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const complex& co)
{
	os << "(" << co.real << "," << co.imaginary << "i)";
	return os;
}

complex operator*(double x, const complex& co)
{
	return co * x;
}
