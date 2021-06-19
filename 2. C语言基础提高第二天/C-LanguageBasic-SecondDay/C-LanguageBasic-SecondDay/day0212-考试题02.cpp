# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

/*****************************************************************************************=
问题：键值("key = valude")字符串，在开发中经常使用
要求 1：请自己定义一个接口，实现数据key 获取valude;
要求 2：编写测试用例；
要求 3：键值对中间可能有n多空格，请去除空格；
注意： 键值对字符串格式可能如下：
"key1 = valude1"
"key2 =        valude2"
"key3  = valude3"
"key4        = valude4"
"key5    =   "
"key6    ="
"key7    =    "
int getKeyByValude(char *keyvaluebuf, char *keybuf, char *valudebuf, int *valuebuflen)
{
}
int main()
{
getKeyByValude("key1 = valude", "key1",  buf, &len);

}
******************************************************************************************/


int TrimSpace(char *p, char *newstr)
{
	int ret = 0,i = 0,j = 0,nconut = 0;
	char *myp = p;
	if (!p||!newstr)
	{
		ret = -1;
		return ret;
	}
	j = strlen(myp) - 1;
	
	while (isspace(myp[i]) && myp[i] != '\0')
	{
		i++;
	}
	while (isspace(myp[j])&& myp[j] != '\0')
	{
		j--;
	}
	nconut = j - i + 1;
	strncpy(newstr,myp + i,nconut);
	newstr[nconut] = '\0';

	

	return ret;

}

int GetKeyByValue(char *keyvalue,char *key,char *value)
{
	int ret = 0;
	char *mykeyvalue = NULL;
	if (!keyvalue||!key||!value)
	{
		ret = -1;
		return ret;
	}

	// 查找key是否在母串中
	mykeyvalue = keyvalue;
	mykeyvalue = strstr(mykeyvalue,key);

	if (!mykeyvalue )
	{
		ret = -1;
		return ret;
	}
	// 让辅助指针变量，达到下一个查找条件
	mykeyvalue = mykeyvalue + strlen(key);

	mykeyvalue = strstr(mykeyvalue,"=");
	if (!mykeyvalue)
	{
		ret = -1;
		return ret;
	}
	// 让辅助指针变量再一次，达到查找条件
	mykeyvalue = mykeyvalue + strlen("=");

	// 去除'='后的，空格
	ret = TrimSpace(mykeyvalue,value);
	if (ret!=0)
	{
		printf("func TrimSpace(mykeyvalue,value):err :: %d\n", ret);
		return ret;

	}
	return ret;
}

int main()
{
	int ret = 0;
	char buf[1024] = {0};


	char *p1 = "     key2   =       value2    ";
	char *p2 = "key2";

	ret = GetKeyByValue(p1,p2,buf);

	if (ret !=0)
	{
		printf("func TrimSpace(mykeyvalue,value):err :: %d\n", ret);
		return ret;
	}
	printf("buf:%s\n",buf);
	printf("hello...\n");
	system("pause");
}