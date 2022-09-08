#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person
{
    int num;
    int roll;
    char name[40];
    float cgpa;
    char branch[4];
    struct person *next;
};
struct person *head = NULL;
void new_record(int n)
{
    struct person *new_record;
    new_record = (struct person *)malloc(sizeof(struct person));
    new_record->num = n;
    printf("\n\n");
    printf("\nStudent-%d\n", new_record->num);
    printf("Enter Roll Number:");
    scanf("%d", &new_record->roll);
    printf("Enter name:");
    scanf("%s", &new_record->name);
    printf("Enter CGPA:");
    scanf("%f", &new_record->cgpa);
    printf("Enter Branch:");
    scanf("%s", &new_record->branch);
    printf("\n\n");
    if (head == NULL)
        head = new_record;
    else
    {
        new_record->next = head;
        head = new_record;
    }
}
void display()
{
    printf("\nEntered Student Details\n");
    printf("\n------------------------\n");
    struct person *temp = head;
    do
    {
        printf("\nStudent No-%d", temp->num);
        printf("\nStudent Roll Number:%d", temp->roll);
        printf("\nStudent name:%s", temp->name);
        printf("\nStudent CGPA:%f", temp->cgpa);
        printf("\nStudent Branch:%s", temp->branch);
        temp = temp->next;
        printf("\n\n");
    } while (temp != NULL);
}
int main()
{
    int c;
    int num = 0;
    printf("\nStudent Management system\n");
    printf("\nMENU\n");
    printf("\nChoose one:\n");
    printf("\n1.Create a new record\n");
    printf("\n2.Display the created records\n");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            num++;
            new_record(num);
            break;
        case 2:
            display();
            break;
        default:
            printf("Wrong Input !!");
            break;
        }
    }

    return 0;
}
