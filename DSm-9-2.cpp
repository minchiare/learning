#include<stdio.h>
struct person{
	int num;char name[20];
	int count;
}leader[3]={{1,"��ĳ",0},{2,"��ĳ",0},{3,"��ĳ",0}};
int main()
{
	int i,j ,leader_num;
	for(i=1;i<=10;i++)
	{
		printf("��ѡ�˵ı�ţ�");
		scanf("%d",&leader_num);
		for(j=0;j<3;j++)
		{
			if(leader_num==leader[j].num )
				leader[j].count ++;
		 } 
	}
	printf("The result is:\n");
	for(i=0;i<3;i++)
		{
			printf("\t%s:%d\t\n",leader[i].name ,leader[i].count ); 
		}
}
