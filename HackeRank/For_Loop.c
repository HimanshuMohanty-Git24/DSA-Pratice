#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    static const char *strings[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int a, b;
    scanf("%d\n%d", &a, &b);
    for (int i = a; i <= b; i++)
    {

        if (i >= 1 && i <= 9)
        {
            printf("%s\n", strings[i - 1]);
        }
        else
        {
            if (i % 2 == 0)
            {
                printf("even\n");
            }
            else
            {
                printf("odd\n");
            }
        }
    }

    return 0;
}
