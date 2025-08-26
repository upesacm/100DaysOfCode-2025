#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to convert binary tree to its mirror
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right child
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively call for left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Inorder before mirroring: ");
    inorder(root);

    mirror(root);

    printf("\nInorder after mirroring: ");
    inorder(root);

    return 0;
}

