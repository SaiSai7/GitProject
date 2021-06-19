# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"




void main08()
{
	int i = 0;
	int j = 0;
	int num = 0;

	// 数组，数组中的每个元素，都为指针，也即指针数组
	char *arry[] = {"aaaaaa","llllll","222222","hhhhhh","zzzzzz"};

	num = sizeof(arry) / sizeof(arry[0]); // 指针数组元素个数

	printf("排序之前的数组:\n");
	for ( i = 0; i < num; i++)
	{
		//printf("%s \n",arry[i]);
		printf("%s \n", *(arry+i));

	}
	printf("排序：\n");
	for ( i = 0; i <num; i++)
	{
		for ( j = i; j < num; j++)
		{
			if (strcmp(arry[i],arry[j])>0)
			{

				char *tep = arry[i];// 此处，交换的是数组元素指针的值
				arry[i] = arry[j];
				arry[j] = tep;
			}
		}

	}
	printf("排序之后的数组:\n");
	for (i = 0; i < num; i++)
	{
		//printf("%s \n",arry[i]);
		printf("%s \n", *(arry + i));

	}
	printf("hello...\n");
	system("pause");
}

void PrintArry01(char **p, int num)
{
	int i = 0;

	for (i = 0; i < num; i++)
	{
		printf("%s \n",p[i]);

	}

}

void SortArray01(char **p,int num)
{
	int i, j = 0;
	for ( i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			if (strcmp(p[i],p[j])>0)
			{
				char *temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}

}



void main09()
{
	int i = 0;
	int j = 0;
	int num = 0;

	// 数组，数组中的每个元素，都为指针，也即指针数组
	char *array[] = { "aaaaaa","llllll","222222","hhhhhh","zzzzzz" };

	num = sizeof(array) / sizeof(array[0]); // 指针数组元素个数

	printf("排序之前的数组:\n");
	PrintArry01(array,num);

	printf("排序:\n");
	SortArray01(array, num);

	printf("排序之后的数组:\n");
	PrintArry01(array, num);

	printf("hello...\n");
	system("pause");
}