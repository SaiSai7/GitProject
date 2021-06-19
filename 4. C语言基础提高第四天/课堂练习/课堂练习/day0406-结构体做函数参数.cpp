# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"



typedef struct Teather
{
	int age;
	char name[64];
	char id;

}Teather;


// 打印
void printTh1(Teather *p1,int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ",p1[i].age);
	}

}


// 排序
void SortTh1(Teather *p2, int num)
{
	int i = 0, j = 0;
	Teather mp;
	for ( i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (p2[i].age > p2[j].age)
			{
				mp = p2[i];
				p2[i] = p2[j];
				p2[j] = mp;
			}
		}
	}

}

//在堆上分配内存
Teather *CreatMemo(int num)
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


// 释放内存
void Free_Memo(Teather *p3)
{
	if (p3!=NULL)
	{
		free(p3);
	}

}




// 在栈上分配内存
void main14()
{
	int i = 0, j = 0;
	Teather t1[6] = { NULL };// 在栈上分配内存
	int num = 6;
	Teather t2;


	for (i = 0; i < num; i++)
	{
		printf("请输入年龄：");
		scanf("%d", &t1[i].age);//输入一个数，并将这个整数放到数组ti的第i个地址上去，简言之就是输入数组t1的第i个值 
		//scanf("%d", &a[i]);
	}
	printf("输入的年龄为：\n");  
	//for (i = 0; i < num; i++)// 打印
	//{
	//	
	//	printf("%d  ", t1[i].age);
	//	//printf("%d ", a[i]);
	//}
	printTh1(t1,num);
	// 按照年龄大小进行排序
	//for (i = 0; i < num; i++)
	//{
	//	for (j = i+1; j < num; j++)
	//	{
	//		if (t1[i].age > t1[j].age)
	//		{
	//			t2 = t1[i];
	//			t1[i] = t1[j];
	//			t1[j] = t2;

	//		}
	//	}
	//}
	SortTh1(t1, num);

	//排序后打印
	printf("\n---------------------------\n");
	for (i = 0; i < num; i++)// 打印
	{

		printf("%d  ", t1[i].age);
		//printf("%d ", a[i]);
	}
	printf("\nhello...\n");
	system("pause");
}






// 在堆上分配内存
void main15()
{
	int i = 0, j = 0;
	Teather *t1 = NULL;// 在栈上分配内存
	int num = 3;

	t1 = CreatMemo(num); // 在被调用函数中，通过在堆上分配内存



	for (i = 0; i < num; i++)
	{
		printf("请输入年龄：");
		scanf("%d", &t1[i].age);//输入一个数，并将这个整数放到数组ti的第i个地址上去，简言之就是输入数组t1的第i个值 
								//scanf("%d", &a[i]);
	}
	printf("输入的年龄为：\n");
	printTh1(t1, num);
	
	SortTh1(t1, num);

	printf("\n年龄排序后打印：\n");
	printTh1(t1, num);

	Free_Memo(t1);

	printf("\nhello...\n");
	system("pause");
}