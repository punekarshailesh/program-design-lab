#include <stdio.h>
#include <stdlib.h>

void read_array(int *ar , int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        scanf("%d",&ar[i]);
    }
}

int solve(int *ar , int n, int k)
{
    if((ar[n-1]-n) < k)
    {
        return -1;
    }
    int Num = -1;

    for(int i = 0 ; i<n ; i++)
    {
        if(ar[i] > Num)
        {
            Num = ar[i];
        }
    }

    int size = Num+1;

    int array[size];
    for(int i = 0 ; i<size ; i++)
    {
        array[i] = 0;
    }

    // struct queue *q = create(Num);

    for(int i = 0 ; i<n ; i++)
    {
        array[ar[i]] += 1;
    }

    int newarray[size];
    int newsize = 0;
    for(int i = 1 ; i<size ; i++)
    {
        if(array[i] == 0)
        {
            newarray[newsize++] = i;
        }
    }
    
    int res = -1;
    int i = 0;
    while(k--)
    {
        res = newarray[i++];
    }
    
    return res;
}

int main()
{

    int n;
    scanf("%d",&n);
    int * ar = (int*)malloc(n*sizeof(int));

    read_array(ar , n);
    int k;
    scanf("%d",&k);

    // int res = solve(ar , n , k);
    printf("%d\n",solve(ar , n, k));

    return 1;
}