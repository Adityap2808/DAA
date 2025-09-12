#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    int i, j, k;
    int mult_count = 0, add_count = 0;

    // Input dimensions
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if multiplication is possible
    if (c1 != r2) {
        printf("Matrix multiplication not possible.\n");
        return 1;
    }

    int a[r1][c1], b[r2][c2], result[r1][c2];

    // Input first matrix
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    // Input second matrix
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    // Initialize result matrix
    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            result[i][j] = 0;

    // Matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            for (k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
                mult_count++; // Counting multiplication
                if (k > 0) add_count++; // Counting addition (not for first element)
            }
        }
    }

    // Print result
    printf("Resultant matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%d ", result[i][j]);
        printf("\n");
    }

    printf("Number of multiplication operations: %d\n", mult_count);
    printf("Number of addition operations: %d\n", add_count);

    return 0;
}