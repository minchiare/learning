#include<stdio.h>
int isprime(int num)
{
    int flag=1,i;
	for(i=2;i<num/2;i++)
	    if(num%i==0)
		    flag=0;
	return(flag);
}
main()
{
    int n;
	printf("请输入一个正整数:");
	scanf("%d",&n);
	if(isprime(n))
	    printf("%d是素数",n);
	else
	    printf("%d不是素数",n);
	printf("\n");
}
