#include<stdio.h>
int main()
{
	int a,b;
	int *ipointer1,*ipointer2;
	printf("����������������"); 
	scanf("%d%d",&a,&b);
	ipointer1 = &a;
	ipointer2 = &b;
	printf("The number is :*ipointer1=%d,*ipointer2=%d\n",*ipointer1,*ipointer2);
	printf("The number is :a= %d,b=%d\n",a,b);
	return 0; 
 } 
