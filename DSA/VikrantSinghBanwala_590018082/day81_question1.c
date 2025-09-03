#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root) return 0;
    if (root->val < L) return rangeSumBST(root->right, L, R);
    if (root->val > R) return rangeSumBST(root->left, L, R);
    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    TreeNode* root1 = newNode(10);
    root1->left = newNode(5);
    root1->right = newNode(15);
    root1->left->left = newNode(3);
    root1->left->right = newNode(7);
    root1->right->right = newNode(18);
    printf("%d\n", rangeSumBST(root1, 7, 15));

    TreeNode* root2 = newNode(10);
    root2->left = newNode(5);
    root2->right = newNode(15);
    root2->left->left = newNode(3);
    root2->left->right = newNode(7);
    root2->right->left = newNode(13);
    root2->right->right = newNode(18);
    printf("%d\n", rangeSumBST(root2, 6, 10));

    return 0;
}