#include <stdio.h>
#define MAX 100
#define INF 99999

int main() {
    int n, src;
    int cost[MAX][MAX], dist[MAX], visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = cost[src][i];
    visited[src] = 1;

    for (int count = 1; count < n; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest distances from source vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("To %d : %d\n", i, dist[i]);
    }
    return 0;
}
