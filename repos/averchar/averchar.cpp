// averchar.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<ctype.h>
int main()
{
    double averchar = 0;
    int ch;
    double count_char=0;
    double count_word = 0;
    int word = 0;//设置用以作为新单词的标志，初始化等于虚拟空格统一情况
    while ((ch = getchar()) != EOF)
    {
        if (ch == ' '||ispunct(ch)!=0)word = 0;//如为空格标志为0,末尾标志句号，问号也可以作为单词结尾的标志
        else if (isalpha(ch))//判断是否是字母
        {
            if (word == 0)//是字母且前一个为空格
            {
                word = 1;//标志单词
                count_word++;//单词数目加1
            }
            count_char++;//总的字母数加1
        }
    }//以前一个字符为空白，后一个字符为字母，判断新单词，设置word标志记录上一个
    //字符的情况，初始化为0，冷启动虚拟空格，统一首字符为空与不为空的情况
    averchar = count_char / count_word;
    printf_s("The whole characters are: %.3lf.\nThe whole words are: %.3lf.\n"
        "The average chars of each word is: %.6lf.", count_char, count_word, averchar);
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
