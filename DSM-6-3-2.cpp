#include<stdio.h>
#include<math.h>
int isPrime(int n);
int main()
{
	int n,i;
	printf("������һ��������:");
	scanf("%d",&n);
	printf("��%dǰ�����������������У�\n",n);
	for(i=2;i<=n;i++)
	{
		if(isPrime(i))
		printf("%d\n",i);
	}
	printf("\n");
	return 0; 
}
int isPrime(int n)
{
	int i=2;
	while(i<=(int) sqrt(n))
	{
		if(n%i==0)
			return 0;
		else
			i++;
	}
	return 1;
}
