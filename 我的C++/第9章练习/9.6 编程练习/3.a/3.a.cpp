// 3.a.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstring>


const int Size = 512;
struct chaff
{
    char dross[20];
    int slag;
};



void show_chaff(const chaff&);
void set_chaff(chaff&);

int main()
{
    using std::cout;
    using std::endl;


    chaff* pd = new chaff[2];
    chaff* ps = new (pd) chaff[2];

    cout << "new address is " << pd << endl;
    cout << "replacement new address is " << ps << endl;
    for (int i = 0; i < 2; i++)
    {
        set_chaff(ps[i]);
        cout << "The assignment address is " << &ps[i] << endl;
    }

    for (int i = 0; i < 2; i++)
        show_chaff(ps[i]);

    delete[] ps;

    cout << "ps address " << ps << endl;
    
    return 0;
}

void show_chaff(const chaff& obj)
{
    using namespace std;
    cout << "Dross: " << obj.dross << endl;
    cout << "Slag: " << obj.slag << endl;
}

void set_chaff(chaff& ps)
{
    using namespace std;
    char dross[20];
    char next;

    cout << "Please input the name of dross:(empty to quit)\n";


    if (cin.get(dross, 20).get(next))
    {
        while (next != '\n')
            cin.get();//Bad input dross

        strcpy_s(ps.dross, 20, dross);

        cout << "Enter a slag: ";
        while (!(cin >> ps.slag).get())
        {//Bad input slag
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input; Enter a value like 12\n";
            cout << "Enter a slag: ";
        }
    }

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
