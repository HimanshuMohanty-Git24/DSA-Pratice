#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert:");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
        rear->next = front;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
        rear->next = front;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\NQueue is empty");
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(temp);
    }
}
void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("\NQueue is empty");
    }
    else
    {
        printf("\nFront element is:%d\n", front->data);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == NULL && rear == NULL)
    {
        printf("\NQueue is empty");
    }
    else
    {
        printf("\nCircular Queue is:\n");
        while (temp->next != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
int main()
{
    int pick;
    printf("\nMENU\n");
    printf("\nChoose one task: \n");
    printf("\n1. Enqueue\n");
    printf("\n2. Dequeue\n");
    printf("\n3. Display\n");
    printf("\n4.Peek\n");
    printf("\n5. To exit\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &pick);
        switch (pick)
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
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}