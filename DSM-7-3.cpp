#include<stdio.h>
int a(int m,int n);
int b(int m,int n);
int main()
{
	int m,n;
	printf("������������������");
	scanf("%d%d",&m,&n);
	printf("�������������ĵ����Լ����%d\n����������������С��������%d",a(m,n),b(m,n));
	return 0; 
}
int a(int m,int n)
{
	int iTemp;
	if(m<n)
	{
		iTemp=n;
		n=m;
		m=iTemp;
	}
	while(n!=0)
	{
		iTemp=m%n;
		m=n;
		n=iTemp;
	}
	return m;
}
int b(int m,int n)
{
	m=n*m/a(m,n);
	return m;
}
