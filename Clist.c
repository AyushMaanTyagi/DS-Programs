#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *getnode()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->next = NULL;
    return p;
}
int freenode(struct node *p)
{
    free(p);
    return 1;
}

int insbeg(struct node **cSTART, int x)
{
    struct node *p = NULL;
    p = getnode();
    p->info = x;
    if ((*cSTART) != NULL)
    {
        p->next = (*cSTART)->next;
        (*cSTART)->next = p;
    }
    else
    {
        p->next = p;
        (*cSTART) = p;
    }
    return 1;
}
/***************************************************************/
int insend(struct node **cSTART, int x)
{
    struct node *p = NULL, *q = NULL;
    p = getnode();
    p->info = x;
    if ((*cSTART) != NULL)
    {
        q = (*cSTART)->next;
        (*cSTART)->next = p;
        p->next = q;
        (*cSTART) = p;
    }
    else
    {
        p->next = p;
        (*cSTART) = p;
    }
    return 1;
}

/***************************************************************/
void Travese(struct node *cSTART)
{
    struct node *p = NULL;
    p = cSTART->next;
    while (p != cSTART)
    {
        printf("%d-->", p->info);
        p = p->next;
    }
    printf("%d-->", p->info);
}
int insaft(struct node *p, int x)
{
    struct node *q = NULL, *r;
    q = getnode();
    q->info = x;
    r = p->next;
    p->next = q;
    q->next = r;
    return 1;
}
/***************************************************************/

int CNodeSum(struct node **cSTART)
{
    struct node *p = (*cSTART)->next;
    int sum = 0;
    while (p != (*cSTART))
    {
        sum = sum + p->info;
        p = p->next;
    }
    sum = sum + p->info;
    return sum;
}
/***************************************************************/
struct node *infoChange(struct node **cSTART)
{
    struct node *p = (*cSTART)->next;
    int s = CNodeSum(cSTART);
    while (p != (*cSTART))
    {
        p->info = s - p->info;
        p = p->next;
    }
    p->info = s - p->info;
    return (*cSTART);
}
/***************************************************************/
int delBeg(struct node **cSTART)
{
    struct node *p = NULL;
    struct node *q = NULL;
    if ((*cSTART) == NULL)
    {
        printf("void deletion:");
    }

    else
    {
        p = (*cSTART)->next;
        q = p->next;
        (*cSTART)->next = q;
        int x = p->info;
        if ((*cSTART)->next == *(cSTART))
        {
            *cSTART = NULL;
        }
        freenode(p);
        return x;
    }
}
/***************************************************************/
int delend(struct node **cSTART)
{
    if (*(cSTART) == NULL)
    {
        printf("Void Del:");
    }
    else
    {
        struct node *p = (*cSTART)->next;
        struct node *q = NULL;
        if ((*cSTART) == (*cSTART)->next)
        {
            q = (*cSTART);
            cSTART = NULL;
        }
        else
        {
            while (p->next != (*cSTART))
            {
                p = p->next;
            }
            q = (*cSTART);
            p->next = (*cSTART)->next;
            (*cSTART) = p;
        }

        int x = q->info;
        freenode(q);
        return x;
    }
}
/***************************************************************/
int delaft(struct node *p, struct node **cSTART)
{
    struct node *q = p->next;
    struct node *r = q->next;
    p->next = r;
    if ((*cSTART) == NULL)
    {
        printf("Void Del.");
    }
    else
    {
        if ((*cSTART)->next == (*cSTART))
        {
            *(cSTART) = NULL;
        }
        else if (q == (*cSTART))
        {
            (*cSTART) = p;
        }
        int x = q->info;
        freenode(q);
        return x;
    }
}
/***************************************************************/
// struct node *JosephusProblem(struct node **cSTART, int k)
// {
//     int c = 1;
//     struct node *p = (*cSTART)->next;
//     while (p->next != p)
//     {
//         while (c != k - 1)
//         {
//             p = p->next;
//             c++;
//         }
//         delaft(p, cSTART);
//         p = p->next;
//         c = 1;
//     }
//     return p;
// }

struct node *JosephusProblem(struct node **cSTART, int k)
{
    if (*cSTART == NULL )
    {
        // Handle the case when the list is empty or has only one element
        return *cSTART;
    }

    int c = 1;
    struct node *p = (*cSTART)->next;
    
    while (p->next != p)
    {
        // Move to the k-th person
        for (int i = 1; i < k; i++)
        {
            p = p->next;
        }

        // Delete the k-th person
        delaft(p, cSTART);
        p = p->next;
        c = 1;
    }

    return p;
}

/***************************************************************/
int main()
{
    struct node *cSTART = NULL;
    struct node *p = NULL;
    int info;
    printf("enter values:");
    for(int i=0;i<101;i++)
    {
        scanf("%d",&info);
        insend(&cSTART,info);
    }
    // p = cSTART;
    // while (p->info != 10)
    // {
    //     p = p->next;
    // }
    // insaft(p, 33);
    // Travese(cSTART);
    // int x = delaft(p->next, &cSTART);
    // printf("\n\%d\n", x);
    // Travese(cSTART);
    p=JosephusProblem(&cSTART,13);
    printf("\n%d",p->info);
    // Travese(cSTART);
    return 0;
}