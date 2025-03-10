#ifndef FILEIO_H
#define FILEIO_H

#include "OvertimeBook.h"
#include <stdio.h>

//读写链表
bool readFile(pOvertimeBook head, const char* fname = "book.txt");
bool writeFile(pOvertimeBook head, const char* fname = "book.txt");

//创建默认用例
bool writeFileDefault(const char* fname = "book.txt");

//备份
bool backupFile(const char* fname = "book.txt", const char* bname = "backup.txt");

#endif


