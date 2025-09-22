#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxPathUtil(struct Node* root, int* res) {
    if (root == NULL) return 0;

    int left = max(0, maxPathUtil(root->left, res));
    int right = max(0, maxPathUtil(root->right, res));

    *res = max(*res, root->data + left + right);

    return root->data + max(left, right);
}

int maxPathSum(struct Node* root) {
    int res = INT_MIN;
    maxPathUtil(root, &res);
    return res;
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);

    printf("%d\n", maxPathSum(root));
    return 0;
}
