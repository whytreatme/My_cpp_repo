#ifndef ABC_OF_DMA_H_
#define ABC_OF_DMA_H_
#include<iostream>


class abcDMA
{
private:
	char* label;
	int rating;

public:
	abcDMA(const abcDMA& aA);
	abcDMA(const char* la, int r);
	abcDMA();
	virtual ~abcDMA();
	abcDMA& operator=(const abcDMA& aA);
	friend std::ostream& operator<<(std::ostream& os, const abcDMA& aA);
	virtual void View()const = 0;
};

class baseDMA:public abcDMA
{
public:
	baseDMA(const char* la, int r);
	baseDMA(const baseDMA& rs) :abcDMA(rs) { ; }
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
	virtual void View()const  ;
	virtual ~baseDMA() { ; }
};

class lacksDMA :public abcDMA
{
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char*, const abcDMA& rs);
	virtual void View()const;
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA :public abcDMA
{
private:
	char* style;

public:
	hasDMA(const char* s = "none", const char* l = "null",
		int r = 0);
	hasDMA(const char* s, const abcDMA& rs);
	hasDMA(const hasDMA& hs);
	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
	virtual void View()const;
};


#endif // !ABC_OF_DMA_H_
