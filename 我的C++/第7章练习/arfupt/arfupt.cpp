// arfupt.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
	using namespace std;

	double av[3] = { 1112.3,1542.6,2227.9 };

	//pointer to a function
	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2; //C++11 automatic type deduction
	//pre-C++11 can use the following code instead
	//const double * (*p2)(const double*, int) = f2
	cout << "Using pointers to functions:\n";
	cout << "Address Value\n";
	cout << (*p1)(av, 3)<<": "<<*(*p1)(av,3)<<endl;
	cout << p2(av, 3)<<": "<<*p2(av,3)<<endl;
	//auto doesn't work with list initialization
	const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
	//but it does work for initializing to a single value
	//pb a pointer to first element of pa
	auto pb = pa;
	//pre-C++11 can use the following code instead
	// const double* (**pb)(const double*,int) = pa;
	cout << "\nUsing an array of a pointer to a function:\n";
	cout << " Address Value\n";

	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	
	cout << "\nUsing a pointer to a pointer to a function:\n";
	cout << " Address Value\n";

	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3)<<endl;

	// what about a pointer to an array of function pointers
	cout << "\nUsing pointers to an array of function pointers:\n";
	cout << " Address Value\n";
	//easy way to declare pc
	auto pc = &pa;
	//pre-C++11 can use the following code instead
	//const double* (*(*pc)[3])(const double*, int) = &pa;
	 cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	//hard way to declare pd
	const double* (*(*pd)[3])(const double*, int) = &pa;
	//store return value in pb
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;
	//alternative notation
	 cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;;
}

const double* f1(const double* ar, int n)
{
	return ar;
}

const double* f2(const double ar[], int n)
{
	return ar + 1;
}

const double* f3(const double ar[], int n)
{
	return ar + 2; 
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
