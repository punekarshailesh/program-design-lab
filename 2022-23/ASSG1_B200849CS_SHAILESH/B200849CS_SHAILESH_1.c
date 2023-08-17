#include <stdio.h>
#include <stdlib.h>


int frequencyOfCharacter(char * ar, char tosearch)
{

    // characters are not case sensitive means 'a' and 'A' can be consider as a same
    for(int i = 0 ; ar[i] != '\0' ; i++)
    {
        if(ar[i] >='A' && ar[i] <= 'Z')
        {
            // converting upper case to lower case
            ar[i] = ar[i] + 32;
        }
    }

    // time complexity - O(n) & space complexity - O(26)
    int Hash[26] = {0};

    for(int i = 0 ; ar[i] != '\0' ; i++)
    {
        Hash[ar[i]-'a'] += 1;
    }


    int res = Hash[tosearch - 'a'];

    return res;

}

int main()
{

    char * str = (char*)malloc(1000 * sizeof(char));

    scanf("%[^\n]s",str);
    getchar();
    char ch;

    scanf("%c",&ch);

    int res = frequencyOfCharacter(str , ch);

    printf("%d\n",res);
    return 0;
}