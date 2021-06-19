# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"



// 01 char*做函数参数，易错模型分析
void copy_str(char *p1,char *p2)
{
	
	//if (*p1=='\0'||*p2=='\0')// 错误写法
	if (p1 == NULL || p2 == NULL)
	{
		printf("func copy_str()::err\n");
		return;
	}
	while (*p2++ = *p1++)
	{
		;
	}

}
void main01()
{
	//char p[1024] = {0};
	char *p = {0}; // char *p = NULL;和char*p = {0}一个意思
	char to[100];
	copy_str(p,to);

	// 02 越界，在C语言中，不存在，字符串数据类型，往往通过字符数组去模拟字符串，C语言字符串以‘\0’结尾的标志，因此应将char buf[3] = "abc";改为char buf[4] = "abc";
	//char buf[3] = "abc";


	printf("hello...\n");
	system("pause");
}




//03 不断修改指针变量的值，见例子day0207-字符串做函数参数

void main02()
{

	system("pause");

}


