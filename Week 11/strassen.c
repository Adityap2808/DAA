#include <stdio.h>

void add(int a[10][10], int b[10][10], int c[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
}

void sub(int a[10][10], int b[10][10], int c[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = a[i][j] - b[i][j];
}

void strassen(int A[10][10], int B[10][10], int C[10][10], int n) {

    if (n == 1) {         // Base case
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int C11[10][10], C12[10][10], C21[10][10], C22[10][10];

    int M1[10][10], M2[10][10], M3[10][10], M4[10][10];
    int M5[10][10], M6[10][10], M7[10][10];
    int T1[10][10], T2[10][10];


    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    // M2 = (A21 + A22)B11
    add(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    // M3 = A11(B12 - B22)
    sub(B12, B22, T1, k);
    strassen(A11, T1, M3, k);

    // M4 = A22(B21 - B11)
    sub(B21, B11, T1, k);
    strassen(A22, T1, M4, k);

    // M5 = (A11 + A12)B22
    add(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    // M6 = (A21 - A11)(B11 + B12)
    sub(A21, A11, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    // M7 = (A12 - A22)(B21 + B22)
    sub(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    // Compute output submatrices
    // C11 = M1 + M4 - M5 + M7
    add(M1, M4, T1, k);
    sub(T1, M5, T2, k);
    add(T2, M7, C11, k);

    // C12 = M3 + M5
    add(M3, M5, C12, k);

    // C21 = M2 + M4
    add(M2, M4, C21, k);

    // C22 = M1 - M2 + M3 + M6
    sub(M1, M2, T1, k);
    add(T1, M3, T2, k);
    add(T2, M6, C22, k);

    // Combine 4 parts into C
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
}

int main() {
    int n;
    int A[10][10], B[10][10], C[10][10];

    printf("Enter matrix size (power of 2 only): ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("\nResult Matrix (A × B):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}