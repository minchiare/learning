#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    printf("请输入要写入的内容，以#结束\n"); 
    if((fp=fopen("d:\\exp01.txt","w"))==NULL)
    {
    	printf("无法打开文件");
		exit(0); 
	}
	fp = fopen("d:\\exp01.txt","w");
    ch=getchar();
    while(ch!='#')
    {
        fputc(ch,fp);
        ch=getchar();
    }
    fclose(fp);
}
