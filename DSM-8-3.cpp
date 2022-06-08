#include<stdio.h>
int main()
{
	int i;
	int *p;
	printf("please int the number :\n");
	scanf("%d",&i);
	p=&i;
	printf("the result1 is :%d\n",p);
	p++;
	printf("the result2 is :%d\n",p);
	return 0;
 } 
