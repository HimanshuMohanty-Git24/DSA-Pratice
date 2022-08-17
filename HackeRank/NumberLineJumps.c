#include <stdio.h>
int main()
{
    long int x1, v1, p = 0;
    long int x2, v2;
    scanf("%ld %ld %ld %ld", &x1, &v1, &x2, &v2);
    for (long int i = 0; i <= 10000000; i++)
    {
        x1 = x1 + v1;
        x2 = x2 + v2;
        if (x1 == x2)
        {
            p = 1;
            break;
        }
    }
    if (p)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}
