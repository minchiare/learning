#include<stdio.h>
#include<malloc.h>
#define NULL 0
#define LEN sizeof(struct student)
struct student{int num;
	float score;
	struct student *next;
};
int n;
struct student *creat(void)
{
	struct student *head ,*p1,*p2;
	head=NULL;
	n=0;
	p1=p2=(struct student *)malloc(LEN);
	scanf("\t%d,%f",&p1->num,&p1->score);
	while(p1->num!=0)
	{
		n=n+1;
		if(n==1)
		{
			head=p1;
		}
		else
			p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(LEN);
		scanf("%d,%f",&p1->num,&p1->score );
	}
	p2->next=NULL;
	free(p1);
	return(head);
}
void print(struct student *head)
{
	struct student *p;
	printf("共有%d条学生记录，包括：\n",n);
	p=head;
	while(p!=NULL)
	{
		printf("\t%d\t%.1f\n",p->num ,p->score );
		p=p->next ;
		
	}
}
int main(
{
	struct Student* pHead;
	pHead=Create();
	Print(Head);
	return 0;
}) 
