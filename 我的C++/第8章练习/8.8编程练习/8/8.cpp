// 8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

template<class T>
T Sum_Array(T arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

template<> debts Sum_Array<debts>(debts arr[], int n);

int main()
{
	using namespace std;

	int things[6] = { 13,31,103,301,130,310 };
	debts mr_E[3] =
	{
		{"Ima Wolfe",2400.0},
		{"Ura Foxe",1300.0},
		{"Iby Stout",1800.0}
	};

	cout << "The total of things is: " << Sum_Array(things, 6) << endl;
	cout << "The total of debts is: " << Sum_Array(mr_E, 3).amount << endl;

	return 0;
}

template<class T>
T Sum_Array(T arr[], int sizes)
{

	for (int i = 1; i < sizes; i++)
	{
		arr[0] += arr[i];
	}

	return arr[0];
}

template<> debts Sum_Array<debts>(debts arr[], int sizes)
{
	debts total = arr[0];
	for (int i = 1; i < sizes; i++)
	{
		total.amount += arr[i].amount;
	}

	return total;
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
