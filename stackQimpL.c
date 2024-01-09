#include<stdio.h>
#include"Linkedlist.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
int Initialise(struct Node* top)
{
    top=NULL;
    return 1;
}
int isempty(struct Node *top)
{
    if(top==NULL)
    return TRUE;
    else
    return FALSE;
}
int push(struct Node** top,int x)
{
    InsBeg(top,x);
    return 1;
}
int pop(struct Node** top)
{
    if(*(top)==NULL)
    {
        printf("Stack Underflows");
        exit(1);
    }
    else
    {
         int x=Delbeg(top);
         return x;
    }
}
int stacktop(struct Node *top)
{
    return top->info;
}
/****************************************************************************************/

int initialize(struct node **front,struct node **rear)
{
    *(front)=NULL;
    *(rear)=NULL;
    return 1;
}
int Enqueue(struct Node** front,struct Node** rear,int x)
{
   if(*(rear) != NULL)
   {
    InsAft(rea)
   }

}

/****************************************************************************************/

int main()
{
  struct Node* top;
  Initialise(top);
  push(&top,1);
  push(&top,2);
  push(&top,3);
  push(&top,4);
  push(&top,5);
  int x=pop(&top);
  printf("%d-->",x);
   x=pop(&top);
  printf("%d-->",x);
   x=pop(&top);
  printf("%d-->",x);
//   x=stacktop(top);
//   printf("%d",x);
   x=pop(&top);
  printf("%d-->",x);
   x=pop(&top);
  printf("%d-->",x);
   x=isempty(top);
   printf("\n%d\n",x);

  return 0;
}