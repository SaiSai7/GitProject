# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main081()
{

	int a = 12;
	char *p1 = (char*)100; //指针也是一种变量，占有内存空间，用来保存内存地址
	char *******p2 ;
	printf(" a:%d\n",a);
	printf("sizeof(a):%d sizeof(p1):%d sizeof(p2):%d\n ",sizeof(a), sizeof(p1), sizeof(p2)); //指针变量占4个字节


	// *p放在等号的左边,写内存
	int *p3 = NULL;
	p3 = &a;
	*p3 = 22;
	printf("a:%d\n",a);


	//*p放在等号的右边，读内存
	int b = 0;
	b = *p3;
	printf(" b:%d\n",b);

	//相当于不断改变指针的指向, 详细流程见其内存四区图
	char *p4 = NULL;
	p4 = (char*)malloc(100);
	p4 = (char*)malloc(150);


	printf("hello...\n");
	system("pause");
}







// 如果要去修改一个内存空间的值，必须确保，这个内存空间的值，可以被修改，如果空间的值不能被修改，若强行修改，则会出现宕机。

char *GetStr()
{
	char *p = NULL;
	p = "abcdefg";
	return p;
}



void main()
{

	char * pp = NULL;
	pp = GetStr();

	*(pp + 1) = 'c';
	printf("pp:%s\n",pp);
	system("pause");
	return;
}