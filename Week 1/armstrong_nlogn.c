#include <stdio.h>
#include <math.h>
#include <time.h>

int isArmstrong_nlogn(int num) {
    int original = num, sum = 0;
    int digits = 0, temp = num;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        int d = temp % 10;
        sum += (int)pow(d, digits);
        temp /= 10;
    }

    return sum == original;
}

void armstrong_nlogn(int limit) {
    for (int i = 1; i <= limit; i++) {
        isArmstrong_nlogn(i);
    }
}

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int count = 5;

    printf("O(n log n) Armstrong Timing (in seconds):\n");
    printf(" n\tTime\n");
    printf("---------------------\n");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        clock_t start, end;
        double t;

        start = clock();
        armstrong_nlogn(n);
        end = clock();
        t = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%6d\t%.6f s\n", n, t);
    }

    return 0;
}
