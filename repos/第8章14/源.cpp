#include<stdio.h>
#include<stdlib.h>

int main()
{
	// void exchange(int*,int n);
	void sort(int*, int n1);
	int i,n,*p1;
	printf_s("enter how much nums you want:\n");
	scanf_s("%d", &n);
	p1 = (int*)malloc(n * sizeof(int));
	printf_s("Please enter the nums:");
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", (p1 + i));
	}
	//exchange(p1,n);
	sort(p1, n);
	free(p1);
}
/*void exchange(int* p, int n)
{
	int i=n-1;
	printf_s("The exchange order is:\n");
	for (; i >= 0; i--)
	{
		printf_s("%d ", *(p + i));
	}
}*/
void sort(int* p2, int n1)
{
	int i, h,temp;
	h =(int) (n1 - 1) / 2;
	for (i = 0; i <= h; i++)
	{
		temp = *(p2 + i);
		*(p2 + i) = *(p2 + n1 - 1 - i);
		*(p2 + n1 - 1 - i) = temp;
	}
	printf_s("The exchange order is:\n");
	for (i = 0; i < n1 ; i++)
	{
		printf_s("%d ", *(p2 + i));
	}
}
