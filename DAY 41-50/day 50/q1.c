#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int key) {
    if(root == NULL) return newNode(key);

    if(key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

int search(Node* root, int key) {
    if(root == NULL) return 0;

    if(root->data == key) return 1;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    int n, key;
    scanf("%d", &n);

    Node* root = NULL;

    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);

    if(search(root, key))
        printf("Found");
    else
        printf("Not Found");

    return 0;
}