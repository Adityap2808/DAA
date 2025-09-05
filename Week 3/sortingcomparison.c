#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

void copyArray(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

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

void bubbleSort(int arr[], int n, int *swaps) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

int main() {
    int sizes[] = {10, 100, 1000, 5000};
    int count = 4;
    printf("n\tInsertion\tSwaps\tSelection\tSwaps\tBubble\t\tSwaps\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));
        int *arr1 = malloc(n * sizeof(int));
        int *arr2 = malloc(n * sizeof(int));
        int *arr3 = malloc(n * sizeof(int));
        int swaps1 = 0, swaps2 = 0, swaps3 = 0;
        double t1, t2, t3;
        clock_t start, end;

        fillRandom(arr, n);
        copyArray(arr, arr1, n);
        copyArray(arr, arr2, n);
        copyArray(arr, arr3, n);

        start = clock();
        insertionSort(arr1, n, &swaps1);
        end = clock();
        t1 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        selectionSort(arr2, n, &swaps2);
        end = clock();
        t2 = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        bubbleSort(arr3, n, &swaps3);
        end = clock();
        t3 = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%d\t%.6f\t%d\t%.6f\t%d\n", n, t1, swaps1, t2, swaps2, t3, swaps3);

        free(arr);
        free(arr1);
        free(arr2);
        free(arr3);
    }
    return 0;
}