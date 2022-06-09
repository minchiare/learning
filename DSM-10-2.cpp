#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;
    char ch;
    fp=fopen("d:\\exp02.txt","r");
    ch = fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch = fgetc(fp);
    }
    fclose(fp);
}
