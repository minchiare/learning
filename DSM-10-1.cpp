#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    printf("������Ҫд������ݣ���#����\n"); 
    if((fp=fopen("d:\\exp01.txt","w"))==NULL)
    {
    	printf("�޷����ļ�");
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
