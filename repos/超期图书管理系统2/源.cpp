#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

struct Record
{
	int day;				// 超期天数
	char name[50];			// 姓名
	char number[50];		// 编号
	char className[50];		// 班级
	char bookName[50];		// 图书名称
	char bookNumber[50];	// 图书编号
	float fine;				// 罚款

	struct Record* next;
};

struct Record* headr = NULL;

// 保存数据
void saveRecordData(void);
// 读取数据
void readRecordData(void);
// 添加
void addRecord();
// 查重
int repeatr(struct Record* temp);
// 菜单
void menu(void);
// 显示
void showr(struct Record* p);
// 显示全部
void showAllRecord(void);
// 查询
void findRecord(void);
// 查询
struct Record* findr(char* number);
// 删除
void delRecord(void);
// 修改记录
void reviseRecord(void);
// 条件查找
void findTermRecord(void);
// 选择条件
//void getTerm(bool* term);
// 统计班级罚款
void countClassName(void);
// 统计姓名罚款
void countName(void);

int main()
{
	headr = (struct Record*)malloc(sizeof(struct Record));
	headr->next = NULL;

	readRecordData();

	menu();

	return 0;
}

// 保存数据
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

// 读取数据
void readRecordData(void)
{
	struct Record* p;
	FILE* fp;

	fp = fopen("\\Record.txt", "r");

	if (fp == NULL)
	{
		printf("未读取数据，请检查数据文件\n");
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

	free(p->next);		// 清除末尾无用数据
	p->next = NULL;

	fclose(fp);
}

// 添加记录
void addRecord()
{
	struct Record* p;

	p = (struct Record*)malloc(sizeof(struct Record));
	p->next = NULL;

	printf("请输入记录编号：");
	scanf("%s", p->number, 50);

	while (repeatr(p))
	{
		printf("编号重复，请重新输入：");
		scanf("%s", p->number, 50);
	}

	printf("请输入学生班级：");
	scanf("%s", p->className, 50);
	printf("请输入学生姓名：");
	scanf("%s", p->name, 50);
	printf("请输入图书编号：");
	scanf("%s", p->bookNumber, 50);
	printf("请输入图书名称：");
	scanf("%s", p->bookName, 50);
	printf("请输入超期时间：");
	scanf("%d", &p->day);

	p->fine = p->day * 0.2f;

	p->next = headr->next;
	headr->next = p;
}

// 查重
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

// 菜单
void menu(void)
{
	while (1)
	{
		printf("超期图书管理系统\n");
		printf("1.添加超期记录\n");
		printf("2.删除超期记录\n");
		printf("3.修改超期记录\n");
		printf("4.查询超期记录\n");
		printf("5.显示超期记录\n");
		printf("6.统计超期记录\n");
		printf("0.退出\n");

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
			printf("是否进行条件查询？（默认编号查询，请按 y 进入条件查询）\n");
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
			printf("是否进行班级统计？（默认编号查询，请按 y 进行班级统计）\n");
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
			printf("非法输入\n");
			break;
		}
	}
}

// 显示记录
void showr(struct Record* p)
{
	printf("编号：%s，班级：%s，姓名：%s，图书编号：%s，图书名称：%s，超期时间：%d, 罚款：%.2f\n",
		p->number, p->className, p->name, p->bookNumber, p->bookName, p->day, p->fine);
}

// 显示全部记录
void showAllRecord(void)
{
	struct Record* p;

	for (p = headr->next; p != NULL; p = p->next)
	{
		showr(p);
	}
}

// 查询
/*void findRecord(void)
{
	char number[50];
	struct Record* p;

	printf("请输入要查询的记录编号：");
	scanf_s("%s", number, 50);

	p = findr(number);

	if (p != NULL)
	{
		showr(p);
	}
	else
	{
		printf("无此编号信息\n");
	}
} */

// 查询
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

// 删除记录
/*void delRecord(void)
{
	char number[50];
	struct Record* p, * last;

	printf("请输入要删除的记录编号：");
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

	printf("无此编号信息\n");
}*/

// 修改记录
void reviseRecord(void)
{
	char number[50];
	struct Record* p;

	printf("请输入要修改的记录编号：");
	scanf("%s", number, 50);

	p = findr(number);

	if (p != NULL)
	{
		showr(p);

		printf("请输入记录编号：");
		scanf("%s", p->number, 50);

		while (repeatr(p))
		{
			printf("编号重复，请重新输入：");
			scanf("%s", p->number, 50);
		}

		printf("请输入学生班级：");
		scanf("%s", p->className, 50);
		printf("请输入学生姓名：");
		scanf("%s", p->name, 50);
		printf("请输入图书编号：");
		scanf("%s", p->bookNumber, 50);
		printf("请输入图书名称：");
		scanf("%s", p->bookName, 50);
		printf("请输入超期时间：");
		scanf("%d", &p->day);

		p->fine = p->day * 0.2f;
	}
	else
	{
		printf("无此编号信息\n");
	}
}

// 条件查找
/*void findTermRecord(void)
{
	bool term[5] = { 0 };
	Record f;
	Record* p;

	getTerm(term);

	if (term[0])
	{
		printf("请输入要查询的班级条件：");
		scanf_s("%s", f.className, 50);
	}
	if (term[1])
	{
		printf("请输入要查询的姓名条件：");
		scanf_s("%s", f.name, 50);
	}
	if (term[2])
	{
		printf("请输入要查询的图书编号条件：");
		scanf_s("%s", f.bookNumber, 50);
	}
	if (term[3])
	{
		printf("请输入要查询的图书名称条件：");
		scanf_s("%s", f.bookName, 50);
	}
	if (term[4])
	{
		printf("请输入要查询的超期时间条件：");
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

// 选择条件
void getTerm(bool* term)
{
	while (true)
	{
		printf("  条件选择\n");
		printf("1.班级%s\n", term[0] ? "√" : "×");
		printf("2.姓名%s\n", term[1] ? "√" : "×");
		printf("3.图书编号%s\n", term[2] ? "√" : "×");
		printf("4.图书姓名%s\n", term[3] ? "√" : "×");
		printf("5.超期时间%s\n", term[4] ? "√" : "×");
		printf("0.完成选择\n");

		switch (_getch())
		{
		case '0':
			if (term[0] || term[1] || term[2] || term[3] || term[4])
			{
				return;
			}
			else
			{
				printf("请选择查询条件\n");
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

// 统计班级罚款
void countClassName(void)
{
	char className[50];
	float sum = 0;
	Record* p;

	printf("请输入要统计的班级：");
	scanf_s("%s", className, 50);

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!strcmp(className, p->className))
		{
			showr(p);
			sum += p->fine;
		}
	}

	printf("%s 班级罚款 %.2f\n", className, sum);
}

// 统计姓名罚款
void countName(void)
{
	char name[50];
	float sum = 0;
	Record* p;

	printf("请输入要统计的姓名：");
	scanf_s("%s", name, 50);

	for (p = headr->next; p != NULL; p = p->next)
	{
		if (!strcmp(name, p->name))
		{
			showr(p);
			sum += p->fine;
		}
	}

	printf("%s 同学罚款 %.2f\n", name, sum);
}
*/
