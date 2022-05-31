#include<stdio.h>
int main()
{
	int n,ave;
	printf("请输入总学生数：");
	scanf("%d",&n); 
	int cj[n];
	int i,a=0;
	float sum= 0;
	for (i = 0;i<n;i++)
	{
		printf("第%d个学生的成绩：",i+1);
		scanf("%d",&cj[i]);
		sum=sum+cj[i];
	 } 
	 ave=sum/n;
	 for(i=0;i<n;i++)
	 {
	 	if(cj[i]>ave)
	 	{
	 		a++;
	 		printf("高于平均分的学生的成绩为%d\n",cj[i]);
	 		
		 }
	 }
	 printf("高于平均分的人数为%d\n",a);
}
