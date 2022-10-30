#include <stdio.h>
#include <stdlib.h>
#define N 5
int dequeue[N];
int f = -1, r = -1;
void enqueuefront()
{
    int x;
    printf("\nEnter the value you want to insert:");
    scanf("%d", &x);
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("\nQueue is Full\n");
    }
    else if (f = -1 && r == -1)
    {
        f = r = 0;
        dequeue[f] = x;
    }
    else if (f == 0)
    {
        f = N - 1;
        dequeue[f] = x;
    }
}
void enqueuerear()
{
    int x;
    printf("\nEnter the value you want to insert:");
    scanf("%d", &x);
    if ((f == 0 && r == N - 1) || (f == r + 1))
    {
        printf("\nQueue is Full\n");
    }
    else if (f = -1 && r == -1)
    {
        f = r = 0;
        dequeue[r] = x;
    }
    else if (r == N - 1)
    {
        r = 0;
        dequeue[r] = x;
    }
    else
    {
        r++;
        dequeue[r] = x;
    }
}
void display()
{
    printf("\nDequeue is:\n");
    int i = f;
    while (i != r)
    {
        printf("%d ", dequeue[i]);
        i = (i + 1) % N;
    }
    printf("%d", dequeue[r]);
}
void getfront()
{
    if (f = -1 && r == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nFront value is:%d\n", dequeue[f]);
    }
}
void getrear()
{
    if (f = -1 && r == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else
    {
        printf("\nrear value is:%d\n", dequeue[r]);
    }
}
void dequeuefront()
{
    if (f == -1 && r == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (f == N - 1)
    {
        f = 0;
    }
    else
    {
        f++;
    }
}
void dequeuerear()
{
    if (f == -1 && r == -1)
    {
        printf("\nQueue is Empty\n");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else if (f == 0)
    {
        r = N - 1;
    }
    else
    {
        r--;
    }
}
int main()
{
    int x;
    int choice = 0;
    printf("\nMenu driven Operation on Queue\n");
    printf("\n1.Enqueue front\n2.Enqueue rear\n3.Dequeue front\n4.Dequeue rear\n5.Display\n6.Get front\n7.Get rear\n8.EXIT\n");
    while (choice != 8)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueuefront();
            break;
        case 2:
            enqueuerear();
            break;
        case 3:
            dequeuefront();
            break;
        case 4:
            dequeuerear();
            break;
        case 5:
            display();
            break;
        case 6:
            getfront();
            break;
        case 7:
            getrear();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("\nNot a valid choice ! !");
        }
    }

    return 0;
}