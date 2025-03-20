#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	bool jud;
	string str;
	cout << "input your words" << endl;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			jud = false;
		}
		else
		{
			jud = true;
			break;
		}
	}
		if (jud == false)
			cout << "false<";
		else cout << "true<";
	
}