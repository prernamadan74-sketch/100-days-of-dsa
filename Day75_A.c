#include <stdio.h>

#define MAX 1000

// Simple hash map using arrays (for demo purpose)
int hash[2001]; // to handle negative sums (shift by +1000)

int maxLenZeroSum(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // Initialize hash with -1
    for (int i = 0; i < 2001; i++)
        hash[i] = -2;

    hash[1000] = -1; // sum = 0 at index -1

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        int index = sum + 1000; // shift for negative

        if (hash[index] != -2) {
            int len = i - hash[index];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[index] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));

    return 0;
}