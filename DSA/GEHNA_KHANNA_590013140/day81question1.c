#include <stdio.h>
#include <stdlib.h>

// Definition of a BST Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Utility function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Function to compute range sum using pruned traversal
int rangeSumBST(struct TreeNode* root, int L, int R) {
    if (root == NULL) return 0;

    if (root->val < L) 
        return rangeSumBST(root->right, L, R);
    else if (root->val > R) 
        return rangeSumBST(root->left, L, R);
    else 
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

int main() {
    struct TreeNode* root = NULL;
    int n, val, L, R;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter range L and R: ");
    scanf("%d %d", &L, &R);

    int sum = rangeSumBST(root, L, R);
    printf("Range Sum [%d, %d] = %d\n", L, R, sum);

    return 0;
}
