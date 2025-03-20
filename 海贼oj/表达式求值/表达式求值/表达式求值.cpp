// 表达式求值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#define MAX_INT 1000
char formula[MAX_INT + 5];
using namespace std;

double calcu(string formu) {
	int weight[MAX_INT + 5] = { 0 };
	int i = 0, j, flag = 0;

	for (; formu[i]; i++)
	{
		switch (formu[i]) {
		case '+':
		case '-':
			weight[i] += 1;
			flag += 1;
			break;
		case '*':
		case'/':
			weight[i] += 2;
			flag += 1;
			break;
		case '(':
			weight[i] = 100;
			j = i;
			while (formu[j] != ')')weight[j++] = 100;
			break;
		case ')':
			weight[i] = 0;
			break;
		}
	}
	int temp_ans=100, ans=0;
	for (int i = 0; formu[i]; i++) {
		if (weight[i]>0&&temp_ans>weight[i]&&flag>1) {
			ans = i;
			temp_ans = weight[i];
		}
		else if (flag == 1&&temp_ans<weight[i]) 
			ans = i;
	}//选出优先级最低的符号
	if (flag ==0) {
		double sum = 0;
		for (int i = 0; formu[i]; i++) {
			if(48<=formu[i]&&formu[i]<=57)
			sum += sum * 10 + (formu[i]-48);
		}
		return sum;
	}

	if (formu[ans] == '+') {
		formu[ans] = '\0';
		return calcu(&(formu[0])) + calcu(&(formu[ans + 1]));
	}
	if (formu[ans] == '-') {
		formu[ans] = '\0';
		return calcu(&(formu[0])) - calcu(&(formu[ans + 1]));
	}
	if (formu[ans] == '*') {
		formu[ans] = '\0';
		return calcu(&(formu[0])) * calcu(&(formu[ans + 1]));
	}
	if (formu[ans] == '/') {
		formu[ans] = '\0';
		return calcu(&(formu[0])) / calcu(&(formu[ans + 1]));
	}
}

int main()
{
	cin >> formula;

	printf_s("%.0lf", calcu(formula));
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
