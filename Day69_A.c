#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Adjacency list node
struct Node {
    int v, w;
    struct Node* next;
};

struct Node* adj[MAX];

int dist[MAX];
int visited[MAX];

// Create node
struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected can be modified)
void addEdge(int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u, w);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Find minimum distance vertex (acts like priority queue)
int getMinVertex(int n) {
    int min = INT_MAX, minIndex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Dijkstra algorithm
void dijkstra(int n, int src) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        int u = getMinVertex(n);
        visited[u] = 1;

        struct Node* temp = adj[u];

        while (temp != NULL) {
            int v = temp->v;
            int w = temp->w;

            if (!visited[v] && dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }

    int u, v, w;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    // print distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}