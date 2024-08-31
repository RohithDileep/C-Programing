#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 100

// Queue array and pointers
int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
bool isFull(int maxSize) {
    return rear == maxSize - 1;
}

// Function to check if the queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to add an element to the queue
void enqueue(int maxSize) {
    int val;

    if (isFull(maxSize)) {
        printf("Queue is full\n");
        return;
    }

    // If queue is empty, initialize front and rear
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    printf("Enter the value to be added to the queue: ");
    scanf("%d", &val);
    queue[rear] = val;
}

// Function to dequeue an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Element removed from the queue is %d\n", queue[front]);

    // If the queue becomes empty after dequeue
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queu
