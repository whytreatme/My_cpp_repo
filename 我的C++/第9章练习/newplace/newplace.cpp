// newplace.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
    using namespace std;

    double* pd1, * pd2;
    int i;
    cout << "Calling new and placement new:\n";
    pd1 = new double[N];
    pd2 = new(buffer)double[N];

    for (int i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;

    cout << "Memory address:\n" << " heap: " << pd1
        << " static: " << (void*)buffer << endl;
    cout << "Memory contents:\n";

    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }
    cout << "\nCalling new and placement new a second time:\n";
    double* pd3, * pd4;
    pd3 = new double[N];
    pd4 = new(buffer)double[N];
    for (i = 0; i < N; i++)
        pd4[i] = pd3[i] = 1000 + 40 * i;

    for (i = 0; i < N; i++)
    {
        cout << pd3[i] << " at " << &pd3[i] << "; ";
        cout << pd4[i] << " at " << &pd4[i] << endl;
    }
    cout << "\nCalling new and placement new a third time:\n";
    delete[] pd1;
    pd1 = new double[N];
    pd2 = new(buffer + N * sizeof(double))double[N];

    for (i = 0; i < N; i++)
        pd2[i] = pd1[i] = 1000 + 60 * i;
    cout << "Memory contents:\n";

    for (i = 0; i < N; i++)
    {
        cout << pd1[i] << " at " << &pd1[i] << "; ";
        cout << pd2[i] << " at " << &pd2[i] << endl;
    }

    delete[] pd1;
    delete[] pd3;

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
