# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


//char *p = "abcd111122abcd3333322abcd3333322qq";//求字符串p中abcd出现的次数
//1. 请自定义函数接口，完成上述需求。
// 2. 自定义的业务函数 和 main函数必须分开
//
//
// do....while模型
void main16()
{
	int nucount = 0;
	char *p1 = "abcd111122abcd3333322abcd3333322qq";

	do 
	{
		p1 = strstr(p1,"abcd");
		if (p1!=NULL)
		{
			p1 = p1 + strlen("abcd");
			nucount++;
		}
		else
		{
			break;
		}
	} while (*p1 != '\0');
	printf("nucount:%d\n",nucount);
	

	printf("hello...\n");
	system("pause");
}


 //while 模型
void main17()
{
	int ncount = 0;
	char *p2 = "123abcd12312434343abcd16768778687abcd1111jj";

	while (p2 = strstr(p2, "abcd"))
	{
		ncount++;
		p2 = p2 + strlen("abcd");
		if (p2 == "\0")
		{ 
			break;
		}
	}
	printf("ncount:%d\n",ncount);
	printf("hello...\n");
	system("pause");
}

int SearchForStrTime(char *p, char*pp, int *num)
{
	int ret = 0;
	int	mynum = 0;
	char *mp = p;

	if (p == NULL || pp == NULL || num == NULL)
	{
		ret = -1;
		printf("func SearchForStrTime():p == NULL || pp == NULL || num == NULL:err:%d\n",ret);
		return ret;
	}
	do
	{
		p = strstr(p, pp);

		if (p != NULL)
		{
			// *num++; 不能这样写，由于后++优先级高于*，应该先num++,后取值，但因为是后++,所以先执行*num,然后等赋值完成以后，num再++，改变了num的地址，会使其打印值成为乱码
			// 应将*num++，改为（*num）++;或者借助辅助指针变量，间接赋值的方式，进行操作
			mynum++;
			p = p + strlen(pp);
		}
		else
		{
			break;
		}

	} while (*p != '\0');
	//printf("*num:%d\n",*num);
	*num = mynum;
	return ret;
}

int main18()
{
	int ncount, ret = 0;
	char *p3 = "123abcd12312434343abcd16768778687abcd1111jj";
	char *p4 = "abcd";
	//char *p4 = NULL;
	ret = SearchForStrTime(p3, p4, &ncount);
	if (ret != 0)
	{
		printf("func:SearchForStr:err:%d\n", ret);
		return ret;
	}
	printf("ncount:%d\n", ncount);
	printf("hello.....\n");
	system("pause");
 }