# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


void main081()
{

	int a = 12;
	char *p1 = (char*)100; //ָ��Ҳ��һ�ֱ�����ռ���ڴ�ռ䣬���������ڴ��ַ
	char *******p2 ;
	printf(" a:%d\n",a);
	printf("sizeof(a):%d sizeof(p1):%d sizeof(p2):%d\n ",sizeof(a), sizeof(p1), sizeof(p2)); //ָ�����ռ4���ֽ�


	// *p���ڵȺŵ����,д�ڴ�
	int *p3 = NULL;
	p3 = &a;
	*p3 = 22;
	printf("a:%d\n",a);


	//*p���ڵȺŵ��ұߣ����ڴ�
	int b = 0;
	b = *p3;
	printf(" b:%d\n",b);

	//�൱�ڲ��ϸı�ָ���ָ��, ��ϸ���̼����ڴ�����ͼ
	char *p4 = NULL;
	p4 = (char*)malloc(100);
	p4 = (char*)malloc(150);


	printf("hello...\n");
	system("pause");
}







// ���Ҫȥ�޸�һ���ڴ�ռ��ֵ������ȷ��������ڴ�ռ��ֵ�����Ա��޸ģ�����ռ��ֵ���ܱ��޸ģ���ǿ���޸ģ�������崻���

char *GetStr()
{
	char *p = NULL;
	p = "abcdefg";
	return p;
}



void main()
{

	char * pp = NULL;
	pp = GetStr();

	*(pp + 1) = 'c';
	printf("pp:%s\n",pp);
	system("pause");
	return;
}