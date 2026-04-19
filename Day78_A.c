#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];

// Function to find minimum key vertex not yet included in MST
int findMin(int key[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int prims() {
    int key[MAX];       // Stores minimum weight to connect
    int visited[MAX];   // Track visited nodes
    int total_weight = 0;

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from node 1
    key[1] = 0;

    for (int count = 1; count <= n; count++) {
        int u = findMin(key, visited);
        visited[u] = 1;
        total_weight += key[u];

        // Update keys of adjacent vertices
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return total_weight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph with 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Undirected graph
    }

    int result = prims();
    printf("%d\n", result);

    return 0;
}
