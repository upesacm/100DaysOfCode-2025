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
int tree_height(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left_height = tree_height(root->left);
    int right_height = tree_height(root->right);

    return 1 + (left_height > right_height ? left_height : right_height);
}
int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    printf("Height of tree: %d\n", tree_height(root));
    struct TreeNode* single = newNode(1);
    printf("Height of single node: %d\n", tree_height(single));
    return 0;
}