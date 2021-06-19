# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"



// 通过返回值的方式，分配内存，和赋值
char ** GetMemo01(int num)
{
	int i = 0;
	char ** p = NULL;
	p = (char**)malloc(sizeof(char*)*num);
	if (p == NULL)
	{
		printf("func GetMemo():分配内存失败\n ");
	
	}

	for ( i = 0; i < num; i++)
	{
		p[i] = (char*)malloc(sizeof(char)*num);
		sprintf(p[i],"%d%d%d",i+1,i+1,i+1);
	}
	return p;
}

// 通过间接赋值的方式，分配内存
int GetMemo02(char ***p,int num)
{
	int ret = 0;
	int i = 0;
	char **tep = NULL;
	if (p ==NULL)
	{
		ret = -1;
		return ret;

	}

	tep = (char **)malloc(sizeof(char *)*num);
	if (tep == NULL)
	{
		ret = -2;
		return  ret;
	}

	for ( i = 0; i < num; i++)
	{
		tep[i] = (char*)malloc(sizeof(char)*10);
		sprintf(tep[i],"%d%d%d",i+1,i+1,i+1);
	}
	*p = tep;

	return ret;
}


// 打印
void PrintStr(char **p, int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",p[i]);
	}
}

// 排序
void SortStr(char **p,int num)
{
	int i,j = 0;
	char *tep = NULL;
	for ( i = 0; i < num; i++)
	{
		for ( j = i+1; j < num; j++)
		{
			if (strcmp(p[i],p[j])<0)
			{
				tep = p[i];
				p[i] = p[j];
				p[j] = tep;

			}


		}
	}


}

// 释放内存  还有野指针存在
int Str_Free(char **p ,int num)
{
	int i = 0;
	if (p ==NULL)
	{
		return -1;
	}
	for ( i = 0; i < num; i++) // 一维指针，置NULL
	{
		free(p[i]);
		p[i] = NULL;
	}
	if (p !=NULL)  // 释放了二维指针所指向的内存空间，但并未将二维指针变量置为NULL,有野指针存在
	{
		free(p);

	}
}

// 释放内存，将主函数中二级指针p1重新置为NULL，可避免野指针出现
void Strmemo_Free(char ***p,int num)
{
	int i = 0;
	char **tep = NULL;
	if (p ==NULL)
	{
		return ;

	}
	tep = *p;
	for ( i = 0; i < num; i++) // 释放一维指针 所指向的内存空间
	{
		free(tep[i]);
	}
	free(tep);      // 释放二维指针，所指向的内存空间

	*p = NULL;     // 一次性将 一维指针变量和二维指针变量全部置为NULL

}


void main16()
{
	char **p1 = NULL;
	int num = 6;
	//p1 = GetMemo01(num);

	int ret = GetMemo02(&p1,num);

	PrintStr(p1,num);
	SortStr(p1,num);
	PrintStr(p1, num);
	Strmemo_Free(&p1,num);

	printf("hello...\n");
	system("pause");

}