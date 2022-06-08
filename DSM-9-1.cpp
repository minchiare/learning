#include<stdio.h>
struct student
{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
}
stu[3]={{1001,"ZhaoMing",'M',18,82.5},{1002,"WangYing",'F',17,90.5},{1003,"ZhaoMing",'M',19,78.5}};
int main()
{
	int i;
	printf("These 3 students' records are:\n");
	printf("\tNumber\tName\t\tSex\tAge\tScore\n");
	for (i=0;i<3;i++)
	{
		printf("\t%d\t%s\t%c\t%d\t%.1f\n",stu[i].num ,stu[i].name ,stu[i].sex ,stu[i].age ,stu[i].score );
	}
}

