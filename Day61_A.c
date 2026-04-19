#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX] = {0};

    scanf("%d", &n);  // number of vertices
    scanf("%d", &m);  // number of edges

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;      // for directed graph
        adj[v][u] = 1;      // comment this line for directed graph
    }

    // Print adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}