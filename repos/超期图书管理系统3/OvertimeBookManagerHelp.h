#ifndef OVERTIMEBOOKMANAGERHELP_H
#define OVERTIMEBOOKMANAGERHELP_H

#include <string.h>
#include "OvertimeBook.h"

//条件查找的辅助函数
bool findClassHelp(pOvertimeBook po, const char* str);
bool findNameHelp(pOvertimeBook po, const char* str);
bool findIdHelp(pOvertimeBook po, const char* str);
bool findBookHelp(pOvertimeBook po, const char* str);

//模糊查找的辅助函数
bool findNameContainHelp(pOvertimeBook po, const char* str);

//排序辅助函数
bool sortClassHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortNameHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortIdHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortBookHelp(pOvertimeBook p1, pOvertimeBook p2);
bool sortOverdayHelp(pOvertimeBook p1, pOvertimeBook p2);

//简单快速排序
void sortOvertimeBook(pOvertimeBook head, bool (*psort)(pOvertimeBook, pOvertimeBook), bool order);

#endif


