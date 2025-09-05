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

// Global variable to store the sum
int sum = 0;

// Convert BST to Greater Tree
void convertToGreaterTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    convertToGreaterTree(root->right);
    sum += root->data;
    root->data = sum;
    convertToGreaterTree(root->left);
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
    TreeNode* root1 = createNode(5);
    root1->left = createNode(2);
    root1->right = createNode(13);
    sum = 0;
    convertToGreaterTree(root1);
    printf("Inorder Traversal: ");
    inorderTraversal(root1);
    printf("\n");

    // Example 2
    TreeNode* root2 = createNode(2);
    root2->left = createNode(0);
    root2->right = createNode(3);
    root2->left->left = createNode(-4);
    root2->left->right = createNode(1);
    sum = 0;
    convertToGreaterTree(root2);
    printf("Inorder Traversal: ");
    inorderTraversal(root2);
    printf("\n");

    return 0;
}
