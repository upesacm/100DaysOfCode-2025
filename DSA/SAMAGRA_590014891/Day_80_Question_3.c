#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (!root) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int kthSmallestUtil(struct Node* root, int* k) {
    if (!root) return -1;
    int left = kthSmallestUtil(root->left, k);
    if (left != -1) return left;
    (*k)--;
    if (*k == 0) return root->data;
    return kthSmallestUtil(root->right, k);
}

int kthSmallest(struct Node* root, int k) {
    return kthSmallestUtil(root, &k);
}

int main() {
    struct Node* root = NULL;
    int nodes[] = {5, 3, 6, 2, 4, 1};
    for (int i = 0; i < 6; i++) root = insert(root, nodes[i]);

    int k = 3;
    printf("%d\n", kthSmallest(root, k));
    return 0;
}
