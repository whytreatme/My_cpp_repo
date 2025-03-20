#ifndef OVERTIMEBOOKMANAGERHELP_H
#define OVERTIMEBOOKMANAGERHELP_H

#include <string.h>
#include "OvertimeBook.h"

//�������ҵĸ�������
bool findClassHelp(pOvertimeBook po, const char* str);
bool findNameHelp(pOvertimeBook po, const char* str);
bool findIdHelp(pOvertimeBook po, const char* str);
bool findBookHelp(pOvertimeBook po, const char* str);

//ģ�����ҵĸ�������
bool findNameContainHelp(pOvertimeBook po, const char* str);

//����������
bool sortClassHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortNameHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortIdHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortBookHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortOverdayHelp(pOvertimeBook p1, pOvertimeBook p2);

//�򵥿�������
void sortOvertimeBook(pOvertimeBook head, bool (*psort)(pOvertimeBook, pOvertimeBook), bool order);

#endif


