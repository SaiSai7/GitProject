# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"



// 01 char*�������������״�ģ�ͷ���
void copy_str(char *p1,char *p2)
{
	
	//if (*p1=='\0'||*p2=='\0')// ����д��
	if (p1 == NULL || p2 == NULL)
	{
		printf("func copy_str()::err\n");
		return;
	}
	while (*p2++ = *p1++)
	{
		;
	}

}
void main01()
{
	//char p[1024] = {0};
	char *p = {0}; // char *p = NULL;��char*p = {0}һ����˼
	char to[100];
	copy_str(p,to);

	// 02 Խ�磬��C�����У������ڣ��ַ����������ͣ�����ͨ���ַ�����ȥģ���ַ�����C�����ַ����ԡ�\0����β�ı�־�����Ӧ��char buf[3] = "abc";��Ϊchar buf[4] = "abc";
	//char buf[3] = "abc";


	printf("hello...\n");
	system("pause");
}




//03 �����޸�ָ�������ֵ��������day0207-�ַ�������������

void main02()
{

	system("pause");

}


