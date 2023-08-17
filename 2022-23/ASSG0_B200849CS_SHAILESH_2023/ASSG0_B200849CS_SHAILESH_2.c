#include <stdio.h>
#include <stdlib.h>

void read_array(int ar[] , int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        scanf("%d",&ar[i]);
    }
}

int findLargest(int ar[] , int n)
{
    int Largest = -1;

    for(int i = 0 ; i<n ; i++)
    {
        if(ar[i] > Largest)
        {
            Largest = ar[i];
        }
    }
    return Largest;
}

int main()
{
    int n;
    scanf("%d",&n);
    int * ar = (int*)malloc(n*sizeof(int));
    read_array(ar , n);

    int largest = findLargest(ar , n);
    printf("%d\n", largest);
    return 0;
}