#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];
int m;

// Initialize hash table
void init() {
    for (int i = 0; i < m; i++) {
        table[i] = -1; // -1 means empty
    }
}

// Insert using quadratic probing
void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

// Search using quadratic probing
int search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i * i) % m;

        if (table[index] == key)
            return 1;

        if (table[index] == -1)
            return 0;
    }
    return 0;
}

int main() {
    int n;
    char op[10];
    int key;

    // Table size
    scanf("%d", &m);

    init();

    // Number of operations
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}