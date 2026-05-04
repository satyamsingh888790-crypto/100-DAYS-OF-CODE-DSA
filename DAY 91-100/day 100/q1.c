#include <stdio.h>

typedef struct {
    int val, idx;
} Node;

void merge(Node arr[], Node temp[], int left, int mid, int right, int count[]) {
    int i = left, j = mid, k = left;

    while (i <= mid - 1 && j <= right) {
        if (arr[i].val <= arr[j].val) {
            temp[k] = arr[i];
            count[arr[i].idx] += (j - mid);
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid - 1) {
        temp[k] = arr[i];
        count[arr[i].idx] += (j - mid);
        i++; k++;
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(Node arr[], Node temp[], int left, int right, int count[]) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid, count);
        mergeSort(arr, temp, mid + 1, right, count);

        merge(arr, temp, left, mid + 1, right, count);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node arr[100], temp[100];
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, temp, 0, n - 1, count);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    return 0;
}