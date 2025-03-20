#include<iostream>
#include"move.h"

int main()
{
	Move ps(12.15, 78.43);
	ps.showmove();

	Move pd;
	pd.reset(10.92, 12.57);
	pd.showmove();

	Move ph = pd.add(ps);
	ph.showmove();

	return 0;
}