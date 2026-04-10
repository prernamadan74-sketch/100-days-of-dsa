#include <stdio.h>
#include <stdlib.h>

// Structure for car
struct Car {
    int position;
    int speed;
};

// Sort by position descending
int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    return c2->position - c1->position;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    struct Car cars[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // Sort cars by position (descending)
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }

    printf("%d\n", fleets);
    return 0;
}