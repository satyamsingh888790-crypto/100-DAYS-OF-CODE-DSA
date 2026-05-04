#include <stdio.h>

#define MAX 10000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0;
    int maxLen = 0;

    int hash[2*MAX];
    for(int i = 0; i < 2*MAX; i++)
        hash[i] = -2;   // -2 means not seen

    // handle prefix sum = 0 case
    hash[MAX] = -1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        int idx = prefix + MAX;

        if(hash[idx] != -2) {
            int len = i - hash[idx];
            if(len > maxLen)
                maxLen = len;
        } else {
            hash[idx] = i;
        }
    }

    printf("%d", maxLen);

    return 0;
}