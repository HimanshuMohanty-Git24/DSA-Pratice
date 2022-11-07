#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    int x;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert:");
    scanf("%d", &x);
    if (x == -1)
    {
        return 0;
    }
    newnode->data = x;
    printf("Enter left child of %d", x);
    newnode->left = create();
    printf("Enter right child of %d", x);
    newnode->right = create();
    return newnode;
}
int main()
{
    struct node *root;
    root = NULL;
    root = create();
}