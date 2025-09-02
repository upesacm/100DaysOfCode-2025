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

// Inorder traversal: left → root → right
void printInorderSorted(struct Node* root) {
    if (root == NULL) return;

    printInorderSorted(root->left);
    printf("%d ", root->data);
    printInorderSorted(root->right);
}

int main() {
    // Example Tree:
    //       5
    //      / \
    //     3   7
    //    / \
    //   2   4
    struct Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);

    printf("Inorder Traversal (Sorted): ");
    printInorderSorted(root);  // Output: 2 3 4 5 7
    printf("\n");

    return 0;
}
