#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *tail = NULL;
void enqueue()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert:");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (front == NULL && tail == NULL)
        front = tail = new_node;
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
}
void dequeue()
{
    struct node *toDelete;

    if (front == NULL && tail == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        toDelete = front;
        front = front->next;

        printf("\nData deleted = %d\n", toDelete->data);

        free(toDelete);

        printf("\nSUCCESSFULLY DELETED\n");
    }
}
void peek()
{

    if (front == NULL && tail == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nFront data is :%d\n", front->data);
    }
}
void display()
{
    if (front == NULL && tail == NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nThe Queue is :\n");
        struct node *temp = front;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != NULL);
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
    printf("\n4. To exit\n");
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
            exit(1);
            break;
        default:
            printf("Incorrect Choice\n");
        }
    }
    return 0;
}
