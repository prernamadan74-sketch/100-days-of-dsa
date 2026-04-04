#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if (arr[i] > maxPages)
            return 0;

        if (sum + arr[i] > maxPages) {
            students++;
            sum = arr[i];

            if (students > m)
                return 0;
        } else {
            sum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller maximum
        } else {
            low = mid + 1;   // increase limit
        }
    }

    printf("%d\n", ans);
    return 0;
}