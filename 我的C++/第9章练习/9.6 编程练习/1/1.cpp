// 1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"golf.h"

int main()
{
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);

    golf men[3] = { };
    for (int i = 0; i < 3; i++)
    {
        int j = 12;
        j = setgolf(men[i]);
        if (j == 0)
            break;
    }
    
    for (int i = 0; i < 3; i++)
        showgolf(men[i]);

    for (int i = 0; i < 3; i++)
        handicap(men[i], (i + 1) * 6);

    for (int i = 0; i < 3; i++)
        showgolf(men[i]);

    return 0;
}


