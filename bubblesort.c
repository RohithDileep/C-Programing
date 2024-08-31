#include <stdio.h>

int main() {
    int arr[100];    // Array to hold the elements
    int n, i, j, swap;

    // Prompt user for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check if the number of elements is within the allowed range
    if (n < 1 || n > 100) {
        printf("Number of elements must be between 1 and 100.\n");
        return 1; // Exit with an error code
    }

    // Prompt user to enter the elements of the array
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Bubble Sort algorithm to sort the array in ascending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            // Compare adjacent elements and swap if needed
            if (arr[j] 
