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

// Find Max in Binary Tree
int findMax(TreeNode* root) {
    if (root == NULL) {
        return -1; // Assuming node values are non-negative
    }
    int max_val = root->data;
    int left_max = findMax(root->left);
    int right_max = findMax(root->right);

    if (left_max > max_val) {
        max_val = left_max;
    }
    if (right_max > max_val) {
        max_val = right_max;
    }
    return max_val;
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(5);
    printf("Maximum value in the tree: %d\n", findMax(root1));

    // Example 2
    TreeNode* root2 = createNode(1);
    root2->right = createNode(9);
    printf("Maximum value in the tree: %d\n", findMax(root2));

    return 0;
}
