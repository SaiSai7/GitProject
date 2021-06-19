# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"

// �ṹ����Ƕ��һ��ָ��

// ����ṹ��
typedef struct Student
{
	char name[64]; // �ѷ����ڴ�
	char *ph;    // δ�����ڴ棬ָ�����������ָ����ڴ�ռ�ı����ǲ�ͬ����
	int age; //�ѷ����ڴ�
	char id; //�ѷ����ڴ�

}Student;

// ���ṹ����������ڴ�ռ�
int Get_Memo(Student **psd,int num)
{
	int i = 0;
	Student *pp = NULL;
	pp = (Student *)malloc(num *sizeof(Student));
	if (pp == NULL)
	{
		return -1;
	}
	memset(pp, 0, num *sizeof(Student));
	for ( i = 0; i < num; i++)  //����char *ph; ���ڴ����
	{
		pp[i].ph = (char *)malloc(60);
	}
	*psd = pp;
	return 0;
}

// �ֶ���ֵ
void Get_Value(Student *pp,int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("���������䣺\n");
		scanf("%d",&pp[i].age);

		printf("������������\n");
		scanf("%s", pp[i].name);

		printf("������ph��\n");
		scanf("%s", pp[i].ph);
	}

}

// ��ӡ
void printStudent(Student *p,int num)
{

	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%d  ",p[i].age);
	}
	printf("\n");
}

// ����
void SortStd_age(Student *p, int num)
{
	int i = 0, j = 0;
	Student stu = {0};
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

void Memo_Free(Student *p,int num)
{
	int i = 0;
	if (p == NULL)
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (p[i].ph != NULL)
		{
			free(p[i].ph);
		}
		
	}
	free(p);
}




int main17()
{
	int ret = 0,i = 0;
	int num = 3;
	Student *sd = NULL;

	// �����ڴ�
	ret = Get_Memo(&sd, num);

	if (ret != 0)
	{
		printf("func  Get_Memo():: %d erro \n",ret);
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

	Memo_Free(sd,num);

	printf("hello...\n");
	system("pause");
}