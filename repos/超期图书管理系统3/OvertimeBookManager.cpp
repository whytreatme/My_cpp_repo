#define _CRT_SECURE_NO_WARNINGS
#include "OvertimeBookManager.h"

bool obShow(pOvertimeBook head) {
	//安全检查
	if(head == NULL || head->next == NULL) {
		return false;
	}

	//遍历链表输出
	head = head->next;
	while(head != NULL) {
		printf("%s %s %s %s %d %.1f\n",
			   head->className, head->name, head->id, head->bookName, head->overday, head->overday * 0.2);
		head = head->next;
	}
	return true;
}

bool obModitify(pOvertimeBook head) {
	printf("输入要修改的记录id：");

	char buf[32];
	scanf("%s", buf);
	buf[31] = '\0';

	//遍历链表查找记录
	head = head->next;
	while(head != NULL) {
		if(strcmp(head->id, buf) == 0)
			break;
		head = head->next;
	}

	//找不到记录
	if(head == NULL) {
		printf("找不到对应的记录\n");
		return false;
	}

	//输出原记录并修改记录
	printf("原记录：");
	printf("%s %s %s %s %d\n",
		   head->className, head->name, head->id, head->bookName, head->overday);
	printf("输入修改后的完整记录：");
	scanf("%s %s %s %s %d",
		  head->className, head->name, head->id, head->bookName, &head->overday);
	return true;
}

bool obDelete(pOvertimeBook head) {
	printf("输入要删除的记录id：");

	char buf[32];
	scanf("%s", buf);
	buf[31] = '\0';

	//遍历链表查找记录
	pOvertimeBook tail = head->next;
	while(tail != NULL) {
		if(strcmp(tail->id, buf) == 0)
			break;
		head = tail;
		tail = tail->next;
	}

	//找不到记录
	if(tail == NULL) {
		printf("找不到对应的记录\n");
		return false;
	}

	//删除记录
	head->next = tail->next;
	free(tail);

	return true;
}

bool obFind(pOvertimeBook head) {
	printf("输入数字进入查询：\n");
	printf("1.班级查询 2.姓名查询 3.图书编号查询 4.图书名称查询 5.班级+姓名查询 6.姓名模糊查询\n");

	int command;
	scanf("%d", &command);
	bool(*pfind)(pOvertimeBook, const char*) = NULL;
	switch(command) {//根据输入选择回调函数指针
		case 1:
			printf("输入班级：");
			pfind = findClassHelp;
			break;
		case 2:
			printf("输入姓名：");
			pfind = findNameHelp;
			break;
		case 3:
			printf("输入图书编号：");
			pfind = findIdHelp;
			break;
		case 4:
			printf("输入图书名称：");
			pfind = findBookHelp;
			break;
		case 5:
			printf("输入班级：");
			pfind = findClassHelp;
			break;
		case 6:
			printf("输入关键字：");
			pfind = findNameContainHelp;
			break;
		default:
			printf("输入错误\n");
			return false;
	}

	bool work = false;//指示是否有输出
	char buf[64];
	scanf("%s", buf);
	buf[63] = '\0';
	if(command == 5) {//组合搜索的情况

		printf("输入姓名：");
		char buf1[64];
		scanf("%s", buf1);
		buf1[63] = '\0';

		//遍历链表，将符合条件的输出
		head = head->next;
		while(head != NULL) {
			if(pfind(head, buf) && findNameContainHelp(head, buf1)) {
				printf("%s %s %s %s %d %.1f\n",
					   head->className, head->name, head->id, head->bookName, head->overday, head->overday * 0.2);
				work = true;
			}
			head = head->next;
		}
	}
	else {//精确或模糊搜索
		//遍历链表，将符合条件的输出
		head = head->next;
		while(head != NULL) {
			if(pfind(head, buf)) {
				printf("%s %s %s %s %d %.1f\n",
					   head->className, head->name, head->id, head->bookName, head->overday, head->overday * 0.2);
				work = true;
			}
			head = head->next;
		}
	}
	//无对应的记录，输出提示
	if(!work)
		printf("找不到对应的记录\n");
	return work;
}

bool obSort(pOvertimeBook head) {
	printf("输入数字进入排序：\n");

	int command;
	bool (*psort)(pOvertimeBook, pOvertimeBook) = NULL;
	bool order;

	printf("1.班级排序 2.姓名排序 3.图书编号排序 4.图书名称排序 5.超期时间排序\n");
	scanf("%d", &command);
	switch(command) {//根据输入选择回调函数指针
		case 1:
			psort = sortClassHelp;
			break;
		case 2:
			psort = sortNameHelp;
			break;
		case 3:
			psort = sortIdHelp;
			break;
		case 4:
			psort = sortBookHelp;
			break;
		case 5:
			psort = sortOverdayHelp;
			break;
		default:
			printf("输入错误\n");
			return false;
	}

	printf("1.升序 2.降序\n");
	scanf("%d", &command);
	switch(command) {
		case 1:
			order = false;
			break;
		case 2:
			order = true;
			break;
		default:
			printf("输入错误\n");
			return false;
	}

	//进行排序
	sortOvertimeBook(head, psort, order);
	return true;

}

bool obSummary(pOvertimeBook head) {
	printf("输入数字进入罚款统计：\n");
	printf("1.班级罚款统计 2.姓名罚款统计\n");

	int command;
	bool (*pfind)(pOvertimeBook, const char*) = NULL;
	scanf("%d", &command);

	switch(command) {//根据输入选择回调函数指针
		case 1:
			pfind = findClassHelp;
			break;
		case 2:
			pfind = findNameHelp;
			break;
		default:
			printf("输入错误\n");
			return false;
	}

	if(command == 1)
		printf("输入班级：");
	else
		printf("输入姓名：");

	char buf[64];
	scanf("%s", buf);
	buf[63] = '\0';

	double sum = 0;
	//遍历链表，累计符合条件的记录
	head = head->next;
	while(head != NULL) {
		if(pfind(head, buf)) {
			sum += head->overday * 0.2;
		}
		head = head->next;
	}

	printf("%s 共计罚款：%.1f\n", buf, sum);
	return true;

}

void obAppend(pOvertimeBook head) {
	printf("输入：班级 姓名 图书编号 图书名称 超期时间（天）\n");
	pOvertimeBook tail = newOvertimeBook();
	scanf("%s %s %s %s %d",
		  tail->className, tail->name, tail->id, tail->bookName, &tail->overday);

	//将记录添加到链表末端
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = tail;
}
