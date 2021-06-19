# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// 结构体中嵌入一级指针

// 定义结构体
typedef struct Student
{
	char name[64]; // 已分配内存
	char *ph;    // 未分配内存，指针变量和它所指向的内存空间的变量是不同概念
	int age; //已分配内存
	char id; //已分配内存

}Student;

// 给结构体变量分配内存空间
int Get_Memo(Student **psd,int num)
{
	int i = 0;
	Student *pp = NULL;
	pp = (Student *)malloc(num *sizeof(Student));
	if (pp == NULL)
	{
		return -1;
	}
	memset(pp, 0, num *sizeof(Student));
	for ( i = 0; i < num; i++)  //进行char *ph; 的内存分配
	{
		pp[i].ph = (char *)malloc(60);
	}
	*psd = pp;
	return 0;
}

// 手动赋值
void Get_Value(Student *pp,int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("请输入年龄：\n");
		scanf("%d",&pp[i].age);

		printf("请输入姓名：\n");
		scanf("%s", pp[i].name);

		printf("请输入ph：\n");
		scanf("%s", pp[i].ph);
	}

}

// 打印
void printStudent(Student *p,int num)
{

	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%d  ",p[i].age);
	}
	printf("\n");
}

// 排序
void SortStd_age(Student *p, int num)
{
	int i = 0, j = 0;
	Student stu = {0};
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

void Memo_Free(Student *p,int num)
{
	int i = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (p[i].ph != NULL)
		{
			free(p[i].ph);
		}
		
	}
	free(p);
}




int main17()
{
	int ret = 0,i = 0;
	int num = 3;
	Student *sd = NULL;

	// 分配内存
	ret = Get_Memo(&sd, num);

	if (ret != 0)
	{
		printf("func  Get_Memo():: %d erro \n",ret);
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

	Memo_Free(sd,num);

	printf("hello...\n");
	system("pause");
}