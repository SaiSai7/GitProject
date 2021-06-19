# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main01()
{
	char *p1 = NULL;
	p1 = (char*)malloc(100);
	if (p1 == NULL)
	{
		return;
	}
	strcpy(p1,"qwerasdfzxcv");
	printf("p1:%s\n",p1);
	if (p1!=NULL)
	{
		free(p1);
		p1 = NULL; // 这样可以避免也指针的出现
	}

	if (p1 != NULL)
	{
		free(p1);	
	}


	printf("hello...\n");
	system("pause");
}