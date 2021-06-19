# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


// ��ͷ��ģ��  ��ǿո��ַ����ĳ���
void main19()
{
	int ncount = 0;
	char *p1 = "    abcdefg     ";

	// ����ָ���±����
	int i = 0;
	int j = 0;
	j = strlen(p1)-1;

	// ��ָ���±꣬����������������
	while (isspace(p1[i]) && p1[i] != '\0')
	{
		i++;
	}
	// ��ָ���±꣬����������������
	while (isspace(p1[j]) && p1[j]!='\0')
	{
		j--;
	}
	ncount = j - i + 1;
	printf("ncount:%d\n",ncount);

	
	printf("hello...\n");
	system("pause");
}


//��main19(),��װ�ɺ���
int GetStrNum(char *p,int *num)
{
	int ret = 0;
	int mynum = 0;
	int i = 0;
	int j = 0;
	char *myp = p;
	j = strlen(myp) - 1;
	if (p == NULL || num == NULL)
	{
		ret = -1;
		printf("func GetStrNum err:(p == NULL || num == NULL) %d\n",ret);
		return ret;


	}
	while (isspace(myp[i])&&myp[i] != '\n')
	{
		i++;
	}
	while (isspace(myp[j])&& myp[j]!= '\n')
	{
		j--;
	}
	*num = j - i + 1;
	return ret;
}

// ���пո��ַ����У��ǿո��ַ������ȣ��ǿ��ַ���
// Ȼ���µ��ַ������洢��һ���µ��ڴ�ռ���
int TrimStr(char *p, char *newp,int *num) 
{
	int ret = 0;
	int mynum = 0;
	int i = 0;
	int j = 0;
	j = strlen(p) - 1;
	char *myp = p;
	char *mynewp = newp;
	if (p == NULL || newp == NULL || num == NULL)
	{
		ret = -1;
		printf("func TrimStr() err :p == NULL || newp == NULL || num == NULL %d\n",ret);
		return ret;
	}
	while (isspace(myp[i]) && myp[i] != '\0')
	{
		i++;
	}
	while (isspace(myp[j]) && myp[j] != '\0')
	{
		j--;
	}
	mynum = j - i + 1;
	*num = mynum;
	strncpy(mynewp,myp+i,*num);
	mynewp[*num] = '\0';
	return ret;
}

// ��������ֱ�ӷ���str ��
// ����ȷ��str��ָ����ڴ�ռ���Ա��޸Ĳ��С���������������ܱ��޸ģ���������ʱ����ֶϵ�
int TrimStr02(char *p, int *num)
{
	int ret = 0;
	int mynum = 0;
	int i = 0;
	int j = 0;
	j = strlen(p) - 1;
	char *myp = p;
	if (p == NULL || num == NULL)
	{
		ret = -1;
		printf("func TrimStr() err :p == NULL || num == NULL %d\n", ret);
		return ret;
	}
	while (isspace(myp[i]) && myp[i] != '\0')
	{
		i++;
	}
	while (isspace(myp[j]) && myp[j] != '\0')
	{
		j--;
	}
	mynum = j - i + 1;
	*num = mynum;
	strncpy(myp, myp + i, *num);
	myp[*num] = '\0';
	return ret;
}

int main20()
{
	int numb = 0;
	int ret = 0;
	char *p2 = "    acdefghj     ";
	char *p3 = (char *)malloc(100);
	ret = GetStrNum(p2, &numb);
	if (ret != 0)
	{
		printf("func  GetStrNum err:%d\n",ret);
		return ret;
	}
	printf("numb:%d\n", numb);
	ret = TrimStr(p2, p3, &numb);
	if (ret != 0)
	{
		printf("func TrimStr() err %d\n",ret);
		return ret;
	}
	printf("str_p3's length:%d  p3:%s\n",numb,p3);

	if (p3 !=NULL)
	{
		free(p3);
		p3 = NULL;
	}
	printf("hello...\n");
	system("pause");
}

int main21()
{
	int numb = 0;
	int ret = 0;
	char *p2 = "    acdefghj     ";
	char *p3 = (char *)malloc(100);
	strcpy(p3,p2);

	ret = TrimStr02(p3,&numb);
	if (ret != 0)
	{
		printf("func TrimStr() err %d\n", ret);
		return ret;
	}
	printf("str_p2's length:%d  p2:%s\n", numb, p2);

	if (p3 != NULL)
	{
		free(p3);
		p3 = NULL;
	}


	printf("hello...\n");
	system("pause");
}