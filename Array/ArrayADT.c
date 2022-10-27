#include <stdio.h>
#include <stdlib.h>
struct Array
{
    int *A;
    int size;
    int length;
};
void display(struct Array arr)
{
    int i;
    printf("\nElemen are:\n");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
}
void Add(int x, struct Array *arr) // T.C:O(1)
{
    if (arr->length == arr->size)
    {
        printf("Array is Full");
    }
    else
    {
        arr->A[arr->length] = x;
        arr->length++;
    }
}
void insert(int x, int pos, struct Array *arr) // T.C:O(n)
{
    if (arr->length == arr->size)
    {
        printf("Array is Full");
    }
    else
    {
        for (int i = arr->length; i > pos; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[pos] = x;
        arr->length++;
    }
}
void delete (int pos, struct Array *arr) // T.C:O(n)
{
    if (arr->length == 0)
    {
        printf("Array is Empty");
    }
    if (arr->length == arr->size)
    {
        printf("No elemnt as such");
    }
    else
    {
        for (int i = pos; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}
int linearSearch(int key, struct Array arr) // T.c:O(n)
{
    if (arr.length == 0)
    {
        printf("Array is Empty");
    }
    else
    {
        for (int i = 0; i < arr.length; i++)
        {
            if (arr.A[i] == key)
            {
                return i;
            }
        }
    }
    return -1;
}
int BinarySearch(int l, int h, int key, struct Array arr)
{
    int mid;
    while (l < h)
    {
        mid = l + h / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] > key)
        {
            h = mid - 1;
        }
        else if (arr.A[mid] < key)
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n;
    struct Array arr;
    printf("Enter size of an array:");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size * sizeof(int)); // Array is created in heap
    arr.length = 0;
    printf("Enter number of numbers:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }
    arr.length = n;
    display(arr);
    Add(7, &arr);
    insert(14, 3, &arr);
    display(arr);
    delete (4, &arr);
    display(arr);
    int choice = 10;
    int key, res;
    printf("\n\nEnter which way you want to search\n1.Linear Search\n2.Binary Search\n0.EXIT\n");
    while (choice != 0)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the element you want to find\n");
            scanf("%d", &key);
            res = linearSearch(key, arr);
            if (res == -1)
            {
                printf("\nElement not found\n");
            }
            else
            {
                printf("\nElement found at %d position in the array\n", res);
            }
            exit(1);
            break;
        case 2:
            printf("\nEnter the element you want to find\n");
            scanf("%d", &key);
            res = BinarySearch(0, arr.length, key, arr);
            if (res == -1)
            {
                printf("\nElement not found\n");
            }
            else
            {
                printf("\nElement found at %d position in the array\n", res);
            }
            exit(1);
            break;
        default:
            break;
        }
    }
}