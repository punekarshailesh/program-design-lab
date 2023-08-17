#include <stdio.h>
#include <stdlib.h>

int palindrome(int a, int b)
{

    if (a != b)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int solve(int num)
{
    int original = num, reverse = 0;
    while (num != 0)
    {
        int rem = num % 10;
        reverse = reverse * 10 + rem;
        num = num / 10;
    }

    if (palindrome(original, reverse))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int num;
    scanf("%d", &num);

    if (solve(num))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}