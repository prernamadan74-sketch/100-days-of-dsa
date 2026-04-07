#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;      // left subarray
    int j = mid + 1;   // right subarray
    int k = left;      // temp index
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1); // count inversions
        }
    }

    // Remaining elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return invCount;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long invCount = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        invCount += mergeSort(arr, temp, left, mid);
        invCount += mergeSort(arr, temp, mid + 1, right);

        invCount += merge(arr, temp, left, mid, right);
    }

    return invCount;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], temp[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", result);
    return 0;
}