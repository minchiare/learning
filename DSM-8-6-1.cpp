#include<stdio.h>
int swap(int a ,int b)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
int main()
{
	int x,y;
	printf("请输入两个数：\n");
	scanf("%d%d",&x,&y);
	swap(x,y);
	printf("x=%d\ny=%d\n",x,y);
	return 0;
}
