#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[100], sum = 0;
    printf("Enter %d numbers (from 0 to n, one missing):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int total = n * (n + 1) / 2;
    printf("Missing number is: %d\n", total - sum);
    return 0;
}