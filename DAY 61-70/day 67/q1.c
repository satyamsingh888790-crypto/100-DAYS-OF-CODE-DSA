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

void dfs(int node, int visited[], int stack[], int *top, struct Node* adj[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while(temp) {
        int v = temp->data;
        if(!visited[v]) {
            dfs(v, visited, stack, top, adj);
        }
        temp = temp->next;
    }

    stack[(*top)++] = node;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    // directed graph
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int stack[n];
    int top = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, visited, stack, &top, adj);
        }
    }

    // print reverse stack
    for(int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}