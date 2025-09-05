#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n, int *swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            (*swaps)++;
            j--;
        }
        arr[j + 1] = key;
    }
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

int main() {
    int sizes[] = {10, 100, 1000, 5000, 10000};
    int count = 5;
    printf("Insertion Sort Timing (in seconds) and Swaps:\n");
    printf(" n\tTime\t\tSwaps\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        int n = sizes[i], swaps = 0;
        int *arr = malloc(n * sizeof(int));
        fillRandom(arr, n);
        clock_t start = clock();
        insertionSort(arr, n, &swaps);
        clock_t end = clock();
        double t = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%6d\t%.6f\t%d\n", n, t, swaps);
        free(arr);
    }
    return 0;
}