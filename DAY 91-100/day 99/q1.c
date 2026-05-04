#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    float time;
} Car;

int cmp(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int position[100], speed[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &position[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &speed[i]);

    Car cars[100];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (float)(target - position[i]) / speed[i];
    }

    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}