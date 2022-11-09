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
    printf("\nEnter the data you want to insert(enter -1 for no node):");
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
void Preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d->", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Preorder(root->left);
    printf("%d->", root->data);
    Preorder(root->right);
}
void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Preorder(root->left);
    Preorder(root->right);
    printf("%d->", root->data);
}
int main()
{
    struct node *root;
    root = NULL;
    printf("\nCreation of Tree !!\n");
    root = create();
    printf("\nPreorder Traversal\n");
    Preorder(root);
    printf("\nInorder Traversal\n");
    Inorder(root);
    printf("\nPostorder Traversal\n");
    Postorder(root);
}