#include<stdio.h>
#include<stdlib.h>
void bubblesort(int A[],int n)
{
    int flag=1;
    for (int i = 0; i <n-1 && flag==1; i++)
    {
        flag =0;
        for( int j=0;j<n-i-1;j++)
        {

            if(A[j]>A[j+1])
            {
                int k=A[j];
                A[j]=A[j+1];
                A[j+1]=k;
                flag= 1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ,",A[i]);
    }
}
/***************************************************************************************/
void selectionSort(int A[],int n)
{ int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for( int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            min=j;
        }
        int k=A[i];
        A[i]=A[min];
        A[min]=k;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ,",A[i]);
    }
}
/***********************************************************************************/
void insertionSort(int A[],int n)
{  int j;
    for(int i=0;i<n-1;i++)
    {
     j=i;
     int k=A[i+1];
     while(j>=0 && A[j]>k)
     {
        A[j+1]=A[j];
        j--;
     }
     A[j+1]=k;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d,",A[i]);
    }
}
void ssort(int **A,int n)
{
    int min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
           if(*(*A+min)>*(*A+j))
           {
            min=j;
           } 
        }
        int k=*(*A+i);
        *(*A+i)=*(*A+min);
        *(*A+min)=k;
    }
}
/***********************************************************************************/
int main()
{
    int *A;
    A=(int *)malloc(sizeof(int)*10);
    for (int i = 0; i < 10; i++)
    {
        scanf("%d",(A+i));
    }
    ssort(&A,10);
    for (int i = 0; i < 10; i++)
    {
      printf("%d||",*(A+i));
    }
    free(A);

    return 0;
    
}