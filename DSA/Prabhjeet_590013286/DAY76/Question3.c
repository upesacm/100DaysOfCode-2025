int countNodesAtLevel(struct Node* root, int level) {
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;

    return countNodesAtLevel(root->left, level - 1) +
           countNodesAtLevel(root->right, level - 1);
}
