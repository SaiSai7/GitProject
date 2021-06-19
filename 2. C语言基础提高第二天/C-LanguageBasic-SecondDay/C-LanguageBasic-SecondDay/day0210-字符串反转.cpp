# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// �ַ�����ת
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




// ͨ���ݹ�ķ�ʽ�������ӡ  
// ���ã��ַ����У��ַ����������������ԣ���ջ��ջ��������ַ�����ת
// �ݹ��ȫ�ֱ�����Ҳ��������������ȫ�ֱ�����
// �ݹ�ͷ�ȫ�ֱ�����Ҳ���ݹ�ָ��������������

char g_buf[1000];

void ReverseStr02(char *p)
{
	if (p == NULL) //�ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0') // �ݹ����������
	{
		return;
	}
	ReverseStr02(p + 1); // ���еݹ���ã� ���ַ���abcdefg, �Ե����ַ��ķ�ʽ����a..��...g�ĵ�ַ��������ջ
	printf("%c ",*p);
}



// ���ݹ��������������ȫ�ֱ����� �ݹ��ȫ�ֱ�����Ҳ��������������ȫ�ֱ�����
void ReverseStr03(char *p)
{
	if (p == NULL) // �ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0') // �ݹ����������
	{
		return;
	}
	ReverseStr03(p + 1); // ���еݹ���ã� ���ַ���abcdefg, �Ե����ַ��ķ�ʽ����a..��...g�ĵ�ַ��������ջ
	//strcat(g_buf,p);
	//strncpy(g_buf,p,1);
	strncat(g_buf,p,1);

}

// �ݹ�ͷ�ȫ�ֱ������ݹ�ָ����������������ΰѵݹ������������ֲ�����
void ReverseStr04(char *p,char *mypuf)
{
	if (p == NULL||mypuf == NULL) // �ݹ�������쳣����
	{
		return;
	}
	if (*p == '\0') // �ݹ����������
	{
		return;
	}
	ReverseStr04(p + 1,mypuf); // ���еݹ���ã� ���ַ���abcdefg, �Ե����ַ��ķ�ʽ����a..��...g�ĵ�ַ��������ջ
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