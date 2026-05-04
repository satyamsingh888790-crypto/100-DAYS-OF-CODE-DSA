#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int v, w;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->v = v;
    n->w = w;
    n->next = NULL;
    return n;
}

// Min Heap
struct HeapNode {
    int v, dist;
};

struct Heap {
    int size;
    struct HeapNode arr[10000];
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(struct Heap* h, int i) {
    while(i && h->arr[i].dist < h->arr[(i-1)/2].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(struct Heap* h, int i) {
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;

    if(l < h->size && h->arr[l].dist < h->arr[smallest].dist)
        smallest = l;
    if(r < h->size && h->arr[r].dist < h->arr[smallest].dist)
        smallest = r;

    if(smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(struct Heap* h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

struct HeapNode pop(struct Heap* h) {
    struct HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        struct Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;

        // undirected (optional)
        newNode = createNode(u, w);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int src;
    scanf("%d", &src);

    int dist[n];
    for(int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    struct Heap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while(h.size) {
        struct HeapNode cur = pop(&h);
        int u = cur.v;

        struct Node* temp = adj[u];

        while(temp) {
            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}