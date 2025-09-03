#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

// LCA function
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (!root) return NULL;

    if (n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if (n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root; // This is the split point → LCA
}

// Example usage
int main() {
    struct Node* root = NULL;
    root = insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 0);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    int n1 = 2, n2 = 8;
    struct Node* lca = LCA(root, n1, n2);
    printf("LCA of %d and %d = %d\n", n1, n2, lca->data);

    n1 = 2; n2 = 4;
    lca = LCA(root, n1, n2);
    printf("LCA of %d and %d = %d\n", n1, n2, lca->data);

    return 0;
}

