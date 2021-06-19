# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


int GetMemo(char **str1,int *strlen1,char **str2,int *strlen2)
{
	int ret = 0;
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = (char*)malloc(100);
	if (p1 == NULL)
	{
		return ret = -1;
	}
	strcpy(p1, "abcdefghijk");
	*str1 = p1;
	*strlen1 = strlen(*str1);

	p2 = (char*)malloc(100);
	if (p2 == NULL)
	{
		return ret = -2;
	}
	strcpy(p2,"123456789");
	*str2 = p2;
	*strlen2 = strlen(*str2);

	return ret;
}

//手动释放堆上所分配的内存空间
int GetMemo_Free(char **str)
{
	int ret = 0;
	if (str ==NULL)
	{
		return ret = -1;
	}

	free(*str);
	*str = NULL;
	return ret;

}

// 对比案例，这样只是释放了，形参中char *str，所指向的内存空间，并不能避免野指针的出现
int GetMemo_Free11(char *str)// 就像想通过实参int a,传递给子函数中形参int b，在子函数中去修改a的值一样，无法对主函数中的a进行修改，修改的只是，形参b的值
{
	int ret = 0;
	if (str == NULL)
	{
		return ret = -1;
	}

	free(str);   // 将str所指向的内存空间，释放
	str = NULL; // 只是将形参中的str的指向修改成NULL,并不能将，主函数中的p1或p2的指向，修改成null
	return ret;
}


int main06()
{
	char *p1 = NULL;
	int len0 = 0;

	char *p2 = NULL;
	int len1 = 0;

	int ret = GetMemo(&p1,&len0,&p2,&len1);
	if (ret == -1)
	{
		printf("fun GetMemo()::第14行，p1在堆上分配内存时出错");
		return ret;
	}
	if (ret == -2)
	{
		printf("fun GetMemo()::第23行，p2在堆上分配内存时出错");
		return ret;
	}
	printf("p1:%s\n",p1);
	printf("len0:%d\n",len0);
	printf("p2:%s\n", p2);
	printf("len1:%d\n", len1);
	GetMemo_Free(&p1);   // 释放1级指针变量p1所指向的内存空间，并将p1指向设置为NULL,避免野指针的出现
	GetMemo_Free(&p2);

	printf("hello...\n");
	system("pause");
}


int main07()
{
	char *p1 = NULL;
	int len0 = 0;

	char *p2 = NULL;
	int len1 = 0;

	int ret = GetMemo(&p1, &len0, &p2, &len1);
	if (ret == -1)
	{
		printf("fun GetMemo()::第14行，p1在堆上分配内存时出错");
		return ret;
	}
	if (ret == -2)
	{
		printf("fun GetMemo()::第23行，p2在堆上分配内存时出错");
		return ret;
	}
	printf("p1:%s\n", p1);
	printf("len0:%d\n", len0);
	printf("p2:%s\n", p2);
	printf("len1:%d\n", len1);

	//if (p1 !=NULL)
	//{
	//	free(p1);
	//	p1 = NULL;
	//}
	//if (p2 != NULL)
	//{
	//	free(p2);
	//	p2 = NULL;
	//}

	GetMemo_Free11(p1); //这样操作，只是释放放，p1所指向的内存空间，但其并不能避免野指针的出现
	printf("p1:%s\n", p1); // 由于也指针现象，此行打印出的为乱码
	GetMemo_Free11(p2);



	printf("hello...\n");
	system("pause");
}




