#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// Complete the following function.

int find_nth_term(int n, int a, int b, int c)
{
    int *ptr = (int *)malloc(n * sizeof(int));
    ptr[0] = a;
    ptr[1] = b;
    ptr[2] = c;
    int sum = 0;
    for (int i = 3; i < n; i++)
    {
        ptr[i] = ptr[(i + 1) - 2] + ptr[(i + 1) - 3] + ptr[(i + 1) - 4];
    }
    sum = ptr[n - 1];
    return sum;
}

int main()
{
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);

    printf("%d", ans);
    return 0;
}