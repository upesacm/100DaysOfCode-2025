#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int val;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) { return a > b ? a : b; }

// Global variable to track max sum
int globalMax;

int maxPathDown(struct Node* root) {
    if (!root) return 0;

    int left = max(0, maxPathDown(root->left));
    int right = max(0, maxPathDown(root->right));

    // Update global maximum (node value + both sides)
    globalMax = max(globalMax, left + right + root->val);

    // Return best single path (node + one side)
    return root->val + max(left, right);
}

int maxPathSum(struct Node* root) {
    globalMax = INT_MIN;
    maxPathDown(root);
    return globalMax;
}

int main() {
    // Example 1
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    printf("Max Path Sum: %d\n", maxPathSum(root)); // Output: 42

    return 0;
}

