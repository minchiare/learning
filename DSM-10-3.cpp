#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char filename[30],str[30];
    printf("请输入文件的名称：\n");
    show:
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
    	printf("无法打开文件，请重新输入文件名：");
    	getchar();
		goto show; 
	}
	fp = fopen(filename,"w");
	printf("请输入字符串:\n");
	getchar();
	gets(str);
	fputs(str,fp);
	fclose(fp);
}
