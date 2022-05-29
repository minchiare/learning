#include<stdio.h>
int main()
{
	float y;
	float x;
	printf("请输入x的值："); 
	scanf("%f",&x);
	if(x<1)
		y=x;
	else if (x<10)
		y=2*x-1;
	else
		y=3*x-11;
	printf("y的值为：%f",y);
	return 0;
}
