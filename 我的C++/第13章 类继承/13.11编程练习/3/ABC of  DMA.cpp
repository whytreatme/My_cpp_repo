#include"ABC of  DMA.h"
#include<iostream>


abcDMA::abcDMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

abcDMA::abcDMA(const abcDMA& rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

abcDMA::~abcDMA()
{
	delete[] label;
}

abcDMA& abcDMA::operator=(const abcDMA& rs)
{
	if (this == &rs)
		return *this;

	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
	return *this;
}

void abcDMA::View()const
{
	using std::cout;
	cout << "Label: " << label << std::endl;
	cout << "Rating: " << rating << std::endl;
}
std::ostream& operator<<(std::ostream& os, const abcDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;

	return os;
}

baseDMA::baseDMA(const char* la, int r) :abcDMA(la, r)
{
	;
}
baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	abcDMA::operator=(rs);
	return*this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << (const abcDMA&)rs;
	return os;
}

void baseDMA::View()const
{
	abcDMA::View();
}


lacksDMA::lacksDMA(const char* c, const char* l, int r) :abcDMA(l, r)
{
	/*std::strncpy(color, c, 39);*/
	strncpy_s(color, 40, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const abcDMA& rs) :abcDMA(rs)
{
	//std::strncpy(color, c,COL_LEN-1);
	strncpy_s(color, 40, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

void lacksDMA::View()const
{
	using std::cout;
	abcDMA::View();
	cout << "Color: " << color << std::endl;
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const abcDMA&)ls;
	os << "Color: " << ls.color << std::endl;

	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r) :abcDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs) :abcDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;

	delete[]style;
	abcDMA::operator=(hs);
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA::hasDMA(const char* s, const abcDMA& rs) :abcDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

void hasDMA::View()const
{
	using std::cout;
	abcDMA::View();
	cout << "Style: " << style << std::endl;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const abcDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}