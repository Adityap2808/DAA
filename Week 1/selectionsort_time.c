#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n, int *swaps) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            (*swaps)++;
        }
    }
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

int main() {
    int sizes[] = {10, 100, 1000, 5000, 10000};
    int count = 5;
    printf("Selection Sort Timing (in seconds) and Swaps:\n");
    printf(" n\tTime\t\tSwaps\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        int n = sizes[i], swaps = 0;
        int *arr = malloc(n * sizeof(int));
        fillRandom(arr, n);
        clock_t start = clock();
        selectionSort(arr, n, &swaps);
        clock_t end = clock();
        double t = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%6d\t%.6f\t%d\n", n, t, swaps);
        free(arr);
    }
    return 0;
}