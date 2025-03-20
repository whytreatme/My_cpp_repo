#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

struct Record
{
	int day;				// ��������
	char name[50];			// ����
	char number[50];		// ���
	char className[50];		// �༶
	char bookName[50];		// ͼ������
	char bookNumber[50];	// ͼ����
	float fine;				// ����

	struct Record* next;
};

struct Record* headr = NULL;

// ��������
void saveRecordData(void);
// ��ȡ����
void readRecordData(void);
// ���
void addRecord();
// ����
int repeatr(struct Record* temp);
// �˵�
void menu(void);
// ��ʾ
void showr(struct Record* p);
// ��ʾȫ��
void showAllRecord(void);
// ��ѯ
void findRecord(void);
// ��ѯ
struct Record* findr(char* number);
// ɾ��
void delRecord(void);
// �޸ļ�¼
void reviseRecord(void);
// ��������
void findTermRecord(void);
// ѡ������
//void getTerm(bool* term);
// ͳ�ư༶����
void countClassName(void);
// ͳ����������
void countName(void);

int main()
{
	headr = (struct Record*)malloc(sizeof(struct Record));
	headr->next = NULL;

	readRecordData();

	menu();

	return 0;
}

// ��������
void saveRecordData(void)
{
	struct Record* p;
	FILE* fp;

	fp = fopen("d:\\Record.txt", "w");

	if (headr->next == NULL)
	{
		fclose(fp);
		remove("Record.txt");
		return;
	}

	for (p = headr->next; p != NULL; p = p->next)
	{
		fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%f", p->number, p->className, p->name, p->bookNumber, p->bookName, p->day, p->fine);
	}

	fclose(fp);
}

// ��ȡ����
void readRecordData(void)
{
	struct Record* p;
	FILE* fp;

	fp = fopen("\\Record.txt", "r");

	if (fp == NULL)
	{
		printf("δ��ȡ���ݣ����������ļ�\n");
		return;
	}

	p = headr;

	while (!feof(fp))
	{
		p->next = (struct Record*)malloc(sizeof(struct Record));
		p = p->next;

		//fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%f", p->number, p->className, p->name, p->bookNumber, p->bookName, &p->day, &p->fine);;
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%f", p->number, 50, p->className, 50, p->name, 50, p->bookNumber, 50, p->bookName, 50, &p->day, &p->fine);;

		p->next = NULL;
	}

	//for (p = headr; p->next->next != NULL; p = p->next);

	free(p->next);		// ���ĩβ��������
	p->next = NULL;

	fclose(fp);
}

// ��Ӽ�¼
void addRecord()
{
	struct Record* p;

	p = (struct Record*)malloc(sizeof(struct Record));
	p->next = NULL;

	printf("�������¼��ţ�");
	scanf("%s", p->number, 50);

	while (repeatr(p))
	{
		printf("����ظ������������룺");
		scanf("%s", p->number, 50);
	}

	printf("������ѧ���༶��");
	scanf("%s", p->className, 50);
	printf("������ѧ��������");
	scanf("%s", p->name, 50);
	printf("������ͼ���ţ�");
	scanf("%s", p->bookNumber, 50);
	printf("������ͼ�����ƣ�");
	scanf("%s", p->bookName, 50);
	printf("�����볬��ʱ�䣺");
	scanf("%d", &p->day);

	p->fine = p->day * 0.2f;

	p->next = headr->next;
	headr->next = p;
}

// ����
int repeatr(struct Record* temp)
{
	struct Record* p;

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!strcmp(p->number, temp->number) && p != temp)
			return 1;
	}

	return 0;
}

// �˵�
void menu(void)
{
	while (1)
	{
		printf("����ͼ�����ϵͳ\n");
		printf("1.��ӳ��ڼ�¼\n");
		printf("2.ɾ�����ڼ�¼\n");
		printf("3.�޸ĳ��ڼ�¼\n");
		printf("4.��ѯ���ڼ�¼\n");
		printf("5.��ʾ���ڼ�¼\n");
		printf("6.ͳ�Ƴ��ڼ�¼\n");
		printf("0.�˳�\n");

		switch (getchar())
		{
		case '0':
			return;
		case '1':
			addRecord();
			saveRecordData();
			break;
			/*	case '2':
					delRecord();
					saveRecordData();
					break; */
		case '3':
			reviseRecord();
			saveRecordData();
			break;
		case '4':
			printf("�Ƿ����������ѯ����Ĭ�ϱ�Ų�ѯ���밴 y ����������ѯ��\n");
			/*	if (getchar() == 'y')
		  {
			  findTermRecord();
		  }
		  else
		  {
			  findRecord();
		  } */
			break;
		case '5':
			showAllRecord();
			break;
		case '6':
			printf("�Ƿ���а༶ͳ�ƣ���Ĭ�ϱ�Ų�ѯ���밴 y ���а༶ͳ�ƣ�\n");
			/*	if (getchar() == 'y')
		 {
			 countClassName();
		 }
		 else
		 {
			 countName();
		 }*/
			break;
		default:
			printf("�Ƿ�����\n");
			break;
		}
	}
}

// ��ʾ��¼
void showr(struct Record* p)
{
	printf("��ţ�%s���༶��%s��������%s��ͼ���ţ�%s��ͼ�����ƣ�%s������ʱ�䣺%d, ���%.2f\n",
		p->number, p->className, p->name, p->bookNumber, p->bookName, p->day, p->fine);
}

// ��ʾȫ����¼
void showAllRecord(void)
{
	struct Record* p;

	for (p = headr->next; p != NULL; p = p->next)
	{
		showr(p);
	}
}

// ��ѯ
/*void findRecord(void)
{
	char number[50];
	struct Record* p;

	printf("������Ҫ��ѯ�ļ�¼��ţ�");
	scanf_s("%s", number, 50);

	p = findr(number);

	if (p != NULL)
	{
		showr(p);
	}
	else
	{
		printf("�޴˱����Ϣ\n");
	}
} */

// ��ѯ
struct Record* findr(char* number)
{
	struct Record* p;

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!strcmp(number, p->number))
		{
			return p;
		}
	}

	return NULL;
}

// ɾ����¼
/*void delRecord(void)
{
	char number[50];
	struct Record* p, * last;

	printf("������Ҫɾ���ļ�¼��ţ�");
	scanf_s("%s", number, 50);

	for (last = headr, p = headr->next; p != NULL; last = p, p = p->next)
	{
		if (!strcmp(number, p->number))
		{
			showr(p);
			last->next = p->next;
			free(p);
			return;
		}
	}

	printf("�޴˱����Ϣ\n");
}*/

// �޸ļ�¼
void reviseRecord(void)
{
	char number[50];
	struct Record* p;

	printf("������Ҫ�޸ĵļ�¼��ţ�");
	scanf("%s", number, 50);

	p = findr(number);

	if (p != NULL)
	{
		showr(p);

		printf("�������¼��ţ�");
		scanf("%s", p->number, 50);

		while (repeatr(p))
		{
			printf("����ظ������������룺");
			scanf("%s", p->number, 50);
		}

		printf("������ѧ���༶��");
		scanf("%s", p->className, 50);
		printf("������ѧ��������");
		scanf("%s", p->name, 50);
		printf("������ͼ���ţ�");
		scanf("%s", p->bookNumber, 50);
		printf("������ͼ�����ƣ�");
		scanf("%s", p->bookName, 50);
		printf("�����볬��ʱ�䣺");
		scanf("%d", &p->day);

		p->fine = p->day * 0.2f;
	}
	else
	{
		printf("�޴˱����Ϣ\n");
	}
}

// ��������
/*void findTermRecord(void)
{
	bool term[5] = { 0 };
	Record f;
	Record* p;

	getTerm(term);

	if (term[0])
	{
		printf("������Ҫ��ѯ�İ༶������");
		scanf_s("%s", f.className, 50);
	}
	if (term[1])
	{
		printf("������Ҫ��ѯ������������");
		scanf_s("%s", f.name, 50);
	}
	if (term[2])
	{
		printf("������Ҫ��ѯ��ͼ����������");
		scanf_s("%s", f.bookNumber, 50);
	}
	if (term[3])
	{
		printf("������Ҫ��ѯ��ͼ������������");
		scanf_s("%s", f.bookName, 50);
	}
	if (term[4])
	{
		printf("������Ҫ��ѯ�ĳ���ʱ��������");
		scanf_s("%d", &f.day);
	}

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!((term[0] && strcmp(f.className, p->className))
			|| (term[1] && strcmp(f.name, p->name))
			|| (term[2] && strcmp(f.bookNumber, p->bookNumber))
			|| (term[3] && strcmp(f.bookName, p->bookName))
			|| (term[4] && f.day != p->day)))
		{
			showr(p);
		}
	}
}

// ѡ������
void getTerm(bool* term)
{
	while (true)
	{
		printf("  ����ѡ��\n");
		printf("1.�༶%s\n", term[0] ? "��" : "��");
		printf("2.����%s\n", term[1] ? "��" : "��");
		printf("3.ͼ����%s\n", term[2] ? "��" : "��");
		printf("4.ͼ������%s\n", term[3] ? "��" : "��");
		printf("5.����ʱ��%s\n", term[4] ? "��" : "��");
		printf("0.���ѡ��\n");

		switch (_getch())
		{
		case '0':
			if (term[0] || term[1] || term[2] || term[3] || term[4])
			{
				return;
			}
			else
			{
				printf("��ѡ���ѯ����\n");
			}
		case '1':
			term[0] = !term[0];
			break;
		case '2':
			term[1] = !term[1];
			break;
		case '3':
			term[2] = !term[2];
			break;
		case '4':
			term[3] = !term[3];
			break;
		case '5':
			term[4] = !term[4];
			break;
		}
	}
}

// ͳ�ư༶����
void countClassName(void)
{
	char className[50];
	float sum = 0;
	Record* p;

	printf("������Ҫͳ�Ƶİ༶��");
	scanf_s("%s", className, 50);

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!strcmp(className, p->className))
		{
			showr(p);
			sum += p->fine;
		}
	}

	printf("%s �༶���� %.2f\n", className, sum);
}

// ͳ����������
void countName(void)
{
	char name[50];
	float sum = 0;
	Record* p;

	printf("������Ҫͳ�Ƶ�������");
	scanf_s("%s", name, 50);

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!strcmp(name, p->name))
		{
			showr(p);
			sum += p->fine;
		}
	}

	printf("%s ͬѧ���� %.2f\n", name, sum);
}
*/
