#include <stdio.h>
#include <stdlib.h>

void read_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
}

int targetIndex(int ar[], int n , int target)
{
    // using binary search
    int low = 0 , high = n-1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(ar[mid] == target)
        {
            return mid;
        }
        else if(ar[mid] > target)
        {
            // search in left part
            high = mid-1;
        }
        else
        {
            // search in right part
            low = mid+1;
        }
    }
    return -1;

}

void printIndex(int ar[], int n, int target)
{
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] > target)
        {
            res = 0;
            printf("%d ", i);
        }
    }
    if (res == -1)
    {
        printf("-1");
    }
    printf("\n");
}

int main()
{
    int n, target;
    scanf("%d %d", &n, &target);
    int *ar = malloc(n * sizeof(int));
    read_array(ar, n);

    int indexTarget = targetIndex(ar, n, target);

    if (indexTarget == -1)
    {
        // key is not present
        printf("-1\n");
        printf("-1\n");
    }
    else
    {
        printf("%d\n", indexTarget);
        printIndex(ar, n, target);
    }

    free(ar);
    return 0;
}