// 括号画家.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;


int main()
{
	int j = 0,k=0;
	int flag = 0;
	string str;
	cin >> str;
	stack<char> s1,s2;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
			s1.push(str[i]);
			k += 1;
			if (!s1.empty() && k > 0)s2.push(str[i]);
		}
		else if (str[i] == '{') {
			s1.push(str[i]);
			k += 1;
			if (!s1.empty() && k > 0)s2.push(str[i]);
		}
		else if (str[i] == '[') {
			s1.push(str[i]);
			k += 1;
			if (!s1.empty() && k > 0)s2.push(str[i]);
		}
		else if (str[i] == ')' && s1.top() == '(') {
			s1.pop();
			k = 0;
			j++;
		}
		else if (str[i] == ']' && s1.top() == '[') {
			s1.pop();
			k = 0;
			j++;
		}
		else if (str[i] == '}' && s1.top() == '{') {
			s1.pop();
			k = 0;
			j++;
		}
		else {
			j = 0;
			while (!s1.empty())s1.pop();
		}
	}
	if (s1.empty())j += k;
	cout << "The integer is" << 2 * j << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
