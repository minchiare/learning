#include<stdio.h>
int fun(int n)
{
if(n==1||n==0) return 1;
return n*fun(n-1);
	
}
int main()
{
	int n ;
	printf("n=");
	scanf("%d",&n);
	printf("n!=%d\n",fun(n));
	return 0; 
}
