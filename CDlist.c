#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* prev;
    struct node* next;
};
struct node* getnode()
{
    struct node* p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
int insbeg(struct node** cdSTART,int x)
{
   struct node* q=NULL,*p=NULL;
   q=getnode();
   q->info=x;
   if(cdSTART!=NULL)
   {
    p=(*cdSTART)->next;
    (*cdSTART)->next=q;
    q->prev=(*cdSTART);
    q->next=p;
    p->prev=q;    

   }
   else{
    (*cdSTART)=q;
    (*cdSTART)->next=q;
    q->prev=(*cdSTART);
   }
   return 0;
}
/*888888888888888888888888888888888888888888888888888888888888888888888888*/
 int traverse(struct node * cdSTART)
 { 
   struct node* p;
   p=cdSTART->next;
   while (p!=cdSTART)
   {
    printf("%d-->",p->info);
    p=p->next;
   }
   printf("%d\n",p->info);
   return 0;
 }
/*888888888888888888888888888888888888888888888888888888888888888888888888*/

 int main()
 {
    struct node* cdSTART=NULL;
    insbeg(&cdSTART,123);
    insbeg(&cdSTART,456);
    insbeg(&cdSTART,748);
    insbeg(&cdSTART,689);
    insbeg(&cdSTART,397);
    traverse(cdSTART);
    return 0;

 }
