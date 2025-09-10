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

struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void printRange(struct TreeNode* root, int L, int R) {
    if (root == NULL) return;
    if (root->val > L) printRange(root->left, L, R);
    if (root->val >= L && root->val <= R) printf("%d ", root->val);
    if (root->val < R) printRange(root->right, L, R);
}

int main() {
    struct TreeNode* root = NULL;
    int n, val, L, R;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &L, &R);
    printRange(root, L, R);
    return 0;
}
