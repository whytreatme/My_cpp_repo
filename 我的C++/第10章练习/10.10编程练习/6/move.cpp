#include<iostream>
#include"move.h"

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	using namespace std;

	cout << "x is: " << x << " y is: " << y << endl;
}

Move Move::add(const Move& m) const
{
	Move new_obj;
	new_obj.x = m.x + this->x;
	new_obj.y = m.y + this->y;

	return new_obj;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
