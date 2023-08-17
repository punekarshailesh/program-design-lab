#include <stdio.h>
#include <stdlib.h>

void read_array(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
}

int reverse(int a)
{
    int rev = 0;
    while (a != 0)
    {
        int rem = a % 10;
        rev = rev * 10 + rem;
        a = a / 10;
    }
    return rev;
}

int PALINDROME(int num)
{

    int ans = reverse(num);
    // int count = 0;
    if (ans == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // return count;
}

int solve(int ar[], int n)
{
    int result = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        result = PALINDROME(ar[i]);
        if (result)
        {
            count += 1;
        }
    }
    // printf("\n");
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);

    // dynamic memory allocation - heap memory
    int *arr = (int *)malloc(n * sizeof(int));

    read_array(arr, n);

    int res = solve(arr, n);

    printf("%d\n", res);

    // after using release the heap memory
    free(arr);
    return 0;
}