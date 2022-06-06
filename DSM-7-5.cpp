#include <stdio.h>
#define N 100
int Fibonacci(int i);
int main()
{
	int n,i;
	int num;
	printf("«Î ‰»În:");
	scanf("%d",&n);
    num=Fibonacci(n);
	printf("\n");
	for(i=1;i<=n;i++)
	{
		num=Fibonacci(i);
		printf("Fibonacci(%d)=%d\n",i,num);
	}
	
	
return 0;
	
}
int Fibonacci(int i)
{
	if(i==1||i==2)
	{
		return 1;
	}	
	else{
		return Fibonacci(i-1)+Fibonacci(i-2);
	}	
			
}
