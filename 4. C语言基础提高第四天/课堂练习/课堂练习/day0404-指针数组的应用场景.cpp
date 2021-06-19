# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"
# define DIM(a) sizeof(a)/sizeof(*a)  // ��һ���㣬���滻



int searcheKeyTable(char *table[],int num,char *p,int *pos)// �ڶ����㣬�����������������˻�Ϊָ������⣬���������е�char *table[]����ͬ��char **table;,д��char *table[]�����ڳ���Ա�Ķ�
{
	int ret = 0, i = 0;
	int nmb = sizeof(table) / sizeof(*table);// ����������num��ȣ���nubΪ1����˵������ά���������������˻�ָ�룬��Ϊ������tableΪ����ָ��Ϊ4���ֽڣ�*tableΪһ��ָ��ҲΪ4���ֽ�
	printf("nmb:%d\n", nmb);                 // ��ӵ�֤���������������������˻�����
	if (table == NULL || p == NULL || pos == NULL)
	{
		ret = -1;
		
		return ret;
	}
	for ( i = 0; i < num; i++)
	{
		//if (strcmp(*(table + i), p) == 0)   C++�������Ὣtable[i]ת��Ϊ*(table + i)��ִ��
		if (strcmp(table[i], p) == 0)
		{
			*pos = i;
			return ret;
		}
	}

	// ��û���ҵ�ֱ�Ӵ���-1
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


	//ָ������
	char*   c_keyword[] = {
		"while",
		"case",
		"static",
		"do"
	};
	num = DIM(c_keyword);// �����sizeof( c_keyword)/sizeof(* c_keyword)
	printf("���� c_keywordԪ�ظ�����%d \n", num);

	//int ret = searcheKeyTable(c_keyword, DIM(c_keyword), "do", &pos);//�ɺ��滻ΪsearcheKeyTable(c_keyword,sizeof(c_keyword)/sizeof(*c_keyword), "do", &pos);
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

//main�����ǲ���ϵͳ���õĺ���
//�ڳ���ִ�е�ʱ�������main�������ݲ���

/*
argc �����в���
argv �����в�������
env  ������������

int main();
int main(int argc);
int main(int argc, char *argv[])
*/

void main008(int argc, char* argv[], char**env) // �����ڴ����ɲ���ϵͳ����ģ�main������Ӧ�ó���Ͳ���ϵͳ���������
{
	int i = 0;
	//main02_1();

	printf("******************* Begin argv *******************\n");
	for (i = 0; i<argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	// 	for(i=0; argv[i]!=NULL; i++) // ����������0��β������
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

	getchar(); //�ڳ���ĩβ��getchar(), �����ó��򲻻������˳�, ��system("pause"); ��һ���Ĺ���

}

// ָ����������ҽ�������
void main11()
{
	int i = 0;

	int pos = 0;
	int num = 0;


	//ָ������,�ڲ�֪��Ҫ�洢ָ������Ԫ�ظ���������£���ָ����������Ϊ�����ҽ������������飬������Ϊ����ָ���������һ��Ԫ�ص�β��
	// �ٷ���һ����ռ䣬��ӡ�\0����0��NULL���Գ�Ϊָ����������ı���
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