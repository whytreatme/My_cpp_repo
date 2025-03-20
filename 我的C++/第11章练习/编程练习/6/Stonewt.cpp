#include<iostream>
using std::cout;
#include"Stonewt.h"

Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = POUNDS;
}

Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = FLOATPOUNDS;
}

Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
	mode = POUNDS;
}

Stonewt::~Stonewt()
{}



bool Stonewt::operator>(const Stonewt& st)const
{
	if (pounds > st.pounds)
		return true;
	else
		return false;
}

bool Stonewt::operator<(const Stonewt& st)const
{
	if (pounds < st.pounds)
		return true;
	else
		return false;
}

bool Stonewt::operator==(const Stonewt& st)const
{
	if (pounds == st.pounds)
		return true;
	else
		return false;
}

bool Stonewt::operator>=(const Stonewt& st)const
{
	if (pounds >= st.pounds)
		return true;
	else
		return false;
}
bool Stonewt::operator<=(const Stonewt& st)const
{
	if (pounds <= st.pounds)
		return true;
	else
		return false;
}

bool Stonewt::operator!=(const Stonewt& st)const
{
	if (pounds != st.pounds)
		return true;
	else
		return false;
}

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
		os << st.stone + st.pds_left / st.Lbs_per_stn << " stone\n";
		return os;
	}
	else if (st.mode == Stonewt::POUNDS)
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
