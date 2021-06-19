# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main02()
{
	char *p1 = NULL;
	//p1 = 0x00000000;
	strcpy(p1,"abcdefgh"); // 此行代码会发生宕机，原因是，指针变量所指向的内存空间为null,也即没有分配内存，或者说p1所指向的内存空间为操作系统所保护的区域
	
	printf("hello...\n");
	system("pause");
}



// 不断改变指针的指向
void main03()
{
	char buf[128]; //在栈上分配内存
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

	p3 = (char*)malloc(100); // 在堆上分配内存
	strcpy(p3,"qwerasdfzxcvrtghbn");

	for ( i = 0; i < 19; i++)
	{
		p2 = p3 + i;
		printf("%c ",*p2);
	}


	printf("hello...\n");
	system("pause");
}