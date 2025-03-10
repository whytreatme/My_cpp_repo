// 知乎试试1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
int main(int argc, char* argv[])
{
	FILE* fp = NULL;
    fopen_s(&fp,"test.txt", "wb");
	if(fp!=0)
	fputs("123456", fp);
	fclose(fp);

	fopen_s(&fp,"test.txt", "ab+");
	if (fp != 0)
	{
		fseek(fp, 0, SEEK_SET);//设置读位置到文件开头
		putchar(fgetc(fp));//此时应该输出1 并且读写指针会指向2
		puts("");

		fseek(fp, 0, SEEK_CUR); //原地fseek
		fputs("999", fp);//写入999 如果读写位置一致 文件内容应该是 199956
		fflush(fp);
		fseek(fp, 0, SEEK_SET);//回到开头输出文件内容
		char str[64];
		puts(fgets(str, 64, fp)); //实际输出结果 123456999
	}
	fclose(fp);
	return 0;
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
