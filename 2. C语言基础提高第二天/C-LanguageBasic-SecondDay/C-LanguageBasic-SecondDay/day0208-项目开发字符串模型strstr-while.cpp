# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


//char *p = "abcd111122abcd3333322abcd3333322qq";//���ַ���p��abcd���ֵĴ���
//1. ���Զ��庯���ӿڣ������������
// 2. �Զ����ҵ���� �� main��������ֿ�
//
//
// do....whileģ��
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


 //while ģ��
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
			// *num++; ��������д�����ں�++���ȼ�����*��Ӧ����num++,��ȡֵ������Ϊ�Ǻ�++,������ִ��*num,Ȼ��ȸ�ֵ����Ժ�num��++���ı���num�ĵ�ַ����ʹ���ӡֵ��Ϊ����
			// Ӧ��*num++����Ϊ��*num��++;���߽�������ָ���������Ӹ�ֵ�ķ�ʽ�����в���
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