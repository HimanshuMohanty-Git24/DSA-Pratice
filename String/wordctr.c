#include <stdio.h>
int main()
{
    char s[] = "Hello There My Name Is Hima";
    int wcounter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' && s[i - 1] != ' ')
        {
            wcounter++;
        }
    }
    printf("\nWords=%d\n", wcounter + 1);
}