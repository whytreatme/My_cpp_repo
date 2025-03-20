#include<iostream>
#include"stack.h"

Stack::Stack()
{
	top = 0;
	//tot_val = 0;	
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item& item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item& item)
{
	using std::cout;

	if (top > 0)
	{
		item = items[--top];
		//tot_val += items[top].payment;
		//cout << "The total value is: " << tot_val << "\n";
		return true;
	}
	else
		return false;
}
