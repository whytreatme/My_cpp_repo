// 10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

double calculate(double a, double b, double (*pf)(double, double));
double add(double x, double y);
double multiple(double x, double y);
double minus_a(double x, double y);

const char* function = { "add,multiple,minus_a" };


int main()
{
    using namespace std;

    double (*pf[3])(double, double) = { add,multiple,minus_a };
    double q;
    double num1 = 0, num2 = 0;

    for (int i = 0; i < 3; i++)
    {
        cout << "Please input two values: (enter non-value to quit )\n";
        if (!(cin >> num1 >> num2))
            break;
        cout << "The result of " << num1 << " and "
            << num2 << " with the operation of "
            << function[i] << " is ";
        q = calculate(num1, num2, pf[i]);
        cout << q << endl;
    }

    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double multiple(double x, double y)
{
    return x * y;
}

double minus_a(double x, double y)
{
    return x - y;
}

double calculate(double a, double b, double (*pf)(double, double))
{
    return (*pf)(a, b);
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
