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

void inorderK(struct Node* root, int k, int* count, int* result) {
    if (root == NULL || *count >= k) return;
    inorderK(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->data;
        return;
    }
    inorderK(root->right, k, count, result);
}

int main() {
    int n; scanf("%d", &n);
    struct Node* root = buildBST(n);
    int k; scanf("%d", &k);
    int count = 0, result = -1;
    inorderK(root, k, &count, &result);
    if (result != -1) printf("%d", result);
    return 0;
}
