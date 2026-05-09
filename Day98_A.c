#include <stdio.h>
#include <stdlib.h>

// Structure for interval
struct Interval {
    int start, end;
};

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // Sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    // Merge intervals
    struct Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= result[index].end) {
            // overlap → merge
            if (arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            // no overlap → new interval
            index++;
            result[index] = arr[i];
        }
    }

    // Print merged intervals
    for (int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}
