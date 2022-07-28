#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int *p;
    int n = 6;
    p = (int *)malloc(n * sizeof(int));
    free(p);
    p = NULL;
    return 0;
}
