#include <stdio.h>
int main()
{
    char s[] = "MOM";
    char r[] = "MOM";
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
    int flag = 0;
    for (int i = 0; s[i] != '\0' && r[i] != '\0'; i++)
    {
        if (s[i] != r[i])
        {
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nIt is a palindrome!!");
    }
    else
    {
        printf("\nNot a palindrome!!");
    }

    return 0;
}
