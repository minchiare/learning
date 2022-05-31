#include<stdio.h>
int main()
{
	int n;
	while(n!=4)
	{
		printf("\n\n\t1.开始游戏");
		printf("\t2.按键说明");
		printf("\t3.游戏规则");
		printf("\t4.退出\n \n");
		printf("\t 请选择【1 2 3 4 】:[ ]\b\b"); 
		scanf("%d",&n);
		switch (n)
		{
			case 1:
				printf("\n\t 您选择了‘1.开始游戏’选项"); 
				break;
			case 2:
				printf("\n\t 您选择了‘2.按键说明’选项");
				break;
			case 3:
				printf("\n\t 您选择了‘3.游戏规则’选项");
				break;
			case 4:
				printf("\n\t 您选择了'4.退出'选项");
				break; 
		 }
	}
}
