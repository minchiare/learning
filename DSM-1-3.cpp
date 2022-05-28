#include<stdio.h>
int main()
{
	int m,n;
	printf("请输入两个数字：");
	scanf("%d %d",&m,&n);
	int r=0;
	while(n!=0)	   
	{
		r=m%n;
		m=n;
		n=r;
	}
	printf("两个数字的最大公约数为%d\n",m);
	
	return 0;
}

