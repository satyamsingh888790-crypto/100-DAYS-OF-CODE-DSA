int* rightSideView(struct TreeNode* root, int* returnSize) {
    if(root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*)malloc(100 * sizeof(int));
    struct TreeNode* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int idx = 0;

    while(front < rear) {
        int size = rear - front;

        for(int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            // last node of level = right view
            if(i == size - 1)
                result[idx++] = node->val;

            if(node->left)
                queue[rear++] = node->left;

            if(node->right)
                queue[rear++] = node->right;
        }
    }

    *returnSize = idx;
    return result;
}