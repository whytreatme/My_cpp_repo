#define _CRT_SECURE_NO_WARNINGS
#include "OvertimeBook.h"

pOvertimeBook newOvertimeBook() {
	pOvertimeBook ob = (pOvertimeBook)malloc(sizeob);
	memset(ob, 0, sizeob);//��ʼ��
	ob->next = NULL;
	return ob;
}

void obsetClassName(pOvertimeBook po, char* str) {
	strncpy(po->className, str, 63);//��ֹ�ַ���������²���ȫ
}

void obsetName(pOvertimeBook po, char* str) {
	strncpy(po->name, str, 63);
}

void obsetId(pOvertimeBook po, char* str) {
	strncpy(po->id, str, 31);
}

void obsetBookName(pOvertimeBook po, char* str) {
	strncpy(po->bookName, str, 63);
}

void obsetOverday(pOvertimeBook po, int overday) {
	po->overday = overday;
}

void obsetNext(pOvertimeBook po, pOvertimeBook next) {
	po->next = next;
}
