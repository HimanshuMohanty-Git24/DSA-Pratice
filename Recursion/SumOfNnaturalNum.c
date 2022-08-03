#include <stdio.h>
// O(n) time complexity
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sum(n - 1) + n;
    }
}
// O(1) time complexity
int sumFr(int n)
{
    return (n * (n + 1)) / 2;
}
// O(n) time complexity
int sumitr(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
}
int main()
{
    int a = 100;
    printf("Sum of first %d natural number is:%d\n", a, sum(a));
    printf("Sum of first %d natural number is:%d\n", a, sumFr(a));
    printf("Sum of first %d natural number is:%d\n", a, sumitr(a));
    return 0;
}
