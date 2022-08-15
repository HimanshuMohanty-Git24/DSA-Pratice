#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    scanf("%s", str);
    // printf("%s", str);
    int size = strlen(str);
    // printf("\n%d", size);
    int arr[10] = {0};
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '0')
        {
            arr[0]++;
        }
        if (str[i] == '1')
        {
            arr[1]++;
        }
        if (str[i] == '2')
        {
            arr[2]++;
        }
        if (str[i] == '3')
        {
            arr[3]++;
        }
        if (str[i] == '4')
        {
            arr[4]++;
        }
        if (str[i] == '5')
        {
            arr[5]++;
        }
        if (str[i] == '6')
        {
            arr[6]++;
        }
        if (str[i] == '7')
        {
            arr[7]++;
        }
        if (str[i] == '8')
        {
            arr[8]++;
        }
        if (str[i] == '9')
        {
            arr[9]++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
