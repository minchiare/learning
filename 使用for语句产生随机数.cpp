#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 10
int main(void)
{
	int i = 1;
	srand((unsigned)time(NULL));
	for (i = 1; i <= NUM; i++)
	{
		int ret = rand() % 100 + 1;
		printf("��%-2d��:����-->%d\n", i, ret);
	}
	return 0;
}

