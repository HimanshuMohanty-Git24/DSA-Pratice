#include <stdio.h>
// Both are O(n) Time complexity
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (fact(n - 1) * n);
    }
}
int factitr(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int main()
{
    int a = 5, result;
    result = fact(a);
    printf("Factorial of %d is:%d\n", a, result);
    a = 6;
    result = factitr(a);
    printf("Factorial of %d is:%d\n", a, result);
    return 0;
}
