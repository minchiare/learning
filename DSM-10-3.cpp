#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char filename[30],str[30];
    printf("�������ļ������ƣ�\n");
    show:
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
    	printf("�޷����ļ��������������ļ�����");
    	getchar();
		goto show; 
	}
	fp = fopen(filename,"w");
	printf("�������ַ���:\n");
	getchar();
	gets(str);
	fputs(str,fp);
	fclose(fp);
}
