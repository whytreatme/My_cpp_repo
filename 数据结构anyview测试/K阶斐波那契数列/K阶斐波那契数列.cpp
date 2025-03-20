// K阶斐波那契数列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdlib.h>
#include<stdio.h>
int summary(int arr[], int n)
{
    int sum = 0;
    int i = 0;
    for (; i < n; i++)
        sum += arr[i];
    return sum;
}

bool Fibonacci(int k, int m, int& f) {
    // Add your code here
    if (k < 2)return false;
    if (m < 0)return false;
    if (m < k - 1) {
        f = 0;
        return true;
    }

    int i, j;
    
    int* arr = (int*)malloc(sizeof(int) * k);
    for (i = 0; i < k - 1; i++)
    {
        arr[i] = 0;
    }
    arr[k - 1] = 1;
    for (i = k , f = 1; i < m;)
    {
        for (j = 1; j < k; j++)
        {
            arr[j - 1] = arr[j];
        }
        arr[k - 1] = f;
        f = summary(arr, k);
        i++;
    }
    return true;
}


int main()
{
    int c;
    Fibonacci(4, 8, c);
    printf_s("%d\n", c);
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
