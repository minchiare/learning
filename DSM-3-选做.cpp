#include<stdio.h>
int main()
{
	float y;
	float x;
	printf("������x��ֵ��"); 
	scanf("%f",&x);
	if(x<1)
		y=x;
	else if (x<10)
		y=2*x-1;
	else
		y=3*x-11;
	printf("y��ֵΪ��%f",y);
	return 0;
}
