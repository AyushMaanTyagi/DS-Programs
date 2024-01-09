#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct node
{
    int info;
    struct node *next;
};
struct headNode
{
    int c, max, min;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void createLL(struct headNode **head)
{
    // (*head)=getnode();
    // (*head)->info=0;
    // (*head)->next=NULL;
    /***********************************************************8*/
    struct headNode *p;
    p = (struct headNode *)malloc(sizeof(struct headNode));
    p->c = 0;
    p->max = INT_MIN;
    p->min = INT_MAX;
    p->next = NULL;
    (*head) = p;
}

void insbeg(struct headNode **head, int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = (*head)->next;
    (*head)->next = p;
    (*head)->c = (*head)->c + 1;
    if (x > (*head)->max)
        (*head)->max = x;
    if (x < (*head)->min)
        (*head)->min = x;
}

void insend(struct headNode **head, int x)
{
    struct node *p, *q;
    q = getnode();
    q->next = NULL;
    q->info = x;
    p = (*head)->next;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
    if (x > (*head)->max)
    {
        (*head)->max = x;
    }
    if (x < (*head)->min)
    {
        (*head)->min = x;
    }
    (*head)->c = (*head)->c + 1;
}
void insAft(struct node *p, int x,struct headNode** head)
{
    struct node *q, *r;
    q = getnode();
    q->info = x;
    r = p->next;
    p->next = q;
    q->next = r;
    if (x > (*head)->max)
    {
        (*head)->max = x;
    }
    if (x < (*head)->min)
    {
        (*head)->min = x;
    }
    (*head)->c = (*head)->c + 1;
}

void traverse(struct headNode *head)
{
    struct node *p;
    p = (head)->next;
    while (p != NULL)
    {
        printf("%d-->", p->info);
        p = p->next;
    }
    printf("\n no of nodes:%d", head->c);
    printf("\n no of nodes:%d", head->max);
    printf("\n no of nodes:%d", head->min);
}
int main()
{
    struct headNode *head;
    createLL(&head);
    insbeg(&head, 100);
    insbeg(&head, 125);
    insbeg(&head, -200);
    insbeg(&head, 89325);
    insbeg(&head, 700);
    insbeg(&head, 17);
    insbeg(&head, 10098);
    insbeg(&head, -100);
    insend(&head, -800);
    traverse(head);
}