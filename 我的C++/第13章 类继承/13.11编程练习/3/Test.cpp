#include<iostream>
#include<string>
#include"ABC of  DMA.h"

const int CLIENTS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	abcDMA* p_clients[CLIENTS];
	char label[50];
	int rating;
	char kind;

	
	for (int i = 0; i < CLIENTS; i++)
	{
		label[49] = '\0';
		cout << "Enter the label : ";
		cin.get(label, 49);
		while (cin.get() != '\n')
		    continue;
		cout << "Enter the rating : ";
		cin >> rating;

		cout << "Enter 1 for  baseDMA  , "
			<< "2 for lacksDMA or "
			<< "3 for hasDMA :";
		while (cin >> kind && (kind != '1' && kind != '2'&&kind!='3'))
			cout << "Enter either 1 , 2 or 3: ";
		while (cin.get() != '\n')
			continue;
		if (kind == '1')
			p_clients[i] = new baseDMA(label,rating);
		else if(kind=='2')
		{
			char color[40];
			color[39] = '\0';
			cout << "Input the color: ";
			cin.get(color, 39);
			while (cin.get() != '\n')
				continue;
			p_clients[i] = new lacksDMA(color, label,rating);
		}
		
		else
		{
			char style[100];
			style[99] = '\0';
			cout << "Input the style: ";
			cin.get(style, 39);
			while (cin.get() != '\n')
				continue;
			p_clients[i] = new hasDMA(style, label, rating);
		}
		
	}
	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->View();
		cout << endl;
	}

	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];
	}
	cout << "Done.\n";
	return 0;
}