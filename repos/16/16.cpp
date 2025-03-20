
#include <stdio.h>
#include<stdlib.h>
int main()
{
	void* change(char* num);
	int digit(char* num, int n);
	char str[50];
	printf_s("input a string:\n");
	gets_s(str);
	change(str);
}
int digit(char* num, int n)//将字符转为数字的函数，递归函数
{
	int sum;

	if (n == 1) sum = (int)num[0];
	else sum = digit(num, n - 1) * 10 + (int)num[n - 1];
	return sum;
}
void* change(char* num)
{
	char* kx = NULL, ch[40] = { '\0' };//设立一个中间存在的字符数组用于存放一小段包含数字的字符串
	int i, j, k = 0, h, d = 0, arr[80] = {}, * poi = NULL;//k是计数有多少数字的计数器

	poi = arr;//使用指针引用数组，把摘下来的数字储存在poi中
	for (i = 0; num[i - 1] != '\0'; i++)//为防止字符串以数字结尾读少一位，以前一位不为'\0'做条件循环
	{
		if ('0' <= num[i] && num[i] <= '9')
		{
			ch[d] = num[i] - 48;//把数字的ASCII码转成可强转
			d++;//用d来统计数字字符的数目
		}
		else
		{
			h = d;
			d = 0;
		}
		if ((d == 0) && (i != 0) && ('0' <= num[i - 1] && num[i - 1] <= '9'))//判断条件是否读入一个数字的条件是d重置为0，且不是第一个字符，并且该字符前一个数字一定是数字
		{
			kx = (char*)malloc(h * sizeof(char));//申请一个刚刚好的字符数组
			for (j = 0; j < h; j++)
				kx[j] = ch[j];//写入


			*poi = digit(kx, h);//把数组与大小传入digit函数，并赋给Poi所指向的单元
			poi++;//poi下移
			k++;//统计加一
			free(kx);//释放所申请的空间
			h = 0;//重置h
		}
	}
	printf_s("There are %d numbers in this line,they are:\n", k);
	poi = arr;

#ifdef DEBUG
	printf_s("%d\n", *poi);
#endif // DEBUG

	for (int m = 0; m < k; m++)
		printf_s("%d ", *poi++);//
	return 0;
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
