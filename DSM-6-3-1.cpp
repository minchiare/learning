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
	printf("������һ��������:");
	scanf("%d",&n);
	if(isprime(n))
	    printf("%d������",n);
	else
	    printf("%d��������",n);
	printf("\n");
}
