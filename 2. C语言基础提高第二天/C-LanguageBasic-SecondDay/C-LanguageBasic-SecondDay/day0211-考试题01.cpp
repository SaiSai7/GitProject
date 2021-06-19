# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
/***************************************************************************
题目：有一个字符串"1a2b3d4z",要求写一个函数实现如下功能：
功能 1：把偶数位字符挑选出来，组成一个字符串 1
功能 2：把奇数位字符串挑选出来，组成一个字符串2
功能 3：把字符串1和字符串2，通过函数参数，传送给main，并打印
功能 4：主函数能测试通过。
****************************************************************************/


// 方法一
int GetJOStr(char *p,char *myJstr,char *myOstr)
{
	int ret = 0;
	char *myp = p;
	char *mjs = myJstr;
	char *mos = myOstr;
	if (p == NULL || myJstr == NULL || myOstr == NULL)
	{
		ret = -1;
		printf("func GetJOStr() err:(p == NULL || myJstr == NULL || myOstr == NULL)::%d\n",ret);
		return ret;
	}

	int i = 0; 
	int	j = 0;
	int k = 0;
	for (i = 0; myp[i] != '\0';i++)
	{
		if (i % 2 != 0)
		{
			mjs[j++] = myp[i];
		}
		else
		{
			mos[k++] = myp[i];
		}
	
	}
	mjs[j] = '\0';
	mos[k] = '\0';
	
	return ret;

}

int main25()
{
	int ret = 0;
	char *p1 = "1a2b3d4z";
	char Jstr[100] = {0};
	char Ostr[100] = {0};

	ret = GetJOStr(p1,Jstr,Ostr);
	if (ret == 0)
	{
		printf("p1:%s\n", p1);
		printf("Jstr:%s\n", Jstr);
		printf("Ostr:%s\n", Ostr);
	}
	else
	{
		printf("func  GetJOStr():err::%d\n",ret);
		return ret;
	}

	


	
	
	printf("hello...\n");
	system("pause");
}

// 方法二
int GetJOStr02(char *p, char *myJstr, char *myOstr)
{
	int ret = 0;
	int i = 0, j = 0, k = 0;
	char *myp = p;
	if (!p || !myJstr || !myOstr)
	{
		ret = -1;
		return ret;
	}
	for (i = 0; myp[i] != '\0'; i += 2)
	{
		myJstr[j++] = myp[i];
	}
	for (i = 1; myp[i] != '\0'; i += 2)
	{
		myOstr[k++] = myp[i];
	}
	myJstr[j] = '\0';
	myOstr[k] = '\0';
	return ret;
}

int main26()
{
	int ret = 0;
	char *p1 = "1a2b3d4z";
	char Jstr[100] = { 0 };
	char Ostr[100] = { 0 };
	ret = GetJOStr02(p1,Jstr,Ostr);
	if (ret == 0)
	{
		printf("p1:%s\n",p1);
		printf("Jstr:%s\n", Jstr);
		printf("Ostr:%s\n", Ostr);
	}
	else
	{
		printf("func GetJOStr02() !p || !myJstr || !myOstr) err::%d\n", ret);
		return ret;
	}


	printf("hello...\n");
	system("pause");
}

// 方法三

int GetJOStr03(char *p,char *myjstr,char *myostr)
{
	int ret = 0, i = 0, j = 0, k = 0;
	char *myp = p;
	if (!p||!myjstr||!myostr)
	{
		ret = -1;
		return ret;
	}
	while (myp[i]!='\0')
	{
		myjstr[j++] = myp[i++];
		myostr[k++] = myp[i++];

	}
	myjstr[j] = '\0';
	myostr[k] = '\0';

	return ret;
}

int main27()
{
	int ret = 0;
	char *p1 = "1a2b3d4z";
	char Jstr[100] = { 0 };
	char Ostr[100] = { 0 };

	ret = GetJOStr03(p1,Jstr,Ostr);
	if (ret == 0)
	{
		printf("p1:;%s\n", p1);
		printf("Jstr:;%s\n", Jstr);
		printf("Ostr:;%s\n", Ostr);
	}
	else
	{
		printf("func GetJOStr03() err::(!p||!myjstr||!myostr):::%d\n", ret);
		return ret;
	}

	printf("hello...\n");
	system("pause");
}