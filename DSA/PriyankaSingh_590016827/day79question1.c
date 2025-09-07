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

// Minimum in BST
int findMin(TreeNode* root) {
    if (root == NULL) {
        return -1; // Or some other indicator for an empty tree
    }
    TreeNode* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Maximum in BST
int findMax(TreeNode* root) {
    if (root == NULL) {
        return -1; // Or some other indicator for an empty tree
    }
    TreeNode* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(8);
    root1->left = createNode(3);
    root1->right = createNode(10);
    root1->left->left = createNode(1);
    root1->left->right = createNode(6);
    root1->right->right = createNode(14);
    printf("Min = %d, Max = %d\n", findMin(root1), findMax(root1));

    // Example 2
    TreeNode* root2 = createNode(5);
    printf("Min = %d, Max = %d\n", findMin(root2), findMax(root2));

    return 0;
}
