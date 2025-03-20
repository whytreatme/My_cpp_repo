// 8.a.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include<iostream>

template <typename T> //template A
void ShowArray(T arr[], int n);

template<typename T>  //template B
void ShowArray(T* arr[], int n);

template<typename T>
T Sum_Array(T arr[], int n);

template<typename T>
T Sum_Array(T* arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = { 13,31,103,301,310,130 };

    debts mr_E[3] =
    {
        {"Ima Wolfe",2400.0},
        {"Ura Foxe",1300.0},
        {"Iby Stout",1800.0}
    };
    double* pd[3];

    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    cout << "Listing Mr.E's counts of things:\n";
    ShowArray(things, 6);
    cout << "The sum of things: "<< Sum_Array(things, 6) << endl;
    cout << "Listing Mr.E's debts:\n";
    ShowArray(pd, 3);
    cout << "The sum of pd: " << Sum_Array(pd, 3) << endl;
    return 0;
}

template<typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;

    cout << "template A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template<typename T>
void ShowArray(T* arr[], int n)
{
    using namespace std;

    cout << "template B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}

template<typename T>
T Sum_Array(T arr[], int n)
{
    T sum = arr[0] - arr[0];

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    return sum;
}

template<typename T>
T Sum_Array(T* arr[], int n)
{
    T sum = *arr[0] - *arr[0];

    for (int i = 0; i < n; i++)
        sum += *arr[i];

    return sum;
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
