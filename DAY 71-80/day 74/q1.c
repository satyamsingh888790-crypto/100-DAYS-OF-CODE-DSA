#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    char names[MAX][50];
    int count[MAX] = {0};
    int size = 0;

    for(int i = 0; i < n; i++) {
        char temp[50];
        scanf("%s", temp);

        int found = -1;

        // check if already exists
        for(int j = 0; j < size; j++) {
            if(strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if(found != -1) {
            count[found]++;
        } else {
            strcpy(names[size], temp);
            count[size] = 1;
            size++;
        }
    }

    int maxVotes = 0;
    char result[50];

    for(int i = 0; i < size; i++) {
        if(count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(result, names[i]);
        }
        else if(count[i] == maxVotes) {
            if(strcmp(names[i], result) < 0) {
                strcpy(result, names[i]);
            }
        }
    }

    printf("%s %d", result, maxVotes);

    return 0;
}