# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// 结构体中嵌入二级指针

// 定义结构体
typedef struct Teather
{
	char name[64]; // 已分配内存
	char *ph;    // 未分配内存，指针变量和它所指向的内存空间的变量是不同概念
	char **stname;   // 或者借助编译器分配的内存， char buf[10][30];
	int age; //已分配内存
	char id; //已分配内存

}Teather;

// 给结构体变量分配内存空间
int Get_Memo(Teather **psd, int num)
{
	int i = 0, j = 0;
	Teather *pp = NULL;

	pp = (Teather *)malloc(num *sizeof(Teather));
	if (pp == NULL)
	{
		return -1;
	}
	memset(pp, 0, num *sizeof(Teather));

	for (i = 0; i < num; i++)  
	{
		char **p = NULL;
		// 分配一维内存空间
		pp[i].ph = (char *)malloc(60);//进行char *ph; 的内存分配

		// 分配二维内存空间
		p = (char **)malloc(num * sizeof(char *)); 

		for (j = 0; j < num; j++)
		{
			p[j] = (char *)malloc(60);
		}
		pp[i].stname = p;

	}
	*psd = pp;
	return 0;
}

// 手动赋值
void Get_Value(Teather *pp, int num)
{
	int i = 0, j = 0;
	for (i = 0; i < num; i++)
	{
		printf("请输入年龄：\n");
		scanf("%d", &pp[i].age);

	/*	printf("请输入姓名：\n");
		scanf("%s", pp[i].name);*/

		printf("请输入ph：\n");
		scanf("%s", pp[i].ph);

		for (j = 0; j < num; j++)
		{
			printf("请输入学生姓名：\n");
			scanf("%s", pp[i].stname[j]);
		}
	}

}


// 打印
void printStudent(Teather *p, int num)
{

	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d  ", p[i].age);
	}
	printf("\n");
}

// 排序
void SortStd_age(Teather *p, int num)
{
	int i = 0, j = 0;
	Teather stu = { 0 };
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (p[i].age > p[j].age)
			{
				stu = p[i];
				p[i] = p[j];
				p[j] = stu;
			}
		}
	}

}


// 释放内存

void Memo_Free(Teather *p, int num)
{
	int i = 0, j = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		// 释放一级指针
		if (p[i].ph != NULL)
		{
			free(p[i].ph);
		}

		// 释放二级指针
		if (p[i].stname != NULL)
		{
			char **mp = p[i].stname;
			for (j = 0; j < num; j++)
			{
				free(mp[j]);
			}
			free(mp);
			p[i].stname = NULL;
		}

	}
	free(p);
}




int main121212121()
{
	int ret = 0, i = 0;
	int num = 3;
	Teather *sd = NULL;

	// 分配内存
	ret = Get_Memo(&sd, num);

	if (ret != 0)
	{
		printf("func  Get_Memo():: %d erro \n", ret);
		return ret;
	}
	//for (i = 0; i < 3; i++)
	//{
	//	printf("请输入年龄：\n");
	//	scanf("%s",&sd[i].age);

	//	printf("请输入姓名：\n");
	//	scanf("%s", sd[i].name); // 无需使用&符号，因为char name[64];数组名，本身就是一级指针

	//	printf("请输入ph：\n");
	//	scanf("%s", sd[i].ph);  // 此时无法，完成赋值，因为，结构体变量中，char *ph;未分配内存，必须分配内存
	//}

	//  赋值
	Get_Value(sd, num);

	printf("未排序前打印：\n");
	printStudent(sd, num);

	SortStd_age(sd, num);

	printf("排序后打印：\n");
	printStudent(sd, num);

	Memo_Free(sd, num);

	printf("hello...\n");
	system("pause");
}