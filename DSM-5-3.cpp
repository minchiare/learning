#include<stdio.h>
int main()
{
	int i,j,n;
	printf("请输入数组个数：");
	scanf("%d",&n); 
	int a[n];
	int iTemp;
	printf("为数组元素赋值：\n");
	for (i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
		
	}
	for (i=1;i<n;i++)
	{
		for (j=n-1;j>=i;j--)
		{
			if(a[j]<a[j-1])
			{
				iTemp= a[j-1];
				a[j-1]=a[j];
				a[j]=iTemp;
			}
		}
	}
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
			printf("\n");
	}
}
