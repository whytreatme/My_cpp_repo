#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "OvertimeBook.h"
#include "OvertimeBookManager.h"
#include "FileIO.h"

void uiPrint();
void manPrint();
void doLoop();

pOvertimeBook head;

int main() {
	head = newOvertimeBook();//内存链表
	if(readFile(head)) {//文件存在
		doLoop();
	}
	else {//文件不存在
		if(writeFileDefault() && readFile(head)) {//创建文件并读入成功
			printf("创建默认用例成功\n");
			doLoop();
		}
		else {//失败
			printf("创建默认用例失败，程序退出\n");
		}
	}
	system("pause");
}

void uiPrint() {
	printf("\n");
	printf("    ********************\n");
	printf("    *  超期图书管理系统  *\n");
	printf("    ********************\n");
}

void manPrint() {
	printf("\n> 输入数字执行指令：\n");
	printf("> 1.显示全部 2.修改 3.删除 4.查询 5.统计 6.添加 7.排序\n> 8.重置界面 9.保存 10.备份 11.退出程序\n");
}

void doLoop() {
	int command;
	bool work = true;
	uiPrint();
	//循环等待用户输入，执行对应操作
	while(work) {
		manPrint();
		scanf("%d", &command);
		switch(command) {
			case 1:
				if(!obShow(head)) {
					printf("无记录\n");
				}
				break;
			case 2:
				if(obModitify(head)) {
					writeFile(head);
				}
				break;
			case 3:
				if(obDelete(head)) {
					writeFile(head);
				}
				break;
			case 4:
				obFind(head);
				break;
			case 5:
				obSummary(head);
				break;
			case 6:
				obAppend(head);
				writeFile(head);
				break;
			case 7:
				if(obSort(head)) {
					if(writeFile(head, "sort.txt"))
						printf("排序结果保存在 sort.txt\n");
				}
				break;
			case 8:
				system("cls");
				uiPrint();
				break;
			case 9:
				if(writeFile(head)) {
					printf("已保存\n");
				}
				break;
			case 10:
				if(backupFile())
					printf("备份成功\n");
				else
					printf("备份失败\n");
				break;
			default:
				work = false;
				break;
		}
	}
}