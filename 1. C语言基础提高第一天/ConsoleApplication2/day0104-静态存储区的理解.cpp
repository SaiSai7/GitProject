#include "stdio.h"
#include "stdlib.h"
#include "string.h"


char *GetStr1()
{
	char *p1 = "abcdefg";
	return p1;
}

char *GetStr2()
{
	char *p2 = "abcdefg1";
	return p2;
}

void main05()
{
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = GetStr1();
	p2 = GetStr2();

	printf("%s  %s\n",p1, p2);
	printf("%d  %d\n",p1, p2);

	printf("hello...\n");
	system("pause");

}