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

int dfs(int node, int visited[], int recStack[], struct Node* adj[]) {
    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while(temp) {
        int v = temp->data;

        if(!visited[v]) {
            if(dfs(v, visited, recStack, adj))
                return 1;
        }
        else if(recStack[v]) {
            return 1;
        }

        temp = temp->next;
    }

    recStack[node] = 0;
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // directed graph (ONLY one direction)
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n], recStack[n];

    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i, visited, recStack, adj)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}