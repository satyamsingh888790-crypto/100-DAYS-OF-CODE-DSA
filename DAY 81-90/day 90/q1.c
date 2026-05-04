#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int sum(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}

int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (time + arr[i] <= maxTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];

            if (painters > k)
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[100];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int low = 0;
    int high = sum(arr, n);
    int ans = high;

    for (int i = 0; i < n; i++) {
        low = max(low, arr[i]);
    }

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}