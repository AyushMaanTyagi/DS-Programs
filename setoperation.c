#include<stdio.h>
#include"Linkedlist.h"
struct Node* MergeList(struct Node *START1,struct Node *START2)
{
struct Node *p=(START1);
struct Node *q=(START2);
struct Node *START3=NULL;
while (p!=NULL && q!=NULL)
{
    if(p->info<q->info)
    {
        InsBeg(&START3,p->info);
        p=p->next;
    }
    else
    {
    if(q->info<p->info)
    {
    InsBeg(&START3,q->info);
     q=q->next;
    }
     else
    {
        InsBeg(&START3,p->info);    
        p=p->next;
        q=q->next;
    }
    }
}
while(p!=NULL)
{
    InsBeg(&START3,p->info);
    p=p->next;
}
while(q!=NULL)
{
    InsBeg(&START3,q->info);
    q=q->next;
}
Reverse(&START3);
return START3;
}
/*###########################################################################*/
struct Node* Intersection(struct Node* START1,struct Node *START2)
{
    struct Node*p=START1;
    struct Node*q=START2;
    struct Node*START3=NULL;
    while(p!=NULL && q!=NULL)
    {
        if(p->info<q->info)
            p=p->next;
        else
        {
            if(q->info<p->info)
            q=q->next;
            else
            {
                InsBeg(&START3,p->info);
                p=p->next;
                q=q->next;
            }
        }
    }
    Reverse(&START3);
    traverse(START3);
}
/*###########################################################################*/
struct Node* Diff(struct Node* START1,struct Node* START2)
{
    struct Node*p=START1;
    struct Node*q=START2;
    struct Node*r=NULL;
    while (p!=NULL && q!=NULL)
    {
        if(p->info<q->info)
        {
            InsBeg(&r,p->info);
            p=p->next;
        }
        else
        {
            if(q->info<p->info)
            {
                q=q->next;
            }
            else
            {
                p=p->next;
                q=q->next;
            }
            
        }
    }
        while (p!=NULL)
        {
            InsBeg(&r,p->info);
            p=p->next;
        }
       Reverse(&r);
       return r; 
}
/*###########################################################################*/
struct Node* SymDiff(struct Node* START1,struct Node*START2)
    {
        struct Node* p=START1;
        struct Node* q=START2;
        struct Node* START3=NULL;
        while (p!=NULL && q!=NULL)
        {
            if(p->info<q->info)
            {
                InsBeg(&START3,p->info);
                p=p->next;
            }
            else
            {
                if(q->info<p->info)
                {
                    InsBeg(&START3,q->info);
                    q=q->next;
                }
                else
                {
                      p=p->next;
                      q=q->next;
                }
            }
        }
        while (p!=NULL)
        {
            InsBeg(&START3,p->info);
            p=p->next;
        }
        while(q!=NULL)
        {
            InsBeg(&START3,q->info);
            q=q->next;
        }
        Reverse(&START3);
        return START3;
    }
/*###########################################################################*/
void main()
{
    struct Node* START1=NULL,*START2=NULL,*START3;
    InsBeg(&START1,15);
    InsBeg(&START1,12);
    InsBeg(&START1,10);
    InsBeg(&START1,8);
    InsBeg(&START1,7);
    InsBeg(&START1,5);
    InsBeg(&START1,2);
    InsBeg(&START1,1);
    traverse(START1);
    printf("\n\n");

    InsBeg(&START2,10);
    InsBeg(&START2,9);
    InsBeg(&START2,8);
    InsBeg(&START2,6);
    InsBeg(&START2,5);
    InsBeg(&START2,4);
    InsBeg(&START2,3);
    InsBeg(&START2,2);
    traverse(START2);
    printf("\n\n");
    START3=MergeList(START1,START2);
    traverse(START3);
     printf("\n\n");
    START3=Intersection(START1,START2);
    traverse(START3);
     printf("\n\n");
    START3=Diff(START1,START2);
    traverse(START3);
     printf("\n\n");
    START3=SymDiff(START1,START2);
    traverse(START3);
}