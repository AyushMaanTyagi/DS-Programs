#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};

struct Node* Getnode()
{
    struct Node*p;
    p=(struct Node *)(malloc(sizeof(struct Node)));
    return p;
}
void traverse(struct Node *START)
{
    struct Node *p;
    p=START;
    while (p!=NULL)
    {
        printf("%d\n",p->info);
        p=p->next;
    }
    
}
void InsBeg(struct Node **list,int x)
{
    struct Node *p;
    p=Getnode();
    p->info=x;
    p->next=*list;
    *list=p;
}
 void Insend(struct Node **list,int x)
{
    struct Node *p,*q;
    p=*list;
    while (p->next!=NULL)
    {
        p=p->next;

    }
q=Getnode();
q->next=NULL;
q->info=x;
p->next=q;
    
}
void InsAft(struct Node **list,int x,int y)
{
    struct Node *temp,*p;
    temp=*list;
    while(temp->info!=x)
    {
        temp=temp->next;
    }
    p=Getnode();
    p->info=y;
    p->next=temp->next;
    temp->next=p;
}
/*
int cnode()
{
    struct Node *p;
int c=0;
    p=START;
    while(p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void Eocount()
{struct Node *p;
p=START;
int co=0,ce=0;
while (p!=NULL) 
{
    if(p->info%2==0)
    ce++;
    else
     co++;
     p=p->next;
    
}
printf("No of even no:%d",ce);
     printf("\nNo. of odd no. %d",co);

    
}*/
void Freenode(struct Node *p)
{

    free(p);
}
int Delbeg(struct Node **list)
{
if(*(list)==NULL)
{
printf("Void DEL.");
return -1;
}
else
{
    struct Node *p;
    p=*list;
    *(list)=p->next;
    int x= p->info;
    Freenode(p);
    return x;
}
}
int delEnd(struct Node **list)
{
if(*(list)==NULL)
printf("Void DEL.");
else
{     struct Node *p,*q;
int x;
    p=*(list);
    q=NULL;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    if(q!=NULL)
    {
        q->next=NULL;
    }
    else
    {
        *(list)=NULL;
    }
x=p->info;
Freenode(p);
return x;
}
}
/*
int  MiddleElement()
{
    struct Node *t,*r;
    t=START;
    r=START->next;
    while(r!=NULL&&r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t->info;
}*/
void Reverse(struct Node **list)
{
    struct Node *p,*c,*n;
    p=NULL;
    c=*(list);
    n=c->next;
    while(c!=NULL)
    {
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL)
        n=n->next;
    }
*(list)=p;
}

