#include<stdio.h>
int main()
{
	int m,n;
	printf("�������������֣�");
	scanf("%d %d",&m,&n);
	int r=0;
	while(n!=0)	   
	{
		r=m%n;
		m=n;
		n=r;
	}
	printf("�������ֵ����Լ��Ϊ%d\n",m);
	
	return 0;
}

