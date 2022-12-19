#include <stdio.h>
int main()
{
    char s[] = "finding";
    int hash[26] = {0};
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
        hash[s[i] - 97]++;
    }
    for (j = 0; j < 26; j++)
    {
        if (hash[j] > 1)
        {
            printf("\n%c has duplicates.\n", j + 97);
        }
    }
}