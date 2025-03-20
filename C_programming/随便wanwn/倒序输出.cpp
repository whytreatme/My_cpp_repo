#include<iostream>

using namespace std;

int main()
{
	cout << "Please enter a positve integer: " << '\n';
	unsigned long num = 0;
	while (!(cin >> num) || ((num < 1) || (num > 100000000)))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Input a positive integer like 103,12,1144:" << '\n';
	}
	
	int count = 0;
	for (unsigned long copy = num; copy != 0; count++)
		copy /= 10;

	int* converse = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++)
	{
		converse[i] = num % 10;
		num /= 10;
	}
	int sum=0;
	for (int i = 0; i < count; i++)
	{
		sum = sum * 10 + converse[i];
	}

	cout << "The conversion of num is:" << sum << endl;
	free(converse);
}