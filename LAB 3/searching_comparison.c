#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillRandom(int arr[], int n) {
    for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
}

void copyArray(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int linearSearch(int arr[], int n, int key, int *comparisons) {
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (arr[i] == key) return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key, int *comparisons) {
    int left = 0, right = n - 1;
    while (left <= right) {
        (*comparisons)++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int count = 5;
    printf("n\tLinearTime\tLinComp\tBinaryTime\tBinComp\n");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        int *arr = malloc(n * sizeof(int));
        int *arr2 = malloc(n * sizeof(int));
        int linComp = 0, binComp = 0;
        double t1, t2;
        clock_t start, end;

        fillRandom(arr, n);
        copyArray(arr, arr2, n);

        int key = arr[n - 1]; // Worst case

        start = clock();
        linearSearch(arr, n, key, &linComp);
        end = clock();
        t1 = (double)(end - start) / CLOCKS_PER_SEC;

        qsort(arr2, n, sizeof(int), compare);

        start = clock();
        binarySearch(arr2, n, key, &binComp);
        end = clock();
        t2 = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%.6f\t%d\t%.6f\t%d\n", n, t1, linComp, t2, binComp);

        free(arr);
        free(arr2);
    }
    return 0;
}