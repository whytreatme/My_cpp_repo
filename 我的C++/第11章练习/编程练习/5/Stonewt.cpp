#include<iostream>
using std::cout;
#include"Stonewt.h"

Stonewt::Stonewt(double lbs,Mode form)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = form;
}

Stonewt::Stonewt(int stn, double lbs,Mode form)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = form;
}

Stonewt::Stonewt()
{
	stone = 0;
	pounds = 0;
	pds_left = 0;
}

Stonewt::~Stonewt()
{}
//构造与析构

Stonewt operator+(const Stonewt& st, const Stonewt& kt)
{
	Stonewt temp(st.pounds + kt.pounds);
	return temp;
}

Stonewt operator-(const Stonewt& st, const Stonewt& kt)
{
	Stonewt temp(st.pounds - kt.pounds);
	return temp;
}
Stonewt Stonewt::operator*(double mult) const
{
	return Stonewt(pounds * mult);
}
//基础运算

void Stonewt::pounds_mode() 
{
	mode = POUNDS;
}

void Stonewt::stone_mode() 
{
	mode = STONE;
}

void Stonewt::float_pounds_mode()
{
	mode = FLOATPOUNDS;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& st)
{
	if (st.mode == Stonewt::STONE)
	{
		os << st.stone+st.pds_left/st.Lbs_per_stn << " stone\n" ;
		return os;
	}
	else if(st.mode==Stonewt::POUNDS)
	{
		os << st.pounds << " pounds";
		return os;
	}

	else if (st.mode == Stonewt::FLOATPOUNDS)
	{
		os << st.stone << " stone, " << st.pds_left << " pounds\n";
		return os;
	}
	else
	{
		cout << "Somthing has been wrong" << '\n';
		return os;
	}
}
