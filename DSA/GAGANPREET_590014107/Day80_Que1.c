#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct Node* buildBST(int n) {
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (x != -1) root = insert(root, x);
    }
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (n1 < root->data && n2 < root->data) return LCA(root->left, n1, n2);
    if (n1 > root->data && n2 > root->data) return LCA(root->right, n1, n2);
    return root;
}

int main() {
    int n; scanf("%d", &n);
    struct Node* root = buildBST(n);
    int a, b; scanf("%d %d", &a, &b);
    struct Node* ans = LCA(root, a, b);
    if (ans) printf("%d", ans->data);
    return 0;
}
