# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"


// ָ��������������-----�ڱ����ú����з����ڴ�(ָ���������)��Ҳ���൱���ڱ����ú����У��޸�ʵ�ε�ֵ
int GetMemo(char **p1/*out*/,int *mylen1/*out*/, char **p2/*out*/, int *mylen2/*out*/)
{
	int ret = 0;
	char *tem1, *tem2;

	tem1 = (char *)malloc(128);
	strcpy(tem1,"abcdefghijklmnopqrst");

	*mylen1 = strlen(tem1);
	*p1 = tem1;

	tem2 = (char *)malloc(128);
	strcpy(tem2,"1234567890abcdefgh");

	*mylen2 = strlen(tem2);
	*p2 = tem2;

	return ret;



}

int  main08()
{
	int ret = 0;
	char *p1 = NULL; // ָ�����p1,�������գ��Ӻ�������õ��ڴ��ŵ�ַ
	char *p2 = NULL;
	int len1 = 0;
	int len2 = 0;

	ret = GetMemo(&p1, &len1, &p2, &len2);//�ֱ��ڱ����ú����У��޸�0��ָ���ֵ��1��ָ���ֵ
	if (ret != 0)
	{
		printf("func:GetMemo():err %d\n",ret);
		return ret;
	}
	printf("p1:%s\n",p1);
	printf("p2:%s\n",p2);
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
	if (p2 != NULL)
	{
		free(p2);
		p2 = NULL;
	}
	printf("hello...\n");
	system("pause");
}