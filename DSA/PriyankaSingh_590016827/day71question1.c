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

// Inorder Traversal of Binary Tree
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(1);
    root1->right = createNode(3);
    root1->right->left = createNode(2);
    printf("Inorder Traversal: ");
    inorderTraversal(root1);
    printf("\n");

    // Example 2
    TreeNode* root2 = createNode(4);
    root2->left = createNode(2);
    root2->right = createNode(5);
    printf("Inorder Traversal: ");
    inorderTraversal(root2);
    printf("\n");

    return 0;
}
