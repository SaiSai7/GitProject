# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


void main12()
{
	int i,j = 0;
	int num = 6;
	char **p1 = NULL;
	char buf[100];
	
	p1 = (char**)malloc(sizeof(char*)*num);// �ڶ��ϣ�����6��(char*)���͵��ڴ�
	
	for (i = 0; i < num; i++)
	{
		p1[i] = (char *)malloc(sizeof(char)*100); // �൱��buf[100] //�ڶ��ϣ��ٷ���char���͵��ڴ�
		sprintf(p1[i],"%d%d%d",i+1,i+2,i+3); //������i+1 ��ӡ��һ���ַ���������s�С�
	}

	// ��ӡ����֮ǰ����
	printf("��ӡ����֮ǰ����:\n");
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",p1[i]);
	}

	// ���� :ͨ������ָ��ָ��ķ�ʽ����������
	/*printf("����\n");
	for (i = 0; i < num; i++)
	{
		for ( j = i+1; j <num; j++)
		{
			if (strcmp(p1[i],p1[j])<0)
			{
				char *tep = p1[i];
				p1[i] = p1[j];
				p1[j] = tep;
			}
		}

	}*/
	// ����ͨ������ָ��ָ����ڴ�飬��������
	for ( i = 0; i < num; i++)
	{
		for ( j = i+1; j < num; j++)
		{
			if (strcmp(p1[i],p1[j])<0)
			{
				strcpy(buf,p1[i]);
				strcpy(p1[i],p1[j]);
				strcpy(p1[j], buf);
			}

		}
	}
	printf("��ӡ����֮������:\n");
	for (i = 0; i < num; i++)
	{
		printf("%s\n", p1[i]);
	}

	// �ͷ��ڴ�1 
	for (size_t i = 0; i < num; i++)
	{
		if (p1[i]!=NULL)
		{
			free(p1[i]);
			p1[i] = NULL;
		}
	}

	//�ͷ��ڴ�2
	if (p1 !=NULL)
	{
		free(p1);
		//p1 = NULL;
	}
	
	printf("hello...\n");
	system("pause");
}

// �����ڴ棬����ֵ
char **getStr(int num)
{
	int i = 0;
	char **p2 = NULL;
	p2 = (char**)malloc(sizeof(char*)*num);

	for (i = 0; i < num; i++)
	{
		p2[i] = (char*)malloc(sizeof(char)*100);
		sprintf(p2[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p2;
}

// ��ӡ
void PrintfStr(char **p,int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",p[i]);
	}
}

// ���� ����ָ��ָ��
void SortStr01(char **p,int num)
{
	int i, j = 0;
	char *q = NULL;
	for ( i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
			if (strcmp(p[i],p[j])>0)
			{
				q = p[i];
				p[i] = p[j];
				p[j] = q;
			}

		}
	}
}

// ���� ����ָ����ָ����ڴ��
void SortStr02(char **p, int num)
{
	int i, j = 0;
	char buf[100];
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(p[i], p[j])>0)
			{
				strcpy(buf,p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], buf);
			}

		}
	}


}

// �ͷ��ڴ�
void Memo_Free(char **p,int num)
{
	int i = 0;

	for ( i = 0; i < num; i++)
	{
		if (p[i]!=NULL)
		{
			free(p[i]);
			p[i] = NULL;
		}
	}

	if (p!=NULL)
	{
		free(p);
	}

	



}
void main13()
{
	int num = 6;
	char **p1 = NULL;

	//�����ڴ棬����ֵ
	p1 = getStr(num);  
	
	// ��ӡ
	printf("����ǰ��ӡ��\n");
	PrintfStr(p1,num);

	// ����1
	//SortStr01(p1,num);
	// ����2
	SortStr02(p1, num);

	// ��ӡ
	printf("����ǰ��ӡ��\n");
	PrintfStr(p1, num);

	// �ͷ��ڴ�
	Memo_Free(p1, num);

	system("pause");


}