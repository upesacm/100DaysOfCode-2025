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

// Sum of All Nodes
int sumNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    printf("Sum of all nodes: %d\n", sumNodes(root1));

    // Example 2
    TreeNode* root2 = createNode(10);
    root2->left = createNode(5);
    printf("Sum of all nodes: %d\n", sumNodes(root2));

    return 0;
}
