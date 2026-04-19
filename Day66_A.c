#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

int visited[MAX];
int recStack[MAX];

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Directed edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS cycle detection
int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;  // mark in current path

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neigh = temp->data;

        // If not visited → go deeper
        if (!visited[neigh]) {
            if (dfs(neigh))
                return 1;
        }
        // If in recursion stack → cycle found
        else if (recStack[neigh]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[v] = 0; // remove from path before returning
    return 0;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Check all components
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}