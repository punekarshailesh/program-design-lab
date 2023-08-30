#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -32768
#define INT_MAX 32768

void read_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
}

void print_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int second_largest(int ar[], int n)
{
    // find largest element in the element
    int firstMax = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (ar[i] > firstMax)
        {
            firstMax = ar[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ar[i] > secondMax && ar[i] < firstMax)
        {
            secondMax = ar[i];
        }
    }
    if (firstMax != secondMax)
        return secondMax;
    else
        return -1;
}

void solve(int ar[], int seondLargest, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ar[i] != seondLargest)
        {
            printf("%d ", ar[i]);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int *ar = (int *)malloc(n * sizeof(int));
    read_array(ar, n);

    int res = second_largest(ar, n);
    if (res == -1)
    {
        // no second largest element
        print_array(ar, n);
    }
    else
    {
        solve(ar, res, n);
    }
    // release memory
    free(ar);
    return 0;
}