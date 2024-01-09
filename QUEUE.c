#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
#define TRUE 1
#define FALSE 0
struct QUEUE
{
    char item[SIZE];
int REAR,FRONT;
};
struct QUEUE Q;
 void INITIALIZE(struct QUEUE *Q)
{
    Q->REAR=-1;
    Q->FRONT=0;
}
int ISEMPTY(struct QUEUE *Q)
{
    if(Q->REAR-Q->FRONT+1==0)
    return TRUE;
    else
    return FALSE;
}
void ENQUEUE(struct QUEUE *Q,char X)
{
if (Q->REAR==SIZE-1)
{
printf("Queue overflows");
exit(1);
}
else
{
Q->REAR++;
Q->item[Q->REAR]=X;
}
}
int DEQUEUE(struct QUEUE *Q)
{
    if (ISEMPTY(Q))
    {
        printf("\nQUEUE UNDERFLOWS");
        exit(1);
    }
    else
    {
        char x;
        x=Q->item[Q->FRONT];
        Q->FRONT++;
        return x;
    }
}
void main()
{
    INITIALIZE(&Q);
    ENQUEUE(&Q,'A');
    ENQUEUE(&Q,'B');
    ENQUEUE(&Q,'C');
    ENQUEUE(&Q,'D');
    char Z=DEQUEUE(&Q);
    printf("\nDELETED ITEM IS:%c",Z);
      Z=DEQUEUE(&Q);
    printf("\nDELETED ITEM IS:%c",Z);
      Z=DEQUEUE(&Q);
    printf("\nDELETED ITEM IS:%c",Z);
    Z=DEQUEUE(&Q);
    printf("\nDELETED ITEM IS:%c",Z);
}