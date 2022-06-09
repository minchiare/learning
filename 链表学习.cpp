#include<stdio.h>
#include<stdlib.h>
struct student{
	char cName[20];
	int iNumber;
	struct Student* pNext;
};
int iCount;
struct Student*Create()
{
	struct Student* pHead=NULL;
	struct Student* pEnd,*pNew;
	iCount = 0;
	pEnd=pNew=(struct Student*)malloc (sizeof(struct Student));
	printf("请先输入学生的姓名，然后输入学生的学号\n");
	scanf("%s ",&pNew->cName);
	scanf("%s",&pNew->iNumber);
	while(pNew->iNUmber!=0)
	{
		iCount++;
		if(iCount ==1)
		{
			pNew->pNext=pHead;
			pEnd=pNew;
			pHead=pNew; 
		}
		else
		{
			pNew->pNExt=NULL;
			pEnd->pNext=pNew;
			pEnd=pNew; 
		}
		pNew=(struct Student*)malloc(size(struct Student));
		
		scanf("%s",&pNew->cName);
		scanf("%d",&pNew->iNumber);
		
	}
	free(pNew);
	return pHead;
}
void Print(struct Student*pHead)
{
	struct Student* pTemp;
	int iIndex=1;
	printf("*****本名单中有%d个学生：*****\n",iCount);
	printf("\n");
	pTemp=pHead;
	while(pTemp!=NULL)
	{
		printf("第%d个学生是：\n",iInedx);
		printf("姓名：%s\n",pTemp->cName);
		printf("学号：%d\n",pTemp->iNumber);
		printf("\n");
		pTemp=pTemp->pNext;
		iIndex++;
		
	}
}
int main()
{
	struct Student* pHead;
	pHead=Create();
	Print(pHead);
	return 0;
}
