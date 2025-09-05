#include <stdio.h>

int main() {
    int n;
    printf("Enter n (matrix size): ");
    scanf("%d", &n);
    int mat[20][20];
    printf("Enter matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    // Transpose
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    // Reverse each row
    for (int i = 0; i < n; i++)
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            int temp = mat[i][j];
            mat[i][j] = mat[i][k];
            mat[i][k] = temp;
        }

    printf("Rotated matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}