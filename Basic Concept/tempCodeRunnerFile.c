#include <stdio.h>

int main(int argc, char const *argv[])
{
    int the_int = 1296;
    int a = (the_int >> 24) & 0xff;
    int b = (the_int >> 16) & 0xff;
    int c = (the_int >> 8) & 0xff;
    int d = the_int & 0xff;
    printf("%d\n%d\n%d\n%d\n", a, b, c, d);
    return 0;
}
