#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmpStart(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    Interval arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(Interval), cmpStart);

    int heap[100], size = 0;

    heap[size++] = arr[0].end;

    for (int i = 1; i < n; i++) {
        int earliest = heap[0];

        if (arr[i].start >= earliest) {
            heap[0] = arr[i].end;
        } else {
            heap[size++] = arr[i].end;
        }

        for (int j = size / 2 - 1; j >= 0; j--) {
            int parent = j;
            while (1) {
                int left = 2 * parent + 1;
                int right = 2 * parent + 2;
                int smallest = parent;

                if (left < size && heap[left] < heap[smallest])
                    smallest = left;
                if (right < size && heap[right] < heap[smallest])
                    smallest = right;

                if (smallest == parent)
                    break;

                int temp = heap[parent];
                heap[parent] = heap[smallest];
                heap[smallest] = temp;

                parent = smallest;
            }
        }
    }

    printf("%d\n", size);

    return 0;
}