#include <stdio.h>
#include <stdlib.h>

void read_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &ar[i]);
}

int getSum(int ar[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ar[i];
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *ar = malloc(n * sizeof(int));

    read_array(ar, n);

    int sum = getSum(ar, n);

    printf("%d\n", sum);

    // free memory
    free(ar);

    return 0;
}