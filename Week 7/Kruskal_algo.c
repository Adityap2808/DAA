#include <stdio.h>
#define MAX 100

struct Edge {
    int u, v, weight;
};

int find(int parent[], int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

int main() {
    int n, e;
    struct Edge edges[MAX];
    int parent[MAX];
    int mst_weight = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Sort edges by weight (Bubble Sort)
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");
    int count = 0;
    for (int i = 0; i < e && count < n - 1; i++) {
        int u_set = find(parent, edges[i].u);
        int v_set = find(parent, edges[i].v);
        if (u_set != v_set) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].weight);
            mst_weight += edges[i].weight;
            parent[u_set] = v_set;
            count++;
        }
    }
    printf("Total weight of MST = %d\n", mst_weight);
    return 0;
}
