#include <stdio.h>
#include <stdlib.h>

typedef struct st_node
{
    int data;
    struct st_node* nextptr;

}Node;

typedef struct tlist
{
    unsigned size;
    Node* start;

}List;


int add(int,List*);
int delete (int,List*);
int display(List*);
int menu();

int main(void)
{
    List one;
    one.size = 0;
    one.start = NULL;
int i,avalue;
    int res = menu();
    printf("menu returned %d\n", res);

    display(&one);
	while(i!=0)
	{
		printf("ENTER THE VALUE YOU WANT TO ADD ");
		scanf("%d",&avalue);
		add(avalue,&one);
		printf("DO you wish to continue adding (1/0 )");
		scanf("%d",&i);
		display(&one);
	}
	
	printf("THE VALUE IN THE LIST IS ");
	display(&one);
   /* for( int i = 0; i<10; i+=1)
        add(i,&one);
    display(&one);
    return 0;*/
}

int add(int value, List* l)
{
    if ( l == NULL ) return -1;
    Node* node = (Node*) malloc(sizeof(Node));
    // simplest: insert at the beginning
    node->nextptr = l->start;
    node->data = value;
    l->start = node;
    l->size += 1;
    return l->size;
};

int display(List* l)
{
    if ( l== NULL) return -1;
    if ( l->size == 0 )
    {
        printf("\n\tlist is empty\n\n");
        return 0;
    }
    else
    {
        printf("\n\t%d elements in the list\n\n", l->size);
    };

    Node* p = l->start;
    for( unsigned i = 0; i< l->size; i+=1)
    {
        printf("%3d: %11d\n", 1+i, p->data);
        p = p->nextptr;
    };
    return l->size;
}

int delete (int v, List* l)
{
    return 0;
}

int menu()
{
    int choice = 0;
    int res = 0;
    printf(
        "\n\tENTER YOUR CHOICE FOR SINGLE LINKED LIST:\n\\n\t\t1. ADD ELEMENT\\n\t\t2. DISPLAY ELEMENT\\n\t\t3. DELETE ELEMENT\\n\t\t4. EXIT\\n\n\t\tYour choice:   ");

   while( res != 1 )
   {
        res = scanf("%d", &choice);
        if ( choice >=1 && choice <= 4 ) return choice;
   };
   return 4;
}