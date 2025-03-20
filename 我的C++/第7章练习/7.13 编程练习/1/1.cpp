// 1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

double average(double x, double y);

int main()
{
	using namespace std;

	double a1, a2;
	double aver = 0;

	do
	{
		cout << "Please input two values:(enter 0 to quit)\n";
		while (!(cin >> a1 >> a2))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter two values like :2.33 1.55\n";
		}
		if ((a1 != 0) && (a2 != 0))
		{
			aver = average(a1, a2);
			cout << "The average is" << aver << endl;
		}
	} while ((a1 != 0) && (a2 != 0));

	return 0;
}

double average(double x, double y)
{
	return 2.0 * x * y / (x + y);
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
