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

	// ���飬�����е�ÿ��Ԫ�أ���Ϊָ�룬Ҳ��ָ������
	char *arry[] = {"aaaaaa","llllll","222222","hhhhhh","zzzzzz"};

	num = sizeof(arry) / sizeof(arry[0]); // ָ������Ԫ�ظ���

	printf("����֮ǰ������:\n");
	for ( i = 0; i < num; i++)
	{
		//printf("%s \n",arry[i]);
		printf("%s \n", *(arry+i));

	}
	printf("����\n");
	for ( i = 0; i <num; i++)
	{
		for ( j = i; j < num; j++)
		{
			if (strcmp(arry[i],arry[j])>0)
			{

				char *tep = arry[i];// �˴���������������Ԫ��ָ���ֵ
				arry[i] = arry[j];
				arry[j] = tep;
			}
		}

	}
	printf("����֮�������:\n");
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

	// ���飬�����е�ÿ��Ԫ�أ���Ϊָ�룬Ҳ��ָ������
	char *array[] = { "aaaaaa","llllll","222222","hhhhhh","zzzzzz" };

	num = sizeof(array) / sizeof(array[0]); // ָ������Ԫ�ظ���

	printf("����֮ǰ������:\n");
	PrintArry01(array,num);

	printf("����:\n");
	SortArray01(array, num);

	printf("����֮�������:\n");
	PrintArry01(array, num);

	printf("hello...\n");
	system("pause");
}