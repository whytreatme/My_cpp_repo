// 14.18.7答案.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define SPACE 40
#define MAXBKS 20
char* s_gets(char* st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int delete_flag;
};
/*添加删除标记成员*/
int main(int argc,char *argv[])
{
    struct book library[SPACE];
    int count = 0,real=0;
    int index, filecount;
    FILE* pbooks;
    int size = sizeof(struct book);
    char delete_a;
    if (fopen_s(&pbooks, "booka.dat", "r+b") != 0)
    {
        fputs("Can't open booka.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while( fread(&library[count], size, 1, pbooks) == 1)
        /*添加标志位，并不影响数据的读取功能，fread()函数按照结构体book的存储空间
        大小依次读取相同的字节。*/
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        if (library[count].delete_flag != 1)
        {
            printf_s("%s by %s: $%.2f\n", library[count].title, library[count].author,
                library[count].value);
            count++;
        }
        real++;
    }
    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The booka.dat is full.", stderr);
        exit(2);
    }
    printf_s("Do you want to modefy library?(y/n)");
       scanf_s("%c", &delete_a, 1);
    if (delete_a == 'y') {
        for (int i = 0; i < real; i++) {
            if (library[i].delete_flag == 2)
            {
                printf_s("%s by %s: $%.2f\n", library[i].title, library[i].author
                    , library[i].value);
                while (getchar() != '\n')continue;
                puts("Do you want to delete this book?(y/n).");
                scanf_s("%c", &delete_a, 1);
                if (delete_a == 'y')library[i].delete_flag = 1;
            }
        }
    }
    /*为了修改原数组，可以设置其标记位，表明它被删除。在要添加记录信息时，
    可通过改标记覆盖旧数据*/
    while (getchar() != '\n')continue;
    puts("Please add new book titles.");
    puts("Press[enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[real].title, MAXTITL) != NULL &&
        library[real].title[0] != '\0' && library[real].delete_flag != 1)
    {
        puts("Now enter the author.");
        s_gets(library[real].author, MAXAUTL);
        puts("Now enter the value.");
        scanf_s("%f", &library[real].value);
        library[real++].delete_flag = 0;
        count++;
        while (getchar() != '\n')
            continue;/*清理输入行*/
        if (count < MAXBKS)
            puts("Enter the next title.");
    }
    /*记录新信息可以覆盖删除信息*/
    rewind(pbooks);
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < real; index++)
            if (library[index].delete_flag != 1) {
                printf_s("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);
                library[index].delete_flag = 2;
                fwrite(&library[index], size,1, pbooks);
            }
       
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    return 0;
}
char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(st, n,stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
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
