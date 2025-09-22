#include <stdio.h>
#include <stdlib.h>

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

int maxPathSumUtil(struct Node* root, int* res) {
    if(root == NULL) return 0;
    int l = maxPathSumUtil(root->left, res);
    int r = maxPathSumUtil(root->right, res);
    int max_single = max(max(l, r) + root->val, root->val);
    int max_top = max(max_single, l + r + root->val);
    if(*res < max_top) *res = max_top;
    return max_single;
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(20);
    root->left->right = newNode(1);
    root->right->right = newNode(-25);
    int res = -100000;
    maxPathSumUtil(root, &res);
    printf("%d\n", res);
    return 0;
}
