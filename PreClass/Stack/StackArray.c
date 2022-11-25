// Stack implememtaion using array
#include <stdio.h>
#define N 50
int stack[N];
int top = -1;
void isempty()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack is not empty\n");
    }
}
void isfull()
{
    if (top == N)
    {
        printf("\nStack is full\n");
    }
    else
    {
        printf("\nStack is not full\n");
    }
}
void push()
{
    int x;
    if (top == N - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("\nEnter the data you want to push to the stack:");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("\nThe popped item is:%d", item);
    }
}
void peek()
{
    if (top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nThe top element is:%d", stack[top]);
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nStack is:\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
int main()
{
    int choice;
    printf("\n\n\t\t\tStack Operation\t\t\t\n\n");
    printf("\nPress 1 to push\n");
    printf("\nPress 2 to pop\n");
    printf("\npress 3 to peek\n");
    printf("\npress 4 to Display the stack\n");
    printf("\npress 5 to check if stack is empty\n");
    printf("\npress 6 to check if stack is full\n");
    printf("\npress 0 to exit the operation\n");
    while (choice != 0)
    {
        printf("\nChoose your desired operation:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            isempty();
            break;
        case 6:
            isfull();
            break;
        default:
            break;
        }
    }
    return 0;
}