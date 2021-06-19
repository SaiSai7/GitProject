# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main03()
{
	//第一个const第二个意思一样 代表一个常整形数,也即代表整型常量a,和 b，不能被修改
	const int a = 6;
	int const b = 12;


	const char *c; //c 是一个指向常整形数的指针(所指向的内存数据不能被修改，但是本身可以修改)
	char * const d = "qwer"; //相当于char buf[100]; d指针变量不能被修改，但是它所指向内存空间可以被修改
	
	const char * const e = " asdf"; //e 一个指向常整形的常指针（指针和它所指向的内存空间，均不能被修改）
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
	const char *p2 = "qazwsx";// p2所指向的内存空间不能被修改，但是指针变量p2可以被修改

	char * const p3 = "qwertasdf";//(char*)malloc(100);//p3所指向的内存空间可以被修改，但是指针变量p3不能被修改
	
	const char * const p4 = NULL; // p4所指向的内存空间和p4指针指向，都不能被修改

	//p2 = (char*)0xa011; //可以被修改
	//*p2 = 'qw';   //不能被修改
	//p2[0] = 'a';  // 不能被修改
	printf("p2:%s\n",p2);
	Getmeom01(p2);

	//p3 = 0xa11; //不能被修改

	//p3[3] = 'a'; //  可以被修改
	printf("p3:%s\n", p3);

	//*p3 = 'd';
	//printf("p3:%s\n",p3);
	Getmeom02(p3);

	//p4 = (char*)0xa011; // 不能被修改
	//p4[1] = 'a';  // 不能被修改
	Getmeom03(p4);
	
	printf("hello...\n");
	system("pause");
}


void main002()
{

	const int a = 12;
	//a = 16; 不能被修改
	/*printf("a:%d\n",a);
	{
	   int *  p = (int *)&a;
		*p = 16;
	}
	printf("%d\n",a);*/
	

	printf("hello...\n");
	system("pause");
}