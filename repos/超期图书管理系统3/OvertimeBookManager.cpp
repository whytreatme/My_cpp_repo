#define _CRT_SECURE_NO_WARNINGS
#include "OvertimeBookManager.h"

bool obShow(pOvertimeBook head) {
	//��ȫ���
	if(head == NULL || head->next == NULL) {
		return false;
	}

	//�����������
	head = head->next;
	while(head != NULL) {
		printf("%s %s %s %s %d %.1f\n",
			   head->className, head->name, head->id, head->bookName, head->overday, head->overday * 0.2);
		head = head->next;
	}
	return true;
}

bool obModitify(pOvertimeBook head) {
	printf("����Ҫ�޸ĵļ�¼id��");

	char buf[32];
	scanf("%s", buf);
	buf[31] = '\0';

	//����������Ҽ�¼
	head = head->next;
	while(head != NULL) {
		if(strcmp(head->id, buf) == 0)
			break;
		head = head->next;
	}

	//�Ҳ�����¼
	if(head == NULL) {
		printf("�Ҳ�����Ӧ�ļ�¼\n");
		return false;
	}

	//���ԭ��¼���޸ļ�¼
	printf("ԭ��¼��");
	printf("%s %s %s %s %d\n",
		   head->className, head->name, head->id, head->bookName, head->overday);
	printf("�����޸ĺ��������¼��");
	scanf("%s %s %s %s %d",
		  head->className, head->name, head->id, head->bookName, &head->overday);
	return true;
}

bool obDelete(pOvertimeBook head) {
	printf("����Ҫɾ���ļ�¼id��");

	char buf[32];
	scanf("%s", buf);
	buf[31] = '\0';

	//����������Ҽ�¼
	pOvertimeBook tail = head->next;
	while(tail != NULL) {
		if(strcmp(tail->id, buf) == 0)
			break;
		head = tail;
		tail = tail->next;
	}

	//�Ҳ�����¼
	if(tail == NULL) {
		printf("�Ҳ�����Ӧ�ļ�¼\n");
		return false;
	}

	//ɾ����¼
	head->next = tail->next;
	free(tail);

	return true;
}

bool obFind(pOvertimeBook head) {
	printf("�������ֽ����ѯ��\n");
	printf("1.�༶��ѯ 2.������ѯ 3.ͼ���Ų�ѯ 4.ͼ�����Ʋ�ѯ 5.�༶+������ѯ 6.����ģ����ѯ\n");

	int command;
	scanf("%d", &command);
	bool(*pfind)(pOvertimeBook, const char*) = NULL;
	switch(command) {//��������ѡ��ص�����ָ��
		case 1:
			printf("����༶��");
			pfind = findClassHelp;
			break;
		case 2:
			printf("����������");
			pfind = findNameHelp;
			break;
		case 3:
			printf("����ͼ���ţ�");
			pfind = findIdHelp;
			break;
		case 4:
			printf("����ͼ�����ƣ�");
			pfind = findBookHelp;
			break;
		case 5:
			printf("����༶��");
			pfind = findClassHelp;
			break;
		case 6:
			printf("����ؼ��֣�");
			pfind = findNameContainHelp;
			break;
		default:
			printf("�������\n");
			return false;
	}

	bool work = false;//ָʾ�Ƿ������
	char buf[64];
	scanf("%s", buf);
	buf[63] = '\0';
	if(command == 5) {//������������

		printf("����������");
		char buf1[64];
		scanf("%s", buf1);
		buf1[63] = '\0';

		//�����������������������
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
	else {//��ȷ��ģ������
		//�����������������������
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
	//�޶�Ӧ�ļ�¼�������ʾ
	if(!work)
		printf("�Ҳ�����Ӧ�ļ�¼\n");
	return work;
}

bool obSort(pOvertimeBook head) {
	printf("�������ֽ�������\n");

	int command;
	bool (*psort)(pOvertimeBook, pOvertimeBook) = NULL;
	bool order;

	printf("1.�༶���� 2.�������� 3.ͼ�������� 4.ͼ���������� 5.����ʱ������\n");
	scanf("%d", &command);
	switch(command) {//��������ѡ��ص�����ָ��
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
			printf("�������\n");
			return false;
	}

	printf("1.���� 2.����\n");
	scanf("%d", &command);
	switch(command) {
		case 1:
			order = false;
			break;
		case 2:
			order = true;
			break;
		default:
			printf("�������\n");
			return false;
	}

	//��������
	sortOvertimeBook(head, psort, order);
	return true;

}

bool obSummary(pOvertimeBook head) {
	printf("�������ֽ��뷣��ͳ�ƣ�\n");
	printf("1.�༶����ͳ�� 2.��������ͳ��\n");

	int command;
	bool (*pfind)(pOvertimeBook, const char*) = NULL;
	scanf("%d", &command);

	switch(command) {//��������ѡ��ص�����ָ��
		case 1:
			pfind = findClassHelp;
			break;
		case 2:
			pfind = findNameHelp;
			break;
		default:
			printf("�������\n");
			return false;
	}

	if(command == 1)
		printf("����༶��");
	else
		printf("����������");

	char buf[64];
	scanf("%s", buf);
	buf[63] = '\0';

	double sum = 0;
	//���������ۼƷ��������ļ�¼
	head = head->next;
	while(head != NULL) {
		if(pfind(head, buf)) {
			sum += head->overday * 0.2;
		}
		head = head->next;
	}

	printf("%s ���Ʒ��%.1f\n", buf, sum);
	return true;

}

void obAppend(pOvertimeBook head) {
	printf("���룺�༶ ���� ͼ���� ͼ������ ����ʱ�䣨�죩\n");
	pOvertimeBook tail = newOvertimeBook();
	scanf("%s %s %s %s %d",
		  tail->className, tail->name, tail->id, tail->bookName, &tail->overday);

	//����¼��ӵ�����ĩ��
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = tail;
}
