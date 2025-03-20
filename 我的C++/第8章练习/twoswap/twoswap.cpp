// twoswap.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

template<typename T>
void Swap(T& a, T& b);

struct job
{
    char name[40];
    double salary;
    int floor;
};

template<>void Swap<job>(job& ji, job& j2);
void Show(const job& j);

int main()
{
    using namespace std;
    cout.precision(2);
    cout.setf(ios::fixed, ios::floatfield);

    int i = 10, j = 20;
    cout << "i, j = " << i << ", " << j << ".\n";
    cout << "Using compiler-generated int swapper:\n";
    Swap(i, j);
    cout << "Now i, j = " << i << ", " << j << ".\n";

    job sue = { "Susan Yaffee",73000.60,7 };
    job sidney = { "Sidney Taffee",78060.72,9 };
    cout << "Before job swapping:\n";
    Show(sue);
    Show(sidney);
    Swap(sue, sidney);

    cout << "After job swapping:\n";
    Show(sue);
    Show(sidney);

    return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<>void Swap<job>(job& j1, job& j2)
{
    double t1;
    int t2;
    t1 = j1.salary;
    j1.salary = j2.salary;
    j2.salary = t1;
    t2 = j1.floor;
    j1.floor = j2.floor;
    j2.floor = t2;
}

void Show(const job& j)
{
    
    std::cout << j.name << ": $" << j.salary
        << " on floor " << j.floor << std::endl;
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
