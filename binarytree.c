#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *Makenode(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void preorederTraversal(struct node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preorederTraversal(t->left);
        preorederTraversal(t->right);
    }
}

void postorderTraversal(struct node * t)
{
    if (t != NULL)
    {
       
        postorderTraversal(t->left);
        postorderTraversal(t->right);
         printf("%d ", t->data);
    }
}
int main()
{
    struct node *root = NULL;
    root = Makenode(1);
    root->left = Makenode(2);
    root->right = Makenode(5);
    root->left->left = Makenode(3);
    root->left->right = Makenode(4);
    root->right->right = Makenode(6);
    postorderTraversal(root);
}