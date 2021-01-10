#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*head;

int add();
void display();

int main()
{
	int choice,count=0,i;
	while(choice!=4)
	{
		printf("\n \t ENTER YOUR CHOICE FOR SINGLE LINKED LIST ");
		printf("\n \t 1. ADD ELEMENT ");
		printf("\n \t 2. DISPLAY ELEMENT ");
		printf("\n \t 3. DELETE ELEMENT ");
		printf("\n \t 4. EXIT  ");
		 scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
					if(count>-1)
						{i=1;}
					while(i!=0)
					{	
						count++;
						add();
						display();
						printf("\n DO YOU WANT TO CONTINUE 1/0 ");
						scanf("%d",&i);
					}
			case 2: display();
					 break;
			case 3: //delete();
					 break;
			case 4:  exit(0);
					 break;
			default: printf("\n \t WRONG VALUE ENTERED ");		
		};
	}
	return 0;
}
void display()
{
	struct node *tmp;
	tmp=head;
	if(head==NULL)
	{
		printf("THE LIST IS EMPTY");
	}
	else
	{
		while(tmp!=NULL)
		{
			printf(" data = %d\n",tmp->data);
			tmp=tmp->next;
		}
	}
}

int add()
{
	int item,i;
	struct node *tmp,*ptr;
	ptr=malloc(sizeof(struct node));
	
	if(ptr==NULL)
	{
		printf("\n MEMORY ALLOCATION FAILED ");
	}
	else
	{
		printf("ENTER THE VALUE YOU WANT TO ADD TO THE LIST");
		scanf("%d",&item);
		if(head==NULL)
		{
			ptr->prev=NULL;
			ptr->data=item;
			ptr->next=NULL;
			head=ptr;
		}
		else
		{	tmp=head;
			while(tmp->next!=NULL)
			{tmp=tmp->next;}
			
			tmp->next=ptr->prev;
			ptr->data=item;
			ptr->next=NULL;
			ptr=ptr->next;
		}
	}
	return 0;
}

