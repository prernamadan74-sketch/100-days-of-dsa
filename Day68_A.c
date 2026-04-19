#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add directed edge u -> v
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    indegree[v]++;  // increase in-degree of v
}

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    // Initialize
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;

    // Input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Push all nodes with indegree 0
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    // Kahn's algorithm
    while (front <= rear) {
        int u = dequeue();
        printf("%d ", u);

        struct Node* temp = adj[u];
        while (temp != NULL) {
            indegree[temp->data]--;

            if (indegree[temp->data] == 0) {
                enqueue(temp->data);
            }

            temp = temp->next;
        }
    }

    return 0;
}