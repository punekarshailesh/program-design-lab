#include <stdio.h>
#include <stdlib.h>

int power(int x)
{
    int prod = 1;
    for(int i = 1 ; i<=x ; i++)
    {
        prod = prod*8;
    }
    return prod;
}

int decimalToOctal(int n)
{

    int ans = 0, count = 0;
    while (n != 0)
    {
        int rem = n % 10;
        ans = rem * power(count) + ans;
        count += 1;
        n = n / 10;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d", &n);

    int result = decimalToOctal(n);

    printf("%d\n", result);
    return 0;
}