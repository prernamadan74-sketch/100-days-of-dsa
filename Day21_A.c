#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == 0)
            count++;

        int tempSum = 0;
        for(int j = 0; j < i; j++) {
            tempSum += arr[j];
            if(tempSum == prefixSum)
                count++;
        }
    }

    printf("%d", count);

    return 0;
}