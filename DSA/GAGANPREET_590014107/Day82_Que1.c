#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct TreeNode* sortedArrayToBST(int arr[], int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct TreeNode* root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}


void preorder(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}


int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    struct TreeNode* bst1 = sortedArrayToBST(arr1, 0, n1 - 1);
    printf("Preorder Output for arr1: ");
    preorder(bst1);
    printf("\n");

    int arr2[] = {10, 20, 30, 40};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    struct TreeNode* bst2 = sortedArrayToBST(arr2, 0, n2 - 1);
    printf("Preorder Output for arr2: ");
    preorder(bst2);
    printf("\n");

    return 0;
}
