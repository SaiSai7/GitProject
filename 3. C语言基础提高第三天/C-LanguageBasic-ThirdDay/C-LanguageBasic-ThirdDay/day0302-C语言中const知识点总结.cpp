# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main03()
{
	//��һ��const�ڶ�����˼һ�� ����һ����������,Ҳ���������ͳ���a,�� b�����ܱ��޸�
	const int a = 6;
	int const b = 12;


	const char *c; //c ��һ��ָ����������ָ��(��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�)
	char * const d = "qwer"; //�൱��char buf[100]; dָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸�
	
	const char * const e = " asdf"; //e һ��ָ�����εĳ�ָ�루ָ�������ָ����ڴ�ռ䣬�����ܱ��޸ģ�
	printf("hello...\n");
	system("pause");
}


void Getmeom01(const char* p)

{
	//p =(char *)0xa011;
	//p = (char *)0xa211;

	//p[1] = 'a';
	printf("p:%s\n",p);


}

void Getmeom02(char * const p)
{
	//p = (char *)0xa011;
	//p = (char *)0xa211;

	//p[1] = 'a'; 
	printf("p:%s\n", p);
}
void Getmeom03(const char * const p)
{
	//p = (char *)0xa011;
	//p = (char *)0xa211;

	//p[1] = 'a'; 
	printf("p:%s\n", p);
}

void main04()
{
	char *p1 = NULL;
	const char *p2 = "qazwsx";// p2��ָ����ڴ�ռ䲻�ܱ��޸ģ�����ָ�����p2���Ա��޸�

	char * const p3 = "qwertasdf";//(char*)malloc(100);//p3��ָ����ڴ�ռ���Ա��޸ģ�����ָ�����p3���ܱ��޸�
	
	const char * const p4 = NULL; // p4��ָ����ڴ�ռ��p4ָ��ָ�򣬶����ܱ��޸�

	//p2 = (char*)0xa011; //���Ա��޸�
	//*p2 = 'qw';   //���ܱ��޸�
	//p2[0] = 'a';  // ���ܱ��޸�
	printf("p2:%s\n",p2);
	Getmeom01(p2);

	//p3 = 0xa11; //���ܱ��޸�

	//p3[3] = 'a'; //  ���Ա��޸�
	printf("p3:%s\n", p3);

	//*p3 = 'd';
	//printf("p3:%s\n",p3);
	Getmeom02(p3);

	//p4 = (char*)0xa011; // ���ܱ��޸�
	//p4[1] = 'a';  // ���ܱ��޸�
	Getmeom03(p4);
	
	printf("hello...\n");
	system("pause");
}


void main002()
{

	const int a = 12;
	//a = 16; ���ܱ��޸�
	/*printf("a:%d\n",a);
	{
	   int *  p = (int *)&a;
		*p = 16;
	}
	printf("%d\n",a);*/
	

	printf("hello...\n");
	system("pause");
}