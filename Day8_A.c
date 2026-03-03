#include <stdio.h>

// Recursive function to calculate a^b
int power(int a, int b) {
    if(b == 0)
        return 1;          // Base case
    
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", power(a, b));

    return 0;
}
