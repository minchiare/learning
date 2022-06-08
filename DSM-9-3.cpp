#include<stdio.h>
#define NULL 0
struct student
{
	int num;
	float score;
	struct student *next;
};
int main()
{	struct student a,b,c,*head,*p;
	a.num=1001;a.score =82.5;
	b.num=1002;b.score =90.5;
	c.num= 1003;c.score =78.5;
	head=&a;
	a.next =&b;b.next =&c;c.next =NULL;
	p=head;
	printf("These 3 students' records are :\n\tNumber\tScore\n");
	do
	{
		printf("\t%d\t%.1f\n",p->num  ,p->score );
		p=p->next ;
	}while(p!=NULL);
}

