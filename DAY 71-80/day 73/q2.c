#include <stdlib.h>

int parent[1001];

int find(int x) {
    if(parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int a, int b) {
    int pa = find(a);
    int pb = find(b);
    parent[pa] = pb;
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {

    for(int i = 1; i <= edgesSize; i++)
        parent[i] = i;

    for(int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if(find(u) == find(v)) {
            int* res = (int*)malloc(sizeof(int) * 2);
            res[0] = u;
            res[1] = v;
            *returnSize = 2;
            return res;
        }

        unionSet(u, v);
    }

    *returnSize = 0;
    return NULL;
}