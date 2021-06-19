# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"



// ͨ������ֵ�ķ�ʽ�������ڴ棬�͸�ֵ
char ** GetMemo01(int num)
{
	int i = 0;
	char ** p = NULL;
	p = (char**)malloc(sizeof(char*)*num);
	if (p == NULL)
	{
		printf("func GetMemo():�����ڴ�ʧ��\n ");
	
	}

	for ( i = 0; i < num; i++)
	{
		p[i] = (char*)malloc(sizeof(char)*num);
		sprintf(p[i],"%d%d%d",i+1,i+1,i+1);
	}
	return p;
}

// ͨ����Ӹ�ֵ�ķ�ʽ�������ڴ�
int GetMemo02(char ***p,int num)
{
	int ret = 0;
	int i = 0;
	char **tep = NULL;
	if (p ==NULL)
	{
		ret = -1;
		return ret;

	}

	tep = (char **)malloc(sizeof(char *)*num);
	if (tep == NULL)
	{
		ret = -2;
		return  ret;
	}

	for ( i = 0; i < num; i++)
	{
		tep[i] = (char*)malloc(sizeof(char)*10);
		sprintf(tep[i],"%d%d%d",i+1,i+1,i+1);
	}
	*p = tep;

	return ret;
}


// ��ӡ
void PrintStr(char **p, int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",p[i]);
	}
}

// ����
void SortStr(char **p,int num)
{
	int i,j = 0;
	char *tep = NULL;
	for ( i = 0; i < num; i++)
	{
		for ( j = i+1; j < num; j++)
		{
			if (strcmp(p[i],p[j])<0)
			{
				tep = p[i];
				p[i] = p[j];
				p[j] = tep;

			}


		}
	}


}

// �ͷ��ڴ�  ����Ұָ�����
int Str_Free(char **p ,int num)
{
	int i = 0;
	if (p ==NULL)
	{
		return -1;
	}
	for ( i = 0; i < num; i++) // һάָ�룬��NULL
	{
		free(p[i]);
		p[i] = NULL;
	}
	if (p !=NULL)  // �ͷ��˶�άָ����ָ����ڴ�ռ䣬����δ����άָ�������ΪNULL,��Ұָ�����
	{
		free(p);

	}
}

// �ͷ��ڴ棬���������ж���ָ��p1������ΪNULL���ɱ���Ұָ�����
void Strmemo_Free(char ***p,int num)
{
	int i = 0;
	char **tep = NULL;
	if (p ==NULL)
	{
		return ;

	}
	tep = *p;
	for ( i = 0; i < num; i++) // �ͷ�һάָ�� ��ָ����ڴ�ռ�
	{
		free(tep[i]);
	}
	free(tep);      // �ͷŶ�άָ�룬��ָ����ڴ�ռ�

	*p = NULL;     // һ���Խ� һάָ������Ͷ�άָ�����ȫ����ΪNULL

}


void main16()
{
	char **p1 = NULL;
	int num = 6;
	//p1 = GetMemo01(num);

	int ret = GetMemo02(&p1,num);

	PrintStr(p1,num);
	SortStr(p1,num);
	PrintStr(p1, num);
	Strmemo_Free(&p1,num);

	printf("hello...\n");
	system("pause");

}