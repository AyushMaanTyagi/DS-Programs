#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int bubblesort(int *A[], int n)
{
    int flag = 1, c = 0;
    for (int i = 0; i < n - 1 && flag == 1; i++)
    {
        c++;
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (*(A + j) > *(A + j + 1))
            {
                int k = *(A + j);
                *(A + j) = *(A + j + 1);
                *(A + j + 1) = k;
                flag = 1;
            }
        }
    }
    return c;
}
/**************************************/
int selectionsort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        int k = A[i];
        A[i] = A[min];
        A[min] = k;
    }
    return 0;
}
/**************************************/
int insertionsort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int k = A[i + 1];
        int j = i;
        while (j >= 0 && A[j] > k)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = k;
    }
    return 0;
}
/**************************************/
int main()
{
    int *a[10000];
    // printf("enter elements:");
    // for (int i = 0; i < 6; i++)
    // {
    //     scanf("%d", (a + i));
    // }
    // insertionsort(a, 6);

    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int rn = rand();
        a[i] = (int *)malloc(sizeof(int));
    }
        bubblesort(a, 10000);
        for (int i = 0; i < 10000; i++)
        {
            printf("%d || ", a[i]);
            free(a[i]);
        }
       
    return 0;
}