#include<stdio.h>
int Arrage(int iArray[10])
{
	int iResult=0;
	int i;
	for (i=0;i<10;i++)
	{
		iResult+=iArray[i];
	}
	iResult/=10;
	return iResult;
}

int main()
{
	printf("������10��ѧ���ĳɼ���");
	int iStudent[10];
	int c;
	for(c=0;c<10;c++)
	{
		scanf("%d",&iStudent[c]);
	 } 
	 int iResult=Arrage(iStudent);
	 printf("ƽ���ɼ��ǣ�%d",iResult);
	 return 0;
}
