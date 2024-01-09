#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// #include"Linkedlist.h"
struct node
{
    int coef;
    int exp;
    struct node* next;
};
struct node* Getnode()
{
    struct node*p;
    p=(struct node *)(malloc(sizeof(struct node)));
    p->next=NULL;
    return p;
}
void InsBeg(struct node **list,int x,int y)
{
    struct node *p;
    p=Getnode();
    p->coef=x;
    p->exp=y;
    p->next=*(list);
    *list=p;
}
struct node* PolyAdd(struct node **poly1,struct node **poly2)
{
    struct node*p=*poly1;
    struct node *q=*poly2;
    struct node *poly3=NULL;
while(p!=NULL&&q!=NULL)
{
    if(p->exp==q->exp)
    {
InsBeg(&poly3,p->coef+q->coef,p->exp);
p=p->next;
q=q->next;
    }
else if(p->exp>q->exp)
{
InsBeg(&poly3,p->coef,p->exp);
p=p->next;
}
else
{
    InsBeg(&poly3,q->coef,q->exp);
    q=q->next;
}
}
while(p!=NULL)
{
    InsBeg(&poly3,p->coef,p->exp);
    p=p->next;
}
while(q!=NULL)
{
    InsBeg(&poly3,q->coef,q->exp);
    q=q->next;
}
return poly3;
}

/************************************************************************************/
struct node *Polysub(struct node **poly1,struct node **poly2)
{
struct node*q=*(poly2);
struct node*poly3=NULL;
while (q!=NULL)
{
    q->coef=-1*(q->coef);
    q=q->next;
}
poly3=PolyAdd(poly1,poly2);
return poly3;
}
struct node *polyMul(struct node **poly1,struct node **poly2)
{  
    struct node*p=*(poly1);
    struct node*q=*(poly2);
    struct node*poly3=NULL;
    int N=p->exp+q->exp+1;
    int *dat= calloc(sizeof(int),N);
   while(p!=NULL) 
   {
    q=*(poly2);
    while(q!=NULL)
    {
    int e=p->exp+q->exp;
    int c=(p->coef)*(q->coef);
    dat[e]=dat[e]+c;
    q=q->next;
    }
    p=p->next;
     }
     for(int i=0;i<N;i++)
     {
      if(dat[i]!=0)
      InsBeg(&poly3,dat[i],i);
     }
     free(dat);
     return poly3;
    
}
void traverse(struct node *START)
{
    struct node *p;
    p=START;
    while (p!=NULL)
    {
        printf("%dx^%d + ",p->coef,p->exp);
        p=p->next;
    }
    
}
void main()
{
    struct node *poly1=NULL,*poly2=NULL,*poly3;
    InsBeg(&poly1,8,1);
    InsBeg(&poly1,1,2);
    InsBeg(&poly1,-2,3);
    InsBeg(&poly1,3,4);
    traverse(poly1);
    printf("\n\n\n");
    InsBeg(&poly2,9,0);
    InsBeg(&poly2,3,3);
    InsBeg(&poly2,5,5);
    traverse(poly2);
    printf("\n\n\n");
    poly3=polyMul(&poly1,&poly2);
    traverse(poly3);
}