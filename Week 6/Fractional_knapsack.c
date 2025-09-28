

#include <stdio.h>

int main() {
	int n, capacity;
	printf("Enter number of items: ");
	scanf("%d", &n);

	int weights[100], values[100];
	double ratio[100];

	printf("Enter weights of items (space separated):\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &weights[i]);
	}

	printf("Enter values of items (space separated):\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &values[i]);
	}

	printf("Enter knapsack capacity: ");
	scanf("%d", &capacity);


	for (int i = 0; i < n; i++) {
		ratio[i] = (double)values[i] / weights[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (ratio[j] < ratio[j + 1]) {

				double tempR = ratio[j];
				ratio[j] = ratio[j + 1];
				ratio[j + 1] = tempR;
				
				int tempW = weights[j];
				weights[j] = weights[j + 1];
				weights[j + 1] = tempW;
				
				int tempV = values[j];
				values[j] = values[j + 1];
				values[j + 1] = tempV;
			}
		}
	}

	double totalValue = 0.0;
	int remainingCapacity = capacity;

	printf("\nItems considered (sorted by value/weight ratio):\n");
	printf("Weight\tValue\tRatio\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%.2f\n", weights[i], values[i], ratio[i]);
	}

	for (int i = 0; i < n; i++) {
		if (remainingCapacity >= weights[i]) {
			remainingCapacity -= weights[i];
			totalValue += values[i];
		} else {
			totalValue += ratio[i] * remainingCapacity;
			break;
		}
	}

	printf("\nMaximum value in knapsack = %.2f\n", totalValue);
	return 0;
}
