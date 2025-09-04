#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void printNodesInRange(struct TreeNode* root, int L, int R) {
    if (!root) return;
    if (root->val > L) printNodesInRange(root->left, L, R);
    if (root->val >= L && root->val <= R) printf("%d ", root->val);
    if (root->val < R) printNodesInRange(root->right, L, R);
}

int main() {
    struct TreeNode* root = NULL;
    int values[] = {10,5,15,3,7,18};
    for (int i = 0; i < 6; i++) root = insert(root, values[i]);

    int L = 7, R = 15;
    printf("Nodes in Range (%d,%d): ", L, R);
    printNodesInRange(root, L, R);
    printf("\n");
    return 0;
}
