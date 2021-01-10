#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>   
int stack[100],i,j,choice=0,n,top=-1,searchval=0;  
void push();  
void pop();  
void show();  
void searchByPosition();
void searchByValue();
void main ()  
{  
    printf(" number of elements  ");   
    scanf("%d",&n);  
    printf("Fine!\n");  
   
    while(choice != 5)  
    {  
        printf("Chose one ...\n-----------------------------\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Search\n5.Exit");  
        printf("\n  your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
           {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                show();  
                break;  
            }  
			case 4:
			{
				printf("1.Search by value\n2.Search by position\nChoose Search>>>\n");
				scanf("%d",&searchval);
				switch(searchval)
				{
					case 1: {searchByValue();  break;}
					case 2: {searchByPosition(); break;}
					default: {printf("\n***Wrong Input***"); break;}
				};
			}
            case 5:   
            {  
                printf("Relax !! Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("You mad! bro?");  
            }   
        };  
    }  
}   
void push ()  
{  
    int val;      
    if (top == n )   
    printf("\n Overflow");   
    else   
    {  
        printf("Enter the value?");  
        scanf("%d",&val);         
        top=top+1;   
        stack[top] = val;  
		printf("Yo, added %d on place %d.\n",stack[top],top);
    }   
}   
  
void pop ()   
{   
    if(top == -1)   
    printf("Underflow");  
    else  
		printf("\nElement at position %d having value %d has been removed\n",top,stack[top]);
    top = top -1;   
	
}   
void show()  
{  
    for (i=top;i>=0;i--)  
    {  
        printf("%d\n",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("Stack Underflow\n");  
    }  
}  
void searchByPosition()
{	int temp;
	printf("\nENTER AT WHAT POSITION YOU WANNA SEARCH ");
	scanf("%d",&temp);	
	printf("\n%d is at position %d ",stack[temp],temp);
}
void searchByValue()
{	int temp;
	printf("\nENTER THE VALUE YOU WANNA KNOW THE POSITION OF ");
	scanf("%d",&temp);	
	for(i=top;i>=0;i--)
	{
		if(stack[i]==temp)
		{
		printf("\nTHE Value is %d is at position %d ",temp,i);
		
		}
	}
}