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

// Global counter for Kth smallest
int count = 0;

// Kth Smallest in BST
int kthSmallest(TreeNode* root, int k) {
    if (root == NULL) {
        return -1;
    }
    int leftResult = kthSmallest(root->left, k);
    if (leftResult != -1) {
        return leftResult;
    }
    count++;
    if (count == k) {
        return root->data;
    }
    return kthSmallest(root->right, k);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(3);
    root1->left = createNode(1);
    root1->right = createNode(4);
    root1->left->right = createNode(2);
    int k1 = 1;
    count = 0;
    printf("Kth smallest element: %d\n", kthSmallest(root1, k1));

    // Example 2
    TreeNode* root2 = createNode(5);
    root2->left = createNode(3);
    root2->right = createNode(6);
    root2->left->left = createNode(2);
    root2->left->right = createNode(4);
    root2->left->left->left = createNode(1);
    int k2 = 3;
    count = 0;
    printf("Kth smallest element: %d\n", kthSmallest(root2, k2));

    return 0;
}
