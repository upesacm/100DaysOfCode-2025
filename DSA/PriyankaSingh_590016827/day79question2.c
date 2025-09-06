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

// Count Nodes in BST
int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(5);
    root1->left = createNode(3);
    root1->right = createNode(7);
    printf("Number of nodes: %d\n", countNodes(root1));

    // Example 2
    TreeNode* root2 = createNode(8);
    root2->left = createNode(6);
    root2->right = createNode(10);
    root2->left->left = createNode(4);
    printf("Number of nodes: %d\n", countNodes(root2));

    return 0;
}
