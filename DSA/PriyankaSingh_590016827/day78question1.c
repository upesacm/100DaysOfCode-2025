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

// Search in BST
int searchBST(TreeNode* root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    if (key < root->data) {
        return searchBST(root->left, key);
    }
    return searchBST(root->right, key);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(5);
    root1->left = createNode(3);
    root1->right = createNode(7);
    root1->left->left = createNode(2);
    root1->left->right = createNode(4);
    root1->right->left = createNode(6);
    root1->right->right = createNode(8);
    int key1 = 4;
    if (searchBST(root1, key1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 2
    TreeNode* root2 = createNode(5);
    root2->left = createNode(3);
    root2->right = createNode(7);
    int key2 = 10;
    if (searchBST(root2, key2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
