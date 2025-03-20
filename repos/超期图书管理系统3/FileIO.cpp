#define _CRT_SECURE_NO_WARNINGS
#include "FileIO.h"

bool readFile(pOvertimeBook head, const char* fname) {
	//打开文件
	FILE *fp = fopen(fname, "r");
	//设置错误信息
	if(fp == NULL) {
		printf("错误：文件 %s 不存在\n", fname);
		return false;
	}

	pOvertimeBook ptem = newOvertimeBook();//临时变量
	//循环写入结构体
	while(~fscanf(fp, "%s %s %s %s %d",
		  ptem->className, ptem->name, ptem->id, ptem->bookName, &ptem->overday)) {
		head->next = ptem;//指针移动
		head = head->next;
		ptem = newOvertimeBook();
	}
	free(ptem);//清理临时变量和文件
	fclose(fp);
	return true;
}

bool writeFile(pOvertimeBook head, const char* fname) {
	//打开文件
	FILE *fp = fopen(fname, "w");
	//设置错误信息
	if(fp == NULL) {
		printf("错误：无法写入文件 %s\n", fname);
		return false;
	}

	head = head->next;//略过哨兵节点
	//循环读取链表，写入文件
	while(head != NULL) {
		fprintf(fp, "%s %s %s %s %d\n",
				head->className, head->name, head->id, head->bookName, head->overday);

		head = head->next;//指针移动
	}
	fclose(fp);//关闭文件
	return true;
}

bool writeFileDefault(const char * fname) {
	//打开文件
	FILE *fp = fopen(fname, "w");
	//设置错误信息
	if(fp == NULL) {
		printf("错误：无法写入文件 %s\n", fname);
		return false;
	}

	fputs("计算机211 张三 T01 程序设计 1\n", fp);
	fputs("计算机211 张三 M01 音乐史 10\n", fp);
	fputs("数学209 王一 M02 合唱艺术 9\n", fp);
	fputs("数学202 李四 T02 图形学 2\n", fp);
	fputs("中文200 王五 W01 史记 7\n", fp);

	fclose(fp);//关闭文件
	return true;
}

bool backupFile(const char* fname, const char* bname) {
	FILE *fp = fopen(fname, "r");
	FILE *fpb = fopen(bname, "w");
	if(fp == NULL || fpb == NULL)
		return false;

	char buf[256];
	while(fgets(buf, 256, fp)) {
		fputs(buf, fpb);
	}
	fclose(fpb);
	fclose(fp);
	return true;
}