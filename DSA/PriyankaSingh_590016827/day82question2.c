#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Check if BST is Balanced
int isBalancedUtil(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = isBalancedUtil(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    int rightHeight = isBalancedUtil(root->right);
    if (rightHeight == -1) {
        return -1;
    }
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int isBalanced(TreeNode* root) {
    if (isBalancedUtil(root) == -1) {
        return 0;
    }
    return 1;
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(4);
    root1->left = createNode(2);
    root1->right = createNode(6);
    root1->left->left = createNode(1);
    root1->left->right = createNode(3);
    root1->right->left = createNode(5);
    root1->right->right = createNode(7);
    if (isBalanced(root1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 2
    TreeNode* root2 = createNode(1);
    root2->right = createNode(2);
    root2->right->right = createNode(3);
    if (isBalanced(root2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
