# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main12()
{
	int i,j = 0;
	int num = 6;
	char **p1 = NULL;
	char buf[100];
	
	p1 = (char**)malloc(sizeof(char*)*num);// 在堆上，分配6块(char*)类型的内存
	
	for (i = 0; i < num; i++)
	{
		p1[i] = (char *)malloc(sizeof(char)*100); // 相当于buf[100] //在堆上，再分配char类型的内存
		sprintf(p1[i],"%d%d%d",i+1,i+2,i+3); //把整数i+1 打印成一个字符串保存在s中。
	}

	// 打印排序之前数据
	printf("打印排序之前数据:\n");
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",p1[i]);
	}

	// 排序 :通过交换指针指向的方式，进行排序
	/*printf("排序：\n");
	for (i = 0; i < num; i++)
	{
		for ( j = i+1; j <num; j++)
		{
			if (strcmp(p1[i],p1[j])<0)
			{
				char *tep = p1[i];
				p1[i] = p1[j];
				p1[j] = tep;
			}
		}

	}*/
	// 排序：通过交换指针指向的内存块，进行排序
	for ( i = 0; i < num; i++)
	{
		for ( j = i+1; j < num; j++)
		{
			if (strcmp(p1[i],p1[j])<0)
			{
				strcpy(buf,p1[i]);
				strcpy(p1[i],p1[j]);
				strcpy(p1[j], buf);
			}

		}
	}
	printf("打印排序之后数据:\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\n", p1[i]);
	}

	// 释放内存1 
	for (size_t i = 0; i < num; i++)
	{
		if (p1[i]!=NULL)
		{
			free(p1[i]);
			p1[i] = NULL;
		}
	}

	//释放内存2
	if (p1 !=NULL)
	{
		free(p1);
		//p1 = NULL;
	}
	
	printf("hello...\n");
	system("pause");
}

// 分配内存，并赋值
char **getStr(int num)
{
	int i = 0;
	char **p2 = NULL;
	p2 = (char**)malloc(sizeof(char*)*num);

	for (i = 0; i < num; i++)
	{
		p2[i] = (char*)malloc(sizeof(char)*100);
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p2;
}

// 打印
void PrintfStr(char **p,int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",p[i]);
	}
}

// 排序 交换指针指向
void SortStr01(char **p,int num)
{
	int i, j = 0;
	char *q = NULL;
	for ( i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(p[i],p[j])>0)
			{
				q = p[i];
				p[i] = p[j];
				p[j] = q;
			}

		}
	}
}

// 排序 交换指针所指向的内存块
void SortStr02(char **p, int num)
{
	int i, j = 0;
	char buf[100];
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p[i], p[j])>0)
			{
				strcpy(buf,p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], buf);
			}

		}
	}


}

// 释放内存
void Memo_Free(char **p,int num)
{
	int i = 0;

	for ( i = 0; i < num; i++)
	{
		if (p[i]!=NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}

	if (p!=NULL)
	{
		free(p);
	}

	



}
void main13()
{
	int num = 6;
	char **p1 = NULL;

	//分配内存，并赋值
	p1 = getStr(num);  
	
	// 打印
	printf("排序前打印：\n");
	PrintfStr(p1,num);

	// 排序1
	//SortStr01(p1,num);
	// 排序2
	SortStr02(p1, num);

	// 打印
	printf("排序前打印：\n");
	PrintfStr(p1, num);

	// 释放内存
	Memo_Free(p1, num);

	system("pause");


}