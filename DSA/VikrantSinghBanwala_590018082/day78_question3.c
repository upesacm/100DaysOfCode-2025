#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}

int findMin(Node* root) {
    if (root == NULL) return -1; // or some error value
    while (root->left != NULL) root = root->left;
    return root->data;
}

int findMax(Node* root) {
    if (root == NULL) return -1; // or some error value
    while (root->right != NULL) root = root->right;
    return root->data;
}

int main() {
    Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    printf("Min = %d, Max = %d\n", findMin(root), findMax(root));

    Node* root2 = NULL;
    root2 = insert(root2, 5);

    printf("Min = %d, Max = %d\n", findMin(root2), findMax(root2));

    return 0;
}