#include<string>
#include"dma.h"

baseDMA::baseDMA(const char* l, int r)
{
	label = new char[strlen(l) + 1];
	strcpy_s(label, strlen(l) + 1, l);
	rating = r;
}

baseDMA::baseDMA(const baseDMA& rs)
{
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label) + 1, rs.label);
	rating = rs.rating;
}

baseDMA::~baseDMA()
{
	delete[] label;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	if (this == &rs)
		return *this;

	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy_s(label, strlen(rs.label)+1, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;

	return os;
}

lacksDMA::lacksDMA(const char* c, const char* l, int r) :baseDMA(l, r)
{
	/*std::strncpy(color, c, 39);*/
	strncpy_s(color, 40, c, 39);
	color[39] = '\0';
}

lacksDMA::lacksDMA(const char* c, const baseDMA& rs) :baseDMA(rs)
{
	//std::strncpy(color, c,COL_LEN-1);
	strncpy_s(color, 40, c, COL_LEN - 1);
	color[COL_LEN-1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const baseDMA&)ls;
	os << "Color: " << ls.color << std::endl;

	return os;
}

hasDMA::hasDMA(const char* s, const char* l, int r) :baseDMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

hasDMA::hasDMA(const hasDMA& hs) :baseDMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;

	delete[]style;
	baseDMA::operator=(hs);
	style = new char[strlen(hs.style) + 1];
	strcpy_s(style, strlen(hs.style) + 1, hs.style);
	return *this;
}

hasDMA::~hasDMA()
{
	delete[] style;
}

hasDMA::hasDMA(const char* s, const baseDMA& rs) :baseDMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy_s(style, strlen(s) + 1, s);
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const baseDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}