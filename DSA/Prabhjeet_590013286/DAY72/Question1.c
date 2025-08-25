#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL) return NULL;

    // Swap left and right
    TreeNode* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);

    return root;
}
