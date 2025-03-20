#include"roleplay.h"
#include<iostream>

Port::Port(const char* br , const char* st , int b = 0)
{
	int len = 0;
	len = strlen(br);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, br);
	len = strlen(st);
	if (len > 19)
		strncpy_s(style, 20, st, 19);
	else
		strcpy_s(style, len + 1, st);
	bottles = b;
}
Port::Port(const Port& p)
{
	int len = 0;
	len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
}


Port& Port::operator=(const Port& p)
{
	if (this == &p)
		return*this;

	delete[] brand;
	int len = 0;
	len = strlen(p.brand);
	brand = new char[len + 1];
	strcpy_s(brand, len + 1, p.brand);
	strcpy_s(style, strlen(p.style) + 1, p.style);
	bottles = p.bottles;
	return *this;
}

Port& Port::operator+=(int b)
{
	bottles += b;
	return*this;
}

Port& Port::operator-=(int b)
{
	bottles -= b;
	return*this;
}

void Port::Show() const
{
	using namespace std;
	cout << "Brand: " << brand << endl
		<< "Kind: " << style << endl
		<< "Bottles: " << bottles;
 }

 ostream& operator<<(ostream& os, const Port& p)
{
	 os << p.brand << ", " << p.style << ", " << p.bottles;
}

 VintagePort::VintagePort():Port()
 {
	 nickname = nullptr;
	 year = 0;
 }

 VintagePort::VintagePort(const char* br,const char* st,int b, const char* nn, int y)
	 :Port(br,st,b)
 {
	 nickname = new char[strlen(nn) + 1];
	 strcpy_s(nickname, strlen(nn) + 1, nn);
	 year = y;
 }

 VintagePort::VintagePort(const VintagePort& vp):Port(vp)
 {
	 nickname = new char[strlen(vp.nickname) + 1];
	 strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	 year = vp.year;
 }

 VintagePort& VintagePort::operator=(const VintagePort& vp)
 {
	 if (this == &vp);
	 return *this;

	 delete[] nickname;
	 Port::operator=(vp);
	 nickname = new char[strlen(vp.nickname) + 1];
	 strcpy_s(nickname, strlen(vp.nickname) + 1, vp.nickname);
	 year = vp.year;
	 return*this;
 }

 void VintagePort::Show() const
 {
	 Port::Show();
	 std::cout << "Nickname: " << nickname << '\n'
		 << "Years: " << year;
 }
 ostream& operator<<(ostream& os, const VintagePort& vp)
 {
	 os << (const Port&)vp << ", " << vp.nickname << ", " << vp.year;
	 return os;
 }