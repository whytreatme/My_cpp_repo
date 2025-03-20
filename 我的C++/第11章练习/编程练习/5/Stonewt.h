#include<iostream>
#ifndef STONEWT_H_
#define STONEWT_H_M


class Stonewt
{
public:
	enum Mode { POUNDS, STONE,FLOATPOUNDS };
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	Mode mode;

public:
	Stonewt(double lbs,Mode mode=POUNDS);
	Stonewt(int stn, double lbs,Mode mode=FLOATPOUNDS);
	Stonewt();
	~Stonewt();
	
	void pounds_mode() ;
	void stone_mode() ;
	void float_pounds_mode();

	Stonewt operator*(double m)const;
	
	
	friend Stonewt operator+(const Stonewt& st, const Stonewt& ht);
	friend Stonewt operator-(const Stonewt& st, const Stonewt& ht);
	friend Stonewt operator*(double m, const Stonewt& st)
	{
		return st * m;
	}
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
};
#endif // !STONEWT_H_

#pragma once
