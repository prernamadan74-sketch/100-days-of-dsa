#include <stdio.h>
#include <stdlib.h>

#define OFFSET 100
#define SIZE 205

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue for BFS
typedef struct Queue {
    Node* node[1000];
    int hd[1000];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void push(Queue* q, Node* n, int h) {
    if (q->front == -1) q->front = 0;
    q->node[++q->rear] = n;
    q->hd[q->rear] = h;
}

Node* popNode(Queue* q) {
    return q->node[q->front];
}

int popHD(Queue* q) {
    return q->hd[q->front++];
}

// Tree node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree (level order)
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Queue q;
    initQueue(&q);

    Node* root = newNode(arr[0]);
    push(&q, root, 0);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        Node* curr = popNode(&q);
        popHD(&q); // not used for building

        // left
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(&q, curr->left, 0);
        }
        i++;

        // right
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(&q, curr->right, 0);
        }
        i++;
    }

    return root;
}

// Vertical order traversal
void verticalOrder(Node* root) {
    if (!root) return;

    // array of "buckets"
    int result[SIZE][1000];
    int count[SIZE] = {0};

    Queue q;
    initQueue(&q);

    push(&q, root, 0);

    int minHD = OFFSET, maxHD = OFFSET;

    while (!isEmpty(&q)) {
        Node* node = popNode(&q);
        int hd = popHD(&q);

        result[hd + OFFSET][count[hd + OFFSET]++] = node->data;

        if (node->left)
            push(&q, node->left, hd - 1);

        if (node->right)
            push(&q, node->right, hd + 1);

        if (hd + OFFSET < minHD) minHD = hd + OFFSET;
        if (hd + OFFSET > maxHD) maxHD = hd + OFFSET;
    }

    for (int i = 0; i < SIZE; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}