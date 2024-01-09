#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
struct Node *START;
struct Node* Getnode()
{
    struct Node*p;
    p=(struct Node *)(malloc(sizeof(struct Node)));
    return p;
}
void traverse()
{
    struct Node *p;
    p=START;
    while (p!=NULL)
    {
        printf("%d\n",p->info);
        p=p->next;
    }
    
}
void InsBeg(int x)
{
    struct Node *p;
    p=Getnode();
    p->info=x;
    p->next=START;
    START=p;
}
struct Node* LSearch(int n)
{
struct Node *p;
p=START;
while(p!=NULL)
{
    if(p->info==n)
    return p;
p=p->next;
}
return NULL;
}
int Cycledetection()
{
    struct Node *t,*r;
    t=START;
    r=START->next;
    while (r!=NULL&&r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
        return 1;
    }
    return 0;
    
}
int countCyclicNodes()
{
    int c=1;
    struct Node*t,*r;
    t=START;
    r=START->next;
    while(r!=NULL&&r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
        break;
    }
    r=r->next;
    while (t!=r)
    {
        c=c+1;
        r=r->next;
    }
    return c;
}
int startofcyclicNodes()
{
    struct Node*t,*r;
    t=START;
    r=START;
    while(r!=NULL&&r->next!=NULL)
    {
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r)
        break;
    }
    t=START;
    while(t!=r)
    {
        t=t->next;
        r=r->next;
    }
    return t->info;
}
void main()
{struct Node *p,*q;
    InsBeg(100);
    InsBeg(900);
    InsBeg(500);
    InsBeg(200);
    InsBeg(70);
    InsBeg(50);
    InsBeg(80);
    InsBeg(30);
p=LSearch(100);
q=LSearch(50);
p->next=q;
// int n=Cycledetection();
// if(n==1)
// printf("YES");
// else
// printf("NO");
// printf("length of cyclic list:%d",countCyclicNodes());
printf("start Node value:%d",startofcyclicNodes());


}