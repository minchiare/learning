#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char i,j;
	char filename[30];
	printf("�������ļ���:\n");
	show:
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("�޷��򿪣������������ļ�����");
		getchar();
		goto show;
	}
	fp = fopen(filename,"r");
	for(i=0;i<5;i++)
	{
		fscanf(fp,"%c",&j);
		printf("%d is :%5d\n",i+1,j);
	}
	fclose(fp);
}
