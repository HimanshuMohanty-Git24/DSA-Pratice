#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Complete the following function.

void calculate_the_maximum(int n, int k)
{
    int and, or, xor, m1 = 0, m2 = 0, m3 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            and = i & j;
            if (and > m1 && and < k)
            {
                m1 = and;
            }
            or = i | j;
            if (or > m2 && or < k)
            {
                m2 = or ;
            }
            xor = i ^ j;
            if (xor > m3 && xor < k)
            {
                m3 = xor;
            }
        }
    }
    printf("%d\n%d\n%d\n", m1, m2, m3);
}

int main()
{
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
