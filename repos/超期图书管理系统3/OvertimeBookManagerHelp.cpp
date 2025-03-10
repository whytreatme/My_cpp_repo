#include "OvertimeBookManagerHelp.h"

bool findClassHelp(pOvertimeBook po, const char* str) {
	return strcmp(po->className, str) == 0;
}

bool findNameHelp(pOvertimeBook po, const char* str) {
	return strcmp(po->name, str) == 0;
}

bool findIdHelp(pOvertimeBook po, const char* str) {
	return strcmp(po->id, str) == 0;
}

bool findBookHelp(pOvertimeBook po, const char* str) {
	return strcmp(po->bookName, str) == 0;
}

bool findNameContainHelp(pOvertimeBook po, const char* str) {
	return strstr(po->name, str) != NULL;
}



bool sortClassHelp(pOvertimeBook p1, pOvertimeBook p2) {
	return strcmp(p1->className, p2->className) > 0;
}

bool sortNameHelp(pOvertimeBook p1, pOvertimeBook p2) {
	return strcmp(p1->name, p2->name) > 0;
}

bool sortIdHelp(pOvertimeBook p1, pOvertimeBook p2) {
	return strcmp(p1->id, p2->id) > 0;
}

bool sortBookHelp(pOvertimeBook p1, pOvertimeBook p2) {
	return strcmp(p1->bookName, p2->bookName) > 0;
}

bool sortOverdayHelp(pOvertimeBook p1, pOvertimeBook p2) {
	return p1->overday > p2->overday;
}

void sortOvertimeBook(pOvertimeBook head, bool(*psort)(pOvertimeBook, pOvertimeBook), bool order) {
	//¿ìËÙ¼òµ¥ÅÅĞò
	while(head->next != NULL) {
		pOvertimeBook topg = head;
		pOvertimeBook temg = head->next;
		if(temg->next == NULL)
			break;
		while(temg->next != NULL) {
			if(psort(topg->next, temg->next) ^ order) {
				topg = temg;
			}
			temg = temg->next;
		}

		temg = topg->next;
		if(topg != head) {
			topg->next = temg->next;
			temg->next = head->next;
			head->next = temg;
		}
		head = temg;
	}
}
