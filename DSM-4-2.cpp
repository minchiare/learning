#include<stdio.h>
int main()
{
	int n;
	while(n!=4)
	{
		printf("\n\n\t1.��ʼ��Ϸ");
		printf("\t2.����˵��");
		printf("\t3.��Ϸ����");
		printf("\t4.�˳�\n \n");
		printf("\t ��ѡ��1 2 3 4 ��:[ ]\b\b"); 
		scanf("%d",&n);
		switch (n)
		{
			case 1:
				printf("\n\t ��ѡ���ˡ�1.��ʼ��Ϸ��ѡ��"); 
				break;
			case 2:
				printf("\n\t ��ѡ���ˡ�2.����˵����ѡ��");
				break;
			case 3:
				printf("\n\t ��ѡ���ˡ�3.��Ϸ����ѡ��");
				break;
			case 4:
				printf("\n\t ��ѡ����'4.�˳�'ѡ��");
				break; 
		 }
	}
}
