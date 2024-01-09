#include<stdio.h>
#define T 1
#define F 0
void ArrayInsertion(int A[],int *N,int x,int i)
{
    for(int j=*N-1;j>=i;j--)
    {
        A[j+1]=A[j];
    }
    A[i]=x;
    (*N)=(*N)+1;
}
int ArrayDeletion(int A[],int *N,int i)
{ 
    int r=A[i];
    for(int j=i+1;j<(*N);j++)
    {
        A[j-1]=A[j];
    }
    (*N)--;
    return r;
}
void Pqinsertion(int A[],int *n,int x)
{
    int i=0;
    while(i<*n && x>=A[i])
    {
        i++;
    }
    ArrayInsertion(A,n,x,i);
}
int Pqdeletion(int A[],int *n)
{
    int r;
    r=ArrayDeletion(A,n,0);
    return r;
}
void main()
{int n,r,e;
printf("enter array size:");
scanf("%d",&n);
int A[n];
printf("enter array elements:");
for(int i=0;i<n;i++)
{
    scanf("%d",&A[i]);
    Pqinsertion(A,&n,A[i]);
}
printf("enter any element to be inserted");
scanf("%d",&e);
Pqinsertion(A,&n,e);
printf("new Queue:");
while(n>0)
{
r=Pqdeletion(A,&n);
printf("%d\n",r);
}

}