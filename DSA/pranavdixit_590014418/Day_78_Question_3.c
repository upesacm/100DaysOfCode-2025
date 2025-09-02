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

int findMin(struct Node* root) {
    if (root == NULL) return -1;
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    if (root == NULL) return -1;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);

    printf("Min = %d, Max = %d\n", findMin(root), findMax(root));

    struct Node* single = newNode(5);
    printf("Min = %d, Max = %d\n", findMin(single), findMax(single));

    return 0;
}
