#include<iostream>

#ifndef COMPLEX_O_H
#define COMPLEX_O_H


class complex
{
private:
	double real;
	double imaginary;

public:
	complex();
	complex(double real, double imaginary);
	~complex(){};

	complex operator+(const complex& co)const;
	complex operator-(const complex& co)const;
	complex operator*(const complex& co)const;
	complex operator*(double x)const;
	complex operator~()const;

	friend bool operator>>(std::istream& is,  complex& co);
	friend std::ostream& operator<<(std::ostream& os, const complex& co);
	friend complex operator*(double x, const complex& co);

};
#endif // !COMPLEX_0_H

