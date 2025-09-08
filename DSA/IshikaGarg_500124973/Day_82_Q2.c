#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a node of the BST
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Helper function: returns height if balanced, else -1
int checkBalance(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) return -1;  // left subtree not balanced

    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1) return -1; // right subtree not balanced

    if (abs(leftHeight - rightHeight) > 1)
        return -1; // current node not balanced

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function to check if BST is balanced
bool isBalanced(struct Node* root) {
    return checkBalance(root) != -1;
}

// -------------------- TESTING --------------------
int main() {
    // Example 1: Balanced Tree
    //        4
    //      /   \
    //     2     6
    //    / \   / \
    //   1   3 5   7

    struct Node* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(6);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(5);
    root1->right->right = newNode(7);

    if (isBalanced(root1))
        printf("Yes\n");
    else
        printf("No\n");

    // Example 2: Unbalanced Tree
    //   1
    //    \
    //     2
    //      \
    //       3

    struct Node* root2 = newNode(1);
    root2->right = newNode(2);
    root2->right->right = newNode(3);

    if (isBalanced(root2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
