#include<stdio.h>
#include<stdlib.h>
int CountingSort(int A[],int n,int k)
{
    int *C=(int *)calloc((k+1),sizeof(int));
    int Ans[n];
    for(int i=0;i<n;i++)
    {
        C[A[i]]=C[A[i]]+1;
    }
    for(int i=1;i<=k;i++)
    {
      C[i]=C[i]+C[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        Ans[C[A[i]]-1]=A[i];
        C[A[i]]=C[A[i]]-1;
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%d",Ans[i]);
    }
}
int main()
{
    int n,k=0;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int A[n],Ans[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(A[i]>k)
        {
            k=A[i];
        }
    }
    
    CountingSort(A,n,k);
   
    }