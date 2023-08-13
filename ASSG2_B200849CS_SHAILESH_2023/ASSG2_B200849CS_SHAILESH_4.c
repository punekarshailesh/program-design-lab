#include <stdio.h>
#include <stdlib.h>

void read_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
}

int findSecretNumber(int ar[], int n, int k)
{
    int pivotIndex = -1;
    int low = 0, high = n - 1, mid = 0;
    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (ar[mid] >= ar[0])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    pivotIndex = low;
    // printf("%d\n",ar[pivotIndex]);

    if (k >= ar[pivotIndex] && k <= ar[n - 1])
    {
        // search after pivot elements
        low = pivotIndex;
        high = n - 1;
        mid = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (ar[mid] == k)
            {
                return mid;
            }

            if (k > ar[mid])
            {
                // search in left part
                low = mid + 1;
            }
            else
            {
                // search in right part
                high = mid - 1;
            }
        }
        return -1;
    }
    else
    {
        // search in right part
        low = 0, high = pivotIndex - 1;
        mid = -1;
        while (low <= high)
        {

            mid = low + (high - low) / 2;
            if (ar[mid] == k)
            {
                return mid;
            }

            if (k > ar[mid])
            {
                // search in left part
                low = mid + 1;
            }
            else
            {
                // search in right part
                high = mid - 1;
            }
        }
        return -1;
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    int *ar = (int *)malloc(n * sizeof(int));
    read_array(ar, n);
    int k;
    scanf("%d", &k);
    int resIndex = findSecretNumber(ar, n, k);
    printf("%d\n", resIndex);
    return 1;
}