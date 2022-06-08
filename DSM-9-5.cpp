#include <stdio.h>
#include <malloc.h>
#define NULL 0
#define LEN sizeof(struct student)
struct student
{
	int num;
	float score;
	struct student *next;
};                                                   
 
int n;
struct student *creat(void)                          
{
	struct student *head,*p1,*p2;                   
	head=NULL;n=0;                                   
	p1=p2=(struct student *)malloc(LEN);             
	scanf("\t%d,%f",&p1->num,&p1->score);           
	while(p1->num!=0)                              
	{
		n=n+1;                                      
		if(n==1) 
		     head=p1;                             
		else
		     p2->next=p1;                           
		p2=p1;                                       
		p1=(struct student *)malloc(LEN);          
		scanf("%d,%f",&p1->num,&p1->score);          
	}
	p2->next=NULL;                                  
	free(p1);                                     
	return(head);                                 
}

void print(struct student *head)                  
{
	struct student *p;
	printf("共有%d条学生记录,包括:\n",n);           
	p=head;                                         
	while(p!=NULL)                                   
	{
		printf("\t%d\t%.lf\n",p->num,p->score);      
		p=p->next;                                  
	}
}

struct student *del(struct student *head,int num)     
{
	struct student *p1,*p2;
	if(head==NULL)
	{
		printf("\nThe List is NULL!\n");
		return(head);
	}                                               
	p1=head;                                          
	while(p1->num!=num&&p1->next!=NULL)              
	{
	    p2=p1;                                        
		p1=p1->next;                                  
	}
	if(p1->num==num)                               
	{
		if(p1==head)head=p1->next;                    
		else p2->next=p1->next;                   
		free(p1);                                     
		printf("Delete:%d\n",num);                   
		n=n-1;                                      
	}
	else
	    printf("%d is not been found!\n",num);        
	return(head);
}

struct student *insert (struct student *head,struct student *stud)
{
	struct student *p0,*p1,*p2;                       
	p1=head;                                          
	p0=stud;                                          
	if(head==NULL)                                    
	{	head=p0;p0->next=NULL;}                       
	else
	{	while((p0->num>p1->num)&&(p1->next!=NULL))    
		{	p2=p1;p1=p1->next;}                       
		if(p0->num<=p1->num)                          
		{
			if(head==p1)head=p0;                     
			else p2->next=p0;                       
			p0->next=p1;                              
		}
		else
		{	p1->next=p0;p0->next=NULL;	}            
	}
	n=n+1;                                            
	return(head);
} 
 
int main()
{
	struct student *head,*stu;
	int del_num;
	printf("请输入记录:\n");                       
	head=creat();                                    
	print(head);
	printf("请输入删除记录的编号:");
	scanf("%d",&del_num);
	while(del_num!=0)
	{
		head=del(head,del_num);                      
		print(head);
		printf("请输入删除的记录编号:");
		scanf("%d",&del_num);
	}
	printf("请输入要插入的记录:\n");
	stu=(struct student *)malloc(LEN);
	scanf("%d,%f",&stu->num,&stu->score);
	while(stu->num!=0)
	{
		head=insert(head,stu);                        
		print(head);
		printf("请输入要插入的记录:\n");
		stu=(struct student *)malloc(LEN);           
		scanf("%d,%f",&stu->num,&stu->score);		
	}
}
 

