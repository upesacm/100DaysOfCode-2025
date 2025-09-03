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

void kthSmallestUtil(struct Node* root, int k, int* count, int* result) {
    if (root == NULL) return;

    kthSmallestUtil(root->left, k, count, result);

    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }

    kthSmallestUtil(root->right, k, count, result);
}

int kthSmallest(struct Node* root, int k) {
    int count = 0, result = -1;
    kthSmallestUtil(root, k, &count, &result);
    return result;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);

    int k = 3;
    printf("%d-th smallest element = %d\n", k, kthSmallest(root, k));

    return 0;
}
