# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main06()
{
	int a[3][5], i, j = 0;
	int temp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = temp++;
		}
	}
	for (i = 0; i < 3; i++) 
	{
		for (j = 0; j < 5; j++) 
		{
			printf("%d ", a[i][j]);
		}
	}
	printf("\n");

	// 多维数组名a，代表什么？
	printf("a:%d  a+1:%d\n", a, a + 1); // a+1的步长为20个字节，也即4*5,数组a[3][5],一行元素所占的内存大小，a+1每次跳一行
	printf("&a:%d  &a+1:%d", &a, &a + 1);

	// 为了验证多为数组名的本质，下面定义一个数组指针变量,通过将数组a[3][5]的数组名赋值给该指针变量，然后用该变量去操作a[3][5]，看是否可以操作
	int(*pMarray)[5];
	pMarray = a;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d  ", pMarray[i][j]);  // 测试结果表明，二维数组名的本质就是一个数组指针，指向一维数组的指针
		}
	}
	printf("\n");  

	// (a+i) 代表是整个第i行的地址  二级指针   // 整个第i行的地址和第i行首元素地址重合，只是其步长不一样
	// *(a+i) 代表 1级指针  第i行首元素的地址
	// *(a+i) + j  ===> &  a[i][j]

	//*( *(a+i) + j) ===>a[i][j]元素的值



	// 多维数组中的[][]和多级指针星号转化推演
	//a[i][j] <=== >*( *(a+i) + j)

	//a[i] ===> a[0+i] ==> *(a+i);

	//a[i][j] === a[0+i][j]  ==>  *(a+i)[j]  ===>  *(a+i)[0 + j] ==>  *( *(a+i)  + j) 


	printf("hello...\n");
	system("pause");
}


// 多维数组做函数参数的退化问题
void printArray01(int a[3][5]) // 最初的方法
{
	int i, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}


}
void printArray02(int a[][5]) // 数组名a实质上为指针数组，其指向多维数组的第一维数组可以挖掉一维维数，仅仅把指向传输过来
{
	int i, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}


}

void printArray03(int (*a)[5]) // a为数组指针,其指向数组首行 可以挖掉一维维数
{
	int i, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", a[i][j]);
		}
	}
}


void main07()
{
	int a[3][5], i, j = 0;
	int temp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a[i][j] = temp++;
		}

	}
	//for (i = 0; i < 3; i++)
	//{
	//	for (j = 0; j < 5; j++)
	//	{
	//		printf("%d ", a[i][j]);
	//	}
	//}
	//printArray01(a);
	//printArray02(a);
	printArray03(a);

	printf("hello...\n");
	system("pause");
}