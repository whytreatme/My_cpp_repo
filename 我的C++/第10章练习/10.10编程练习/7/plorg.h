#ifndef PLORG_H_
#define PLORG_H_

class Plorg
{
private:
	enum{MAX=19};
	char plorg[MAX];
	int CI;
	
public:
	Plorg(const char* na = "Plorga", int Ci = 50);
	~Plorg() {};
	void set_CI(int change);
	void show_plorg() const;
};
#endif // !PLORG_H_

