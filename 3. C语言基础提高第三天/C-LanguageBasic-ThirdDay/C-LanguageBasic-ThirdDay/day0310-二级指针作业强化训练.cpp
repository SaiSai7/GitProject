# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

// 主函数分配内存

// 指针输入特性
int SplitString(char *myp,char c,int *ccount, char **p/*in*/)
{
	int ret = 0; int ncount = 0; int i = 0;
	char *q1 = NULL;
	char *q2 = NULL;

	q1 = q2 = myp;

	do
	{
		q1 = strchr(q1,c);
		if (q1!=NULL)
		{
			strncpy(p[ncount],q2,q1-q2);
			p[ncount][q1 - q2] = '\0';
			ncount++;

			q2 = q1 = q1 + 1;
		}
		else
		{
			break;
		}

	} while (*q1 != '\0');
	*ccount = ncount;

	return ret;
}

// 打印
void PrintString(char **p, int num)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("%s\n", p[i]);
	}

}

int Memo_Free(char ***p,int num)
{
	int ret = 0;
	int i = 0;
	char ** tep = NULL;
	if (p==NULL)
	{
		ret = -1;
		return ret;

	}
	tep = *p;
	for ( i = 0; i < num; i++)
	{
		free(tep[i]);
	}

	free(tep);

	*p = NULL;



}


void main18()
{
	int i = 0;
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char p2 = ',';
	int count = 0;

	char **p3 = NULL;  // 相当于，分配一个char buf[10][30],内存
	int num = 10;      
	// 分配一维内存空间                           
	p3 = (char**)malloc(sizeof(char*)*num); // 相当于，char *array[num];     

	
	if (p3!= NULL)
	{
		for ( i = 0; i < num; i++) // 分配二维内存空间
		{
			p3[i] = (char*)malloc(sizeof(char)*30);
		}
	}



	int ret = SplitString(p1,p2,&count,p3);

	//for ( i = 0; i <count; i++)
	//{
	//	printf("%s\n",p3[i]);
	//}
	PrintString(p3,count);
	Memo_Free(&p3, num);
	//for ( i = 0; i < num; i++)
	//{
	//	free(p3[i]);
	//}
	//free(p3);
	//p3 = NULL;
	

	printf("hello...\n");
	system("pause");
}