#include <stdio.h>
#define INF 99999
#define MAX 100

int main() {
    int n;
    int cost[MAX][MAX];
    int selected[MAX] = {0};
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    selected[0] = 1; // Start from vertex 0

    printf("\nEdges in MST:\n");
    for (int edges = 0; edges < n - 1; edges++) {
        int min = INF, x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (x != -1 && y != -1) {
            printf("%d - %d : %d\n", x, y, min);
            total += min;
            selected[y] = 1;
        }
    }
    printf("Total cost of MST = %d\n", total);
    return 0;
}
