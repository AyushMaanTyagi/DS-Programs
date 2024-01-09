#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct PQUEUE
{
    char ITEM[SIZE];
int prn; 
};
struct PQUEUE *PQ;
void ArrayInsertion(char A[],int *N,char x,int i)
{
    for(int j=*N-1;j>=i;j--)
    {
        A[j+1]=A[j];
    }
    A[i]=x;
    *N=*N+1;
}
char ArrayDeletion(char A[],int *N,int i)
{
    for(int j=i+1;j<*N;j++)
    {
        A[j-1]=A[j];
    }
    *N=*N-1;
}
void INITIALIZE(struct PQUEUE *PQ)
{
PQ->=SIZE-1;
}
void PQInsert(char *A[],int n,char c,int prn)
{i=0;
    while(i<n&&x>=A[i])
    {
        i++;
    }
ArrayInsertion(A[],n,i,c);
}
char PQDelete(char *A[],int n)
{
   char x=A[0];
ArrayDeletion(A[],n,0);
return x;
}
void main()
{
    struct PQUEUE W;
    INITIALIZE(&W);
    PQInsert(&W,SIZE,'A',7);
    PQInsert(&W,SIZE,'B',4);
    PQInsert(&W,SIZE,'C',3);
    PQInsert(&W,SIZE,'D',7);
    PQInsert(&W,SIZE,'F',2);
}