#include <stdio.h>
#include <stdlib.h>

void read_and_store(int *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
}

void print(int *ar, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", ar[i]);
    printf("\n");
}

int sum(int *ar, int i)
{
    int index = 0, sum = 0;
    for (; index < i; index++)
    {
        sum += ar[index];
    }
    return sum;
}

int search(int *ar, int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == s)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char opt;
    int size;
    int *ar;

    while (1)
    {
        scanf("%c", &opt);
        switch (opt)
        {
        case 'r':
            scanf(" %d", &size);
            ar = (int *)malloc(size * sizeof(int));
            read_and_store(ar, size);
            break;
        case 's':
            printf("%d\n", sum(ar, size));
            break;
        case 'f':
            int toFind;
            scanf(" %d", &toFind);
            int res = search(ar, size, toFind);
            printf("%d\n", res);
            break;
        case 'k':
            int find_sum_till_index;
            scanf(" %d", &find_sum_till_index);
            printf("%d\n", sum(ar, find_sum_till_index));
            break;
        case 'p':
            print(ar, size);
            break;
        case 't':
            exit(0);
        }
    }
    return 0;
}