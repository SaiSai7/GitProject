# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

// 如何定义一个结构体，通过struct 关键字
// 定义结构体变量的三种方法
// 1. 用类型定义变量
// 2. 定义类型的同时 定义变量
// 3. 匿名类型 定义变量

struct Teather01 //定义了一个结构体数据类型（固定大小内存块的别名）（同int、 char等数据类型一样）  还没有分配内存
{
	int age;
	char name[64];
	char id;
};

typedef struct Teather02 //结构体数据类型重定义 用typedef关键字
{
	int age;
	char name[64];
	char id;
	
}Th1;

struct Student01
{
	char name[64];
	int age;

}s1, s2; // 2. 定义类型的同时 定义变量

struct 
{
	char name[64];
	int age;

}s3, s4; // 3. 匿名类型 定义变量

// 结构体变量初始化的方法
struct Student02
{
	char name[64];
	int aga;
}s5 = { "names", 21 }; // 定义变量并赋值

struct 
{
	char name[64];
	int age;

}s6 = {"cccccc",23}; 

struct Teather01 th5 = { 27,"aaaaa",'12' };//定义为全局变量



void main0013()
{
	struct Teather01 th1; //告诉C编译器给我分配内存

	Th1 th2 = {  31,"aaabbaa",22 };   // 这样可以省去struct关键字

	struct Teather01 th3 = { 27,"aaaaa",'12'};//定义变量的同时并初始化
	Th1 th4 = {28,"bbbbb",'11'};

	// 结构体变量的引用 1.通过th1.的方式，进行操作
	th1.age = 30;//th1. 操作符  是干什么的？  有没有操作内存？
					//是寻址操作 计算age 相对于 th1大变量的 偏移量 ===》计算 cup中进行。。
					//没有操作内存，等号是，才开始操作内存
	strcpy(th1.name,"wanger");
	printf("年龄：%d  名字：%s  \n",th1.age,th1.name);

	// 2. 通过指针的方式进行操作  ->
	{
		Th1 *p = NULL;
		p = &th2;
		printf("年龄：%d\n",p->age); //  ->是寻址操作 计算age 相对于 t2大变量的偏移量  计算 cup中进行。
		printf("姓名：%s\n",p->name);

	}



	printf("hello...\n");
	getchar();
}



// 结构体变量做函数参数
void copy_Th1(Th1 th1, Th1 th2)
{
	th2 = th1;
}

// 结构体指针变量，做函数参数
void copy_Th102(Th1 *th1, Th1 *th2)
{
	*th2 = *th1;
}

void main13()
{
	Th1 t1 = {32,"abcdefg",02};
	Th1 t2 = t1;
	Th1 t3 ;
	memset(&t3, 0, sizeof(t3)); // 等同于Th1 t3 = {0};


	printf("年龄：%d\n", t2.age);//编译器给我们提供 简单 =号 赋值操作 。。。我们要顺从
	printf("姓名：%s\n", t2.name);
	
	
	copy_Th1(t1,t3);// 这样无法完成copy工作，这样只是把，t1和t2的初始化数据传输给了copy_Th1()函数，并在该函数中通过形参进行了赋值coPy工作，在该函数完成之后，形参所分配的内存就被析构掉了 
	               //  并没有将主函数中实参进行coPy工作
	printf("执行copy_Th1()函数\n");
	printf("t3年龄：%d\n", t3.age);
	printf("t3姓名：%s\n", t3.name);

	copy_Th102(&t1,&t3);
	printf("执行copy_Th102()函数\n");
	printf("t3年龄：%d\n", t3.age);
	printf("t3姓名：%s\n", t3.name);


	printf("hello...\n");
	system("pause");
}