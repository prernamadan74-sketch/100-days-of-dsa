#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    if(n < 2) {
        return 0;  // At least two elements required
    }

    int arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;

    int minSum = arr[left] + arr[right];
    int minLeft = left;
    int minRight = right;

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = left;
            minRight = right;
        }

        // Move pointers
        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d", arr[minLeft], arr[minRight]);

    return 0;
}