#include<stdio.h>
int fun(int n)
{
if(n==1||n==0) return 1;
n=n*fun(n-1);
return n;                
}

int main()      
{
int n;
printf("n=");
scanf("%d",&n);
printf("n!=%d\n",fun(n));
return 0;
}

