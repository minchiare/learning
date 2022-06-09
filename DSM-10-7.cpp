#include<stdio.h>
#include<stdlib.h>
main()
{
	FILE *fp;
	char filename[50];
	printf("please input the name of the file which do you want to delete:\n");
	scanf("%s",filename);
	if((fp=fopen (filename,"r"))!=NULL)
	{
		printf("%s open successfully!",filename);
		fclose(fp);
	}
	else
	{
		printf("%s cannot open!",filename);
		exit(0);
	}
	remove(filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("\n%s has removed!",filename);
	}
	else
		printf("error");
}
