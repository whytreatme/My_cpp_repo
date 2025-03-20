// cin直接输入字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

const int SLEN = 30;

struct student
{
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student* ps);
void diplay3(const student pa[], int n);
int my_get(char*, int);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;

	auto ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);

	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	diplay3(ptr_stu, entered);
	delete[] ptr_stu;

	cout << "Done.\n";

	return 0;
}

int getinfo(student pa[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		cout << "Enter the student's name: ";
		cin >> pa[i].fullname;
		cout << "Enter the student's hobby: ";
		cin >> pa[i].hobby;
		cout << "Input the student's ooplevel: ";
		cin >> pa[i].ooplevel;
		if(!cin)
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Bad input; Please input a value:\n";
				break;
			}
			
		
		
	}
	return i;
}

int my_get(char* str, int size)
{

	if (!cin.get(str, size))
		return 0;


	while (cin.get() != '\n')
		continue;

	return 1;
}

void display1(student st)
{
	cout << "name: " << st.fullname << endl;
	cout << "hobby: " << st.hobby << endl;
	cout << "ooplevel: " << st.ooplevel << endl;
}

void display2(const student* ps)
{
	cout << "name: " << ps->fullname << endl;
	cout << "hobby: " << ps->hobby << endl;
	cout << "ooplevel: " << ps->ooplevel << endl;
}

void diplay3(const student pa[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "name: " << pa[i].fullname << endl;
		cout << "hobby: " << pa[i].hobby << endl;
		cout << "ooplevel: " << pa[i].ooplevel << endl;
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
