// 6.a.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstring>


template<typename T>
T Maxn(T[], int size);


template<> std::string Maxn<std::string>(std::string p[], int size)
{  //具体化一样是模板的实例化不要随便加const限定符，要保持一致
    //连返回类型都要一样
    std::string max = p[0];
    for (int i = 0; i < size; i++)
    {
        if (max.size() < p[0].size())
            max = p[i];
    }

    return max;
}

/*template <typename T>
T Maxn( T arr[])
{
    int len = sizeof(arr) / sizeof(arr[0]);
    T m = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (m < arr[i])
        {
            m = arr[i];
        }
    }
    return m;
}

template <> char* Maxn <char*>(char* arr[])
{
    return arr[0];
}*/

int main()
{
    using namespace std;
    int ar[6] = { 1,2,3,4,5,6 };
    double se[4] = { 1.2,4.87,7.56,0.22 };

    int max_in = 0;

    max_in = Maxn(ar,6);
    cout << "Max int is " << max_in << endl;

    double max_do = 0;
    max_do = Maxn(se,4);
    cout << "Max dou is " << max_do << endl;

    string ps[5] =
     {
         "一生难忘柯春蕊做我老婆",
         "我要长到一米八七",
         "我要到麻省理工求学",
         "我要到硅谷工作",
         "我要成为篮球高手"
     };//可以把字符串常量赋给string类对象,可以设计返回字符串的函数
     cout << "my dream is " << Maxn(ps, 5) << endl;


    return 0;
}

template<typename T>
T Maxn(T arr[], int size)//不可以声明和定义不一致，不要乱加const
{
    T max = arr[0];

    for (int i = 1; i < size; i++)
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
