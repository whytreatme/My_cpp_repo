// arrfun3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

const int Max = 5;

int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;

    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;

        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input;Please enter a number: ";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }
    cout << "Done.\n";

    return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;

    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Enter value # " << (i + 1) << ": ";
        if (!(cin >> temp))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Please enter a number:";
        }
        else if (temp < 0)
            break;
        ar[i] = temp;
    }
    return i;
}

void show_array(const double ar[], int n)
{
    using namespace std;
    int i=0;
    for (; i < n; i++)
    {
        cout << "Property # " << (i + 1) << ":$ ";
        cout << ar[i] << endl;
    }
 }

void revalue(double r, double ar[], int n)
{
    int i = 0;
    for (; i < n; i++)
        ar[i] *= r;
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
