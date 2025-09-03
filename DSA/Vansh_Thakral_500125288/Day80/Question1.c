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

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

struct Node* LCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (p < root->val && q < root->val)
        return LCA(root->left, p, q);
    else if (p > root->val && q > root->val)
        return LCA(root->right, p, q);
    return root;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    int p = 2, q = 8;
    struct Node* lca = LCA(root, p, q);
    if (lca) printf("LCA of %d and %d = %d\n", p, q, lca->val);

    return 0;
}
