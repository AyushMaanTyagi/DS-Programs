#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *prev;
    struct node *next;
};

struct node *getnode()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    p->prev = NULL;
    return p;
}

int Insbeg(struct node **dstart, int x)
{
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = (*dstart);
    if ((*dstart) != NULL)
        (*dstart)->prev = p;
    (*dstart) = p;
    return 0;
}
/********************************************/
int insEnd(struct node **dSTART, int x)
{
    struct node *p, *q;
    p = getnode();
    p->info = x;
    p->next = NULL;
    if ((*dSTART) != NULL)
    {
        q = (*dSTART);
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->prev = q;
    }
    else
    {
        p->prev = NULL;
        (*dSTART) = p;
    }

    return 1;
}
int insAft(struct node **p, int x)
{
    struct node *r, *q;
    r = getnode();
    r->info = x;
    q = (*p)->next;
    (*p)->next = r;
    r->prev = (*p);
    r->next = q;
    if (q != NULL)
    {
        q->prev = r;
    }
    return 0;
}
int insbefore(struct node **p, int x,struct node** dSTART)
{
    struct node *q;
    struct node *r = getnode();
    r->info = x;
    r->next = (*p);
    q = (*p)->prev;
    (*p)->prev = r;
    r->prev = q;
    if (q != NULL)
        q->next = r;
    else
    (*dSTART)=r;

    return 0;
}
/*****************************************************************************/

int freenode(struct node *p)
{
    free(p);
    return 0;
}
int delbeg(struct node **dSTART)
{
    if ((*dSTART) == NULL)
    {
        printf("Void Del.");
        exit(1);
    }
    else
    {
        struct node *p = (*dSTART);
        (*dSTART) = (*dSTART)->next;
        if ((*dSTART) != NULL)
        {
            (*dSTART)->prev = NULL;
        }
        int x = p->info;
        freenode(p);
        return x;
    }
}

int delend(struct node **dSTART)
{
    if ((*dSTART) == NULL)
    {
        printf("VD");
        exit(1);
    }
    else
    {
        struct node *p = (*dSTART);
        while (p->next != NULL)
        {
            p = p->next;
        }
        struct node *q;
        q = p->prev;
        if (q != NULL)
            q->next = NULL;
        else
            (*dSTART) = NULL;
        int x = p->info;
        freenode(p);
        return x;
    }
}

int delAft(struct node *p)
{
    struct node *q, *r;
    int x;
    q = p->next;
    if (q == NULL)
    {
        printf("VD.");
        exit(1);
    }
    else
    {
        r = q->next;
        p->next = r;
        if (r != NULL)
            r->prev = p;

        x = q->info;
    }

    freenode(q);
    return x;
}

int delBef(struct node *p)
{
    struct node *q, *r;
    q = p->prev;
    if (q == NULL)
    {
        printf("VD.");
        exit(1);
    }
    else
    {
        r = q->prev;
        if(r!=NULL)
        r->next = p;
        p->prev = r;
    }
    int x = q->info;
    freenode(q);
    return x;
}

/*****************************************************************************/
struct node *search(struct node *dSTART, int x)
{
    struct node *p = dSTART;
    while (p->info != x)
    {
        p = p->next;
    }
    return p;
}

int traverse(struct node *dstart)
{
    struct node *p = dstart;
    while (p != NULL)
    {
        printf("%d  ", p->info);
        p = p->next;
    }
    return 0;
}

int main()
{
    struct node *dSTART = NULL, *p;
    Insbeg(&(dSTART), 100);
    Insbeg(&(dSTART), 200);
    Insbeg(&(dSTART), 300);
    Insbeg(&(dSTART), 400);
    Insbeg(&(dSTART), 500);
    Insbeg(&(dSTART), 600);
    Insbeg(&(dSTART), 700);
    Insbeg(&(dSTART), 800);
    // traverse(dSTART);

    insEnd(&(dSTART), 454);
    insEnd(&(dSTART), 159);
    insEnd(&(dSTART), 333);
    traverse(dSTART);
    p = search(dSTART,800);
    // insAft(&p, 77777);
    printf("\n\n");
    insbefore(&p, 55555,&dSTART);
    traverse(dSTART);
    // int x = delBef(p);
    // printf("\n%d\n", x);
    //  x = delbeg(&dSTART);
    // printf("\n%d\n", x);
     
    //  x = delAft(p);
    // printf("\n%d\n", x);

    // x = delend(&dSTART);
    // printf("\n%d\n", x);
    // traverse(dSTART);

    return 0;
}