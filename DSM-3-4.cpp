#include<stdio.h>
int main()
{
	float fDues;
	float fAmount;
	int iOntime;
	char cChar;
	
	printf("Enter dues amount :\n");
	scanf("%f",&fDues);
	printf("On Time ��(y/n)\n");
	getchar();
	cChar=getchar();
	iOntime=(cChar == 'y')?1:0;				//�ж��Ƿ�׼ʱ,׼ʱ��ֵΪ1 ����׼ʱ��Ϊ0// 
	fAmount= iOntime?fDues:(fDues*1.1);		//ʹ��iOntime�����жϣ�1Ϊ�棬0Ϊ�٣���ֵʱ���fDues����ֵ�����fDues*1.1 
	printf("the Amount is :%.2f\n",fAmount );
	return 0;
}
