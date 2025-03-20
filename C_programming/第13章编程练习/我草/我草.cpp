#include <stdio.h>

#include<stdlib.h>

#include<ctype.h>

#define LEN 100

int main()

{



	FILE* fp = NULL;

	char file[LEN];//用来存放文件名

	file[LEN - 1] = '\0';

	char ch;

	long now = 0L;//文件指针指示器

	printf_s("Please enter the file name:\n");

	scanf_s("%s", file, (unsigned)_countof(file));//从键盘读入文件名

	if (fopen_s(&fp, file, "rb+") != 0)

	{

		fprintf_s(stderr, "Can't open %s file.", file);

		exit(EXIT_FAILURE);

	}//打开文件失败失败时退出

	while ((ch = getc(fp)) != EOF)//以读到文件结尾为条件，每次从文件读入一个字符

	{

		if ((now = ftell(fp)) > 0)

			//为了防止指针越界，设置now来显示当前位置距离与文件头的字节数

			fseek(fp, -1L, SEEK_CUR);

		//每读一个字符，fp会指向下一位，所以用fseek使文件指针返回当前位置的前一位

		putc(toupper(ch), fp);//在文件指针fp当前的位置输出大写字符
		fflush(fp);
	}

	if (fp != 0)

		fclose(fp);

	return 0;

}