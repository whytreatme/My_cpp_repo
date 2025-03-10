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
	head = newOvertimeBook();//�ڴ�����
	if(readFile(head)) {//�ļ�����
		doLoop();
	}
	else {//�ļ�������
		if(writeFileDefault() && readFile(head)) {//�����ļ�������ɹ�
			printf("����Ĭ�������ɹ�\n");
			doLoop();
		}
		else {//ʧ��
			printf("����Ĭ������ʧ�ܣ������˳�\n");
		}
	}
	system("pause");
}

void uiPrint() {
	printf("\n");
	printf("    ********************\n");
	printf("    *  ����ͼ�����ϵͳ  *\n");
	printf("    ********************\n");
}

void manPrint() {
	printf("\n> ��������ִ��ָ�\n");
	printf("> 1.��ʾȫ�� 2.�޸� 3.ɾ�� 4.��ѯ 5.ͳ�� 6.��� 7.����\n> 8.���ý��� 9.���� 10.���� 11.�˳�����\n");
}

void doLoop() {
	int command;
	bool work = true;
	uiPrint();
	//ѭ���ȴ��û����룬ִ�ж�Ӧ����
	while(work) {
		manPrint();
		scanf("%d", &command);
		switch(command) {
			case 1:
				if(!obShow(head)) {
					printf("�޼�¼\n");
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
						printf("������������ sort.txt\n");
				}
				break;
			case 8:
				system("cls");
				uiPrint();
				break;
			case 9:
				if(writeFile(head)) {
					printf("�ѱ���\n");
				}
				break;
			case 10:
				if(backupFile())
					printf("���ݳɹ�\n");
				else
					printf("����ʧ��\n");
				break;
			default:
				work = false;
				break;
		}
	}
}