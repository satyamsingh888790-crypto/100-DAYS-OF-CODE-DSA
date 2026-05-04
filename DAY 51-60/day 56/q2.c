int isMirror(struct TreeNode* a, struct TreeNode* b) {
    if(a == NULL && b == NULL) return 1;
    if(a == NULL || b == NULL) return 0;

    return (a->val == b->val) &&
           isMirror(a->left, b->right) &&
           isMirror(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL) return true;
    return isMirror(root->left, root->right);
}