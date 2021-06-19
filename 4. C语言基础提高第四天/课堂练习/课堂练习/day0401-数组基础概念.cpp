# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

// 数组名的技术盲点
// 1）数组首元素的地址和数组地址是两个不同的概念
// 2）数组名代表数组首元素的地址，它是个常量。
// 解释如下：变量本质是内存空间的别名，一定义数组，就分配内存，
// 内存就固定了。所以数组名起名以后就不能被修改了。
// 3）数组首元素的地址和数组的地址值相等




void main01()
{
	int a[] = {1,2,3};// 未指定长度初始化
	int b[10] = {1,2,3,4,5}; //指定长度初始化

	int c[100] = { 0 }; //编译器在编译（静态编译）时，已经确定所有的元素为0


	memset(c,0,sizeof(c)); // 显式的重置内存块（手工操作）

	// 对于一维数组，C规定：数组名c代表数组首元素的地址，&c为整个数组的地址值
	printf("得到整个数组的地址 c: %d \n", &c); // 这样的c+1步长为，100*4个字节
	printf("数组的首元素的地址 c: %d \n", c);   // 这样的c+1步长为 4个字节

	printf("hello...\n");
	system("pause");
}

// 怎么样表达 int a[10]这种数据类型呢？至少需要把数据类型（int、char、float等）和中括号 []   ，int [],

// 如何表达数组类型，数组类型分为基础和非基础的，如何去定义一个数组类型
//? C 语言中的数组有自己特定的类型
//? 数组的类型由元素类型和数组大小共同决定
//? 例：int array[5]的类型为 int[5]
void main02()
{
	// 数组类型的定义
	typedef int(MYARRAY6)[6]; // 定义了一个数据类型---数组数据类型
	MYARRAY6 m ;  // 等同于 int m[6];
	int i = 0;
	for ( i = 0; i < 6; i++)
	{
		m[i] = i;
	}

	for ( i = 0; i < 6; i++)
	{
		printf("%d ",m[i]);
	}
	printf("\n");
	printf("m代表数组首元素地址 m:%d  m+1:%d \n",m,m+1);
	printf("&m代表整个数组的地址：&m:%d  &m+1:%d \n", &m, &m + 1);
	printf("hello...\n");
	system("pause");
}


// 定义数组指针--通过定义指针变量的方式实现（用数组类型 + * 的方式来定义 ）
void main03()
{
	int i = 0;
	char *p[] = { "111111","aaaaaa","222222","bbbbbb","333333" };// 指针数组

	// 数组指针，用一个指针来指向一个数组
	typedef int(MYARRAY6)[6]; // 定义了一个数据类型---数组数据类型
	MYARRAY6 m;  // 等同于 int m[6]; 用数组类型定义的一个变量
	MYARRAY6 *mp; // 用数组类型，定义了一个数组指针 ，可用该变量指向一个MYARRAY6数组类型变量
	

	{
		int a = 0;
		int *p = NULL;
		p = &a;
	
	}
	{
		mp = &m;    // 同p = &a;一样的道理
		int array[6];         // 相当于一级指针
		mp = &array; //（相当于二级指针） 可以用mp指针变量操作，int array[6];这个内存空间,如下
		for ( i = 0; i < 6; i++)
		{
			//array[i] = i + 1;或者(*mp)[i] = i + 1;
			(*mp)[i] = i + 1;
		}
		for ( i = 0; i < 6; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
		

		for (i = 0; i < 6; i++)
		{
			printf("%d",(*mp)[i]);
		}
		printf("\n");

	
	}


	printf("hello...\n");
	system("pause");
}


// 定义数组指针变量的第二种方法
void main04()
{
	int i = 0;
	// 直接声明一个数组指针类型
	typedef int (*MYArray)[6];
	MYArray mp;

	int c[6];

	mp = &c;
	for ( i = 0; i < 6; i++)
	{
		(*mp)[i] = i + 1;
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d ",(*mp)[i]);
	}
	printf("\n");

	printf("hello...\n");
	system("pause");
}


// 定义数组指针变量的第三种方法,
// 前2种方法 通过类型定义变量 比较麻烦
void main05()
{
	int i = 0;
	
	int(*MYArray)[6]; //直接定义一个指向数组的 数组指针变量

	int c[6];

	MYArray = &c;
	for (i = 0; i < 6; i++)
	{
		(*MYArray)[i] = i + 1;
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d ", (*MYArray)[i]);
	}
	printf("\n");

	printf("hello...\n");
	system("pause");
}