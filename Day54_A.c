#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

// Queue
typedef struct Queue {
    Node* arr[1000];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void push(Queue* q, Node* n) {
    if (q->front == -1) q->front = 0;
    q->arr[++q->rear] = n;
}

Node* pop(Queue* q) {
    return q->arr[q->front++];
}

// Create node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order
Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    Queue q;
    initQueue(&q);

    Node* root = newNode(arr[0]);
    push(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        Node* curr = pop(&q);

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(&q, curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(&q, curr->right);
        }
        i++;
    }

    return root;
}

// Zigzag traversal
void zigzagTraversal(Node* root) {
    if (!root) return;

    Queue q;
    initQueue(&q);

    push(&q, root);

    int leftToRight = 1;

    while (!isEmpty(&q)) {
        int size = q.rear - q.front + 1;
        int level[1000];

        for (int i = 0; i < size; i++) {
            Node* node = pop(&q);
            level[i] = node->data;

            if (node->left)
                push(&q, node->left);
            if (node->right)
                push(&q, node->right);
        }

        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", level[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}