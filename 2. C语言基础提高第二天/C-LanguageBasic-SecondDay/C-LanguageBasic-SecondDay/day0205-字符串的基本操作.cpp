# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// 一级指针的典型用法--本例子以字符串的基本操作为主
// 1. 数组
// 2. 字符串 
////////////字符串注意点/////////
// （1）C语言的字符串是以零结尾的字符串
// （2）C语言中没有字符串类型，通过字符数组来模拟字符串
// （3）字符串的内存分配：可以在栈上、可以在堆上、也可以在全局区。

// 字符数组，初始化
void main09()
{
	//1.指定长度，字符数组
	char buf1[100] = {'a','b','c','d'};//  后面的buf2[4]---buf[99] 会自动为0，这样可以看成以0结尾的字符串

	//char buf2[3] = {'a','b','c','d'};//如果初始化的元素个数大于分配元素的个数，会出现编译错误


	//2.不指定长度，字符数组
	char buf3[] = { 'a','b','c','d'};// buf3是一个数组， 不是一个C风格的字符串  不是一个以0 结尾的字符串


	printf("buf1:%s\n",buf1);
	printf("buf1:%d\n",buf1[40]);

	printf("buf3:%s\n",buf3);
	
	
	printf("hello...\n");
	system("pause");
}



// 用字符串，初始化字符数组
// strlen()函数用来测字符串的长度 其长度不包括字符串结尾\0
// sizeof() 操作符 用来测数据类型所占字节大小

void main10()
{
	char buf4[] = "abcdef";

	int len = strlen(buf4);//6     //buf4 作为字符数组 应该是7个字节 // 作为字符串 应该是6个字节

	int size = sizeof(buf4);// 7
	printf("buf4:%s\n",buf4);
	printf("buf4的长度：%d\n",len);
	printf("buf4所占内存大小：%d\n",size);

	char buf5[128] = "asdfgh";
	printf("buf5:%s\n",buf5);
	printf("buf5[100]:%d\n",buf5[100]);
	printf("hello...\n");
	system("pause");
}



// 通过数组下标 和指针
void main11()
{
	int i = 0;
	char *p = NULL;
	char buf6[128] = "asdfqwer";

	printf("buf6:");
	for (i = 0; i < strlen(buf6); i++)
	{
		printf("%c ", buf6[i]);
	}
	printf("\n");

	
	p = buf6; 	printf("buf6:");

	for (i = 0; i < strlen(buf6);i++)
	{
		printf("%c ",*(p+i));
	}
	printf("\n");


	printf("buf6:");
	for (i = 0; i < strlen(buf6);i++)
	{
		printf("%c ",*(buf6+i));
	}
	printf("\n");
	// 指针和内存首地址的区别
	// [] 和*p的作用是一样的，，只不过，[]更符合程序员的阅读习惯
	// []和*p也有一定的区别，buf6为数据首元素地址，在C和C++编译器中，为只读的指针常量
	// 因此，其不允许，buf6 = buf6 +i;类似这样的操作，而指针变量，就可以允许p=p+i这样的操作;




	printf("hello...\n");
	system("pause");
}