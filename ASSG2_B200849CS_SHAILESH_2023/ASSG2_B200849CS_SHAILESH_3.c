#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -2147483647

void read_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
}

int SOLVE(int ar[], int n)
{
    int RES = -1;

    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low)/2;
        if (ar[mid] > ar[mid + 1])
        {
            RES = ar[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return RES;
}

int main()
{

    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    read_array(arr, n);

    int RES = SOLVE(arr, n);
    printf("%d\n", RES);
    return 1;
}