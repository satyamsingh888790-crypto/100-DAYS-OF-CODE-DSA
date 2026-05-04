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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int indegree[n];
    for(int i = 0; i < n; i++)
        indegree[i] = 0;

    // directed graph
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        indegree[v]++;
    }

    int queue[n];
    int front = 0, rear = 0;

    // push nodes with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int topo[n];
    int count = 0;

    while(front < rear) {
        int node = queue[front++];
        topo[count++] = node;

        struct Node* temp = adj[node];
        while(temp) {
            int v = temp->data;
            indegree[v]--;

            if(indegree[v] == 0)
                queue[rear++] = v;

            temp = temp->next;
        }
    }

    // check cycle
    if(count != n) {
        printf("Cycle detected\n");
    } else {
        for(int i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}