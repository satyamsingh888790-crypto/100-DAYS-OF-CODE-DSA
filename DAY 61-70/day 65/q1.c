#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

int dfs(int node, int parent, int visited[], struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while(temp) {
        int v = temp->data;

        if(!visited[v]) {
            if(dfs(v, node, visited, adj))
                return 1;
        }
        else if(v != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1, visited, adj)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}