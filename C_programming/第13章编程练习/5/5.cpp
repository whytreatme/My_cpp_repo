// 5.cpp---检索关键字符串
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 1000
int main(int argc, char* argv[])
{
    char backup[LEN], line[LEN];
    backup[99] = '\0';//数组存放字符串，先设置字符串结尾标志
    FILE* fp = NULL, * gp = NULL;
    
    if (argc != 3)
    {
        fprintf_s(stderr, "Can't open %s file.", argv[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        if (fopen_s(&fp, argv[2], "r") != 0)
        {
            fprintf_s(stderr, "error!");
            exit(EXIT_FAILURE);
        }
            while (fgets(line, LEN, fp) != NULL)//读一行
            {
                if (fopen_s(&gp, "temp.txt", "w+") != 0)//以读写模式打开一个临时文件
                    exit(EXIT_FAILURE);//且每次迭代把文件长度截为0
                else
                {
                    fprintf_s(gp, "%s", line);//先把一行写入临时文件
                    rewind(gp);//文件指针返回开头
                    while (fscanf_s(gp, "%s", backup, (unsigned)_countof(backup)) == 1)
                    {  //从临时文件中读取字符串，有空格算一个字符                                                                  
                        if ((strcmp(argv[1], backup) == 0))
                        {//比较所取字符是否与待检索字符串相同
                            fputs(line, stdout);//输出行
                            break;
                        }
                    }
                    if (gp != 0)//关闭文件很重要！
                        fclose(gp);
                } 
            }
        if (fp != 0)
            fclose(fp);
        return 0;
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
