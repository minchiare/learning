#include<stdio.h>
int main()
{
	float fDues;
	float fAmount;
	int iOntime;
	char cChar;
	
	printf("Enter dues amount :\n");
	scanf("%f",&fDues);
	printf("On Time ？(y/n)\n");
	getchar();
	cChar=getchar();
	iOntime=(cChar == 'y')?1:0;				//判断是否准时,准时则赋值为1 ，不准时则为0// 
	fAmount= iOntime?fDues:(fDues*1.1);		//使用iOntime进行判断，1为真，0为假；真值时输出fDues，假值是输出fDues*1.1 
	printf("the Amount is :%.2f\n",fAmount );
	return 0;
}
