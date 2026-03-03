#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check Identity Matrix condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            // Diagonal elements must be 1
            if(i == j && matrix[i][j] != 1) {
                printf("Not an Identity Matrix");
                return 0;
            }
            
            // Non-diagonal elements must be 0
            if(i != j && matrix[i][j] != 0) {
                printf("Not an Identity Matrix");
                return 0;
            }
        }
    }

    printf("Identity Matrix");
    return 0;
}