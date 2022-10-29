#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue()
{
    int x;
    printf("\nEnter the element you want to insert:");
    scanf("%d", &x);
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("The dequed element is:%d\n", queue[front]);
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue is:\n");
        while (i != rear + 1)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("%d", queue[front]);
    }
}
int main()
{
    int x;
    int choice = 0;
    printf("\nMenu driven Operation on Queue\n");
    printf("\n1.Enqueue\n2.Dequeue\n3.display\n4.Peek\n5.EXIT\n");
    while (choice != 4)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(1);
            break;
        default:
            printf("\nNot a valid choice ! !");
        }
    }

    return 0;
}