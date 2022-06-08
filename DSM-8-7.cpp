#include<stdio.h>
int swap(int *a ,int *b,int *c)
{
	int tmp;
	if(*a>*b)
	{
		tmp=*a;
		*a=*b;
		*b=tmp;
	}
	if(*a>*c)
	{
		tmp=*a;
		*a=*c;
		*c=tmp;
	
	}
	if(*b>*c)
	{
		tmp=*b;
		*b=*c;
		*c=tmp;
	}
}
int main()
{
	int x,y,z;
	int *p_x,*p_y,*p_z;
	printf("请输入三个数：\n");
	scanf("%d%d%d",&x,&y,&z);
	p_x= &x;
	p_y=&y;
	p_z=&z;
	swap(p_x,p_y,p_z);
	printf("xyz按从小到大排序为：%d    %d\t%d",x,y,z);
	return 0;
}
