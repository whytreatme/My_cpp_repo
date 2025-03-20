// reverse.cpp --倒序显示文件内容
//

#include <stdio.h>
#include<stdlib.h>
#define CNTL_Z '\032'
#define SLEN 81
int main()
{
    char file[SLEN];
    char ch;
    FILE* fp;
    long count, last;
    file[SLEN - 1] = '\0';
    puts("Enter the name of the file to be processed:");
    scanf_s("%80s", file, (unsigned)_countof(file));
    
    if (fopen_s(&fp, file, "rb")!=0)
    {
        printf_s("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);
        ch = getc(fp);
        if (ch != '\r')/*MS-DOS文件,二进制在行末尾用\r\n来回车+换行*/
            putchar(ch);/*而打印出是\n就可以表示回车+换行*/
    }                   /*多出来的\r舍弃，否侧丢失一部分 */
    putchar('\n');
    if (fclose(fp) != 0)
        fprintf_s(stderr, "Error closing file.\n");
    return 0;
}

// 运行程序: Ctrl + F5 或调试 > “开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
