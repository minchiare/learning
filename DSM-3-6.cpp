#include<stdio.h>
int main()
{
	float salary=500;
	int k;
	int profit;
	float commission;			//����Ա�������// 
	printf("����Ա������µ����۶");
	scanf("%d",&profit);
	if(profit%1000==0)
		k=profit/1000;
	else
		k=profit/1000+1;
	switch(k)
	{
	case 0:
	case 1:
	case 2:
		commission=1;
		break;
	case 3:
	case 4:
	case 5:
		commission=1.08;
		break;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		commission=1.10;
		break;
	default:
		commission=1.12;
		break;
	}
	salary=profit*commission+salary;
	printf("�����Ա���Ĺ����ǣ�%.3f",salary);
return 0;
}
