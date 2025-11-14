#include <stdio.h>

void activitySelection(int start[], int finish[], int n) {
    int i = 0;
    printf("Selected activities: %d ", i);

    for (int j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    int n;
    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];
    printf("Enter start times: ");
    for (int i = 0; i < n; i++) scanf("%d", &start[i]);
    printf("Enter finish times: ");
    for (int i = 0; i < n; i++) scanf("%d", &finish[i]);

   
    activitySelection(start, finish, n);
    return 0;
}