#ifndef OVERTIMEBOOK_H
#define OVERTIMEBOOK_H

#include <stdlib.h>
#include <string.h>

//超期图书结构体
typedef struct OVERTIMEBOOK {
	char className[64];
	char name[64];
	char id[32];
	char bookName[64];
	int overday;

	OVERTIMEBOOK* next;
}OvertimeBook;

//超期图书结构体指针别名
typedef OvertimeBook* pOvertimeBook;

//超期图书结构体大小
const size_t sizeob = sizeof(OvertimeBook);

//返回新建的超期图书结构体
pOvertimeBook newOvertimeBook();

//设置超期图书结构体的成员
void obsetClassName(pOvertimeBook po, char* str);
void obsetName(pOvertimeBook po, char* str);
void obsetId(pOvertimeBook po, char* str);
void obsetBookName(pOvertimeBook po, char* str);
void obsetOverday(pOvertimeBook po, int overday);
void obsetNext(pOvertimeBook po, pOvertimeBook next);

#endif 
