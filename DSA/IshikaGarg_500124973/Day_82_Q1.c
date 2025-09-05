#include <stdio.h>
#include <stdlib.h>

// ---------- Tree Node Definition ----------
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ---------- Create a New Node ----------
TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// ---------- Convert Sorted Array to Balanced BST ----------
TreeNode* sortedArrayToBST(int* arr, int start, int end) {
    if (start > end) return NULL;

    int mid = (start + end) / 2;
    TreeNode* root = newNode(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// ---------- Preorder Traversal (for Output) ----------
void preorder(TreeNode* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// ---------- Free Memory ----------
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// ---------- Main Function ----------
int main() {
    // ----------- Test Case 1 -----------
    int arr1[] = {1, 2, 3, 4, 5, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    TreeNode* root1 = sortedArrayToBST(arr1, 0, n1 - 1);
    printf("Preorder of Balanced BST (Test 1):\n");
    preorder(root1);
    printf("\n\n");

    freeTree(root1);

    // ----------- Test Case 2 -----------
    int arr2[] = {10, 20, 30, 40};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    TreeNode* root2 = sortedArrayToBST(arr2, 0, n2 - 1);
    printf("Preorder of Balanced BST (Test 2):\n");
    preorder(root2);
    printf("\n");

    freeTree(root2);

    return 0;
}
