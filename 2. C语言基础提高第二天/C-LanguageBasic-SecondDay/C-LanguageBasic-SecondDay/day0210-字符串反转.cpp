# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// 字符串反转
void main22()
{
	char buf[] = "1234567";
	int len = strlen(buf);

	char *p1 = buf;
	char *p2 = buf + len - 1;
	while (p1 < p2)
	{
		char a = *p1;
		*p1 = *p2;
		*p2 = a;
		p1++;
		p2--;
	}
	printf("buf:%s\n",buf);
	printf("hello...\n");
	system("pause");
}


int ReveseStr(char *p)
{
	int ret = 0;
	if (p == NULL)
	{
		ret = -1;
		printf("func ReveseStr():p == NULL err %d\n",ret);
		return ret;
	}
	
	char *myp = p;
	char *p2;
	char *p3;
	p2 = myp;
	p3 = myp + strlen(myp) - 1;

	while (p2 < p3)
	{
		char a = *p2;
		*p2 = *p3;
		*p3 = a;
		p2++;
		p3--;
	}
	return ret;
}
int main23()
{
	int ret = 0;
	char buf[] = "1234567";
	ret = ReveseStr(buf);
	if (ret != 0)
	{
		printf("func ReveseStr():%d\n",ret);
		return ret;
	}

	printf("buf::%s\n",buf);

	printf("hello...\n");
	system("pause");
}




// 通过递归的方式，逆向打印  
// 运用，字符串中，字符做函数参数的特性，入栈出栈，来完成字符串反转
// 递归和全局变量（也即把逆序结果存入全局变量）
// 递归和非全局变量（也即递归指针做函数参数）

char g_buf[1000];

void ReverseStr02(char *p)
{
	if (p == NULL) //递归结束的异常条件
	{
		return;
	}
	if (*p == '\0') // 递归结束的条件
	{
		return;
	}
	ReverseStr02(p + 1); // 进行递归调用， 让字符串abcdefg, 以单个字符的方式，从a..到...g的地址，依次入栈
	printf("%c ",*p);
}



// 将递归的逆序结果，存入全局变量。 递归和全局变量（也即把逆序结果存入全局变量）
void ReverseStr03(char *p)
{
	if (p == NULL) // 递归结束的异常条件
	{
		return;
	}
	if (*p == '\0') // 递归结束的条件
	{
		return;
	}
	ReverseStr03(p + 1); // 进行递归调用， 让字符串abcdefg, 以单个字符的方式，从a..到...g的地址，依次入栈
	//strcat(g_buf,p);
	//strncpy(g_buf,p,1);
	strncat(g_buf,p,1);

}

// 递归和非全局变量（递归指针做函数参数）如何把递归的运算结果存入局部变量
void ReverseStr04(char *p,char *mypuf)
{
	if (p == NULL||mypuf == NULL) // 递归结束的异常条件
	{
		return;
	}
	if (*p == '\0') // 递归结束的条件
	{
		return;
	}
	ReverseStr04(p + 1,mypuf); // 进行递归调用， 让字符串abcdefg, 以单个字符的方式，从a..到...g的地址，依次入栈
						 //strcat(g_buf,p);
						 //strncpy(g_buf,p,1);
	strncat(mypuf, p, 1);

}

void main24()
{
	char buf[] = "abcdef";
	//ReverseStr02(buf);

	//memset(g_buf,0,sizeof(g_buf));
	//ReverseStr03(buf);
	//printf("g_buf:%s\n",g_buf);

	{
		char mybuf[1024] = {0};
		ReverseStr04(buf,mybuf);
		printf("mybuf:%s\n", mybuf);
	
	}
	printf("hello...\n");
	system("pause");
}