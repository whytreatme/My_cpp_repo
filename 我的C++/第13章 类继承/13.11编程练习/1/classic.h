#ifndef CLASSIC_H_
#define CLASSIC_H_

class Cd
{
private:
	char performers[50];
	char label[20];
	int selecttions;
	double playtime;

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd();
	virtual ~Cd();
	virtual void Report()const;
	
};

class Classic :public Cd
{
private:
	char str[100];
public:
	Classic(const char* sr, const Cd& d);
	Classic(const char* sr = "noinfo", const char* pf = "noname", const char* lb = "nolabel",
		int sl = 0, double pt = 0.0);
	virtual ~Classic();
	virtual void Report()const;
};
#endif // !CLASSIC_H_
