# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// 间接赋值从0级指针到1级指针
void GetFileLen01(int *p2)
{
	*p2 = 42;
}

int GetFileLen02()
{
	int b = 52;
	return b;
}

int GetFileLen03(int c)
{
	c = 62;
	return c;
}


void main04()
{
	int a = 12;
	int *p1 = NULL;

	// 直接赋值
	a = 22;
	printf("直接赋值a:%d\n",a);

	// 间接赋值
	p1 = &a;
	*p1 = 32;
	printf("间接赋值a:%d\n",a);

	//通过函数去完成间接赋值(一级指针)
	GetFileLen01(&a);
	printf("函数赋值a:%d\n",a);

	// 通过函数返回值的形式赋值
	a = GetFileLen02();
	printf("函数赋值a:%d\n",a);

	GetFileLen03(a);
	printf("a:%d\n",a);
	
	printf("hello...\n");
	system("pause");
}





// 间接赋值从1级指针到2级指针

void GeMemo(char ** pp)
{
	*pp = (char*)2222;

}

void GeMemo02(char *p)
{
	// *p = 3333;  // 不能这样操作，因为*p所指向的内存空间未分配
	p = (char*)3333;
	printf("&p:%d\n",p);
}
void main05()
{
	char *p1 = NULL;// NULL即为0
	char **p2 = NULL;
	printf("&p1:%d\n",p1);
	printf("&p1:%s\n", p1);  //null为操作系统保护的内存区域，不能被修改，只有手动分配内存后，才能被修改使用

	// 直接赋值,改变指针指向
	p1 = (char*)11;
	p2 = (char**)111;
	printf("直接修改后p1的值：\n");
	printf("&p1:%d\n",p1);//打印指针p1十进制的地址编号
	//printf("&p1:%s\n", p1);

	// 间接赋值，改变指针指向
	p2 = &p1;
	*p2 = (char*)1111;
	printf("&p1:%d\n",p1);//打印指针p1十进制的地址编号

	{

		// 间接赋值，再次改变指针指向
		*p2 = (char*)2111;
		printf("&p1:%d\n",p1);
		//将间接赋值的应用场景，提取成函数
	}
	GeMemo(p2);//通过被调用函数，间接的修稿p1的值
	printf("&p1:%d\n",p1);

	// 这样操作不能修改指针变量p1的指向，改变的只是形参参数p的指向
	GeMemo02(p1);
	printf("&p1:%d\n",p1);

	printf("hello...\n");
	system("pause");

}



int Getmemo03(char **p7,int *mylen1,char **p8,int *mylen2)
{
	int ret = 0;
	char *temp1, *temp2;

	temp1 = (char*)malloc(100);
	strcpy(temp1,"abcdefghijklmn");

	*mylen1 = strlen(temp1);
	*p7 = temp1;

	temp2 = (char*)malloc(100);
	strcpy(temp2,"qwerasdfzxcvtyghbn");

	*mylen2 = strlen(temp2);
	*p8 = temp2;

	return ret;

}

int main06()
{
	int ret = 0;
	char *p5 = NULL;
	int len1 = 0;
	char *p6 = NULL;
	int len2 = 0;

	ret = Getmemo03(&p5, &len1, &p6, &len2);
	if (ret != 0)
	{
		printf("function:Getmemo03():erro %d\n",ret);
		//return ret;
		system("pause");
	}
	printf("p5:%s len1:%d\n",p5,len1);
	printf("p6:%s len2:%d\n",p6,len2);

	if (p5 != NULL)
	{
		free(p5);
		p5 = NULL;
	}

	if (p6 != NULL)
	{
		free(p6);
		p6 = NULL;
	}


	printf("hello...\n");
	system("pause");

	return ret;

}


// 间接赋值成立的条件与应用场景

void main07()
{
	char from[128];
	char to[128] = {0};
	strcpy(from,"abcdefghijklmnopq");
	char *p1 = from;
	char *p2 = to;

	while (*p1 != '\0')
	{
		*p2 = *p1;
		
		p1++;
		p2++;
		
	}
	printf("to:%s\n",to);
	printf("hello...\n");
	system("pause");
}
