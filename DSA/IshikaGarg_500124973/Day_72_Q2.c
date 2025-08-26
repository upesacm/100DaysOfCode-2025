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

// Recursive function to check if two trees are identical
int areIdentical(struct Node* t1, struct Node* t2) {
    // If both are NULL, they are identical
    if (t1 == NULL && t2 == NULL)
        return 1;

    // If one is NULL and other is not, they are not identical
    if (t1 == NULL || t2 == NULL)
        return 0;

    // Check current node values + left subtree + right subtree
    return (t1->data == t2->data) &&
           areIdentical(t1->left, t2->left) &&
           areIdentical(t1->right, t2->right);
}

int main() {
    // Example 1
    struct Node* tree1 = newNode(1);
    tree1->left = newNode(2);
    tree1->right = newNode(3);

    struct Node* tree2 = newNode(1);
    tree2->left = newNode(2);
    tree2->right = newNode(3);

    if (areIdentical(tree1, tree2))
        printf("Yes\n");
    else
        printf("No\n");

    // Example 2
    struct Node* tree3 = newNode(1);
    tree3->left = newNode(2);

    struct Node* tree4 = newNode(1);
    tree4->right = newNode(2);

    if (areIdentical(tree3, tree4))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

