#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student 
{
	int num;
	char name[20];
	float score;
};
int main()
{
	struct student *p;
	p=(struct student *)malloc (sizeof(struct student));
	p->num =1001;
	strcpy(p->name ,"ZhangQiang");
	p->score=82.5;
	printf("The student's record is :\n");
	printf("\tNumber:%d\n\tName:%s\n\tScore:%.1f\n",p->num ,p->name,p->score );
	free(p);
}
