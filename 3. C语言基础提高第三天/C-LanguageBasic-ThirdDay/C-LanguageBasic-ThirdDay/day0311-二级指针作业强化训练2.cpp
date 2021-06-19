# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

/////////////////////********* 多级指针避免野指针的知识点**************//////////////////////////////////////////
/*1. 一维内存分配不成功！这种情况说明，一维内存没有分配到，直接return出去就可以了，不用做释放处理-因为没有分配到内存
  2. 一维内存分配成功，二维内存分配时，部分分配成功，部分分配失败！这种情况，需要将所分配成功的内存，不管时一维内存
  还是二维内存统统释放掉，以便于重新申请内存
  */


// 被调用函数中分配内存---精确分配内存(也即根据所要存储对象所占内存大小进行精确分配)---通过返回值的形式操作
char ** SplitString01(char *myp, char c, int *ccount)
{
	int ret = 0; int ncount = 0; int i = 0; int len = 0;

	char *q1 = NULL;//（初始化辅助指针变量 q1、q2）
	char *q2 = NULL;
	
	
	char **p3 = NULL;//（初始化所分配存储指针变量p3）
	q1 = q2 = myp; // (初始化指针辅助指针变量的位置，让其同时指向，字符串开头)

	// 1. 求出所要分配内存的行数，也即一维元素的个数 
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			ncount++;  // 内存行数

			q2 = q1 = q1 + 1; // 重新达到，下一次查找条件
		}
		else
		{
			break;
		}
	} while (*q1 != '\0');
	*ccount = ncount;

	// 2. 根据行数，进行内存行数分配
	p3 = (char**)malloc(sizeof(char*)*ncount);  // 一维元素个数精确分配
	if (p3 == NULL)
	{
		printf("进行一维元素内存分配时出错\n");
		return NULL;
	}
	//////////////////////////////////////////////////////////////////////////


	ncount = 0; // 再初始化ncount为0，进行下一次，扫描
	q1 = q2 = myp; // 设置辅助指针变量指向字符串的起始位置
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			if (q1-q2>0)
			{
				len = q1 - q2 + 1; // +1是为了，存储‘\0’,因为q1 - q2的长度，不包括‘\0’
				p3[ncount] = (char *)malloc(sizeof(char)*len);
				if (p3[ncount]==NULL)
				{
					return NULL;
				}
				strncpy(p3[ncount],q2,q1-q2);
				p3[ncount][q1-q2] = '\0';
				ncount++;  // 内存行数

				q2 = q1 = q1 + 1; // 重新达到，下一次查找条件
			}
			
		}
		else
		{
			break;
		}
	} while (*q1 != '\0');


	return p3;
}


void eorrMemo_Free(char **p, int num)
{
	int i = 0;
	if (p == NULL) // 则说明，一维内存资源申请时，就出现错误,无法解决
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (p[i] != NULL) // 在申请内存资源出错的情况下，也申请到内存资源了，（如果p[i]！=NULL，说明分配内存成功）那么
		{
			free(p[i]);// 将已成功分配到的所有内存资源释放掉，（若p[i]==NULL，则说明没有分配到的内存）就不用释放了
		}

	}
	if (p != NULL)
	{
		free(p);
	}
}
void eorrMemo_Free02(char ***p, int num)
{
	int i = 0;
	char **mp = NULL;
	if (p == NULL) // 用来判断，传过来的形参三级指针p是否为NULL
	{
		return;
	}
	mp = *p;
	if (mp ==NULL) // 用来判断，一维内存是否申请成功，如果申请失败，直接退出本函数
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (mp[i] != NULL) // 在申请内存资源出错的情况下，也申请到内存资源了
		{
			free(mp[i]);// 将已经分配了内存的资源释放掉，未分配的就不用释放了
		}

	}
	if (p != NULL)
	{
		free(mp);
	}
	*p = NULL;
}


// 被调用函数分配内存--精确分配内存 通过指针做函数参数的方式操作
int SplitString02(char *myp, char c,char ***p, int *ccount)
{
	int ret = 0; int ncount = 0; int i = 0; int len = 0;

	char *q1 = NULL;  //（初始化辅助指针变量 q1、q2）
	char *q2 = NULL;  


	char **p3 = NULL;//（初始化所分配存储指针变量p3）
	q1 = q2 = myp; // (初始化指针辅助指针变量的位置，让其同时指向，字符串开头)

 // 1. 求出所要分配内存的行数，也即一维元素的个数 
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			ncount++;  // 内存行数

			q2 = q1 = q1 + 1; // 重新达到，下一次查找条件
		}
		else
		{
			break;
		}
	} while (*q1 != '\0');
	*ccount = ncount;

// 2. 根据行数，进行内存行数分配
	p3 = (char**)malloc(sizeof(char*)*ncount);  // 一维元素个数精确分配

	// 针对有，一个入口，多个出口被调用函数，假设在return 时，存在有资源申请，那么不得不将出错情况的下的，所分配的内存释放掉,此时最好的方法是，用goto END的方式进行统一处理，而不用return
	// 
	if (p3 == NULL)   // 假设此处出现分配内存出错情况，则无法解决
	{
		ret = -1;	
		printf("fun SplitString02()::%d p3 = (char**)malloc(sizeof(char*)*ncount) \n",ret);
		goto END;
		//return ret; // 函数出口一
	}
	memset(p3,0, sizeof(char*)*ncount); // 将所申请的所有内存空间初始化为0，以避免一维内存出现野指针，以便于判断


	//////////////////////////////////////////////////////////////////////////
	ncount = 0; // 再初始化ncount为0，进行下一次，扫描
	q1 = q2 = myp; 
	
	// 设置辅助指针变量指向字符串的起始位置
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			if (q1 - q2>0)
			{
				len = q1 - q2 + 1; // +1是为了，存储‘\0’,因为q1 - q2的长度，不包括‘\0’
				p3[ncount] = (char *)malloc(sizeof(char)*len);

				if (p3[ncount] == NULL) // 假设分配内存时，出现出错情况
				{
					ret = -2;
					printf("fun SplitString02()::%d p3[ncount] = (char *)malloc(sizeof(char)*len)\n", ret);
					goto END;
					//return ret;  // 函数出口二
				}
				strncpy(p3[ncount], q2, q1 - q2);
				p3[ncount][q1 - q2] = '\0';
				ncount++;  // 内存行数

				q2 = q1 = q1 + 1; // 重新达到，下一次查找条件

			}

		}
		else
		{
			break;
		}
	} while (*q1 != '\0');

END:  // 可将内存资源申请出错时的，资源释放，优化成一个函数
	if (ret!=0) // 说明申请内存资源时出错，那么需要把所申请的内存资源全部释放掉
	{
		//if (p3 == NULL) // 则说明，一维内存资源申请时，没分配到内存，因此不需要进行释放
		//{
		//	return ret;
		//}
		//for ( i = 0; i < *ccount; i++)
		//{
		//	if (p3[i]!=NULL) // 在申请内存资源出错的情况下，也申请到内存资源了
		//	{
		//		free(p3[i]);// 将出错误的和无错误的所有内存资源释放掉
		//	}
		//	
		//}
		//if (p3 != NULL)
		//{
		//	free(p3);
		//}
		eorrMemo_Free02(&p3, *ccount);
		//eorrMemo_Free(p3, *ccount);
		//p3 = NULL;
	}
	else // 内存资源申请成功
	{
		*p = p3;
	}


	return ret;
}


int main()
{
	int i = 0;
	char *p1 = "abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";
	char p2 = ',';
	int count = 0;

	char **p3 = NULL; // 未分配内存，在被调函数中，分配内存
	
	//p3 = SplitString01(p1, p2, &count);
	int ret = SplitString02(p1,p2,&p3,&count);
	if (ret ==-1)
	{
		printf("fuc SplitString02():: 一维内存分配时，出错！\n");
		return ret;
	}
	if (ret == -2)
	{
		printf("fuc SplitString02():: 二维内存分配时，出错！\n");
		return ret;
	}

	for ( i = 0; i <count; i++)
	{
		printf("%s\n",p3[i]);
	}
	/*PrintString(p3, count);
	Memo_Free(&p3, num);*/
	for ( i = 0; i <count; i++)
	{
		free(p3[i]);
	}
	free(p3);
	p3 = NULL;


	printf("hello...\n");
	system("pause");
	return 0;
}