#include<stdio.h>
#include<math.h>
int a(int m)
{
	int b;
	b =	sqrt(m);
	int i;
	for(i=2;i<b+1;i++)
	{
		int n;
		n=m%i;
		if(n==0)
		{
			printf("输入的数%d不是素数",m);
			goto Show;
		}
		else if(i==b)
		{
			printf("输入的数%d是素数",m); 
		}
	}
	Show:
	return 0;
}

int main()
{
	int m;
	printf("请输入一个正整数：");
	scanf("%d",&m);
	a(m);
	return 0;
}
