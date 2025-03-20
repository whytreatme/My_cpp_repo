﻿#include"Time.h"

#ifndef TIME_H_
#define TIME_H_


Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

 Time operator+(const Time& t,const Time& s)
{
	Time sum;
	sum.minutes = s.minutes + t.minutes;
	sum.hours = s.hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;

	return sum;
}

Time operator-(const Time& t,const Time& s) 
{
	Time diff;
	int tot1, tot2;
	tot1 = t.minutes + 60 * t.hours;
	tot2 = s.minutes + 60 * s.hours;
	diff.minutes = (tot1 - tot2) % 60;
	diff.hours = (tot1 - tot2) / 60;

	return diff;
}

Time Time::operator*(double mult) const
{
	Time result;
	long totalminutes = hours * mult * 60 + minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;

	return result;
}

Time operator*(double mult, const Time& t)
{
	return t * mult;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

std::ostream& operator<<(std::ostream& os, const Time& t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

#endif // !TIME_H_