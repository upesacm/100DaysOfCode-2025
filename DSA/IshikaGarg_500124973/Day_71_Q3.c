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

// Recursive function to find height of binary tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;  // empty tree has height 0

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Driver code
int main() {
    /*
       Example Tree 1:
            1
           /
          2
         /
        3
       Height = 3
    */
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->left->left = newNode(3);

    printf("Height of Tree 1: %d\n", height(root1));

    /*
       Example Tree 2:
            1
           / \
          2   3
       Height = 2
    */
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    printf("Height of Tree 2: %d\n", height(root2));

    return 0;
}

