#include "mybook.h"

void delete_record(FILE* pbooks, book library[],int& filecount)
{//��������������ṹ����ǰ�Ͽ��ļ���

    
    int i = 0;
    long mark = 0L;
    char line[40] = { '\0' };
    book as = { };
    int size = sizeof(book);

    printf_s("Choose which book you'd like to delete:\n");
    s_gets(line, 40);
    rewind(pbooks);//�ص��ļ���ͷ

    while (fread(&library[i], size, 1, pbooks) == 1)
    {//�ٴδ��ļ�����ṹ
        if (i == 0)
            mark = ftell(pbooks);

        fflush(pbooks);

        if (strcmp(line, library[i].title) == 0
            || strcmp(line, library[i].author) == 0)
        {//�ж��Ƿ��Ǳ�ɾ����
            as.delete_flag = 1;
            fseek(pbooks, -mark, SEEK_CUR);
            fwrite(&as, size, 1, pbooks);
            fflush(pbooks);
            break;//���ظ���֮ǰ���ļ�д��
        }

        i++;
    }
    
}