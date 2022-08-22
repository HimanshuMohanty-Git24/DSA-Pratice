#include <stdio.h>
int fibitr(int n) // O(n)
{
    int t0 = 0, t1 = 1, s = 0, i;
    if (n <= 1)
    {
        return n;
    }
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int rfib(int n) // O(2^n)
{
    if (n <= 1)
    {
        return n;
    }
    return rfib(n - 2) + rfib(n - 1);
}
// memoization method to avoid excessive calls
int F[10]; // Global array
int mfib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        if (F[n - 2] == -1)
        {
            F[n - 2] = mfib(n - 2);
        }
        if (F[n - 1] == -1)
        {
            F[n - 1] = mfib(n - 1);
        }
        return F[n - 2] + F[n - 1];
    }
}
int main()
{
    for (int i = 0; i < 10; i++) // intializing for memoization
    {
        F[i] = -1;
    }
    int n;
    scanf("%d", &n);
    int res = fibitr(n);
    printf("\nUsing itterative method:%d\n", res);
    res = rfib(n);
    printf("\nUsing recursive method:%d\n", res);
    res = mfib(n);
    printf("\nUsing memoizaztion method:%d\n", res);
    return 0;
}
