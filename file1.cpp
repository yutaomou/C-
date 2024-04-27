#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	struct student* pprev;
	struct student* pnext;
	int ID;
	int subject[3];
}stu;
void Create(stu** L){

	*L=(stu*)malloc(sizeof(stu));
	(*L)->pnext=NULL;
	stu *s,*p=*L;
	int i;
	printf ("how many groups of data?\n");
	scanf("%d",&i);
	printf("Input Id and 3 subjects:");
	scanf("%d %d %d %d",&p->ID,p->subject,p->subject+1,p->subject+2);
	while (--i){
	s=(stu*)malloc(sizeof (stu));
	s->pprev=p;
	p->pnext=s;
	p=s;
	printf("Input Id and 3 subjects:");
	scanf("%d %d %d %d",&p->ID,p->subject,p->subject+1,p->subject+2);
	p->pnext=NULL;
	}
	printf("success\n"); 
} 
void search( stu* L)
{
	printf("what ID do you want to search?\n");
	int i;
	scanf("%d",&i);
	stu*p=L;
	do
	{
		if(p->ID==i)
		{
			printf ("successful! The marks are %d %d %d.\n",(*p).subject[0],
															(*p).subject[1],
															(*p).subject[2]);
			break;
		}
		else
		{
			p=p->pnext;
		}
	}while(p);
	if(p==NULL)
	{
		printf("There is no ID you are looking for.\n");
	}
}
void Delete(stu*L)
{
	printf("what ID do you want to delete?\n");
	int i;
	scanf("%d",&i);
	stu*p=L;
	do
	{
		if(p->ID==i)
		{
			if(p->pnext)
			{
				p->pprev->pnext=p->pnext;
				p->pnext->pprev=p->pprev;
				free(p);
				break;
			}
			else
			{
				p->pprev->pnext=p->pnext;
				free(p);
				break;
			}
			
		}
		else
		{
			p=p->pnext;
		}
	}while(p);
}
void show( stu* L)
{
	stu*p=L;
	while(p)
	{
		printf("%d %d %d %d\n",p->ID,p->subject[0],p->subject[1],p->subject[2]);
		p=p->pnext;
	}
}
void insert(stu*L)
{
	stu*p=L;
	stu* s;
	printf("Which ID you want to insert it after?\n");
	int i;
	scanf("%d",&i);
	do
	{
		if(p->ID==i)
		{
			if(p->pnext)
			{
				s=(stu*)malloc(sizeof(stu));
				printf("Input Id and 3 subjects:");
				scanf("%d %d %d %d",&s->ID,s->subject,s->subject+1,s->subject+2);
				s->pnext=p->pnext;
				s->pprev=p;
				p->pnext->pprev=s;
				p->pnext=s;
				printf("insert successfully!\n");
			}
			else
			{
				s=(stu*)malloc(sizeof(stu));
				printf("Input Id and 3 subjects:");
				scanf("%d %d %d %d",&s->ID,s->subject,s->subject+1,s->subject+2);
				s->pnext=NULL;
				s->pprev=p;
				p->pnext=s;
			}
			break;
		}
		else
		{
			p=p->pnext;
		}
	}while(p);
	if(p==NULL)
	{
		printf("The ID does not exist.\n");
	}
}
void End(stu*L)
{
	stu*p=L;
	stu*s;
	while(p)
	{
		s=p;
		p=p->pnext;
		free(s);
		s=NULL;
	}
}
void menu()
{
	printf("############################\n");
	printf("#######1.show 2.search #####\n");
	printf("#######3.insert 4.delete####\n");
	printf("#######0. end################\n");
	printf("############################\n");

}
int main()
{
	stu g={NULL,NULL,0,0};
	stu *l=&g;
	Create(&l);
	menu();
	int i;
	scanf("%d",&i);
	while(i)
	{
		switch(i)
		{
		case 1:
			show(l);
			menu();
			scanf("%d",&i);
			break;
		case 2:
			search(l);
			menu();
			scanf("%d",&i);
			break;
		case 3:
			insert(l);	
			menu();
			scanf("%d",&i);
			break;
		case 4:
			Delete(l);
			menu();
			scanf("%d",&i);
			break;
		default:
			printf("input error,please re-enter\n");
			menu();
			scanf("%d",&i);
			break;
		}
	}
	End(l);
	return 0;
}