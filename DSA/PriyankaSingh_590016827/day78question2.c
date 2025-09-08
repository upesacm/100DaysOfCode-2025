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

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }
    return root;
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
    root1->left = createNode(3);
    root1->right = createNode(7);
    root1 = insertBST(root1, 4);
    printf("Output Tree (inorder): ");
    inorderTraversal(root1);
    printf("\n");

    // Example 2
    TreeNode* root2 = createNode(10);
    root2 = insertBST(root2, 20);
    printf("Output Tree (inorder): ");
    inorderTraversal(root2);
    printf("\n");

    return 0;
}
