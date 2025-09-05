#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) return i;
    }
    return -1;
}

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 10000;
}

int main() {
    int sizes[] = {10, 100, 1000, 5000, 10000};
    int count = 5;
    printf("Linear Search Timing (in seconds) and Comparisons:\n");
    printf(" n\tTime\t\tComparisons\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        int n = sizes[i], comparisons = 0;
        int *arr = malloc(n * sizeof(int));
        fillRandom(arr, n);
        int key = arr[n - 1]; // Worst case
        clock_t start = clock();
        linearSearch(arr, n, key, &comparisons);
        clock_t end = clock();
        double t = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%6d\t%.6f\t%d\n", n, t, comparisons);
        free(arr);
    }
    return 0;
}