#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *str)
{
    // converting uppercase to lower cases
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }

    // now checking is palindrome or not

    int i = 0, j = strlen(str) - 1;
    for (; i <= j; i++, j--)
    {
        if (str[i] != str[j])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char *str = malloc(1000 * sizeof(char));

    scanf("%[^\n]s", str);
    int res = isPalindrome(str);

    if (res)
        printf("YES\n");
    else
        printf("NO\n");

    free(str);

    return 0;
}