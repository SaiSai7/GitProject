# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// һ��ָ��ĵ����÷�--���������ַ����Ļ�������Ϊ��
// 1. ����
// 2. �ַ��� 
////////////�ַ���ע���/////////
// ��1��C���Ե��ַ����������β���ַ���
// ��2��C������û���ַ������ͣ�ͨ���ַ�������ģ���ַ���
// ��3���ַ������ڴ���䣺������ջ�ϡ������ڶ��ϡ�Ҳ������ȫ������

// �ַ����飬��ʼ��
void main09()
{
	//1.ָ�����ȣ��ַ�����
	char buf1[100] = {'a','b','c','d'};//  �����buf2[4]---buf[99] ���Զ�Ϊ0���������Կ�����0��β���ַ���

	//char buf2[3] = {'a','b','c','d'};//�����ʼ����Ԫ�ظ������ڷ���Ԫ�صĸ���������ֱ������


	//2.��ָ�����ȣ��ַ�����
	char buf3[] = { 'a','b','c','d'};// buf3��һ�����飬 ����һ��C�����ַ���  ����һ����0 ��β���ַ���


	printf("buf1:%s\n",buf1);
	printf("buf1:%d\n",buf1[40]);

	printf("buf3:%s\n",buf3);
	
	
	printf("hello...\n");
	system("pause");
}



// ���ַ�������ʼ���ַ�����
// strlen()�����������ַ����ĳ��� �䳤�Ȳ������ַ�����β\0
// sizeof() ������ ����������������ռ�ֽڴ�С

void main10()
{
	char buf4[] = "abcdef";

	int len = strlen(buf4);//6     //buf4 ��Ϊ�ַ����� Ӧ����7���ֽ� // ��Ϊ�ַ��� Ӧ����6���ֽ�

	int size = sizeof(buf4);// 7
	printf("buf4:%s\n",buf4);
	printf("buf4�ĳ��ȣ�%d\n",len);
	printf("buf4��ռ�ڴ��С��%d\n",size);

	char buf5[128] = "asdfgh";
	printf("buf5:%s\n",buf5);
	printf("buf5[100]:%d\n",buf5[100]);
	printf("hello...\n");
	system("pause");
}



// ͨ�������±� ��ָ��
void main11()
{
	int i = 0;
	char *p = NULL;
	char buf6[128] = "asdfqwer";

	printf("buf6:");
	for (i = 0; i < strlen(buf6); i++)
	{
		printf("%c ", buf6[i]);
	}
	printf("\n");

	
	p = buf6; 	printf("buf6:");

	for (i = 0; i < strlen(buf6);i++)
	{
		printf("%c ",*(p+i));
	}
	printf("\n");


	printf("buf6:");
	for (i = 0; i < strlen(buf6);i++)
	{
		printf("%c ",*(buf6+i));
	}
	printf("\n");
	// ָ����ڴ��׵�ַ������
	// [] ��*p��������һ���ģ���ֻ������[]�����ϳ���Ա���Ķ�ϰ��
	// []��*pҲ��һ��������buf6Ϊ������Ԫ�ص�ַ����C��C++�������У�Ϊֻ����ָ�볣��
	// ��ˣ��䲻����buf6 = buf6 +i;���������Ĳ�������ָ��������Ϳ�������p=p+i�����Ĳ���;




	printf("hello...\n");
	system("pause");
}