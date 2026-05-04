void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;

    while(curr) {
        if(curr->left) {
            // find rightmost node of left subtree
            struct TreeNode* prev = curr->left;
            while(prev->right)
                prev = prev->right;

            // attach right subtree
            prev->right = curr->right;

            // move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}