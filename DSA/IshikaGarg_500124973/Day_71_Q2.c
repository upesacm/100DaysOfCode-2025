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

// Recursive function to count leaf nodes
int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;

    // If node has no children -> it's a leaf
    if (root->left == NULL && root->right == NULL)
        return 1;

    // Otherwise, count leaves in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

// Driver code
int main() {
    /*
       Example Tree 1:
            1
           / \
          2   3
       Leaf nodes: 2, 3 → Count = 2
    */
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);

    printf("Leaf Node Count of Tree 1: %d\n", countLeaves(root1));

    /*
       Example Tree 2:
            10
              \
               20
              /
             15
       Leaf nodes: 15 → Count = 1
    */
    struct Node* root2 = newNode(10);
    root2->right = newNode(20);
    root2->right->left = newNode(15);

    printf("Leaf Node Count of Tree 2: %d\n", countLeaves(root2));

    return 0;
}

