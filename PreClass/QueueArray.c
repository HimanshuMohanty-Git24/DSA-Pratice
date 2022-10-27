// Queue implementation using array
#include <stdio.h>
#include <stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("\nQueue is full");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
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
        printf("\nThe dequeued element from the queue is:%d", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe Queue is:\n");
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
int main()
{
    int x;
    int choice = 0;
    printf("\nMenu driven Operation on Queue\n");
    printf("\n1.Enqueue\n2.Dequeue\n3.display\n4.EXIT\n");
    while (choice != 4)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data you want to insert:");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\nNot a valid choice ! !");
        }
    }

    return 0;
}
