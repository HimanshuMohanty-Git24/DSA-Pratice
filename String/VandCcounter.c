#include <stdio.h>
int main()
{
    char s[] = "Hello There My Name Is Hima";
    int vcounter = 0;
    int ccounter = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vcounter++;
        }
        else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            ccounter++;
        }
    }
    printf("\nVowel=%d\nConsonant=%d\n", vcounter, ccounter);
}