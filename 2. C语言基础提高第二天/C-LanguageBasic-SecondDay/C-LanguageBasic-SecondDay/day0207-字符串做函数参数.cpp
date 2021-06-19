# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// 初级版的，字符串copy技术
void main13()
{
	//将一个字符串从a[]中，copy到b[64]中
	char a[] = "i am a student!";
	char b[64];
	int i = 0;

	for (i = 0; *(a + i) != '\0';i++)
	{
		*(b + i) = *(a+i);
	}
	// 未copy到字符串的的尾部 '\0',这里需要手动添加'\0'
	b[i] = '\0';
	printf("a:%s\n",a);
	printf("b:%s\n",b);
	
	printf("hello...\n");
	system("pause");
}



// 字符串copy技术推演
void CopyStr_01(char *from,char *to)
{
	
	for (; *from != '\0';from++,to++)
	{
		*to = *from;
	}
	*to = '\0';
}
// 01优化成02
void CopyStr_02(char *from,char *to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;  // 由于++的优先级高于*， 但由于此处是后++；因此，此处相当于先执行*to = *from;再执行from++,to++
	}
	*to = '\0';
}
// 02优化成03
void CopyStr_03(char *from,char *to)
{
	while ((*to = *from) != '\0')// 也即，*to=a、*to=b、*to=c、*to=d、*to=\0,当*to=\0时，跳出while循环
	{
		from++;
		to++;
	}
}
// 03优化成04
void CopyStr_04(char *from,char *to)
{
	while ((*to++ = *from++)!= '\0')
	{
		;
	}

}
// 04优化成05
void CopyStr_05(char *from,char *to)
{
	while (*to++ = *from++)
	{
		;
	}

}

void CopyStr_05_err(char *from, char *to)
{
	while (*to++ = *from++)
	{
		;
	}
	printf("from:%s\n",from);
}

int CopyStr_06(char *from,char *to)
{
	if (from == NULL || to == NULL)
	{
		return -1;
	}
	while (*to++ == *from++)
	{
		;
	}
// 或	while (*to++ == *from++);
	
}

int CopyStr_06_good(char *from, char *to)
{//   一般情况下，不要轻易改变形参的值  ，运用指针辅助变量把形参的值，接过来，通过辅助指针变量去改变同一区域的的值（避免了改变形参的值），
 //如CopyStr_06_good() ，这样在打印形参from的值时，还可以打印出abcd,// 如果没有指针辅助变量，直接去打印形参from的值，则打印不出from的接
 //受过来的值，如在CopyStr_05_err()中,printf("from:%s \n", from);打印不出from的值
// 如果从主函数中传过来的内存首地址from，为在堆上分配的内存，并没有辅助指针变量，那么在指针变量from被改变后，去释放堆上分配的内存时，会出现无法释放的问题，因为from的内存地址指向已经被改变
	char *tpfrom = from; // 辅助指针变量。
	char *tpto = to;

	if (tpfrom == NULL || tpto == NULL)
	{
		return -1;
	}
	while (*tpto++ == *tpfrom++)
	{
		;
	}
	// 或	while (*to++ == *from++);
	printf("from:%s\n", from);

}

void main14()
{
	int ret = 0;
	char *p1 = "abcd";
	char c[100];

	CopyStr_01(p1, c);
	printf("c:%s\n",c);

	CopyStr_02(p1, c);
	printf("c:%s\n", c);

	CopyStr_03(p1, c);
	printf("c:%s\n", c);

	CopyStr_04(p1, c);
	printf("c:%s\n", c);

	CopyStr_05(p1, c);
	printf("c:%s\n", c);


	//{// 错误案例
	//	char *p2 = NULL;  //指针变量myto指向操作系统保护的地方，操作系统保护的地方不允许程序员手动去改变它的值，如果让程序运行，会在被调用函数中挂掉。
	//	CopyStr_05(p1, p2);// //可以对函数CopyStr_05优化成CopyStr_06，避免这种情况发生。
	//}
    
	char *p2 = NULL;
	ret = CopyStr_06(p1,p2);
	if (ret!=0)
	{
		printf("fuc:CopyStr_06:err:%d\n",ret);
		system("pause");
		return;
	}
	printf("hello...\n");
	system("pause");
}

void main15()
{
	int ret = 0;
	char *p1 = "abcd";
	char c[100];

	printf("after CopyStr_05_err:\n");
	CopyStr_05_err(p1,c);   // 未申请辅助指针变量，复制过程中，改变了形参的指向，使形参指向指向了字符串结尾

	printf("after CopyStr_06_good:\n");
	CopyStr_06_good(p1,c); //复制过程中，只改变的是辅助指针的值，形参的值没被改变。
    

	printf("hello...\n");
	system("pause");


}


