#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define MAX_TRIPLETS 10

void main() {
    int sparse[MAX_ROWS][MAX_COLS];
    int triplet[MAX_TRIPLETS][3];
    int i, j, k = 1, col, row;

    // Input number of rows and columns
    printf("Enter the number of rows (max %d): ", MAX_ROWS);
    scanf("%d", &row);
    printf("Enter the number of columns (max %d): ", MAX_COLS);
    scanf("%d", &col);

    // Validate row and column sizes
    if (row > MAX_ROWS || col > MAX_COLS || row <= 0 || col <= 0) {
        printf("Invalid row or column size. Exiting.\n");
        return;
    }

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }

    // Convert to triplet representation
    triplet[0][0] = row;          // Number of rows
    triplet[0][1] = col;          // Number of columns
    triplet[0][2] = 0;            // Initialize count of non-zero elements

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (sparse[i][j] != 0) {
                triplet[k][0] = i;           // Row index
                triplet[k][1] = j;           // Column index
                triplet[k][2] = sparse[i][j]; // Non-zero value
                k++;
                triplet[0][2]++; // Increment count of non-zero elements
            }
        }
    }

    // Print the original matrix
    printf("Sparse matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", sparse[i][j]);
        }
   
