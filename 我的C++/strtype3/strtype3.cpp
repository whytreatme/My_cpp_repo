// strtype3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>  //make string class available
#include<cstring>  //C-style string library


int main()
{
	using namespace std;

	char charr1[20];
	char charr2[20] = "jaquar";
	string str1;
	string str2="panther";

	//assignment for string objects and character arrays
	str1 = str2;    //copy str2 to str1
	strcpy_s(charr1, charr2);

	//appending for string objects and character arrays
	str1 += "paste";  //add paste to the end of str1
	strcat_s(charr1, "juice");

	//finding the length of a string objects and C-style string
	int len1 = str1.size();  //obtain length of str1
	int len2 = strlen(charr1);

	cout << "The string " << str1 << " contains" << len1 << " characters.\n";
	cout << "The string " << charr1 << " contains " << len2 << " characters.\n";
	/*The output shows that cout object can also print the C-style strings ,
	which are stored at arrays*/
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
