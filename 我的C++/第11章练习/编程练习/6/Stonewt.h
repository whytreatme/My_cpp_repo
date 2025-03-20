#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
public:
	enum Mode{STONE,POUNDS,FLOATPOUNDS};
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
	Mode mode;
public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();
	
	void pounds_mode();
	void stone_mode();
	void float_pounds_mode();


	bool operator>(const Stonewt& st)const;
	bool operator<(const Stonewt& st)const;
	bool operator==(const Stonewt& st)const;
	bool operator>=(const Stonewt& st)const;
	bool operator<=(const Stonewt& st)const;
	bool operator!=(const Stonewt& st)const;

	friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
};
#endif // !STONEWT_H_

#pragma once
