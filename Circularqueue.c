#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 50 
int front = -1, rear = -1, cq[N];
void enqueue(int item, int size)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        printf("%d successfully inserted\n", item);
        cq[rear] = item;
    }
    else if ((rear + 1) % size == front)
    {
        printf("Queue overflow\n");
    }
    else
    {
        printf("%d successfully inserted\n", item);
        rear = (rear + 1) % size;
        cq[rear] = item;
    }
}
void dequeue(int item, int size)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow\n");
    }
    else if (rear == front)
    {
        printf("%d successfully deleted", cq[front]);
        cq[front] = 0;
        rear = -1;
        front = -1;
    }
    else
    {
        printf("%d successfully deleted", cq[front]);
        cq[front] = 0;
        front = (front + 1) % size;
    }
}
void display(int size)
{
    if (front == -1 && rear == -1)
    {
        printf("Queue underflow\n");
    }
    else
    {
        printf("Queue elements:\n");
        for (int i = 0; i < size; i++)
        {
            if (cq[i] == 0)
                printf("_\t");
            else
                printf("%d\t", cq[i]);
        }
        printf("\n");
    }
}
void main()
{
    int size, item, choice;
    printf("Enter the size of queue\n");
    scanf("%d", &size);
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display queue elements\n4.Exit\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                printf("Enter element to be inserted:");
                scanf("%d", &item);
                enqueue(item, size);
                break;
            }
            case 2:
                dequeue(item, size);
                break;
            case 3:
                display(size);
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
        }
    } while (true);
}
