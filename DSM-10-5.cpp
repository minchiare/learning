#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char i=88;
	char filename[30];
	printf("�������ļ���:\n");
	show:
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("�޷��򿪣������������ļ�����");
		getchar();
		goto show;
	}
	fprintf(fp,"%c",i);
	fclose(fp);
}
