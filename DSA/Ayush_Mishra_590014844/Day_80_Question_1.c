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
    if (!root) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root) {
        if (n1 < root->val && n2 < root->val) root = root->left;
        else if (n1 > root->val && n2 > root->val) root = root->right;
        else return root;
    }
    return NULL;
}

int main() {
    int n, val, n1, n2;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d %d", &n1, &n2);
    struct Node* lca = findLCA(root, n1, n2);
    if (lca) printf("%d\n", lca->val);
    return 0;
}
