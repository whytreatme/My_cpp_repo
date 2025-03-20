#include<iostream>
#include"stack.h"

using namespace std;

const int MAX = 5;
int main()
{
	Item item = 0;
	Stack st(MAX);
	

	for (int i = 0; i < MAX; i++)
	{
		cout << "Enter a unsigned long number : ";
		cin >> item;
		while (cin.get()!='\n')
			continue;
		st.push(item);
		cout << "Item pushed.\n";
	}

	Stack st_new(st);
	for (int i = 0; i < MAX; i++)
	{
		st_new.pop(item);
		cout << "Item poped: " << item << endl;
	}

	cout << "Bye\n";
	return 0;
}
