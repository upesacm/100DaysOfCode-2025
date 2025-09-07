#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Check if Valid BST
int isValidBSTUtil(TreeNode* root, long min, long max) {
    if (root == NULL) {
        return 1;
    }
    if (root->data <= min || root->data >= max) {
        return 0;
    }
    return isValidBSTUtil(root->left, min, root->data) &&
           isValidBSTUtil(root->right, root->data, max);
}

int isValidBST(TreeNode* root) {
    return isValidBSTUtil(root, LONG_MIN, LONG_MAX);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(3);
    if (isValidBST(root1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 2
    TreeNode* root2 = createNode(5);
    root2->left = createNode(1);
    root2->right = createNode(4);
    root2->right->left = createNode(3);
    root2->right->right = createNode(6);
    if (isValidBST(root2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
