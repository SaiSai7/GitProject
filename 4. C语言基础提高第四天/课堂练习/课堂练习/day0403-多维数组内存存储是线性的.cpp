# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

void printArray(int *p,int num)
{
	int i, j = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
}
void main08()
{
	int i, j, temp = 1;
	int a[3][5];
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			a[i][j] = temp++;
		}
	}
	//�Ѷ�ά���� ����  1ά���� ����ӡ ֤�����Դ洢
	printArray((int*)a,15);
	printf("hello...\n");
	system("pause");
}