#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int roll;
    char name[30];
    float cgpa;
    char branch[30];
    struct node *next;
} s;

s *makenode()
{
    s *p = (s *)malloc(sizeof(s));
    p->next = NULL;
    return p;
}
s *insert(int roll, char name[], float cgpa, char branch[], s *head)
{
    s *nw = makenode();
    nw->roll = roll;
    for (int i = 0; name[i] != '\0'; i++)
    {
        nw->name[i] = name[i];
    }

    nw->cgpa = cgpa;
    for (int i = 0; branch[i] != '\0'; i++)
    {
        nw->branch[i] = branch[i];
    }
    nw->next = head;
    head = nw;
    return head;
}
void traverse(s *ptr)
{
    while (ptr != NULL)
    {
        printf("%d %s %f %s", ptr->roll, ptr->name, ptr->cgpa, ptr->branch);
        printf("\n");
        ptr = ptr->next;
    }
}
void whiteList(s *head, char start[], char end[])
{
    s *p = head;
    while (p != NULL)
    {
        int flagb, flagn;
        for (int i = 0; p->branch[i] != '\0' && p->name[i] != '\0'; i++)
        {
            flagb = 0, flagn = 0;
            if ((p->branch[i] >= start[0] && p->branch[i] <= end[0]))
            {
                flagb = 1;
            }
            if ((p->name[i] >= start[0] && p->name[i] <= end[0]))
            {
                flagn = 2;
            }
        }
        if (flagb == 1)
        {
            printf("%s\n", p->branch);
        }
        if (flagn == 2)
        {
            printf("%s\n", p->name);
        }
        else
        {
            printf("");
        }
        p = p->next;
    }
}
int main()
{
    int n;
    int roll;
    char name[30];
    float cgpa;
    char branch[30];
    char whiteL[2], start[1], end[1];
    s *head = NULL;
    printf("Enter number of students:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Roll number:");
        scanf("%d", &roll);
        printf("Enter name:");
        scanf("%s", name);
        printf("Enter CGPA:");
        scanf("%f", &cgpa);
        printf("Enter Branch:");
        scanf("%s", branch);
        head = insert(roll, name, cgpa, branch, head);
    }
    printf("\nEnter the whitelist:");
    scanf("%s", whiteL);
    start[0] = whiteL[0];
    end[0] = whiteL[1];
    whiteList(head, start, end);

    return 0;
}