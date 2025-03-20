// 2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

const int Max = 10;

void show_score(const float ar[], int size);
int input_score(float ar[], int num);
float aver_score(const float ar[], int size);

int main()
{
	float score[Max];
	int size = 0;

	size = input_score(score, Max);
	show_score(score, size);
	std::cout << "The average of all the scores is: "
		<< aver_score(score, size) <<std:: endl;

	return 0;
}


int input_score(float ar[], int num)
{
	using namespace std;

	int i;
	float temp;

	cout << "Please fill the array with scores:\n";
	for (i = 0; i < num; i++)
	{
		cout << i + 1 << " : ";
		while (!(cin >> temp))
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a value : like 1.23\n";
		}
		if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}

void show_score(const float ar[], int size)
{
	using namespace std;

	cout << "All the scores are:\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " : " << ar[i]<<endl;
	}
	printf_s("\n");
}

float aver_score(const float ar[], int size)
{
	float total = 0;

	for (int i = 0; i < size; i++)
		total += ar[i];

	return total / (float)size;
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
