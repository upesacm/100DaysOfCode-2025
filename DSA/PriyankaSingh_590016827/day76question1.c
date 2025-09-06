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

// Convert to Sum Tree
int convertToSumTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftSum = convertToSumTree(root->left);
    int rightSum = convertToSumTree(root->right);
    int originalData = root->data;
    root->data = leftSum + rightSum;
    return originalData + root->data;
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
    TreeNode* root1 = createNode(10);
    root1->left = createNode(-2);
    root1->right = createNode(6);
    root1->left->left = createNode(8);
    root1->left->right = createNode(-4);
    root1->right->left = createNode(7);
    root1->right->right = createNode(5);
    convertToSumTree(root1);
    printf("Sum Tree Inorder: ");
    inorderTraversal(root1);
    printf("\n");

    return 0;
}
