#include <stdio.h>
void funA(int n);
void funB(int n);
int main()
{
    int a = 20;
    funA(a);
}
void funA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funA(n / 2);
    }
}