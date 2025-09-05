#include <stdio.h>
#include <math.h>
#include <time.h>

// O(n^2) Armstrong
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

// O(n log n) Armstrong
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
    printf("Armstrong numbers between 1 and 1000:\n");
    for (int i = 1; i <= 1000; i++) {
        if (isArmstrong_nlogn(i)) {
            printf("%d ", i);
        }
    }
    printf("\n\n");

    int sizes[] = {10, 100, 1000, 10000, 100000};
    int count = 5;

    printf("Runtime Comparison (in seconds):\n");
    printf(" n\tO(n^2)\t\tO(n log n)\n");
    printf("------------------------------------\n");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];

        clock_t start, end;
        double t1, t2;

        start = clock();
        armstrong_n2(n);
        end = clock();
        t1 = ((double)(end - start)) / CLOCKS_PER_SEC;

        start = clock();
        armstrong_nlogn(n);
        end = clock();
        t2 = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("%6d\t%.6f s\t%.6f s\n", n, t1, t2);
    }

    return 0;
}