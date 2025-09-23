#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) { return a > b ? a : b; }

int dfs(TreeNode* root, int* maxSum) {
    if (!root) return 0;
    int left = max(dfs(root->left, maxSum), 0);
    int right = max(dfs(root->right, maxSum), 0);
    *maxSum = max(*maxSum, root->val + left + right);
    return root->val + max(left, right);
}

int maxPathSum(TreeNode* root) {
    int maxSum = -1000000000;
    dfs(root, &maxSum);
    return maxSum;
}

int main() {
    // Example 1
    TreeNode* root1 = newNode(10);
    root1->left = newNode(2);
    root1->right = newNode(10);
    root1->left->left = newNode(20);
    root1->left->right = newNode(1);
    root1->right->right = newNode(-25);
    root1->right->right->left = newNode(3);
    root1->right->right->right = newNode(4);

    printf("Max Path Sum = %d\n", maxPathSum(root1)); // Output: 42

    // Example 2
    TreeNode* root2 = newNode(-10);
    root2->left = newNode(9);
    root2->right = newNode(20);
    root2->right->left = newNode(15);
    root2->right->right = newNode(7);

    printf("Max Path Sum = %d\n", maxPathSum(root2)); // Output: 42

    return 0;
}
