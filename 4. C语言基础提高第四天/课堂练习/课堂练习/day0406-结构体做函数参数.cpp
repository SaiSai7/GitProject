# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"



typedef struct Teather
{
	int age;
	char name[64];
	char id;

}Teather;


// ��ӡ
void printTh1(Teather *p1,int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%d ",p1[i].age);
	}

}


// ����
void SortTh1(Teather *p2, int num)
{
	int i = 0, j = 0;
	Teather mp;
	for ( i = 0; i < num; i++)
	{
		for (j = i + 1; j < num; j++)
		{
			if (p2[i].age > p2[j].age)
			{
				mp = p2[i];
				p2[i] = p2[j];
				p2[j] = mp;
			}
		}
	}

}

//�ڶ��Ϸ����ڴ�
Teather *CreatMemo(int num)
{
	Teather *p = NULL;
	int i = 0;
	p = (Teather *)malloc(sizeof(Teather) * num);
	if (p == NULL)
	{
		return NULL;
	}
	return p;
}


// �ͷ��ڴ�
void Free_Memo(Teather *p3)
{
	if (p3!=NULL)
	{
		free(p3);
	}

}




// ��ջ�Ϸ����ڴ�
void main14()
{
	int i = 0, j = 0;
	Teather t1[6] = { NULL };// ��ջ�Ϸ����ڴ�
	int num = 6;
	Teather t2;


	for (i = 0; i < num; i++)
	{
		printf("���������䣺");
		scanf("%d", &t1[i].age);//����һ������������������ŵ�����ti�ĵ�i����ַ��ȥ������֮������������t1�ĵ�i��ֵ 
		//scanf("%d", &a[i]);
	}
	printf("���������Ϊ��\n");  
	//for (i = 0; i < num; i++)// ��ӡ
	//{
	//	
	//	printf("%d  ", t1[i].age);
	//	//printf("%d ", a[i]);
	//}
	printTh1(t1,num);
	// ���������С��������
	//for (i = 0; i < num; i++)
	//{
	//	for (j = i+1; j < num; j++)
	//	{
	//		if (t1[i].age > t1[j].age)
	//		{
	//			t2 = t1[i];
	//			t1[i] = t1[j];
	//			t1[j] = t2;

	//		}
	//	}
	//}
	SortTh1(t1, num);

	//������ӡ
	printf("\n---------------------------\n");
	for (i = 0; i < num; i++)// ��ӡ
	{

		printf("%d  ", t1[i].age);
		//printf("%d ", a[i]);
	}
	printf("\nhello...\n");
	system("pause");
}






// �ڶ��Ϸ����ڴ�
void main15()
{
	int i = 0, j = 0;
	Teather *t1 = NULL;// ��ջ�Ϸ����ڴ�
	int num = 3;

	t1 = CreatMemo(num); // �ڱ����ú����У�ͨ���ڶ��Ϸ����ڴ�



	for (i = 0; i < num; i++)
	{
		printf("���������䣺");
		scanf("%d", &t1[i].age);//����һ������������������ŵ�����ti�ĵ�i����ַ��ȥ������֮������������t1�ĵ�i��ֵ 
								//scanf("%d", &a[i]);
	}
	printf("���������Ϊ��\n");
	printTh1(t1, num);
	
	SortTh1(t1, num);

	printf("\n����������ӡ��\n");
	printTh1(t1, num);

	Free_Memo(t1);

	printf("\nhello...\n");
	system("pause");
}