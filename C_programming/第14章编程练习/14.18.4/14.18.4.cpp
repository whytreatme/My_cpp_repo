// 14.18.4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#define N 20
struct name {
    char given_name[N];
    char middle_name[N];
    char family_name[N];
};
typedef struct ensurance{
    double number;
    struct {
        char given_name[N];
        char middle_name[N];
        char family_name[N];
    };
}ENS;

void print(ENS ps[]);
int main()
{
    ENS per[5] = {
        {302039823,"Dribble","Martun","Flossie"},
        {201706238,"Kenneth","Harbour","Rosen"},
        {201806735,"Stephen","Lmyon","Prata"},
        {305738295,"Catherine","Soyld","Jackson"},
        {242838488,"Elizabath","Winsor","Mayer"}
    };
    print(per);
    return 0;
}
void print(ENS ps[])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf_s("%s, %s %c.--%.lf\n", ps[i].given_name, ps[i].family_name
            , ps[i].middle_name[0], ps[i].number);
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
