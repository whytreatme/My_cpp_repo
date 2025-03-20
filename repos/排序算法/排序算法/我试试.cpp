#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
  void sorting(int* arr, int num)
  {
	  int max;
	  for (int i=0;i<num;i++)
	  {
		  max = arr[i] > arr[i + 1] ? arr[i] : arr[i + 1];
	  }
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,9,10 };
	int num = 8;
	sorting(arr, num);
	for (int i = 0; i < num; ++i)
		printf("%d", arr[i]);

}