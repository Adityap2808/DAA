#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int V, E, S;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Edge edge[E];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);

    printf("Enter source vertex: ");
    scanf("%d", &S);

    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[S] = 0;

    for (int i = 1; i < V; i++) {  
        for (int j = 0; j < E; j++) {
            int u = edge[j].u, v = edge[j].v, w = edge[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = edge[j].u, v = edge[j].v, w = edge[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle!\n");
            return 0;
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);

    return 0;
}