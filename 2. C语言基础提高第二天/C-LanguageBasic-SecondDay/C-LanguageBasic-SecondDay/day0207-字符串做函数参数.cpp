# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// ������ģ��ַ���copy����
void main13()
{
	//��һ���ַ�����a[]�У�copy��b[64]��
	char a[] = "i am a student!";
	char b[64];
	int i = 0;

	for (i = 0; *(a + i) != '\0';i++)
	{
		*(b + i) = *(a+i);
	}
	// δcopy���ַ����ĵ�β�� '\0',������Ҫ�ֶ����'\0'
	b[i] = '\0';
	printf("a:%s\n",a);
	printf("b:%s\n",b);
	
	printf("hello...\n");
	system("pause");
}



// �ַ���copy��������
void CopyStr_01(char *from,char *to)
{
	
	for (; *from != '\0';from++,to++)
	{
		*to = *from;
	}
	*to = '\0';
}
// 01�Ż���02
void CopyStr_02(char *from,char *to)
{
	for (; *from != '\0';)
	{
		*to++ = *from++;  // ����++�����ȼ�����*�� �����ڴ˴��Ǻ�++����ˣ��˴��൱����ִ��*to = *from;��ִ��from++,to++
	}
	*to = '\0';
}
// 02�Ż���03
void CopyStr_03(char *from,char *to)
{
	while ((*to = *from) != '\0')// Ҳ����*to=a��*to=b��*to=c��*to=d��*to=\0,��*to=\0ʱ������whileѭ��
	{
		from++;
		to++;
	}
}
// 03�Ż���04
void CopyStr_04(char *from,char *to)
{
	while ((*to++ = *from++)!= '\0')
	{
		;
	}

}
// 04�Ż���05
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
// ��	while (*to++ == *from++);
	
}

int CopyStr_06_good(char *from, char *to)
{//   һ������£���Ҫ���׸ı��βε�ֵ  ������ָ�븨���������βε�ֵ���ӹ�����ͨ������ָ�����ȥ�ı�ͬһ����ĵ�ֵ�������˸ı��βε�ֵ����
 //��CopyStr_06_good() �������ڴ�ӡ�β�from��ֵʱ�������Դ�ӡ��abcd,// ���û��ָ�븨��������ֱ��ȥ��ӡ�β�from��ֵ�����ӡ����from�Ľ�
 //�ܹ�����ֵ������CopyStr_05_err()��,printf("from:%s \n", from);��ӡ����from��ֵ
// ������������д��������ڴ��׵�ַfrom��Ϊ�ڶ��Ϸ�����ڴ棬��û�и���ָ���������ô��ָ�����from���ı��ȥ�ͷŶ��Ϸ�����ڴ�ʱ��������޷��ͷŵ����⣬��Ϊfrom���ڴ��ַָ���Ѿ����ı�
	char *tpfrom = from; // ����ָ�������
	char *tpto = to;

	if (tpfrom == NULL || tpto == NULL)
	{
		return -1;
	}
	while (*tpto++ == *tpfrom++)
	{
		;
	}
	// ��	while (*to++ == *from++);
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


	//{// ������
	//	char *p2 = NULL;  //ָ�����mytoָ�����ϵͳ�����ĵط�������ϵͳ�����ĵط����������Ա�ֶ�ȥ�ı�����ֵ������ó������У����ڱ����ú����йҵ���
	//	CopyStr_05(p1, p2);// //���ԶԺ���CopyStr_05�Ż���CopyStr_06�������������������
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
	CopyStr_05_err(p1,c);   // δ���븨��ָ����������ƹ����У��ı����βε�ָ��ʹ�β�ָ��ָ�����ַ�����β

	printf("after CopyStr_06_good:\n");
	CopyStr_06_good(p1,c); //���ƹ����У�ֻ�ı���Ǹ���ָ���ֵ���βε�ֵû���ı䡣
    

	printf("hello...\n");
	system("pause");


}


