#include <stdio.h>

int POWER(int a, int e)
{
    // base condition
    if (e == 0)
    {
        return 1;
    }

    if (e == 1)
    {
        return a;
    }

    int ans = POWER(a, e / 2);

    if (e % 2 == 0)
    {
        // if power is even
        return (ans * ans);
    }
    else
    {
        // power is odd
        return (a * ans * ans);
    }
}

int solve(int num, int e)
{

    int answer = 0;
    while (num != 0)
    {
        int digit = num % 10;
        answer += POWER(digit, e);
        num = num / 10;
    }

    return answer;
}

int main()
{
    int n, e;
    scanf("%d", &n);
    scanf("%d", &e);

    int result = solve(n, e);
    printf("%d\n", result);

    return 0;
}