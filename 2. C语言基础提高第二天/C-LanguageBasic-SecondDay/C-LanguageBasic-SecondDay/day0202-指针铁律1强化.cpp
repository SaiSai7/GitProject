# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main02()
{
	char *p1 = NULL;
	//p1 = 0x00000000;
	strcpy(p1,"abcdefgh"); // ���д���ᷢ��崻���ԭ���ǣ�ָ�������ָ����ڴ�ռ�Ϊnull,Ҳ��û�з����ڴ棬����˵p1��ָ����ڴ�ռ�Ϊ����ϵͳ������������
	
	printf("hello...\n");
	system("pause");
}



// ���ϸı�ָ���ָ��
void main03()
{
	char buf[128]; //��ջ�Ϸ����ڴ�
	int i, j = 0;

	char *p2 = NULL;
	char *p3 = NULL;
	
	p2 = &buf[0];
	p2 = &buf[1];
	p2 = &buf[2];
	p2 = &buf[3];

	for (i = 0; i < 10; i++)
	{
		p2 = &buf[i];
	}

	p3 = (char*)malloc(100); // �ڶ��Ϸ����ڴ�
	strcpy(p3,"qwerasdfzxcvrtghbn");

	for ( i = 0; i < 19; i++)
	{
		p2 = p3 + i;
		printf("%c ",*p2);
	}


	printf("hello...\n");
	system("pause");
}