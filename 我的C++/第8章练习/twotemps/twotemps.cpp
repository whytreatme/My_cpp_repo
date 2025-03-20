// twotemps.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

template<typename T>
void Swap(T& a, T& b);

template<typename T>
void Swap(T* a, T* b, int n);
void Show(int a[]);

const int Lim = 8;

int main()
{
    using namespace std;
    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    int d1[Lim] = { 0,7,0,4,1,7,7,6 };
    int d2[Lim] = { 0,7,2,0,1,9,6,9 };
    cout << "Original arrays:\n";

    Show(d1);
    Show(d2);
    Swap(d1, d2, Lim);

    cout << "Swapped arrays:\n";
    Show(d1);
    Show(d2);

    return 0;
}

template<typename T>
void Swap(T a[], T b[], int n)
{
    T temp;

    for (int i = 0; i < n; i++)
    {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

template<typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void Show(int a[])
{
    using namespace std;

    cout << a[0] << a[1] << "/";
    cout << a[2] << a[3] << "/";
    for (int i = 4; i < Lim; i++)
        cout << a[i];

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
