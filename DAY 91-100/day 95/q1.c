#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float arr[100];

    for (int i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    float bucket[100][100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        bucket[bi][count[bi]++] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < count[i]; j++) {
            float key = bucket[i][j];
            int k = j - 1;

            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%.2f ", bucket[i][j]);
        }
    }

    return 0;
}