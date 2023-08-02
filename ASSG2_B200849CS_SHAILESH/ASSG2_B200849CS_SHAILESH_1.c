#include <stdio.h>
#include <stdlib.h>

int solve(char *a, char *b)
{
    for (int i = 0; a[i] != '\0'; i++)
    {
        char ch = a[i] - 'a';
        b[ch] += 1;
    }

    int freq = 1;
    for (int i = 0; i < 27; i++)
    {
        if (b[i] > 0)
        {
            freq = freq * b[i];
        }
    }

    // printf("%d\n", freq);
    return freq;
}

int main()
{

    char string[1000];

    scanf("%[^\n]s", string);

    char frequency_ar[27] = {0};

    int result = solve(string, frequency_ar);
    printf("%d\n",result);
    return 0;
}