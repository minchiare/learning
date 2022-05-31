#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int counter;
	for (counter=0;counter<10;counter++)
	{
		srand(time(0)+counter);
			printf("Random number %d is :%d\n",counter,rand());
	}
	return 0;
}
