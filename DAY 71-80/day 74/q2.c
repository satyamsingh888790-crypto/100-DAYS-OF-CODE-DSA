#include <stdlib.h>

void dfs(int** isConnected, int n, int* visited, int node) {
    visited[node] = 1;

    for(int j = 0; j < n; j++) {
        if(isConnected[node][j] == 1 && !visited[j]) {
            dfs(isConnected, n, visited, j);
        }
    }
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize) {

    int n = isConnectedSize;
    int* visited = (int*)calloc(n, sizeof(int));

    int provinces = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(isConnected, n, visited, i);
            provinces++;
        }
    }

    return provinces;
}