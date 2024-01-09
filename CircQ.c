#include<stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define SIZE 8
struct QUEUE
{
    char ITEM[10];
int REAR;
int FRONT;
};
struct QUEUE *CQ;


void INITIALIZE(struct QUEUE *CQ)
{
CQ->REAR=SIZE-1;
CQ->FRONT=SIZE-1;
}

int Isempty(struct QUEUE *CQ)
{
if(CQ->REAR==CQ->FRONT)
return TRUE;
else
return FALSE;
}
void Enqueue(struct QUEUE *CQ,char x)
{
    if((CQ->REAR+1)%SIZE==CQ->FRONT)
    { printf("\nQUEUE OVERFLOW");
      exit(1);
    }
    else
    {
       CQ->REAR=(CQ->REAR+1)%SIZE;
      
       CQ->ITEM[CQ->REAR]=x;
    }
}
char Dequeue(struct QUEUE *CQ)
{
    if(Isempty(CQ))
    {
        printf("\nQueue underflows");
        exit(1);
    }
    else
    {char X;
     CQ->FRONT=(CQ->FRONT+1)%SIZE;
     X=CQ->ITEM[CQ->FRONT];
     return X;
    }
    
}

void main()
{ char C;struct QUEUE W;
    Enqueue(&W,'A');
    Enqueue(&W,'B');
    Enqueue(&W,'C');
    Enqueue(&W,'D');
    Enqueue(&W,'E');
    Enqueue(&W,'F');
    Enqueue(&W,'G');
    // Enqueue(&W,'H');
   C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C);
    C=Dequeue(&W);
     printf("\nDELETED ITEM :%c",C);
      C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C);
     C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C);
     C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C);
     C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C); 
    C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C);
     C=Dequeue(&W);
    printf("\nDELETED ITEM :%c",C);
    }