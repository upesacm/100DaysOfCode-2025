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

// Find the minimum value node in a BST
TreeNode* findMinNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Delete Node in BST
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        TreeNode* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
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
    root1->right = createNode(6);
    root1->left->left = createNode(2);
    root1->left->right = createNode(4);
    root1 = deleteNode(root1, 3);
    printf("Inorder after deleting 3: ");
    inorderTraversal(root1);
    printf("\n");

    // Example 2
    TreeNode* root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(15);
    root2 = deleteNode(root2, 10);
    printf("Inorder after deleting 10: ");
    inorderTraversal(root2);
    printf("\n");

    return 0;
}
