#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

void printNodesInRange(TreeNode* root, int L, int R) {
    if (!root) return;
    if (root->val > L) printNodesInRange(root->left, L, R);
    if (root->val >= L && root->val <= R) printf("%d ", root->val);
    if (root->val < R) printNodesInRange(root->right, L, R);
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
    printNodesInRange(root1, 7, 15);
    printf("\n");

    TreeNode* root2 = newNode(6);
    root2->left = newNode(2);
    root2->right = newNode(8);
    root2->left->left = newNode(0);
    root2->left->right = newNode(4);
    root2->right->left = newNode(7);
    root2->right->right = newNode(9);
    printNodesInRange(root2, 2, 8);
    printf("\n");

    return 0;
}
