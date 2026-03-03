#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int visited[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;   // Mark all as not visited
    }

    // Count frequency
    for(int i = 0; i < n; i++) {

        if(visited[i] == 1)
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;   // Mark duplicate as visited
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}