#include "mybook.h"

void delete_record(FILE* pbooks, book library[],int& filecount)
{//传入主函数定义结构，当前认可文件数

    
    int i = 0;
    long mark = 0L;
    char line[40] = { '\0' };
    book as = { };
    int size = sizeof(book);

    printf_s("Choose which book you'd like to delete:\n");
    s_gets(line, 40);
    rewind(pbooks);//回到文件开头

    while (fread(&library[i], size, 1, pbooks) == 1)
    {//再次从文件读入结构
        if (i == 0)
            mark = ftell(pbooks);

        fflush(pbooks);

        if (strcmp(line, library[i].title) == 0
            || strcmp(line, library[i].author) == 0)
        {//判断是否是被删除项
            as.delete_flag = 1;
            fseek(pbooks, -mark, SEEK_CUR);
            fwrite(&as, size, 1, pbooks);
            fflush(pbooks);
            break;//返回该项之前把文件写入
        }

        i++;
    }
    
}