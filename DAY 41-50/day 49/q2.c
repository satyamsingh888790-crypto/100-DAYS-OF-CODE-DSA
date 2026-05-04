struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;

    if(root == NULL) return node;

    struct TreeNode* curr = root;

    while(1) {
        if(val < curr->val) {
            if(curr->left == NULL) {
                curr->left = node;
                break;
            }
            curr = curr->left;
        } else {
            if(curr->right == NULL) {
                curr->right = node;
                break;
            }
            curr = curr->right;
        }
    }

    return root;
}