# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main07()
{
	int a;
	int b;

	char buf[128];

	printf(" a:%d\n b:%d\n",&a, &b);//此处证明栈的开口方向是向下的
  
	printf("hello...\n");
	system("pause");
}