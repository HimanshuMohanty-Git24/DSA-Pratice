// Digit to word
#include <stdio.h>

int main()
{
    static const char *strings[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n;
    scanf("%d", &n);
    if (n >= 1 && n <= 9)
    {
        printf("%s", strings[n - 1]);
    }
    else
    {
        printf("Greater than 9");
    }
    return 0;
}
