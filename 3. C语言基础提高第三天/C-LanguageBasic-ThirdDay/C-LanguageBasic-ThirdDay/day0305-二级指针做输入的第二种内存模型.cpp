# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main10()
{
	int i,j = 0;
	char buf1[30];
	char tembuf[30];
	char buf2[10][30] = {"qqqqqq","tttttt","yyyyy","111111","222222","333333"};
	int num = 6;


	printf("����ǰ�����飺\n");
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",buf2[i]);
	}


	printf("����\n");
	for ( i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(buf2[i],buf2[j])>0)
			{
				strcpy(tembuf,buf2[i]); // �������ǣ�ָ��ָ����ڴ�ռ�
				strcpy(buf2[i],buf2[j]);
				strcpy(buf2[j], tembuf);
			}
		}

	}



	printf("���������飺\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\n", buf2[i]);
	}

	printf("hello...\n");
	system("pause");
}



// ��ӡ����
//����ı����ǣ�����ָ��������_��2���ڴ�ģ�� �� myArray + 1
// �����ָ��������_��1���ڴ�ģ��   myArray + 1 ��һ�� ��
//Ҳ��ָ��Ĳ�����һ��  ָ����ָ����ڴ�ռ�������಻һ�� ����������ˣ�PrintMyArray02_err(),�������ڶ���ָ��������_��2���ڴ�ģ�ʹ�ӡ��
void PrintMyArray02_err(char **myArray, int num)
{
	int i = 0;
	for (i = 0; i<num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));  //
	}
}
void PrintArray02(char buf[10][30], int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",buf[i]);
	}


}
void SortArray02(char buf[10][30],int num)
{
	int i, j = 0;
	char tembuf[30];
	for (i = 0; i < num; i++)
	{
		for ( j = i; j < num; j++)
		{
			if (strcmp(buf[i], buf[j])>0)
			{
				strcpy(tembuf, buf[i]); // �������ǣ�ָ��ָ����ڴ�ռ�
				strcpy(buf[i], buf[j]);
				strcpy(buf[j], tembuf);
			}
		}

	}


}


void main11()
{
	char buf2[10][30] = { "qqqqqq","tttttt","yyyyy","111111","222222","333333" };
	int num = 6;

	{//buf2�� ������ֻ����ģ���10�� ��ÿ��30�С�����������ʲô��buf2+1��������30����Ԫ  Ҳ����ά�������ı��ʣ�
		int len1 = sizeof(buf2); // 300���ֽ�

		int len2 = sizeof(buf2[0]);// 30��
		int size = len1 / len2;  // 10��
		printf("len1:%d\n",len1);
		printf("len2:%d\n", len2);
		printf("size:%d\n", size);
	
	
	}

	printf("����ǰ�����飺\n");
	PrintArray02(buf2,num);

	printf("����\n");
	SortArray02(buf2, num);

	printf("���������飺\n");
	PrintArray02(buf2, num);

	printf("hello...\n");
	system("pause");
}