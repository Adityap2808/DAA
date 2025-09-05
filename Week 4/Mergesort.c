#include <stdio.h>

int main() {
    int arr[100], n;
    int L[100], R[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    // Merge sort logic inside main
    int size;
    for (size = 1; size < n; size = 2 * size) {
        int left_start;
        for (left_start = 0; left_start < n; left_start += 2 * size) {
            int mid = left_start + size - 1;
            int right_end = left_start + 2 * size - 1;
            if (mid >= n) continue;
            if (right_end >= n) right_end = n - 1;

            int n1 = mid - left_start + 1;
            int n2 = right_end - mid;
            for (int i = 0; i < n1; i++) L[i] = arr[left_start + i];
            for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

            int i = 0, j = 0, k = left_start;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j]) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
            while (i < n1) arr[k++] = L[i++];
            while (j < n2) arr[k++] = R[j++];
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}