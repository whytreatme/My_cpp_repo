// 6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstring>


template<typename T> 
 T Maxn(T[], int size);


/*template<> string Maxn<string>(string p[], int size)
{
    string max = p[0];
    for (int i = 0; i < size; i++)
    {
        if (max.size() < p[0].size())
            max = p[i];
    }

    return max;
}*/

int main()
{
    using namespace std;
    int ar[6] = { 1,2,3,4,5,6 };
    double se[4] = { 1.2,4.87,7.56,0.22 };
    
    int max_in = 0;

    max_in = Maxn(ar, 6);
    cout << "Max int is " << max_in << endl;

    double max_do = 0;
    max_do = Maxn(se, 4);
    cout << "Max dou is " << max_do << endl;

   /* string ps[5] =
    {
        "一生难忘柯春蕊做我老婆"
        "我要长到一米八七"
        "我要到麻省理工求学"
        "我要到硅谷工作"
        "我要成为篮球高手"
    };
    cout << "my dream is " << Maxn(ps, 5) << endl;*/
   

   return 0;
}

template<typename T>
T Maxn(const T arr[],int size)
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
