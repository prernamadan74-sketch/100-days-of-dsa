#include <stdio.h>
#include <stdlib.h>

// Structure for meeting
struct Meeting {
    int start, end;
};

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    struct Meeting *m1 = (struct Meeting *)a;
    struct Meeting *m2 = (struct Meeting *)b;
    return m1->start - m2->start;
}

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int pop(int heap[], int *size) {
    int root = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Meeting meetings[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }

    // Sort meetings by start time
    qsort(meetings, n, sizeof(struct Meeting), compare);

    int heap[n]; // min heap for end times
    int size = 0;

    // Add first meeting
    push(heap, &size, meetings[0].end);

    // Process remaining meetings
    for (int i = 1; i < n; i++) {
        if (heap[0] <= meetings[i].start) {
            pop(heap, &size); // reuse room
        }
        push(heap, &size, meetings[i].end);
    }

    printf("%d\n", size);
    return 0;
}
