#ifndef OVERTIMEBOOKMANAGER_H
#define OVERTIMEBOOKMANAGER_H

#include <stdio.h>
#include <string.h>
#include "OvertimeBook.h"
#include "OvertimeBookManagerHelp.h"

bool obShow(pOvertimeBook head);

bool obModitify(pOvertimeBook head);

bool obDelete(pOvertimeBook head);

bool obFind(pOvertimeBook head);

bool obSort(pOvertimeBook head);

bool obSummary(pOvertimeBook head);

void obAppend(pOvertimeBook head);

#endif

