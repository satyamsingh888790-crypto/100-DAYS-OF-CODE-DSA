#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

typedef struct QNode {
    Node* node;
    int hd;
} QNode;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order (-1 = NULL)
Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1) return NULL;

    Node* root = newNode(arr[0]);
    Node* queue[n];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;
    while(i < n) {
        Node* curr = queue[front++];

        if(arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if(i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(Node* root, int n) {
    if(root == NULL) return;

    QNode queue[10000];
    int front = 0, rear = 0;

    int hdArr[10000], valArr[10000];
    int idx = 0;

    int minHD = 0, maxHD = 0;

    queue[rear++] = (QNode){root, 0};

    while(front < rear) {
        QNode temp = queue[front++];
        Node* curr = temp.node;
        int hd = temp.hd;

        hdArr[idx] = hd;
        valArr[idx] = curr->data;
        idx++;

        if(hd < minHD) minHD = hd;
        if(hd > maxHD) maxHD = hd;

        if(curr->left)
            queue[rear++] = (QNode){curr->left, hd - 1};

        if(curr->right)
            queue[rear++] = (QNode){curr->right, hd + 1};
    }

    for(int h = minHD; h <= maxHD; h++) {
        for(int i = 0; i < idx; i++) {
            if(hdArr[i] == h)
                printf("%d ", valArr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node* root = buildTree(arr, n);

    verticalOrder(root, n);

    return 0;
}