# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

// ��ζ���һ���ṹ�壬ͨ��struct �ؼ���
// ����ṹ����������ַ���
// 1. �����Ͷ������
// 2. �������͵�ͬʱ �������
// 3. �������� �������

struct Teather01 //������һ���ṹ���������ͣ��̶���С�ڴ��ı�������ͬint�� char����������һ����  ��û�з����ڴ�
{
	int age;
	char name[64];
	char id;
};

typedef struct Teather02 //�ṹ�����������ض��� ��typedef�ؼ���
{
	int age;
	char name[64];
	char id;
	
}Th1;

struct Student01
{
	char name[64];
	int age;

}s1, s2; // 2. �������͵�ͬʱ �������

struct 
{
	char name[64];
	int age;

}s3, s4; // 3. �������� �������

// �ṹ�������ʼ���ķ���
struct Student02
{
	char name[64];
	int aga;
}s5 = { "names", 21 }; // �����������ֵ

struct 
{
	char name[64];
	int age;

}s6 = {"cccccc",23}; 

struct Teather01 th5 = { 27,"aaaaa",'12' };//����Ϊȫ�ֱ���



void main0013()
{
	struct Teather01 th1; //����C���������ҷ����ڴ�

	Th1 th2 = {  31,"aaabbaa",22 };   // ��������ʡȥstruct�ؼ���

	struct Teather01 th3 = { 27,"aaaaa",'12'};//���������ͬʱ����ʼ��
	Th1 th4 = {28,"bbbbb",'11'};

	// �ṹ����������� 1.ͨ��th1.�ķ�ʽ�����в���
	th1.age = 30;//th1. ������  �Ǹ�ʲô�ģ�  ��û�в����ڴ棿
					//��Ѱַ���� ����age ����� th1������� ƫ���� ===������ cup�н��С���
					//û�в����ڴ棬�Ⱥ��ǣ��ſ�ʼ�����ڴ�
	strcpy(th1.name,"wanger");
	printf("���䣺%d  ���֣�%s  \n",th1.age,th1.name);

	// 2. ͨ��ָ��ķ�ʽ���в���  ->
	{
		Th1 *p = NULL;
		p = &th2;
		printf("���䣺%d\n",p->age); //  ->��Ѱַ���� ����age ����� t2�������ƫ����  ���� cup�н��С�
		printf("������%s\n",p->name);

	}



	printf("hello...\n");
	getchar();
}



// �ṹ���������������
void copy_Th1(Th1 th1, Th1 th2)
{
	th2 = th1;
}

// �ṹ��ָ�����������������
void copy_Th102(Th1 *th1, Th1 *th2)
{
	*th2 = *th1;
}

void main13()
{
	Th1 t1 = {32,"abcdefg",02};
	Th1 t2 = t1;
	Th1 t3 ;
	memset(&t3, 0, sizeof(t3)); // ��ͬ��Th1 t3 = {0};


	printf("���䣺%d\n", t2.age);//�������������ṩ �� =�� ��ֵ���� ����������Ҫ˳��
	printf("������%s\n", t2.name);
	
	
	copy_Th1(t1,t3);// �����޷����copy����������ֻ�ǰѣ�t1��t2�ĳ�ʼ�����ݴ������copy_Th1()���������ڸú�����ͨ���βν����˸�ֵcoPy�������ڸú������֮���β���������ڴ�ͱ��������� 
	               //  ��û�н���������ʵ�ν���coPy����
	printf("ִ��copy_Th1()����\n");
	printf("t3���䣺%d\n", t3.age);
	printf("t3������%s\n", t3.name);

	copy_Th102(&t1,&t3);
	printf("ִ��copy_Th102()����\n");
	printf("t3���䣺%d\n", t3.age);
	printf("t3������%s\n", t3.name);


	printf("hello...\n");
	system("pause");
}