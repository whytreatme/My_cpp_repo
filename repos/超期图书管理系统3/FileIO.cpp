#define _CRT_SECURE_NO_WARNINGS
#include "FileIO.h"

bool readFile(pOvertimeBook head, const char* fname) {
	//���ļ�
	FILE *fp = fopen(fname, "r");
	//���ô�����Ϣ
	if(fp == NULL) {
		printf("�����ļ� %s ������\n", fname);
		return false;
	}

	pOvertimeBook ptem = newOvertimeBook();//��ʱ����
	//ѭ��д��ṹ��
	while(~fscanf(fp, "%s %s %s %s %d",
		  ptem->className, ptem->name, ptem->id, ptem->bookName, &ptem->overday)) {
		head->next = ptem;//ָ���ƶ�
		head = head->next;
		ptem = newOvertimeBook();
	}
	free(ptem);//������ʱ�������ļ�
	fclose(fp);
	return true;
}

bool writeFile(pOvertimeBook head, const char* fname) {
	//���ļ�
	FILE *fp = fopen(fname, "w");
	//���ô�����Ϣ
	if(fp == NULL) {
		printf("�����޷�д���ļ� %s\n", fname);
		return false;
	}

	head = head->next;//�Թ��ڱ��ڵ�
	//ѭ����ȡ����д���ļ�
	while(head != NULL) {
		fprintf(fp, "%s %s %s %s %d\n",
				head->className, head->name, head->id, head->bookName, head->overday);

		head = head->next;//ָ���ƶ�
	}
	fclose(fp);//�ر��ļ�
	return true;
}

bool writeFileDefault(const char * fname) {
	//���ļ�
	FILE *fp = fopen(fname, "w");
	//���ô�����Ϣ
	if(fp == NULL) {
		printf("�����޷�д���ļ� %s\n", fname);
		return false;
	}

	fputs("�����211 ���� T01 ������� 1\n", fp);
	fputs("�����211 ���� M01 ����ʷ 10\n", fp);
	fputs("��ѧ209 ��һ M02 �ϳ����� 9\n", fp);
	fputs("��ѧ202 ���� T02 ͼ��ѧ 2\n", fp);
	fputs("����200 ���� W01 ʷ�� 7\n", fp);

	fclose(fp);//�ر��ļ�
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