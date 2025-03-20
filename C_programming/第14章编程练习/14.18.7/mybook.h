#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef MYBOOK_H
#define MYBOOK_H

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

 struct mybook
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int delete_flag;
};
 typedef mybook book;

void input(book library[], FILE* pbooks,int& filecount,int real);
void delete_record(FILE* pbooks, book[],int& filecount);
void change_record(book library[], int count, FILE* pbooks);
void print(book library[], int& filecount, FILE* pbooks,int real);
char get_char();
char* s_gets(char* st, int n);






#endif // !MYBOOK_H
