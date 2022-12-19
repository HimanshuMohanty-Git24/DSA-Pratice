#include <stdio.h>
int main()
{
    char s[] = "Hello";
    char temp;
    int i, j;
    for (j = 0; s[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    printf("\nReversed string:%s", s);
}