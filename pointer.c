#include<stdio.h>
#include<stdlib.h>
void diplay(int *a,int n)
{
for(int i=0;i<5;i++)
    {
        printf("%d\n",*(a+i));
    }
}
void main()
{
    int a[]={1,2,3,4,5};
    int *t;
    diplay(a,5);
    int n;
    // printf("enter n");
    // scanf("%d",&n);
    // t=(int*)malloc(n*sizeof(int));
    // for(int i=0;i<n;i++)
    // {
    //     scanf("%d",(t+i));
    // }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%d\n",*(t+i));
    }
