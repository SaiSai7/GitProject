# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main06()
{
	int a[3][5], i, j = 0;
	int temp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = temp++;
		}
	}
	for (i = 0; i < 3; i++) 
	{
		for (j = 0; j < 5; j++) 
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");

	// ��ά������a������ʲô��
	printf("a:%d  a+1:%d\n", a, a + 1); // a+1�Ĳ���Ϊ20���ֽڣ�Ҳ��4*5,����a[3][5],һ��Ԫ����ռ���ڴ��С��a+1ÿ����һ��
	printf("&a:%d  &a+1:%d", &a, &a + 1);

	// Ϊ����֤��Ϊ�������ı��ʣ����涨��һ������ָ�����,ͨ��������a[3][5]����������ֵ����ָ�������Ȼ���øñ���ȥ����a[3][5]�����Ƿ���Բ���
	int(*pMarray)[5];
	pMarray = a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d  ", pMarray[i][j]);  // ���Խ����������ά�������ı��ʾ���һ������ָ�룬ָ��һά�����ָ��
		}
	}
	printf("\n");  

	// (a+i) ������������i�еĵ�ַ  ����ָ��   // ������i�еĵ�ַ�͵�i����Ԫ�ص�ַ�غϣ�ֻ���䲽����һ��
	// *(a+i) ���� 1��ָ��  ��i����Ԫ�صĵ�ַ
	// *(a+i) + j  ===> &  a[i][j]

	//*( *(a+i) + j) ===>a[i][j]Ԫ�ص�ֵ



	// ��ά�����е�[][]�Ͷ༶ָ���Ǻ�ת������
	//a[i][j] <=== >*( *(a+i) + j)

	//a[i] ===> a[0+i] ==> *(a+i);

	//a[i][j] === a[0+i][j]  ==>  *(a+i)[j]  ===>  *(a+i)[0 + j] ==>  *( *(a+i)  + j) 


	printf("hello...\n");
	system("pause");
}


// ��ά�����������������˻�����
void printArray01(int a[3][5]) // ����ķ���
{
	int i, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}


}
void printArray02(int a[][5]) // ������aʵ����Ϊָ�����飬��ָ���ά����ĵ�һά��������ڵ�һάά����������ָ�������
{
	int i, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}


}

void printArray03(int (*a)[5]) // aΪ����ָ��,��ָ���������� �����ڵ�һάά��
{
	int i, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}


void main07()
{
	int a[3][5], i, j = 0;
	int temp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = temp++;
		}

	}
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 5; j++)
	//	{
	//		printf("%d ", a[i][j]);
	//	}
	//}
	//printArray01(a);
	//printArray02(a);
	printArray03(a);

	printf("hello...\n");
	system("pause");
}