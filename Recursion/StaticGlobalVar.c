#include <stdio.h>
int fun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    int a = 5;
    printf("%d", fun(a));
    return 0;
}
