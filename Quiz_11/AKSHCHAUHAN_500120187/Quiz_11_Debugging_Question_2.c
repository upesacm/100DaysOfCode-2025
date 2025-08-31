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
int convert_to_sum_tree(struct TreeNode* root) {
    if (root == NULL) return 0;
    int old_val = root->val;
    int left_sum = convert_to_sum_tree(root->left);
    int right_sum = convert_to_sum_tree(root->right);
    root->val = left_sum + right_sum;
    return root->val + old_val;
}

void print_inorder(struct TreeNode* root) {
    if (root == NULL) return;
    print_inorder(root->left);
    printf("%d ", root->val);
    print_inorder(root->right);
}

int main() {
    struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    printf("Original tree (inorder): ");
    print_inorder(root);
    printf("\n");
    convert_to_sum_tree(root);
    printf("After conversion (inorder): ");
    print_inorder(root);
    printf("\n");
    return 0;
}