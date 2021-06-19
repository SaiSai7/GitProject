# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


//有一个字符串符合以下特征（”abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";）
// 要求写出一个函数接口，输出以下结果：
// （1）以逗号分割字符串，形成二维数组，并把结果传出。
// （2）把二维数组行数结果也传出 

int SplitString(char *p,char c, char buf[10][30],int *count)
{
	int ret = 0;
	char *q1 = NULL;
	char *q2 = NULL;
	int ncount = 0;

	q1 = q2 = p;// 第一步：辅助指针变量都指向起始位置

		do
		{
			
			q1 = strchr(q1, c);// 第二步：找出字符串中，逗号，首次出现的位置，让其中一个辅助指针变量向后移动，
			if (q1 != NULL)
			{
				if (q1-q2>0)   // 用让移动的辅助指针变量p1与未移动的指针变量p2做差值，挖字符串
				{
					strncpy(buf[ncount], q2, q1 - q2); // 将第一个逗号，以前的字符串，赋值到指定内存中
					buf[ncount][q1 - q2] = '\0'; // 把第ncount行字符串转换为C风格的字符串
					ncount++;

					q2 = q1 = q1 + 1;//让q1和q2重新达到下一次检索条件
				}
			}
			else
			{
				break;
			}
		} while (*q1 != '\0');

		*count = ncount;
	
	return  ret;

}
// 打印
void PrintString(char buf[10][30],int num)
{
	int i = 0;
	for ( i = 0; i < num; i++)
	{
		printf("%s\n",buf[i]);
	}

}

void main17()
{
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char p2 = ',';
	int count = 0;

	char buf[10][30];
	int ret = SplitString(p1,p2,buf,&count);
	PrintString(buf,count);



	printf("hello...\n");
	system("pause");
}