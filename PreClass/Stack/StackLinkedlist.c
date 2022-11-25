// Stack implementation using linkedlist
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void isempty()
{
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack is not empty");
    }
}
void push(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}
void display()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Under flow");
    }
    else
    {
        printf("\nStack Is:\n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
void peek()
{
    if (top == NULL)
    {
        printf("Under Flow");
    }
    else
    {
        printf("The top element is:%d", top->data);
    }
}
void pop()
{
    struct node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Under Flow");
    }
    else
    {
        printf("The popped element is:%d", top->data);
        top = top->next;
        free(temp);
    }
}
int main()
{
    int choice;
    int x;
    printf("\n\n\t\t\tStack Operation\t\t\t\n\n");
    printf("\nPress 1 to push\n");
    printf("\nPress 2 to pop\n");
    printf("\npress 3 to peek\n");
    printf("\npress 4 to Display the stack\n");
    printf("\npress 0 to exit the operation\n");
    while (choice != 0)
    {
        printf("\nChoose your desired operation:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data you want to push:");
            scanf("%d", &x);
            push(x);
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
        default:
            break;
        }
    }
    return 0;
}
