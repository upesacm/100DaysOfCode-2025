#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int value) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find Minimum
int findMin(struct Node* root) {
    if (root == NULL) return -1;
    struct Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current->data;
}

// Find Maximum
int findMax(struct Node* root) {
    if (root == NULL) return -1;
    struct Node* current = root;
    while (current->right != NULL)
        current = current->right;
    return current->data;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);

    printf("Minimum = %d\n", findMin(root));
    printf("Maximum = %d\n", findMax(root));

    return 0;
}

