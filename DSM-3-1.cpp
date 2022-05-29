#include<stdio.h>
int main()
{
	int iSignal;
	printf("the Red Light is 0,\n the Green Light is 1 ,\n the Yellow Light is other number \n");
	printf("put the number \n");
	scanf("%d",&iSignal);
	
	if(iSignal==1)
	
		printf("the Light is Green,car can run \n");
	 
	else
		if(iSignal==0)
	 		printf("the Light is red ,can can¡¯t run \n");
		else 
			printf("the Light is yellow ,cans are ready\n");
		
	return 0;
}
