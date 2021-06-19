# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"



// 
typedef struct Teather
{
	int age;
	char name[64];
	char id;

}Teather;


// 打印
void printTh01(Teather *th1, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ", th1[i].age);
	}

}


// 排序
void SortTh01(Teather *th2, int num)
{
	int i = 0, j = 0;
	Teather mp;
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (th2[i].age > th2[j].age)
			{
				mp = th2[i];
				th2[i] = th2[j];
				th2[j] = mp;
			}
		}
	}

}

//在堆上分配内存
Teather *CreatMemo01(int num)
{
	Teather *p = NULL;
	int i = 0;
	p = (Teather *)malloc(sizeof(Teather) * num);
	if (p == NULL)
	{
		return NULL;
	}
	return p;
}


// 堆上分配内存优化
int CreatMemo02(Teather **th3,int num)
{
	Teather *p = NULL;
	int i = 0;
	p = (Teather *)malloc(sizeof(Teather) * num);
	if (p == NULL)
	{
		return -1;
	}
	*th3 = p;
	return 0;
}


// 释放内存
void Free_Memo00(Teather *p)
{
	if (p != NULL)
	{
		free(p);
	}

}

// 释放内存 youhua 
void Free_Memo01(Teather **p)
{
	Teather *tep = NULL;
	if (p == NULL)
	{
		return;
	}
	tep = *p;
	free(tep);
	*p = NULL;
}


int main0123()
{
	int i = 0, j = 0, ret = 0;
	Teather *t1 = { NULL };// 在栈上分配内存
	int num = 3;

	//t1 = CreatMemo01(num); // 在被调用函数中，通过在堆上分配内存
	ret = CreatMemo02(&t1, num);
	if (ret != 0)
	{
		printf("func  CreatMemo02():%d erro", ret);
		return ret;
	}
	



	for (i = 0; i < num; i++)
	{
		printf("请输入年龄：");
		scanf("%d", &t1[i].age);//输入一个数，并将这个整数放到数组ti的第i个地址上去，简言之就是输入数组t1的第i个值 
								//scanf("%d", &a[i]);
	}
	printf("输入的年龄为：\n");
	printTh01(t1, num);

	SortTh01(t1, num);

	printf("\n年龄排序后打印：\n");
	printTh01(t1, num);

	//Free_Memo00(t1);
	Free_Memo01(&t1);
	

	printf("\nhello...\n");
	system("pause");
}