#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 4;
    int len = ((n * 2) - 1);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("4 ");
        }
        printf("\n");
    }
    return 0;
}
