#include<iostream>
#include<cctype>
#include"stack.h"

int main()
{
	using namespace std;

	Stack st;
	char ch;
	customer po;
	double sum_payment = 0;

	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a po, or Q to quit.\n";

	while (cin >> ch && toupper(ch) != 'Q')
	{//cin会自动跳过空白、换行符，但是要注意cin>>value和cin.get()
		//混合输入时存在吸收字符问题
		while (cin.get() != '\n')
			continue;

		if (!isalpha(ch))
		{
			cout << '\a';
			continue; //在if里使用continue继续while循环
		}

		switch (ch)
		{
		case'A':
		case'a':cout << "Enter customer's name: ";
			cin.get(po.fullname, 35);
			if (cin)
			{
				while (cin.get() != '\n')
					continue;
				cout << "Enter the value of payment: ";
				while (!(cin >> po.payment))
				{
					cin.clear();
					while (cin.get() != '\n')
						continue;
					cout << "Bad input; Please input a value:\n";
					continue;
				}
			}
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case'p':
		case'P':if (st.isempty())
			cout << "stack already empty\n";
			   else
		{
			st.pop(po);
		}
			   break;

		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";

	return 0;
}