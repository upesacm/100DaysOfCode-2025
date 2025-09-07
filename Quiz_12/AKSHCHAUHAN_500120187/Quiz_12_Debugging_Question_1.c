#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int isValidBSTHelper(struct TreeNode* root, long minVal, long maxVal) {
    if (root == NULL) 
        return 1;

    if (root->val <= minVal || root->val >= maxVal) 
        return 0;

    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

int isValidBST(struct TreeNode* root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
}

int main() {
    struct TreeNode* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(15);
    root1->right->left = newNode(6);
    root1->right->right = newNode(20);
    printf("Is valid BST (Tree 1): %s\n", isValidBST(root1) ? "True" : "False");
    return 0;
}
