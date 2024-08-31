#include <stdio.h>

int main() {
    int i, arr[100], n, mid, left, right, searchElement;

    // Prompt user for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input validation
    if (n < 1 || n > 100) {
        printf("Number of elements must be between 1 and 100.\n");
        return 1; // Exit with an error code
    }

    // Prompt user to enter the elements of the array
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sorting the array using Bubble Sort (to ensure binary search works correctly)
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Prompt user to enter the element to search
    printf("Enter the element to be searched: ");
    scanf("%d", &searchElement);

    // Initialize binary search boundaries
    left = 0;
    right = n - 1;

    // Binary search algorithm
    while (left <= right) {
        mid = (left + right) / 2;
        if (searchElement == arr[mid]) {
            // Element found
            printf("%d is found at position %d\n", searchElement, mid + 1);
            return 0;
        } else if (searchElement < arr[mid]) {
            // Search in the left half
            right = mid - 1;
        } else {
            // Search in the right half
            left = mid + 1;
        }
    }

    // Element not found
    printf("Element not found\n");

    return 0;
}
