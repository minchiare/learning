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
			printf("�������%d��������",m);
			goto Show;
		}
		else if(i==b)
		{
			printf("�������%d������",m); 
		}
	}
	Show:
	return 0;
}

int main()
{
	int m;
	printf("������һ����������");
	scanf("%d",&m);
	a(m);
	return 0;
}
