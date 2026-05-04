#include <stdlib.h>
#include <limits.h>

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {

    int** adj = (int**)malloc(sizeof(int*) * (n + 1));
    int* adjSize = (int*)calloc(n + 1, sizeof(int));

    for(int i = 1; i <= n; i++)
        adj[i] = (int*)malloc(sizeof(int) * timesSize * 2);

    // build graph
    for(int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];

        adj[u][adjSize[u]++] = v;
        adj[u][adjSize[u]++] = w;
    }

    int dist[n + 1];
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    int visited[n + 1];
    for(int i = 1; i <= n; i++)
        visited[i] = 0;

    dist[k] = 0;

    for(int i = 1; i <= n; i++) {
        int u = -1;

        // find min distance node
        for(int j = 1; j <= n; j++) {
            if(!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if(dist[u] == INT_MAX)
            break;

        visited[u] = 1;

        for(int j = 0; j < adjSize[u]; j += 2) {
            int v = adj[u][j];
            int w = adj[u][j + 1];

            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    int max = 0;

    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX)
            return -1;
        if(dist[i] > max)
            max = dist[i];
    }

    return max;
}