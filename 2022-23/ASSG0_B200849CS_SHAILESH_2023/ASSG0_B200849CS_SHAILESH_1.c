#include <stdio.h>

int Sum(int a , int b , int c)
{
    return (a+b+c);
}

int main()
{
    int a , b , c;
    scanf("%d %d %d",&a , &b, &c);

    int res = Sum(a, b, c);
    printf("%d\n",res);
    return 0;
}