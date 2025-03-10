#ifndef FILEIO_H
#define FILEIO_H

#include "OvertimeBook.h"
#include <stdio.h>

//��д����
bool readFile(pOvertimeBook head, const char* fname = "book.txt");
bool writeFile(pOvertimeBook head, const char* fname = "book.txt");

//����Ĭ������
bool writeFileDefault(const char* fname = "book.txt");

//����
bool backupFile(const char* fname = "book.txt", const char* bname = "backup.txt");

#endif


