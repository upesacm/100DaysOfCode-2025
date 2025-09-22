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

int max(int a, int b) {
    return a > b ? a : b;
}

int maxPathUtil(struct Node* root, int *res) {
    if (!root) return 0;

    int left = maxPathUtil(root->left, res);
    int right = maxPathUtil(root->right, res);

    int single = max(root->val, root->val + max(left, right));
    int top = max(single, root->val + left + right);

    if (top > *res) *res = top;

    return single;
}

int maxPathSum(struct Node* root) {
    int res = INT_MIN;
    maxPathUtil(root, &res);
    return res;
}

int main() {
    // Example 1
    struct Node* root1 = newNode(10);
    root1->left = newNode(2);
    root1->right = newNode(10);
    root1->left->left = newNode(20);
    root1->left->right = newNode(1);
    root1->right->right = newNode(-25);
    root1->right->right->left = newNode(3);
    root1->right->right->right = newNode(4);

    printf("%d\n", maxPathSum(root1)); // Output: 42

    // Example 2
    struct Node* root2 = newNode(-10);
    root2->left = newNode(9);
    root2->right = newNode(20);
    root2->right->left = newNode(15);
    root2->right->right = newNode(7);

    printf("%d\n", maxPathSum(root2)); // Output: 42

    return 0;
}
