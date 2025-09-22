#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxSum;

int findMaxPath(Node* root) {
    if (!root) return 0;
    int left = findMaxPath(root->left);
    int right = findMaxPath(root->right);

    int singlePath = max(root->val, root->val + max(left, right));
    int topPath = max(singlePath, root->val + left + right);

    if (topPath > maxSum) maxSum = topPath;

    return singlePath;
}

int main() {
    Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    maxSum = -1e9;
    findMaxPath(root);

    printf("Maximum Path Sum: %d\n", maxSum);
    return 0;
}
