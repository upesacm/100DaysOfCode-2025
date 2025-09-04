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
    if (!root) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Range sum function with pruning
int rangeSumBST(struct Node* root, int L, int R) {
    if (!root) return 0;

    if (root->data < L) // Skip left subtree
        return rangeSumBST(root->right, L, R);
    if (root->data > R) // Skip right subtree
        return rangeSumBST(root->left, L, R);

    // Node in range → include + explore both sides
    return root->data + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 18);

    int L = 7, R = 15;
    printf("Range Sum = %d\n", rangeSumBST(root, L, R)); // Expected: 32
    return 0;
}

