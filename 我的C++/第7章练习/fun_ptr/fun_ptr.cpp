// fun_ptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

double betsy(int);
double pam(int);
void estimate(int lines, double (*pf)(int));

int main()
{
	using namespace std;

	int code;
	cout << "How many lines of code  do you need? ";
	while (!(cin >> code))
	{
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Bad input; Please input a value:\n";
	}
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);
	cout << "Here's pam's estimate:\n";
	estimate(code, pam);

	return 0;
}

double betsy(int lns)
{
	return 0.05 * lns;
 }

double pam(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	using namespace std;

	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";
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
