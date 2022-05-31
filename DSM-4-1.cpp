#include<stdio.h>
int main()
{
	int a;
	for(a=105;a<1000;a+=7)
	{
		if(a%6==5&&a%5==4&&a%3==2&&a%2==1)
			printf("这条阶梯可能有%d阶\n",a);
	}
	return 0;
}
