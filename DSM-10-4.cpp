#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	char filename[30],str[30];
	printf("请输入文件名:\n");
	show:
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("无法打开文件！请重新输入文件名：");
		getchar();
		goto show;
	}
	fgets(str ,sizeof(str),fp);
	printf("%s",str);
	fclose(fp);
}
