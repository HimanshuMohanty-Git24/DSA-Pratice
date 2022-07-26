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
int delete(int pos, struct Array *arr) // T.C:O(n)
{
    int x;
    x = arr->A[pos];
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
    return x;
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
int linRec(int m, int arr[], int key) // Recursive method of linear search
{
    if (m < 0)
    {
        return -1;
    }
    if (arr[m] == key)
    {
        return m;
    }
    else
    {
        return linRec(m - 1, arr, key);
    }
}
int BinarySearch(int l, int h, int key, struct Array arr) // T.C:O(log n)
{
    int mid;
    while (l <= h)
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
int BsRec(int a[], int key, int low, int high) // Binary Search Recursive method
{
    if (low > high)
    {
        return -1;
    }
    int mid = (low + high) / 2;
    if (a[mid] == key)
    {
        return mid;
    }
    if (key > a[mid])
    {
        return BsRec(a, key, mid + 1, high);
    }
    else
    {
        return BsRec(a, key, low, mid - 1);
    }
}
int Get(int index, struct Array arr)
{
    if (index >= 0 && index < arr.size)
    {
        return arr.A[index];
    }
    else
    {
        return -1;
    }
}
void set(int index, int key, struct Array arr)
{
    if (index >= 0 && index < arr.size)
    {
        arr.A[index] = key;
    }
    else
    {
        printf("\nWrong Index Please Try Again...\n");
    }
}
int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    }
    return max;
}
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    }
    return min;
}
int sum(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum = sum + arr.A[i];
    }
    return sum;
}
float avg(struct Array arr)
{
    float total = sum(arr);
    return total / arr.length;
}
void reverse(struct Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[i] = temp;
    }
}
void sortedInsert(int key, struct Array *arr)
{
    int i = arr->length - 1;
    while (arr->A[i] > key)
    {
        arr->A[i] = arr->A[i - 1];
        i--;
    }
    arr->A[i + 1] = key;
}
void sortedCheck(struct Array arr)
{
    int flag = 0;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nArray is sorted !!\n");
    }
    else if (flag == 1)
    {
        printf("\nArray is not sorted !!\n");
    }
}
void negPosSides(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (arr->A[i] < 0)
    {
        i++;
    }
    while (arr->A[j] >= 0)
    {
        j--;
    }
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
}
struct Array *Merge(struct Array *arr1, struct Array *arr2) // T.C=O(m+n)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct
                                                       Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;

    return arr3;
}
struct Array *Union(struct Array *arr1, struct Array *arr2)
{
    int i, j, k;
    i = j = k = 0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct
                                                       Array));

    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if (arr2->A[j] < arr1->A[i])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr1->A[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}
int main()
{
    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array:");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;
    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");

        printf("enter you choice ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter an element and index ");
            scanf("%d%d", &x, &index);
            insert(x, index, &arr1);
            break;
        case 2:
            printf("Enter index ");
            scanf("%d", &index);
            x = delete (index, &arr1);
            printf("Deleted Element is %d\n", x);
            break;
        case 3:
            printf("Enter element to search ");
            scanf("%d", &x);
            index = linearSearch(x, arr1);
            if (index == -1)
            {
                printf("\nElement not found !!!\n");
            }
            else
            {
                printf("Element index %d", index);
            }
            break;
        case 4:
            printf("Sum is %d\n", sum(arr1));
            break;
        case 5:
            display(arr1);
        }
    } while (ch < 6);
    return 0;
}