#include <stdio.h>
#include <stdlib.h>
void Merge(int A[], int low, int mid, int high);
void mergesort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}
void Merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int *C = (int *)malloc((high + 1) * sizeof(int));
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            C[k] = A[i];
            i++;
            k++;
        }
        else
        {
            C[k] = A[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        C[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        C[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = C[i];
    }
    free(C);
}
int main()
{
    int n;
    printf("enter n");
    scanf("%d", &n);
    int *A = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    mergesort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}