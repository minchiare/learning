#include<stdio.h>
int main()
{
	int i,j,n;
	printf("���������������");
	scanf("%d",&n); 
	int a[n];
	int iTemp;
	printf("Ϊ����Ԫ�ظ�ֵ��\n");
	for (i=0;i<n;i++)
	{
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
		
	}
	for (i=1;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				iTemp= a[j+1];
				a[j+1]=a[j];
				a[j]=iTemp;
			}
		}
	}
	printf("��������飺\n");
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
		if(i==4)
			printf("\n");
	}
}
