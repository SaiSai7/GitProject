# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"

/////////////////////********* �༶ָ�����Ұָ���֪ʶ��**************//////////////////////////////////////////
/*1. һά�ڴ���䲻�ɹ����������˵����һά�ڴ�û�з��䵽��ֱ��return��ȥ�Ϳ����ˣ��������ͷŴ���-��Ϊû�з��䵽�ڴ�
  2. һά�ڴ����ɹ�����ά�ڴ����ʱ�����ַ���ɹ������ַ���ʧ�ܣ������������Ҫ��������ɹ����ڴ棬����ʱһά�ڴ�
  ���Ƕ�ά�ڴ�ͳͳ�ͷŵ����Ա������������ڴ�
  */


// �����ú����з����ڴ�---��ȷ�����ڴ�(Ҳ��������Ҫ�洢������ռ�ڴ��С���о�ȷ����)---ͨ������ֵ����ʽ����
char ** SplitString01(char *myp, char c, int *ccount)
{
	int ret = 0; int ncount = 0; int i = 0; int len = 0;

	char *q1 = NULL;//����ʼ������ָ����� q1��q2��
	char *q2 = NULL;
	
	
	char **p3 = NULL;//����ʼ��������洢ָ�����p3��
	q1 = q2 = myp; // (��ʼ��ָ�븨��ָ�������λ�ã�����ͬʱָ���ַ�����ͷ)

	// 1. �����Ҫ�����ڴ��������Ҳ��һάԪ�صĸ��� 
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			ncount++;  // �ڴ�����

			q2 = q1 = q1 + 1; // ���´ﵽ����һ�β�������
		}
		else
		{
			break;
		}
	} while (*q1 != '\0');
	*ccount = ncount;

	// 2. ���������������ڴ���������
	p3 = (char**)malloc(sizeof(char*)*ncount);  // һάԪ�ظ�����ȷ����
	if (p3 == NULL)
	{
		printf("����һάԪ���ڴ����ʱ����\n");
		return NULL;
	}
	//////////////////////////////////////////////////////////////////////////


	ncount = 0; // �ٳ�ʼ��ncountΪ0��������һ�Σ�ɨ��
	q1 = q2 = myp; // ���ø���ָ�����ָ���ַ�������ʼλ��
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			if (q1-q2>0)
			{
				len = q1 - q2 + 1; // +1��Ϊ�ˣ��洢��\0��,��Ϊq1 - q2�ĳ��ȣ���������\0��
				p3[ncount] = (char *)malloc(sizeof(char)*len);
				if (p3[ncount]==NULL)
				{
					return NULL;
				}
				strncpy(p3[ncount],q2,q1-q2);
				p3[ncount][q1-q2] = '\0';
				ncount++;  // �ڴ�����

				q2 = q1 = q1 + 1; // ���´ﵽ����һ�β�������
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
	if (p == NULL) // ��˵����һά�ڴ���Դ����ʱ���ͳ��ִ���,�޷����
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (p[i] != NULL) // �������ڴ���Դ���������£�Ҳ���뵽�ڴ���Դ�ˣ������p[i]��=NULL��˵�������ڴ�ɹ�����ô
		{
			free(p[i]);// ���ѳɹ����䵽�������ڴ���Դ�ͷŵ�������p[i]==NULL����˵��û�з��䵽���ڴ棩�Ͳ����ͷ���
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
	if (p == NULL) // �����жϣ����������β�����ָ��p�Ƿ�ΪNULL
	{
		return;
	}
	mp = *p;
	if (mp ==NULL) // �����жϣ�һά�ڴ��Ƿ�����ɹ����������ʧ�ܣ�ֱ���˳�������
	{
		return;
	}
	for (i = 0; i < num; i++)
	{
		if (mp[i] != NULL) // �������ڴ���Դ���������£�Ҳ���뵽�ڴ���Դ��
		{
			free(mp[i]);// ���Ѿ��������ڴ����Դ�ͷŵ���δ����ľͲ����ͷ���
		}

	}
	if (p != NULL)
	{
		free(mp);
	}
	*p = NULL;
}


// �����ú��������ڴ�--��ȷ�����ڴ� ͨ��ָ�������������ķ�ʽ����
int SplitString02(char *myp, char c,char ***p, int *ccount)
{
	int ret = 0; int ncount = 0; int i = 0; int len = 0;

	char *q1 = NULL;  //����ʼ������ָ����� q1��q2��
	char *q2 = NULL;  


	char **p3 = NULL;//����ʼ��������洢ָ�����p3��
	q1 = q2 = myp; // (��ʼ��ָ�븨��ָ�������λ�ã�����ͬʱָ���ַ�����ͷ)

 // 1. �����Ҫ�����ڴ��������Ҳ��һάԪ�صĸ��� 
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			ncount++;  // �ڴ�����

			q2 = q1 = q1 + 1; // ���´ﵽ����һ�β�������
		}
		else
		{
			break;
		}
	} while (*q1 != '\0');
	*ccount = ncount;

// 2. ���������������ڴ���������
	p3 = (char**)malloc(sizeof(char*)*ncount);  // һάԪ�ظ�����ȷ����

	// ����У�һ����ڣ�������ڱ����ú�����������return ʱ����������Դ���룬��ô���ò�������������µģ���������ڴ��ͷŵ�,��ʱ��õķ����ǣ���goto END�ķ�ʽ����ͳһ����������return
	// 
	if (p3 == NULL)   // ����˴����ַ����ڴ������������޷����
	{
		ret = -1;	
		printf("fun SplitString02()::%d p3 = (char**)malloc(sizeof(char*)*ncount) \n",ret);
		goto END;
		//return ret; // ��������һ
	}
	memset(p3,0, sizeof(char*)*ncount); // ��������������ڴ�ռ��ʼ��Ϊ0���Ա���һά�ڴ����Ұָ�룬�Ա����ж�


	//////////////////////////////////////////////////////////////////////////
	ncount = 0; // �ٳ�ʼ��ncountΪ0��������һ�Σ�ɨ��
	q1 = q2 = myp; 
	
	// ���ø���ָ�����ָ���ַ�������ʼλ��
	do
	{
		q1 = strchr(q1, c);
		if (q1 != NULL)
		{
			if (q1 - q2>0)
			{
				len = q1 - q2 + 1; // +1��Ϊ�ˣ��洢��\0��,��Ϊq1 - q2�ĳ��ȣ���������\0��
				p3[ncount] = (char *)malloc(sizeof(char)*len);

				if (p3[ncount] == NULL) // ��������ڴ�ʱ�����ֳ������
				{
					ret = -2;
					printf("fun SplitString02()::%d p3[ncount] = (char *)malloc(sizeof(char)*len)\n", ret);
					goto END;
					//return ret;  // �������ڶ�
				}
				strncpy(p3[ncount], q2, q1 - q2);
				p3[ncount][q1 - q2] = '\0';
				ncount++;  // �ڴ�����

				q2 = q1 = q1 + 1; // ���´ﵽ����һ�β�������

			}

		}
		else
		{
			break;
		}
	} while (*q1 != '\0');

END:  // �ɽ��ڴ���Դ�������ʱ�ģ���Դ�ͷţ��Ż���һ������
	if (ret!=0) // ˵�������ڴ���Դʱ������ô��Ҫ����������ڴ���Դȫ���ͷŵ�
	{
		//if (p3 == NULL) // ��˵����һά�ڴ���Դ����ʱ��û���䵽�ڴ棬��˲���Ҫ�����ͷ�
		//{
		//	return ret;
		//}
		//for ( i = 0; i < *ccount; i++)
		//{
		//	if (p3[i]!=NULL) // �������ڴ���Դ���������£�Ҳ���뵽�ڴ���Դ��
		//	{
		//		free(p3[i]);// ��������ĺ��޴���������ڴ���Դ�ͷŵ�
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
	else // �ڴ���Դ����ɹ�
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

	char **p3 = NULL; // δ�����ڴ棬�ڱ��������У������ڴ�
	
	//p3 = SplitString01(p1, p2, &count);
	int ret = SplitString02(p1,p2,&p3,&count);
	if (ret ==-1)
	{
		printf("fuc SplitString02():: һά�ڴ����ʱ������\n");
		return ret;
	}
	if (ret == -2)
	{
		printf("fuc SplitString02():: ��ά�ڴ����ʱ������\n");
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