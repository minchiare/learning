#include<stdio.h>
int main()
{
	int a[2][3],b[3][2];
	int max,min;
	int h,j,l,i;
	for (i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("�������ά���飺\n");
	for (i=0;i<2;i++)
	{
		for (j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	max=a[0][0];
	h=0;
	l=0;
	for (i=0;i<2;i++)
	{
		for (j=0;j<3;j++)
		{
			if(max<a[i][j])
			{
				max =a[i][j];
				h=i;
				l=j;
			}
		 } 
	}
	printf("���������Ԫ���ǣ�\n");
	for(i=0;i<2;i++)
	{
		for (j=0;j<3;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	printf("���ת����Ķ�ά���飺\n");
	for (i=0;i<3;i++)
	{
		for (j=0;j<2;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
