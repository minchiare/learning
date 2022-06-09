#include<stdio.h>
#define N 100
int F(int i);
int main()
{
	int n,i;
	int num;
	printf("«Î ‰»În£∫");
	scanf("%d",&n);
	num=F(n);
	printf("\n");
	for (i=1;i<=n;i++)
	{
		num=F(1);
		printf("F(%d)=%d\n",i,num);
	 }
return 0; 
}
int F(int i)
{
	if(i==1||i==2)
	{
		return 1;
	}
	else
	{
		return F(i-1)+F(i-2);
	}
}
