#include <stdio.h>
int main()
{
    char a[] = "Hello";
    char b[] = "Hello";
    int flag = 0;
    for (int i = 0; a[i] != '\0' && b[i] != '\0'; i++)
    {
        if (a[i] != b[i])
        {
            flag++;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nSame string");
    }
    else
    {
        printf("\nNot same string");
    }
}