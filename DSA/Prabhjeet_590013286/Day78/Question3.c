#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int findMin(Node* root) {
    Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current->key;
}

int findMax(Node* root) {
    Node* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current->key;
}

int main() {
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    printf("Minimum value: %d\n", findMin(root)); // Output: 1
    printf("Maximum value: %d\n", findMax(root)); // Output: 14

    return 0;
}
