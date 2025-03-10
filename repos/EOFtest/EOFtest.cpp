// EOFtest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
int main()
{
    int testArr[100];
    int count=0;//计数器
    int i = 0;
    while ((testArr[i++] = getchar()) != EOF)//遇到EOF就不读了，所以-1没办法读出
    {
#define DEBUG 1
#ifdef DEBUG



        if (testArr[i-1] == '\n')//我不让换行符输出，但是换行符确实被读进了数组
            continue;//所以换行后输入文件结尾还是可以结束
        else
#endif // DEBUG
        {
            cout << testArr[i - 1] << " ";
            count++;
        }
    }
    cout << "testArr[i-1]:" << testArr[i - 1] << endl;//读出文件末的-1
    cout << "Total count:" << count;
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
