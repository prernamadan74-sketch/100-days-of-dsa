#include <stdio.h>
#include <stdlib.h>

struct Pair {
    int value;
    int index;
};

void merge(struct Pair arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = 0;
    int tempSize = right - left + 1;
    struct Pair temp[tempSize];

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

void mergeSort(struct Pair arr[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, count);
        mergeSort(arr, mid + 1, right, count);

        merge(arr, left, mid, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Pair arr[n];
    int count[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, 0, n - 1, count);

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}