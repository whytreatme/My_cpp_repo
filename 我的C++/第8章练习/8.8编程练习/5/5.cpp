// 5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

template<class T>
T max5(T[],int size);

int main()
{
    using namespace std;

    int ar[5] = { 1,2,3,4,5 };
    double st[5] = { 17.09,76.19,100.45,1.03,15.88 };

    int max_int = 0;
    max_int = max5(ar,5);
    cout << "The maximun value is " << max_int << endl;

    double max_dou = 0;
    max_dou = max5(st,5);
    cout << "The maximun dou is " << max_dou << endl;

    return 0;
}

template<class T>
T max5(T arr[],int size)
{
    T max = arr[0];

    for (int i = 1 ; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
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
