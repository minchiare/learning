#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char filename[30],str[30];
	printf("�������ļ���:\n");
	show:
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("�޷����ļ��������������ļ�����");
		getchar();
		goto show;
	}
	fgets(str ,sizeof(str),fp);
	printf("%s",str);
	fclose(fp);
}
