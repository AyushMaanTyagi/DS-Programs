#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Index_Seq_Search(int *A,int n,int x)
{
    int low=0,high=n-1;
    int m=(int)sqrt(n);
    if(A[low]>x && A[high]<x)
    {
        return -1;
    }
    else
    {
        int i=low;
        while (A[i]<x && i<high)
        {
            i+=m;
        }
        if(A[i]==x)
        return i;
        else
        {
            for (int j = i-m+1; j <=i-1; j++)
            {
                if(A[j]==x)
                return j;
            }
            return -1;
            
        }
        
    }

}

int main()
{
    // int A[]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,33,34,36,38,40,42,44,46,48,50,52,54};
    // int A[]={5,9,15,20,21,29,35,47,67};
    printf("%d",Index_Seq_Search(A,9,37));
}