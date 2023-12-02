#include<stdio.h>
#include<stdlib.h>
int LinSearch(int a[],int N,int e)
{
 for(int i=0;i<N;i++)
    {
        if(a[i]==e)
        {
 printf("element present at index:%d",i);
        exit(0);
        }
    }
printf("element not present");
}
int BinSearch(int a[],int N,int e)
{
int mid,l=0,h=N-1;
    
    
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==e)
        return mid;
        else{
            if(a[mid]>e)
            h=mid-1;
            else
            l=mid+1;
        }
    }
    return-1;
}
void main()
{
   int a[]={45,56,78,93,100,236}; 
   int e=450;
   LinSearch(a,6,e);
   int n=BinSearch(a,6,e);
   if(n!=-1)
   printf("element pr. at index:%d",n);
   else
   printf("element not present");

}