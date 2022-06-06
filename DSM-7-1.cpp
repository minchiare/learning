#include<stdio.h>
int AddTwoNum(int iNum1,int iNum2);
int main()
{
	int iResult;
	int iNum3=10;
	iResult=iNum3*AddTwoNum(3,5);
	printf("The result is :%d\n",iResult);
	return 0;
}
int AddTwoNum(int iNum1,int iNum2)
{
	int iTempResult;
	iTempResult=iNum1+iNum2;
	return iTempResult;
}
