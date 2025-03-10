#include<stdio.h>
#include<stdlib.h>
void sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		t = array[k]; array[k] = array[i]; array[i] = t;
	}
}


int main()
{
	int a[6], i, k, s;
	printf("please input k:");
	scanf_s("%d", &k);
	for (i = 0; i < 5; i++)
	{
		printf("please input a£º");
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < 5; i++)
	{
		if (a[i] == k)
		{
			printf("exist");
			break;
		}
		else s = 0;
	}
	if (s == 0)
	{
		a[5] = k;
		sort(a, 6);
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d\n", a[i]);

	}
}
