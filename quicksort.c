#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
int Partition(int A[], int low, int high)
{
    // int rn=rand()%(high-low+1)+low;
    // int a[low];
    // int k=A[rn];
    // A[rn]=A[low];
    // A[low]=k;
    int i = low;
    int j = high + 1;
    int pivot = A[low];
    do
    {
        do
        {
            i++;
        } while (A[i] < pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
        {
            int k = A[i];
            A[i] = A[j];
            A[j] = k;
        }

    } while (i < j);
    int a = A[j];
    A[j] = A[low];
    A[low] = a;
    return j;
}
int quicksort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = Partition(A, low, high);
        quicksort(A, low, j - 1);
        quicksort(A, j + 1, high);
    }
    return 0;
}
int medianquicksort(int A[], int low, int high)
{
    int mid = (low + high) / 2;
    int k = A[low];
    A[low] = A[mid];
    A[mid] = k;
    int j = Partition(A, low, high);
    quicksort(A, low, j - 1);
    quicksort(A, j + 1, high);
    return 0;
}
int randomquicksort(int A[], int low, int high)
{
    int rn = rand() % high;
    printf("%d\n", rn);
    int k = A[low];
    A[low] = A[rn];
    A[rn] = k;
    int j = Partition(A, low, high);
    randomquicksort(A, low, j - 1);
    randomquicksort(A, j + 1, high);
}

int main()
{
    int n;
    printf("enter n");
    scanf("%d", &n);
    int *A = (int *)malloc(sizeof(int) * n + 1);
    printf("enter elements");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int low = 0, high = n - 1;
    A[n] = INT_MAX;
    quicksort(A, low, high);
    for (int i = 0; i < n; i++)
    {
        printf("%d-->", A[i]);
    }
    return 0;
}