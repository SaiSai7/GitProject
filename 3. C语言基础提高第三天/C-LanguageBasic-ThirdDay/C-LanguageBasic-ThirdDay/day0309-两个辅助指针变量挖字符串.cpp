# define _CRT_SECURE_NO_WARNINGS
# include "stdio.h"
# include "stdlib.h"
# include "string.h"
# include "ctype.h"


//��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";��
// Ҫ��д��һ�������ӿڣ�������½����
// ��1���Զ��ŷָ��ַ������γɶ�ά���飬���ѽ��������
// ��2���Ѷ�ά�����������Ҳ���� 

int SplitString(char *p,char c, char buf[10][30],int *count)
{
	int ret = 0;
	char *q1 = NULL;
	char *q2 = NULL;
	int ncount = 0;

	q1 = q2 = p;// ��һ��������ָ�������ָ����ʼλ��

		do
		{
			
			q1 = strchr(q1, c);// �ڶ������ҳ��ַ����У����ţ��״γ��ֵ�λ�ã�������һ������ָ���������ƶ���
			if (q1 != NULL)
			{
				if (q1-q2>0)   // �����ƶ��ĸ���ָ�����p1��δ�ƶ���ָ�����p2����ֵ�����ַ���
				{
					strncpy(buf[ncount], q2, q1 - q2); // ����һ�����ţ���ǰ���ַ�������ֵ��ָ���ڴ���
					buf[ncount][q1 - q2] = '\0'; // �ѵ�ncount���ַ���ת��ΪC�����ַ���
					ncount++;

					q2 = q1 = q1 + 1;//��q1��q2���´ﵽ��һ�μ�������
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
// ��ӡ
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