#include <stdio.h>
#include <time.h>

int isArmstrong_n2(int num) {
    int original = num, sum = 0;
    int digits = 0, temp = num;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        int d = temp % 10;
        int mul = 1;
        for (int i = 0; i < digits; i++) {
            mul *= d;
        }
        sum += mul;
        temp /= 10;
    }

    return sum == original;
}

void armstrong_n2(int limit) {
    for (int i = 1; i <= limit; i++) {
        isArmstrong_n2(i);
    }
}

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};
    int count = 5;

    printf("O(n^2) Armstrong Timing (in seconds):\n");
    printf(" n\tTime\n");
    printf("---------------------\n");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];
        clock_t start, end;
        double t;

        start = clock();
        armstrong_n2(n);
        end = clock();
        t = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%6d\t%.6f s\n", n, t);
    }

    return 0;
}