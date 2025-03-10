#ifndef OVERTIMEBOOK_H
#define OVERTIMEBOOK_H

#include <stdlib.h>
#include <string.h>

//����ͼ��ṹ��
typedef struct OVERTIMEBOOK {
	char className[64];
	char name[64];
	char id[32];
	char bookName[64];
	int overday;

	OVERTIMEBOOK* next;
}OvertimeBook;

//����ͼ��ṹ��ָ�����
typedef OvertimeBook* pOvertimeBook;

//����ͼ��ṹ���С
const size_t sizeob = sizeof(OvertimeBook);

//�����½��ĳ���ͼ��ṹ��
pOvertimeBook newOvertimeBook();

//���ó���ͼ��ṹ��ĳ�Ա
void obsetClassName(pOvertimeBook po, char* str);
void obsetName(pOvertimeBook po, char* str);
void obsetId(pOvertimeBook po, char* str);
void obsetBookName(pOvertimeBook po, char* str);
void obsetOverday(pOvertimeBook po, int overday);
void obsetNext(pOvertimeBook po, pOvertimeBook next);

#endif 
