# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// �Խṹ������У�name�ַ������и�ֵ�����򡢴�ӡ
// ����ṹ�����
typedef struct Manager
{
	char name[64] = {0};   // �������ѷ�����ڴ�
	char *alias;    // �������ڴ�
	char **empname;  // �������ڴ�
	int age;
	char id;
}Manager;

// �����ڴ�
int  Get_MgMemo(Manager **m/*out*/, int num)
{
	Manager *myp = NULL;
	if (m == NULL)
	{
		return -1;
	}
	myp = (Manager*)malloc(num*sizeof(Manager));
	if (myp == NULL)
	{
		return -1;
	}
	*m = myp;
	return 0;
}


void main0000000()
{
	int ret = 0; int i = 0, j = 0;
	int num = 3;
	Manager *mg = NULL;

	Manager tem;

	ret = Get_MgMemo(&mg, num);

	for ( i = 0; i < num; i++)
	{
		printf("����������:\n");
		scanf("%s",mg[i].name);
	}
	printf("δ�����ӡ��\n");
	for ( i = 0; i < num; i++)
	{
		printf("%s  ",mg[i].name);
	}
	printf("\n");

	for ( i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (strcmp(mg[i].name, mg[j].name)>0)
			{
				tem = mg[i];
				mg[i] = mg[j];
				mg[j] = tem;
			}
		}
	}
	printf("������ӡ��\n");
	for (i = 0; i < num; i++)
	{
		printf("%s  ", mg[i].name);
	}
	printf("\n");

	printf("hello...\n");
	system("pause");
}