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

// Recursive function to count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;  // empty tree has 0 nodes

    // 1 for current node + left subtree count + right subtree count
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    // Example 1
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    printf("Total Nodes (Tree1): %d\n", countNodes(root1));  // Output: 3

    // Example 2
    struct Node* root2 = newNode(5);
    root2->right = newNode(6);

    printf("Total Nodes (Tree2): %d\n", countNodes(root2));  // Output: 2

    return 0;
}

