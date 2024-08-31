#include <stdio.h>

int main() {
    int i, key, n, flag = 0, arr[100], count = 0;

    // Prompt user for the number of elements in the array
    printf("Enter the limit: ");
    scanf("%d", &n);
    count += 2;  // Increment count for reading the limit

    // Prompt user to enter the elements of the array
    printf("Enter the elements:\n");
    count++;  // Increment count for prompt message
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count += 2;  // Increment count for each scan operation (1 for scan and 1 for loop iteration)
    }
    count++;  // Increment count for loop completion

    // Prompt user for the search key
    printf("Enter the search key: ");
    scanf("%d", &key);
    count += 2;  // Increment count for the search key input

    // Perform linear search for the key
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            flag = 1;
            break;
        }
        count += 4;  // Increment count for each loop iteration: 1 for comparison, 1 for increment, 2 for the condition check
    }
    count++;  // Increment count for loop compl
