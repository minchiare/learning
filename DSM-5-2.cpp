#include <stdio.h>
int main()
{
	int i, num, k;												/*��������*/
	int a[10]={10,11,27,25,34,56,18,37,45,16};					/*��ʼ��һ������*/
	k=11;													/*Ϊ������ֵ*/
	printf("Please input the member which you want to find:\n");
	scanf("%d",&num);							/*����һ����num*/
	for (i=0;i<10; i++)									/*ִ��ѭ��*/
	{
		if(num==a[i])								/*�ж��Ƿ������Ԫ��ֵ���*/
		k=i;					/*��k��¼�±�λ��*/
	}
	if(k!=11)													/*���ݽ�����*/
		printf("The member is a[%d] \n",k);
	else
		printf("Have not found the number\n");
}
