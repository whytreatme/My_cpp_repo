// strtype1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>

int main()
{
    using namespace std;

    char charr1[20];
    char charr2[20] = "jaquar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline:";
    cin >> charr1;//说明cin把换行符舍弃了，并不留在输入队列里
    cout << "Enter another kind of feline:";
    cin >> str1;
    cout << "Here are felines:\n";
    cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;
    cout << "The third letter in " << charr2 << " is " << charr2[2] << endl;
    cout << "The third letter in " << str2 << " is " << str2[2] << endl;
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
