#include<iostream>
#include<new>
#include"list.h"

List::List(int num)
{
	Item* ps = NULL;
	
	number = num;
	if (num == 0)
		return;
	ps = new Item;
	items = ps;
	for (int i = 0; i < num-1; i++)
	{
		ps->next = new Item;
		ps = ps->next;
	}
	ps->next = NULL;
}

List::~List()
{
	using namespace std;
	Item* ps = NULL;
	if (number == 0)
		return;
	ps = items;
	for (int i = 0; i < number; i++)
	{
		items = items->next;
		delete ps;
		cout << "Destruct an object" << endl;
		ps = items;
	}
}