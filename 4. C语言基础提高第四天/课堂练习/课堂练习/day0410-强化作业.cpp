# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// 对结构体变量中，name字符串进行赋值、排序、打印
// 定义结构体变量
typedef struct Manager
{
	char name[64] = {0};   // 编译器已分配好内存
	char *alias;    // 待分配内存
	char **empname;  // 待分配内存
	int age;
	char id;
}Manager;

// 分配内存
int  Get_MgMemo(Manager **m/*out*/, int num)
{
	Manager *myp = NULL;
	if (m == NULL)
	{
		return -1;
	}
	myp = (Manager*)malloc(num*sizeof(Manager));
	if (myp == NULL)
	{
		return -1;
	}
	*m = myp;
	return 0;
}


void main0000000()
{
	int ret = 0; int i = 0, j = 0;
	int num = 3;
	Manager *mg = NULL;

	Manager tem;

	ret = Get_MgMemo(&mg, num);

	for ( i = 0; i < num; i++)
	{
		printf("请输入名字:\n");
		scanf("%s",mg[i].name);
	}
	printf("未排序打印：\n");
	for ( i = 0; i < num; i++)
	{
		printf("%s  ",mg[i].name);
	}
	printf("\n");

	for ( i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(mg[i].name, mg[j].name)>0)
			{
				tem = mg[i];
				mg[i] = mg[j];
				mg[j] = tem;
			}
		}
	}
	printf("排序后打印：\n");
	for (i = 0; i < num; i++)
	{
		printf("%s  ", mg[i].name);
	}
	printf("\n");

	printf("hello...\n");
	system("pause");
}