# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


int GetMemo(char **str1,int *strlen1,char **str2,int *strlen2)
{
	int ret = 0;
	char *p1 = NULL;
	char *p2 = NULL;

	p1 = (char*)malloc(100);
	if (p1 == NULL)
	{
		return ret = -1;
	}
	strcpy(p1, "abcdefghijk");
	*str1 = p1;
	*strlen1 = strlen(*str1);

	p2 = (char*)malloc(100);
	if (p2 == NULL)
	{
		return ret = -2;
	}
	strcpy(p2,"123456789");
	*str2 = p2;
	*strlen2 = strlen(*str2);

	return ret;
}

//�ֶ��ͷŶ�����������ڴ�ռ�
int GetMemo_Free(char **str)
{
	int ret = 0;
	if (str ==NULL)
	{
		return ret = -1;
	}

	free(*str);
	*str = NULL;
	return ret;

}

// �ԱȰ���������ֻ���ͷ��ˣ��β���char *str����ָ����ڴ�ռ䣬�����ܱ���Ұָ��ĳ���
int GetMemo_Free11(char *str)// ������ͨ��ʵ��int a,���ݸ��Ӻ������β�int b�����Ӻ�����ȥ�޸�a��ֵһ�����޷����������е�a�����޸ģ��޸ĵ�ֻ�ǣ��β�b��ֵ
{
	int ret = 0;
	if (str == NULL)
	{
		return ret = -1;
	}

	free(str);   // ��str��ָ����ڴ�ռ䣬�ͷ�
	str = NULL; // ֻ�ǽ��β��е�str��ָ���޸ĳ�NULL,�����ܽ����������е�p1��p2��ָ���޸ĳ�null
	return ret;
}


int main06()
{
	char *p1 = NULL;
	int len0 = 0;

	char *p2 = NULL;
	int len1 = 0;

	int ret = GetMemo(&p1,&len0,&p2,&len1);
	if (ret == -1)
	{
		printf("fun GetMemo()::��14�У�p1�ڶ��Ϸ����ڴ�ʱ����");
		return ret;
	}
	if (ret == -2)
	{
		printf("fun GetMemo()::��23�У�p2�ڶ��Ϸ����ڴ�ʱ����");
		return ret;
	}
	printf("p1:%s\n",p1);
	printf("len0:%d\n",len0);
	printf("p2:%s\n", p2);
	printf("len1:%d\n", len1);
	GetMemo_Free(&p1);   // �ͷ�1��ָ�����p1��ָ����ڴ�ռ䣬����p1ָ������ΪNULL,����Ұָ��ĳ���
	GetMemo_Free(&p2);

	printf("hello...\n");
	system("pause");
}


int main07()
{
	char *p1 = NULL;
	int len0 = 0;

	char *p2 = NULL;
	int len1 = 0;

	int ret = GetMemo(&p1, &len0, &p2, &len1);
	if (ret == -1)
	{
		printf("fun GetMemo()::��14�У�p1�ڶ��Ϸ����ڴ�ʱ����");
		return ret;
	}
	if (ret == -2)
	{
		printf("fun GetMemo()::��23�У�p2�ڶ��Ϸ����ڴ�ʱ����");
		return ret;
	}
	printf("p1:%s\n", p1);
	printf("len0:%d\n", len0);
	printf("p2:%s\n", p2);
	printf("len1:%d\n", len1);

	//if (p1 !=NULL)
	//{
	//	free(p1);
	//	p1 = NULL;
	//}
	//if (p2 != NULL)
	//{
	//	free(p2);
	//	p2 = NULL;
	//}

	GetMemo_Free11(p1); //����������ֻ���ͷŷţ�p1��ָ����ڴ�ռ䣬���䲢���ܱ���Ұָ��ĳ���
	printf("p1:%s\n", p1); // ����Ҳָ�����󣬴��д�ӡ����Ϊ����
	GetMemo_Free11(p2);



	printf("hello...\n");
	system("pause");
}




