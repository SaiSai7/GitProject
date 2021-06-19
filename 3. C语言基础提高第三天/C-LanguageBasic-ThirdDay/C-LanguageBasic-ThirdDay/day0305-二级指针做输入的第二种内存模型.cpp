# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main10()
{
	int i,j = 0;
	char buf1[30];
	char tembuf[30];
	char buf2[10][30] = {"qqqqqq","tttttt","yyyyy","111111","222222","333333"};
	int num = 6;


	printf("排序前的数组：\n");
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",buf2[i]);
	}


	printf("排序：\n");
	for ( i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(buf2[i],buf2[j])>0)
			{
				strcpy(tembuf,buf2[i]); // 交换的是，指针指向的内存空间
				strcpy(buf2[i],buf2[j]);
				strcpy(buf2[j], tembuf);
			}
		}

	}



	printf("排序后的数组：\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\n", buf2[i]);
	}

	printf("hello...\n");
	system("pause");
}



// 打印数组
//问题的本质是：二级指针做输入_第2种内存模型 的 myArray + 1
// 与二级指针做输入_第1种内存模型   myArray + 1 不一样 ；
//也即指针的步长不一样  指针所指向的内存空间的数据类不一样 。。。。因此，PrintMyArray02_err(),不能用于二级指针做输入_第2种内存模型打印，
void PrintMyArray02_err(char **myArray, int num)
{
	int i = 0;
	for (i = 0; i<num; i++)
	{
		//printf("%s \n", myArray[i]);
		printf("%s \n", *(myArray + i));  //
	}
}
void PrintArray02(char buf[10][30], int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",buf[i]);
	}


}
void SortArray02(char buf[10][30],int num)
{
	int i, j = 0;
	char tembuf[30];
	for (i = 0; i < num; i++)
	{
		for ( j = i; j < num; j++)
		{
			if (strcmp(buf[i], buf[j])>0)
			{
				strcpy(tembuf, buf[i]); // 交换的是，指针指向的内存空间
				strcpy(buf[i], buf[j]);
				strcpy(buf[j], tembuf);
			}
		}

	}


}


void main11()
{
	char buf2[10][30] = { "qqqqqq","tttttt","yyyyy","111111","222222","333333" };
	int num = 6;

	{//buf2： 编译器只会关心：有10行 ，每行30列。。。。。干什么？buf2+1会往后跳30个单元  也即多维数组名的本质，
		int len1 = sizeof(buf2); // 300个字节

		int len2 = sizeof(buf2[0]);// 30列
		int size = len1 / len2;  // 10行
		printf("len1:%d\n",len1);
		printf("len2:%d\n", len2);
		printf("size:%d\n", size);
	
	
	}

	printf("排序前的数组：\n");
	PrintArray02(buf2,num);

	printf("排序：\n");
	SortArray02(buf2, num);

	printf("排序后的数组：\n");
	PrintArray02(buf2, num);

	printf("hello...\n");
	system("pause");
}