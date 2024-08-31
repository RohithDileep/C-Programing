#include <stdio.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Global variables for stack operations
int top = -1;            // Index of the top element in the stack
int stack[MAX_SIZE];     // Array to store stack elements

// Function to add an element to the stack
void push(int item, int size) {
    // Check if the stack is full
    if (top == size - 1) {
        printf("Stack overflow\n");
        return;
    }
    // Increment the top index and add the item to the stack
    top++;
    stack[top] = item;
    printf("Element successfully added to stack\n");
}

// Function to remove and return the top element of the stack
int pop() {
    // Check if the stack is empty
    if (top == -1) {
        printf("Stack underflow\n");
        return 0; // Return 0 to indicate an error (not a valid stack element)
    }
    // Remove the top element and decrement the top index
    int item = stack[top];
    top--;
    printf("Element successfully removed from the stack is %d\n", item);
    return item;
}

// Function to display the top element of the stack without removing it
void peek() {
    // Check if the stack is empty
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    // Display the top element of the stack
    printf("The element at the top of the stack is %d\n", stack[top]);
}

// Function to check if the stack is full
void isFull(int size) {
    // Compare the top index with the maximum size of the stack
    i
