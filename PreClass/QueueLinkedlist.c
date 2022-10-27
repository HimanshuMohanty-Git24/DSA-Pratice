#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void enqueue()
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert:");
    scanf("%d", &new_node->data);
    if (head == NULL)
        head = new_node;
    else
    {
        struct node *temp = NULL;
        for (temp = head; temp->next != NULL; temp = temp->next)
            ;
        temp->next = new_node;
    }
}
void dequeue()
{
    struct node *toDelete;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        /* Clears the memory occupied by first node*/
        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}
void display()
{
    printf("\nThe Queue is :\n");
    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != NULL);
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
