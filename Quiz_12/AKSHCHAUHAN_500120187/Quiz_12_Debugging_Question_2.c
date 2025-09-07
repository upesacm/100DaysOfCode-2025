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
    node->left = node->right = NULL;
    return node;
}

int rangeSumBST(struct TreeNode* root, int L, int R) {
    if (root == NULL) 
        return 0;
    if (root->val < L) 
        return rangeSumBST(root->right, L, R);
    if (root->val > R) 
        return rangeSumBST(root->left, L, R);
    return root->val 
         + rangeSumBST(root->left, L, R) 
         + rangeSumBST(root->right, L, R);
}

int main() {
    struct TreeNode* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(13);
    root->right->right = newNode(18);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(6);
    root->right->right->right = newNode(20);

    int L = 7, R = 15;
    int result = rangeSumBST(root, L, R);

    printf("Range sum [%d, %d]: %d\n", L, R, result);

    return 0;
}