#include <stdio.h>

int main() {
    int arr[100], n, i, j, min, temp;

    // Prompt user to enter the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Check for valid number of elements
    if (n <= 0 || n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1;
    }

    // Prompt user to enter the elements of the array
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        min = i; // Assume the minimum is the first el
