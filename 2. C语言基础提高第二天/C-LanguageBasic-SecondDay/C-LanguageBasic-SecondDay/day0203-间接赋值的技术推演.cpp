# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// ��Ӹ�ֵ��0��ָ�뵽1��ָ��
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

	// ֱ�Ӹ�ֵ
	a = 22;
	printf("ֱ�Ӹ�ֵa:%d\n",a);

	// ��Ӹ�ֵ
	p1 = &a;
	*p1 = 32;
	printf("��Ӹ�ֵa:%d\n",a);

	//ͨ������ȥ��ɼ�Ӹ�ֵ(һ��ָ��)
	GetFileLen01(&a);
	printf("������ֵa:%d\n",a);

	// ͨ����������ֵ����ʽ��ֵ
	a = GetFileLen02();
	printf("������ֵa:%d\n",a);

	GetFileLen03(a);
	printf("a:%d\n",a);
	
	printf("hello...\n");
	system("pause");
}





// ��Ӹ�ֵ��1��ָ�뵽2��ָ��

void GeMemo(char ** pp)
{
	*pp = (char*)2222;

}

void GeMemo02(char *p)
{
	// *p = 3333;  // ����������������Ϊ*p��ָ����ڴ�ռ�δ����
	p = (char*)3333;
	printf("&p:%d\n",p);
}
void main05()
{
	char *p1 = NULL;// NULL��Ϊ0
	char **p2 = NULL;
	printf("&p1:%d\n",p1);
	printf("&p1:%s\n", p1);  //nullΪ����ϵͳ�������ڴ����򣬲��ܱ��޸ģ�ֻ���ֶ������ڴ�󣬲��ܱ��޸�ʹ��

	// ֱ�Ӹ�ֵ,�ı�ָ��ָ��
	p1 = (char*)11;
	p2 = (char**)111;
	printf("ֱ���޸ĺ�p1��ֵ��\n");
	printf("&p1:%d\n",p1);//��ӡָ��p1ʮ���Ƶĵ�ַ���
	//printf("&p1:%s\n", p1);

	// ��Ӹ�ֵ���ı�ָ��ָ��
	p2 = &p1;
	*p2 = (char*)1111;
	printf("&p1:%d\n",p1);//��ӡָ��p1ʮ���Ƶĵ�ַ���

	{

		// ��Ӹ�ֵ���ٴθı�ָ��ָ��
		*p2 = (char*)2111;
		printf("&p1:%d\n",p1);
		//����Ӹ�ֵ��Ӧ�ó�������ȡ�ɺ���
	}
	GeMemo(p2);//ͨ�������ú�������ӵ��޸�p1��ֵ
	printf("&p1:%d\n",p1);

	// �������������޸�ָ�����p1��ָ�򣬸ı��ֻ���ββ���p��ָ��
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


// ��Ӹ�ֵ������������Ӧ�ó���

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
