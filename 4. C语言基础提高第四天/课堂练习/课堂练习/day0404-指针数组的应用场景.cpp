# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"
# define DIM(a) sizeof(a)/sizeof(*a)  // 第一个点，宏替换



int searcheKeyTable(char *table[],int num,char *p,int *pos)// 第二个点，数组做函数参数，退化为指针的问题，函数参数中的char *table[]，等同于char **table;,写成char *table[]，便于程序员阅读
{
	int ret = 0, i = 0;
	int nmb = sizeof(table) / sizeof(*table);// 与主函数中num相比，若nub为1，则说明，多维数组做函数参数退化指针，因为数组名table为二级指针为4个字节，*table为一级指针也为4个字节
	printf("nmb:%d\n", nmb);                 // 间接的证明了数组做函数参数的退化问题
	if (table == NULL || p == NULL || pos == NULL)
	{
		ret = -1;
		
		return ret;
	}
	for ( i = 0; i < num; i++)
	{
		//if (strcmp(*(table + i), p) == 0)   C++编译器会将table[i]转化为*(table + i)，执行
		if (strcmp(table[i], p) == 0)
		{
			*pos = i;
			return ret;
		}
	}

	// 若没有找到直接传出-1
	if (i == num)
	{
		*pos = -1;
	}
	return ret;
}


int main09()
{
	int pos = 0;
	int num = 0;


	//指针数组
	char*   c_keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};
	num = DIM(c_keyword);// 其等于sizeof( c_keyword)/sizeof(* c_keyword)
	printf("数组 c_keyword元素个数：%d \n", num);

	//int ret = searcheKeyTable(c_keyword, DIM(c_keyword), "do", &pos);//可宏替换为searcheKeyTable(c_keyword,sizeof(c_keyword)/sizeof(*c_keyword), "do", &pos);
	int ret = searcheKeyTable(c_keyword, (sizeof(c_keyword) / sizeof(*c_keyword)), "do", &pos);
	if (ret != 0)
	{
		printf("func searcheKeyTable()::%d err\n", ret);
		return ret;
	}
	printf("pos:%d \n", pos);

	searcheKeyTable(c_keyword, sizeof(c_keyword) / sizeof(*c_keyword), "case", &pos);

	printf("pos:%d \n", pos);
	printf("hello...\n");
	system("pause");
}

//main函数是操作系统调用的函数
//在程序执行的时候可以向main函数传递参数

/*
argc 命令行参数
argv 命令行参数数组
env  函数变量数组

int main();
int main(int argc);
int main(int argc, char *argv[])
*/

void main008(int argc, char* argv[], char**env) // 参数内存是由操作系统分配的，main函数是应用程序和操作系统交互的入口
{
	int i = 0;
	//main02_1();

	printf("******************* Begin argv *******************\n");
	for (i = 0; i<argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	// 	for(i=0; argv[i]!=NULL; i++) // 该数组是以0结尾的数组
	// 	{
	// 		printf("%s\n", argv[i]);
	// 	}
	printf("******************* End argv *******************\n");

	printf("\n");
	printf("\n");
	printf("\n");

	printf("******************* Begin env *******************\n");

	for (i = 0; env[i] != NULL; i++)  //
	{
		printf("%s\n", env[i]);
	}

	printf("******************* End env*******************\n");

	getchar(); //在程序末尾加getchar(), 用来让程序不会立即退出, 跟system("pause"); 是一样的功能

}

// 指针数组的自我结束能力
void main11()
{
	int i = 0;

	int pos = 0;
	int num = 0;


	//指针数组,在不知所要存储指针数组元素个数的情况下，将指针数组设置为有自我结束能力的数组，其做法为，在指针数组最后一个元素的尾部
	// 再分配一块儿空间，添加‘\0’或0或NULL，以成为指针数组结束的标致
	char*   c_keyword01[] = {
		"while",
		"case",
		"static",
		"do",
		'\0'
	};
	char*   c_keyword02[] = {
		"while",
		"case",
		"static",
		"do",
		0
	};
	char*   c_keyword03[] = {
		"while",
		"case",
		"static",
		"do",
		NULL
	};
	for (size_t i = 0; c_keyword01[i] != NULL; i++)
	{
		printf("%s ", c_keyword01[i]);
	}
	printf("\n***************************\n");

	for (size_t i = 0; c_keyword02[i] != NULL; i++)
	{ 
		printf("%s ", c_keyword02[i]);
	}
	printf("\n***************************\n");
	for (size_t i = 0; c_keyword03[i] != NULL; i++)
	{
		printf("%s ", c_keyword03[i]);
	}
	printf("\n***************************\n");
	printf("hello...\n");
	system("pause");
}