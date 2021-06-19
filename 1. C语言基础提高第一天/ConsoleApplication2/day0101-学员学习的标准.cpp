#include "stdio.h"
#include "string.h"
#include "stdlib.h"



void main01()
{
	int i = 0,j = 0;
	int temp = 0;
	int a[] = {11,99,3,8,22,6,5};

	//未排序的数组打印
	printf("打印数组：\n");
	for ( i = 0; i < 7; i++)
	{
		printf("%d ",a[i]);

	}
	//数组排序
	printf("数组排序：\n");
	for ( i = 0; i < 7; i++)
	{
		for ( j = i + 1; j < 7; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	//排序后数组打印
	printf("排序后数组打印：\n");
	for (i = 0; i < 7; i++)
	{
		printf("%d ",a[i]);
	}
	printf("hello...\n");
	system("pause");
}


void PrintAarry01(int a[1])
{
	int i = 0;
	for ( i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void PrintAarry02(int a[1],int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void PrintAarry03(int * a, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}





void SortArry01(int a[1])
{
	int i = 0, j = 0;
	int temp = 0;
	for ( i = 0; i < 7; i++)
	{
		for ( j = i + 1; j < 7; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

}

void SortArray02(int a[1],int num)
{
	int i = 0, j = 0;
	int temp = 0;
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void SortArray03(int * a, int num)
{
	int i = 0,j = 0;
	int temp = 0;
	for ( i = 0; i < num; i++)
	{
		for ( j = i + 1; j < num; j++)
		{
			if (a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

}


void main02()
{
	int num = 0;
	int a[] = { 11,99,3,8,22,6,5 };
	num = sizeof(a) / sizeof(a[0]);
	printf("printer array:\n");
	//PrintAarry01(a);
	//PrintAarry02(a,num);
	PrintAarry03(a,num);

	printf("数组排序：\n");
	
	//SortArry01(a);
	//SortArray02(a,num);
	 SortArray03(a,num);

	//再次打印数组
	//PrintAarry01(a);
	//PrintAarry02(a, num);
	PrintAarry03(a, num);

	printf("hello...\n");
	system("pause");
}