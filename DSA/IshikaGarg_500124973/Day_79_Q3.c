#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

// Insert into BST (for test cases)
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return newNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Validate BST using range checking
int isValidBST(struct Node* root, int min, int max) {
    if (root == NULL) return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isValidBST(root->left, min, root->data) &&
           isValidBST(root->right, root->data, max);
}

int main() {
    // Example 1: Valid BST
    struct Node* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);

    if (isValidBST(root1, INT_MIN, INT_MAX))
        printf("Yes\n");
    else
        printf("No\n");

    // Example 2: Invalid BST
    struct Node* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);

    if (isValidBST(root2, INT_MIN, INT_MAX))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

