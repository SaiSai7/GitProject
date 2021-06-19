#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
# include "stdio.h"


//////////////////////////////////////////////////////////////////////////¶Ñ
char *GetMemo(int num)
{
	char *p = NULL;
	p = (char*)malloc(sizeof(char)*num);
	if (p == NULL)
	{
		return NULL;
	}
	return p;
}

//////////////////////////////////////////////////////////////////////////-Õ»
char *GetMemo2()
{
	char buf[64];
	strcpy(buf,"123456778");
	printf("buf:%s\n",buf);
	return buf;
}
void main06()
{
	char *temp = NULL;
	temp = GetMemo(12);
	if (temp == NULL)
	{
		return;
	}

	strcpy(temp,"abcdefgh123456789");
	printf("temp:%s\n",temp);

	temp = GetMemo2();
	printf("temp:%s\n",temp);

	printf("hello...\n");
	system("pause");
}