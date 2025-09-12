#include <stdio.h>

// Function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function for 0/1 Knapsack
int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
            knapsack(W, wt, val, n - 1)
        );
}

int main() {
    int n, W, i;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &val[i]);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &wt[i]);

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    int result = knapsack(W, wt, val, n);
    printf("Maximum value in knapsack = %d\n", result);

    return 0;
}