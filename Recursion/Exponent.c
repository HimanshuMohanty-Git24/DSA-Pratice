#include <stdio.h>
int funPow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return funPow(m, n - 1) * m;
    }
}
int funPow1(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return funPow1(m * m, n / 2);
    }
    else
    {
        return m * funPow1(m * m, (n - 1) / 2);
    }
}
int funPow2(int m, int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = result * m;
    }
    return result;
}
int main()
{
    int m = 2, n = 9;
    printf("%d to the power %d:%d\n", m, n, funPow(m, n));
    printf("%d to the power %d:%d\n", m, n, funPow1(m, n));
    printf("%d to the power %d:%d\n", m, n, funPow2(m, n));

    return 0;
}
