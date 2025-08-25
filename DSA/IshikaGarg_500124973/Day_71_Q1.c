#include <stdio.h>
#include <stdlib.h>

// Define structure for Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive Inorder Traversal (Left - Root - Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    // Visit left subtree
    inorderTraversal(root->left);

    // Visit current node
    printf("%d ", root->data);

    // Visit right subtree
    inorderTraversal(root->right);
}

// Driver code
int main() {
    /*
       Example Tree 1:
            1
             \
              3
             /
            2
    */
    struct Node* root1 = newNode(1);
    root1->right = newNode(3);
    root1->right->left = newNode(2);

    printf("Inorder Traversal of Tree 1: ");
    inorderTraversal(root1);
    printf("\n");

    /*
       Example Tree 2:
            4
           / \
          2   5
    */
    struct Node* root2 = newNode(4);
    root2->left = newNode(2);
    root2->right = newNode(5);

    printf("Inorder Traversal of Tree 2: ");
    inorderTraversal(root2);
    printf("\n");

    return 0;
}

