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

void kthSmallest(struct Node* root, int k, int* count, int* result) {
    if (!root || *result != -1) return;
    kthSmallest(root->left, k, count, result);
    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }
    kthSmallest(root->right, k, count, result);
}

int main() {
    int n, val, k;
    scanf("%d", &n);
    struct Node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    scanf("%d", &k);
    int count = 0, result = -1;
    kthSmallest(root, k, &count, &result);
    if (result != -1) printf("%d\n", result);
    return 0;
}
