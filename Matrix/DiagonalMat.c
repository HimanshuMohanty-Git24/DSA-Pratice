#include <stdio.h>
int main()
{
    int Mat[5][5] = {// Diagonal matrix
                     {1, 0, 0, 0, 0},
                     {0, 2, 0, 0, 0},
                     {0, 0, 3, 0, 0},
                     {0, 0, 0, 4, 0},
                     {0, 0, 0, 0, 5}};
    int A[5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", Mat[i][j]);
            if (i == j)
            {
                A[i] = Mat[i][j];
            }
        }
        printf("\n");
    }
    printf("\nDIAGONAL ELEMENT\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
}