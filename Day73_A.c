#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    int visited[26] = {0}; // for 'a' to 'z'

    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        int index = s[i] - 'a';

        if (visited[index] == 1) {
            printf("%c", s[i]);
            return 0;
        }

        visited[index] = 1;
    }

    printf("-1");
    return 0;
}