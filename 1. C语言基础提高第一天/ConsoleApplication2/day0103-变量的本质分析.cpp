#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void main04()
{
	int a;
	a = 10; //ֱ���޸�
	 
	printf("a:%d ",a);

	int *p = &a;
	printf("&a:%d\n ",&a);


	*p = 100;               //����޸�
	printf("a:%d\n ",a);


	printf("hello...\n");
	system("pause");
}