#include<stdio.h>
int main()
{
	int a[3][5],i,j;
	printf("please input :\n");
	for (i=0;i<3;i++)
	{
		for (j=0;j<5;j++)
		{
			scanf("%d",a[i]+j);
		}
	}
	printf("the array is :\n");
	for (i=0;i<3;i++)
	{
		for (j=0;j<5;j++)
		{
			printf("%5d",*(a[i]+j));
		}
		printf("\n");
	}
	return 0;
}
