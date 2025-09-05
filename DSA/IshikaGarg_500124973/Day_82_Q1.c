#include <stdio.h>
#include <stdlib.h>

// Tree node structure
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Create a new node
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Recursive divide-and-conquer function
TreeNode* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Preorder traversal (to verify tree structure)
void preorder(TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

