#include <stdio.h>
#include <stdlib.h>
int *fun(int n)
{
    int *p;
    p = (int *)malloc(n * sizeof(int));
    return (p);
}
int main()
{
    int *A;
    A = fun(5);
    return 0;
}
