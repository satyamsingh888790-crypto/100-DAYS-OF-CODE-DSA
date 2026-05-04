int find(int parent[], int x) {
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

void unionSet(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);
    if(px != py)
        parent[px] = py;
}

int isCycle(int edges[][2], int E, int V) {
    int parent[V];

    for(int i = 0; i < V; i++)
        parent[i] = i;

    for(int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        if(pu == pv)
            return 1;

        unionSet(parent, pu, pv);
    }

    return 0;
}