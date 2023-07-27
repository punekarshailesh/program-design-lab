#include <stdio.h>
#include <stdlib.h>


void read_array(int ar[] , int n)
{
    for(int i = 0 ; i<n ; i++){
        scanf("%d",&ar[i]);
    }
}


void rotate_array(int ar[] , int n , int m)
{
    int i = 0;
    while(m>0)
    {
        int temp = ar[0];
        // shifting
        for(i = 1 ; i<n ; i++)
        {
            ar[i-1] = ar[i];
        }
        ar[i-1] = temp;
        m = m-1;
    }
}

void print_array(int ar[] , int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
}

int main()
{
    int n,m;
    scanf("%d",&n);
    int * ar = (int*)malloc(n*sizeof(int));
    
    // read array
    read_array(ar , n);
    scanf("%d",&m);

    // call rotate function
    rotate_array(ar , n , m);
    
    // print the array
    print_array(ar , n);

    // release the heap memory
    free(ar);
    return 0;
}