#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num, mask = 255;
    printf("Enter a number:");
    scanf("%d", &num);
    int a = (num >> 24) & mask;
    int b = (num >> 16) & mask;
    int c = (num >> 8) & mask;
    int d = num & mask;
    printf("The content of B1 is:%d\nThe content of B2 is:%d\nThe content of B3 is:%d\nThe content of B4 is:%d\n", a, b, c, d);
    return 0;
}
