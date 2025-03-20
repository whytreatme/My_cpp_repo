#include<iostream>
#include"Stonewt.h"

int main()
{
	using std::cout;

	Stonewt incognito = 275;
	cout << "incognito: " << incognito << '\n';
	incognito.stone_mode();
	cout << "incognito in stone: " << incognito << '\n';
	incognito.float_pounds_mode();
	cout << "incognito in floatpounds: " << incognito << '\n';

	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	Stonewt total, diff;

	total = wolfe + taft;
	diff = taft - wolfe;
	diff.float_pounds_mode();
	cout << "total is: " << total << '\n';
	cout << "diff is: " << diff << '\n';

	cout << " 12 times wolfe is: " << (12 * wolfe) << '\n';
	

	return 0;
}