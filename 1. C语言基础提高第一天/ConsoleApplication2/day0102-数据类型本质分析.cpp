#include "stdlib.h"
#include "string.h"
#include "stdio.h"


struct Student
{
	char gender;
	char name;
	int year;
};

typedef struct teacher
{
	char gender;
	char name;
	int year;

}th;

typedef int u32;

void main03()
{
	int a;
	int b[10];
	printf(" b:%d b+1:%d &b:%d b+1:%d\n",b, b+1, &b, &b+1);

	printf(" sizeof(a):%d\n sizeof(b[10]):%d\n", sizeof(a), sizeof(b));

	struct Student st1;
	st1.year = 18;

	th th1;
	th1.year = 28;


	printf("学生的年龄：%d, 老师的年龄：%d\n",st1.year,th1.year);

	u32 i = 100;
	printf("sizeof(i):%d\n",sizeof(i));

	printf("hello...\n");
	system("pause");
}