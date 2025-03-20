// 6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

int Fill_array(double ar[], int num);
void Reverse_array(double ar[], int size);
void Show_array(const double ar[], int size);

const int Max = 10;

int main()
{
	double arr[Max] ;
	int size = 0;

	size = Fill_array(arr, Max);
	Show_array(arr, size);
	Reverse_array(arr, size);
	Show_array(arr, size);

	return 0;
}

int Fill_array(double ar[], int num)
{
	using namespace std;
	
	int i;
	double temp = 0;

	for (i = 0; i < num; i++)
	{
		cout << "input a value: (enter a non-value to quit):\n";
			if (!(cin >> temp))
				break;
			ar[i] = temp;
	}
	return i;
}

void Reverse_array(double ar[], int size)
{
	double temp = 0;

	for (int i = 1; i <= (size - 1)/2 ; i++)
	{
		temp = ar[i];
		ar[i] = ar[size - 1 - i];
		ar[size - 1 - i] = temp;
	}
}

void Show_array(const double ar[], int size)
{
	using namespace std;

	cout << "Now the array is :\n" ;
	for (int i = 0; i < size; i++)
		cout << ar[i] << " ";
	cout << endl;
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
