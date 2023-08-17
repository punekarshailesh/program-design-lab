#include <stdio.h>
#include <math.h>

long long int factorial(int val)
{
    long long int fact =1;

    for(int i = 1 ; i<=val ; i++)
    {
        fact = fact * i;
    }
    return fact;
}

void Sin(int x, int n)
{
    // first convert x to radian x = x *(3.1415/180)

    float rad = x * (3.1415/180);

    float ans = 0;
    ans += rad;
    for(int i = 3 ; i<=n ; i+=2)
    {
        ans -= (pow(rad , i)/factorial(i));
    }

    printf("%.4f\n",ans);

}

int main()
{
    int x , n; 
    scanf("%d %d",&x,&n);

    Sin(x , n);


    return 0;
}