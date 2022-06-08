#include<stdio.h>
int main()
{
	int *p,q;
	printf("please input:\n");
	scanf("%d",&q);
	p=&q;
	printf("the number is :\n");
	printf("%d\n",*p);
	return 0;
}
