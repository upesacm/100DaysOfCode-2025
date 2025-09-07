#include <stdio.h>
#include <stdlib.h>

// Define a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Count total nodes recursively
int countTotalNodes(struct Node* root) {
    if (root == NULL) return 0;

    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int main() {
    // Example Tree:
    //       8
    //      / \
    //     6  10
    //    /
    //   4
    struct Node* root = createNode(8);
    root->left = createNode(6);
    root->right = createNode(10);
    root->left->left = createNode(4);

    int total = countTotalNodes(root);  // Output: 4
    printf("Total number of nodes: %d\n", total);

    return 0;
}
