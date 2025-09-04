#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

int kthSmallestUtil(struct Node* root, int* count, int k) {
    if (root == NULL) return -1;

    int left = kthSmallestUtil(root->left, count, k);
    if (left != -1) return left;

    (*count)++;
    if (*count == k) return root->data;

    return kthSmallestUtil(root->right, count, k);
}

int kthSmallest(struct Node* root, int k) {
    int count = 0;
    return kthSmallestUtil(root, &count, k);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 3);
    insert(root, 1);
    insert(root, 4);
    insert(root, 2);

    printf("1st Smallest: %d\n", kthSmallest(root, 1));

    struct Node* root2 = NULL;
    root2 = insert(root2, 5);
    insert(root2, 3);
    insert(root2, 6);
    insert(root2, 2);
    insert(root2, 4);
    insert(root2, 1);

    printf("3rd Smallest: %d\n", kthSmallest(root2, 3));

    return 0;
}
