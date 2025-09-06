#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Lowest Common Ancestor (LCA)
TreeNode* lca(TreeNode* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data > n1 && root->data > n2) {
        return lca(root->left, n1, n2);
    }
    if (root->data < n1 && root->data < n2) {
        return lca(root->right, n1, n2);
    }
    return root;
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(6);
    root1->left = createNode(2);
    root1->right = createNode(8);
    root1->left->left = createNode(0);
    root1->left->right = createNode(4);
    root1->right->left = createNode(7);
    root1->right->right = createNode(9);
    printf("LCA of 2 and 8: %d\n", lca(root1, 2, 8)->data);

    // Example 2
    TreeNode* root2 = createNode(6);
    root2->left = createNode(2);
    root2->right = createNode(8);
    root2->left->left = createNode(0);
    root2->left->right = createNode(4);
    root2->right->left = createNode(7);
    root2->right->right = createNode(9);
    printf("LCA of 2 and 4: %d\n", lca(root2, 2, 4)->data);

    return 0;
}
