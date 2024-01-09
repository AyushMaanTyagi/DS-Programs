#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};

struct Node *Getnode()
{
    struct Node *p;
    p = (struct Node *)(malloc(sizeof(struct Node)));
    return p;
}
void traverse(struct Node *START)
{
    struct Node *p;
    p = START;
    while (p != NULL)
    {
        printf("%d-->", p->info);
        p = p->next;
    }
}
void InsBeg(struct Node **list, int x)
{
    struct Node *p;
    p = Getnode();
    p->info = x;
    p->next = *list;
    *list = p;
}

int main()
{
    struct Node *A[10] = {NULL};
    for (int i = 0; i < 100; i++)
    {
        int k = i % 10;
        InsBeg(&A[k], i);
    }
    for (int i = 9; i >= 0; i--)
    {
        printf("\nCycle %d:", i);
        traverse(A[i]);
    }

    return 0;
}