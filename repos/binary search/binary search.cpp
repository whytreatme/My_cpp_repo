/*binary search.cpp---- - 二分法解决简单猜数字问题*/
//李爹第一次先画流程图后写代码

#include <stdio.h>
void get_choice(int guess);
int binary_search(int a);
int main()
{
    int guess = 50;
    printf_s("Pick an integer from 1 to 100 . I will try to guess ");
    printf_s("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");//意思意思，无比操蛋的主函数放引言
    get_choice(guess);//随便传个参数
    printf_s("I knew I could do it!\n");
}
void get_choice(int guess)//错误测试以及最终判断
{
    int ch;
    printf_s("Uh...is your number %d?\n", guess);
    while ((ch=getchar())!=EOF)
    {
        if (ch == 'y')//唯一一条出路，最终一定是该结果   
            break;
        else if (ch == 'n')
        {
            while (getchar() != '\n')//接下来的binary_search函数有getchar()
                continue;           //把无用的包括换行全部舍弃
              guess=binary_search(guess);//调用函数二分法判断，返回猜测值
              printf_s("Uh...is your number %d?\n", guess);//再度猜测
        }
        else
        {
            printf_s("Sorry, I understand only y or n.\n");//出错提示
            while (getchar() != '\n')//友好用户界面，舍弃无用字符及换行
                continue;
        }
    }
}
int binary_search(int guess)//二分法及出错提示
{
   static int great=100;//设置每次最大上限，使用静态，要反复使用上次结果
    static int less=0;
    char cx;
    printf_s("If it's greater , input a g\nIf it's less , input a l: ");
    while ((cx = getchar()) != EOF)
    {
        if (cx == 'g')
        {
            while (getchar() != '\n')
                continue;
            great = guess;//以本次猜测值为最大上界并保存
            guess = (guess + less) / 2;//与最小值相加二分
            return guess;
        }
        else if (cx == 'l')
        {
            while (getchar() != '\n')
                continue;
            less = guess;
            guess = (great + guess) / 2;
            return guess;
        }
        else
        {
            printf_s("Sorry, I understand only g or l.\n");
            while (getchar() != '\n')//出错提示，友好界面
                continue;
        }
        printf_s("If it's greater , input a g\nIf it's less , input a l: ");
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
