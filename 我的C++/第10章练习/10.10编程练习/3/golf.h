#ifndef GOLF_H_
#define GOLF_H_



const int Len = 40;

class Golf
{
private:
	char fullname[Len];
	int m_handicap;

public:
	Golf(const char* name, int hc);
	Golf();
	~Golf();
	void handicap(int hc);
	void showgolf() const;
};

#endif // !GOLF_H_
