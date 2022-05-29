#include<stdio.h>
int main()
{
	int iSignal;
	printf("the Red Light is 0,\n the Green Light is 1 ,\n the Yellow Light is other number \n");
	scanf("%d",&iSignal);
	
	if(iSignal==1)
	{	
		printf("the Light is green ,cars can run\n");
	}
	else if (iSignal==0)
	{
		printf("the Light is red ,cars can¡¯t run\n");
	}
	else 
	{
		printf("the Light is yellow ,cars are ready\n");
		
	}
	return 0;
}
