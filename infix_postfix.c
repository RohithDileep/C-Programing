#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Global stack for operators in infix to postfix conversion
char stack[MAX_SIZE];
int top = -1; // Stack top index

// Push an element onto the stack
void push(char x) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = x;
}

// Pop an element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

// Return the precedence of an operator
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

// Convert an infix expression to postfix notation
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        // Skip spaces
        if (infix[i] == ' ')
            continue;

        // If the character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it onto the stack
        else if (infix[i] == '(') {
            push(infix[i]);
        }
        // If the character is ')', pop from the stack until '(' is found
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from the stack
        } 
        // If the character is an operator, pop operators from the stack
        // with higher or equal precedence
        else {
            while (top != -1 && stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Global stack for evaluating postfix expressions
int evalStack[MAX_SIZE];
int evalTop = -1; // Stack top index for evaluation

// Push an integer onto the evaluation stack
void pushEval(int x) {
    if (evalTop >= MAX_SIZE - 1) {
        printf("Evaluation Stack Overflow\n");
        exit(1);
    }
    evalStack[++evalTop] = x;
}

// Pop an integer from the ev
