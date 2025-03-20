// ruler.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);

int main()
{
	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++)
		ruler[i] = ' ';
	ruler[Len - 1] = '\0';

	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	std::cout << ruler << std::endl;

	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		std::cout << ruler << std::endl;
		
		for (int j = 1; j < Divs-2; j++)
			ruler[j] = ' ';
	}
	return 0;
}

void subdivide(char ar[], int low, int hign, int level)
{
	if (level == 0)
		return;
	int mid = (hign + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, hign, level - 1);
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
