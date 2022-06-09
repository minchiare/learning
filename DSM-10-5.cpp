#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char i=88;
	char filename[30];
	printf("请输入文件名:\n");
	show:
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)
	{
		printf("无法打开！请重新输入文件名：");
		getchar();
		goto show;
	}
	fprintf(fp,"%c",i);
	fclose(fp);
}
