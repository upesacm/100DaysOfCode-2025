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

// Print nodes in range [L, R]
void printRange(struct Node* root, int L, int R) {
    if (!root) return;

    if (root->data > L) // explore left
        printRange(root->left, L, R);

    if (root->data >= L && root->data <= R) // print if in range
        printf("%d ", root->data);

    if (root->data < R) // explore right
        printRange(root->right, L, R);
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
    printf("Nodes in Range [%d, %d]: ", L, R);
    printRange(root, L, R); // Expected: 7 10 15
    printf("\n");
    return 0;
}

