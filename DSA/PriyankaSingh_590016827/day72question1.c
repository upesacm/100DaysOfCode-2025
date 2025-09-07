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

// Mirror of Binary Tree
void mirror(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

// Helper function to print tree inorder for verification
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
    root1->left = createNode(2);
    root1->right = createNode(3);
    printf("Original Tree Inorder: ");
    inorderTraversal(root1);
    printf("\n");
    mirror(root1);
    printf("Mirrored Tree Inorder: ");
    inorderTraversal(root1);
    printf("\n");

    return 0;
}
