#include <stdio.h>
#include <stdlib.h>
struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle *ptr;
    ptr = (struct Rectangle *)malloc(sizeof(struct Rectangle));
    ptr->length = 20;
    ptr->breadth = 10;
    printf("Area:%d", (ptr->length) * (ptr->breadth));
    return 0;
}
