#include<stdio.h>
int main()
{
	int n,ave;
	printf("��������ѧ������");
	scanf("%d",&n); 
	int cj[n];
	int i,a=0;
	float sum= 0;
	for (i = 0;i<n;i++)
	{
		printf("��%d��ѧ���ĳɼ���",i+1);
		scanf("%d",&cj[i]);
		sum=sum+cj[i];
	 } 
	 ave=sum/n;
	 for(i=0;i<n;i++)
	 {
	 	if(cj[i]>ave)
	 	{
	 		a++;
	 		printf("����ƽ���ֵ�ѧ���ĳɼ�Ϊ%d\n",cj[i]);
	 		
		 }
	 }
	 printf("����ƽ���ֵ�����Ϊ%d\n",a);
}
