# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main12()
{
	char buf1[20] = "aaaa"; // ��ȫ���������ڴ棬Ȼ��copy����ʱ��buf1
	char buf2[] = "bbbb";
	char *p1 = "1111111";
	char *p2 = (char*)malloc(100);
	strcpy(p2,"222222");
	
	printf("hello...\n");
	system("pause");
}