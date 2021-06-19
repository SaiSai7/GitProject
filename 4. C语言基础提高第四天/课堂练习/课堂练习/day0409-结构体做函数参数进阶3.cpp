# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// �ṹ����Ƕ�����ָ��

// ����ṹ��
typedef struct Teather
{
	char name[64]; // �ѷ����ڴ�
	char *ph;    // δ�����ڴ棬ָ�����������ָ����ڴ�ռ�ı����ǲ�ͬ����
	char **stname;   // ���߽���������������ڴ棬 char buf[10][30];
	int age; //�ѷ����ڴ�
	char id; //�ѷ����ڴ�

}Teather;

// ���ṹ����������ڴ�ռ�
int Get_Memo(Teather **psd, int num)
{
	int i = 0, j = 0;
	Teather *pp = NULL;

	pp = (Teather *)malloc(num *sizeof(Teather));
	if (pp == NULL)
	{
		return -1;
	}
	memset(pp, 0, num *sizeof(Teather));

	for (i = 0; i < num; i++)  
	{
		char **p = NULL;
		// ����һά�ڴ�ռ�
		pp[i].ph = (char *)malloc(60);//����char *ph; ���ڴ����

		// �����ά�ڴ�ռ�
		p = (char **)malloc(num * sizeof(char *)); 

		for (j = 0; j < num; j++)
		{
			p[j] = (char *)malloc(60);
		}
		pp[i].stname = p;

	}
	*psd = pp;
	return 0;
}

// �ֶ���ֵ
void Get_Value(Teather *pp, int num)
{
	int i = 0, j = 0;
	for (i = 0; i < num; i++)
	{
		printf("���������䣺\n");
		scanf("%d", &pp[i].age);

	/*	printf("������������\n");
		scanf("%s", pp[i].name);*/

		printf("������ph��\n");
		scanf("%s", pp[i].ph);

		for (j = 0; j < num; j++)
		{
			printf("������ѧ��������\n");
			scanf("%s", pp[i].stname[j]);
		}
	}

}


// ��ӡ
void printStudent(Teather *p, int num)
{

	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d  ", p[i].age);
	}
	printf("\n");
}

// ����
void SortStd_age(Teather *p, int num)
{
	int i = 0, j = 0;
	Teather stu = { 0 };
	for (i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (p[i].age > p[j].age)
			{
				stu = p[i];
				p[i] = p[j];
				p[j] = stu;
			}
		}
	}

}


// �ͷ��ڴ�

void Memo_Free(Teather *p, int num)
{
	int i = 0, j = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		// �ͷ�һ��ָ��
		if (p[i].ph != NULL)
		{
			free(p[i].ph);
		}

		// �ͷŶ���ָ��
		if (p[i].stname != NULL)
		{
			char **mp = p[i].stname;
			for (j = 0; j < num; j++)
			{
				free(mp[j]);
			}
			free(mp);
			p[i].stname = NULL;
		}

	}
	free(p);
}




int main121212121()
{
	int ret = 0, i = 0;
	int num = 3;
	Teather *sd = NULL;

	// �����ڴ�
	ret = Get_Memo(&sd, num);

	if (ret != 0)
	{
		printf("func  Get_Memo():: %d erro \n", ret);
		return ret;
	}
	//for (i = 0; i < 3; i++)
	//{
	//	printf("���������䣺\n");
	//	scanf("%s",&sd[i].age);

	//	printf("������������\n");
	//	scanf("%s", sd[i].name); // ����ʹ��&���ţ���Ϊchar name[64];���������������һ��ָ��

	//	printf("������ph��\n");
	//	scanf("%s", sd[i].ph);  // ��ʱ�޷�����ɸ�ֵ����Ϊ���ṹ������У�char *ph;δ�����ڴ棬��������ڴ�
	//}

	//  ��ֵ
	Get_Value(sd, num);

	printf("δ����ǰ��ӡ��\n");
	printStudent(sd, num);

	SortStd_age(sd, num);

	printf("������ӡ��\n");
	printStudent(sd, num);

	Memo_Free(sd, num);

	printf("hello...\n");
	system("pause");
}