# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// 二级指针第一种内存模型和第二种内存模型中的数据 copy到二级指针第三种内存模型中。
// 分配内存并赋值
int GetMemo12_to_m3(char ** myp1/*in*/, int num1, char(*myp2)[20]/*in*/, int num2, char ***myp3/*out*/, int * num3)
{
	int i = 0, j = 0, k = 0;
	int tlen = 0;
	char **p3 = NULL;
	if (myp3 == NULL || myp1 == NULL || myp2 == NULL)
	{
		return -1;
	}
	p3 = (char **)malloc(sizeof(char*)*(num1 + num2));
	if (p3 == NULL)
	{
		return -2;
	}
	memset(p3, 0, sizeof(char*)*(num1 + num2));

	for (i = 0; i < num1; i++)
	{
		tlen = strlen(myp1[i]) + 1;
		p3[i] = (char *)malloc(sizeof(char)*tlen);
		if (p3[i] == NULL)
		{
			return -3;
		}
		strcpy(p3[i],myp1[i]);
	}

	for (j = 0; j < num2; j++,i++)
	{
		tlen = strlen(myp2[j]) + 1;
		p3[i] = (char *)malloc(sizeof(char)*tlen);
		if (p3[i] == NULL)
		{
			return -4;
		}
		strcpy(p3[i],myp2[j]);
	}
	*num3 = num1 + num2;
	*myp3 = p3;
	return 0;
}


//打印
void PrintString(char ** p, int num)
{
	int i = 0;
	for (size_t i = 0; i < num; i++)
	{
		printf("%s",p[i]);
		printf("\n");
	}
}


//排序
void SortString(char **p, int num)
{
	int i, j = 0;
	char *tep = NULL;
	for (size_t i = 0; i < num; i++)
	{
		for (j = i + 1; i < num; i++)
		{
			if (strcmp(p[i],p[j])>0)
			{
				tep = p[i];
				p[i] = p[j];
				p[j] = tep;
			}
		}
	}
}


// 释放内存
void Memo_FRee(char ***p,int num)
{
	int i = 0;
	char **myp = NULL;
	if (p == NULL)
	{
		return;
	}
	myp = *p;
	for ( i = 0; i < num; i++)
	{
		if (myp[i] != NULL)
		{
			free(myp[i]);
			myp[i] = NULL;
		}

	}
	free(myp);
	*p = NULL;
}

void main()
{
	int ret = 0; int i = 0;
	char *a[] = {"aaaaa","11111","bbbbbccc","2222333","ccccddddd"};
	char b[3][20] = {"wwwww","qqqqqqqqq","mmmmmmmm"};
	char **c = NULL;
	int len1 = sizeof(a) / sizeof(a[0]);
	int len2 = 3;
	int len3 = 0;


	ret = GetMemo12_to_m3(a, len1, b, len2, &c, &len3);
	if (ret != 0)
	{
		return;
	}

	printf("");
	PrintString(c,len3);
	SortString(c,len3);

	printf("\n");
	PrintString(c, len3);

	Memo_FRee(&c,len3);



	//for (i = 0; i < len3; i++)
	//{
	//	printf("%s",c[i]);
	//	printf("\n");
	//}




	printf("hello...\n");
	system("pause");
}




