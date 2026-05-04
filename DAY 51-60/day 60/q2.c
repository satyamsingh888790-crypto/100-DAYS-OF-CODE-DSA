int dfs(struct TreeNode* root, int* cameras) {
    if(root == NULL)
        return 2;

    int left = dfs(root->left, cameras);
    int right = dfs(root->right, cameras);

    if(left == 0 || right == 0) {
        (*cameras)++;
        return 1;
    }

    if(left == 1 || right == 1)
        return 2;

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    int cameras = 0; // reset for each test case

    if(dfs(root, &cameras) == 0)
        cameras++;

    return cameras;
}