// word or phrase formed by rearranging the letters of a different word or phrase
#include <stdio.h>
int main()
{
    char A[] = "decimal";
    char B[] = "medical";
    int i, h[26] = {0};
    for (i = 0; A[i] != '\0'; i++)
    {
        h[A[i] - 97]++;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        h[B[i] - 97]--; // If three is an odd alphabate then it will decrement the 0 which is -1 so we will find the odd alpahabte
        if (h[B[i] - 97] < 0)
        {
            printf("Not a anagram");
        }
    }
    if (B[i] == '\0')
    {
        printf("It's a anagram");
    }
    return 0;
}
