#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    // Read string
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;

    // Reverse using two pointers
    while(left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    // Print reversed string
    printf("%s", str);

    return 0;
}
