#ifndef CLASSIC2_H_
#define CLASSIC2_H_

class Cd
{
private:
	char* performers;
	char* label;
	int selecttions;
	double playtime;

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd();
	Cd(const Cd& d);
	virtual ~Cd();
	const Cd& operator=(const Cd& d);
	virtual void Report()const;

};

class Classic :public Cd
{
private:
	char* str;
public:
	Classic(const char* sr, const Cd& d);
	Classic(const char* sr , const char* pf, const char* lb ,
		int sl, double pt );
	Classic(const Classic& cl);
	Classic();
	const Classic& operator=(const Classic& cl);
	virtual ~Classic();
	virtual void Report()const;
};
#endif // !CLASSIC2_H_
