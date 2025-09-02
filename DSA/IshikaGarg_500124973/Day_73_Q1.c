#include <stdio.h>
#include <stdlib.h>

// Define node structure
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

// Recursive sum function
int sumOfNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    printf("Sum of all nodes = %d\n", sumOfNodes(root));  // Output: 6
    return 0;
}

