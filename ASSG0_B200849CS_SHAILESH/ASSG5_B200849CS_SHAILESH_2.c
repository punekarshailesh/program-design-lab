#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_string(char *str)
{
    int i = 0, j = strlen(str) - 1;
    for (; i <= j; i++, j--)
    {
        swap(&str[i], &str[j]);
    }
}

int main()
{
    char *str = malloc(1000 * sizeof(char));

    scanf("%[^\n]s", str);

    reverse_string(str);

    printf("%s\n", str);
    return 0;
}