#include <stdio.h>
#include <stdlib.h>

// Define a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Recursive function to print nodes at distance K
void printKDistance(struct Node* root, int K) {
    if (root == NULL)
        return;

    if (K == 0) {
        printf("%d ", root->data);
        return;
    }

    // Recurse for left and right subtrees
    printKDistance(root->left, K - 1);
    printKDistance(root->right, K - 1);
}

// Driver code
int main() {
    /* Constructed binary tree is:
             1
            / \
           2   3
          / \
         4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int K = 2;
    printf("Nodes at distance %d from root are:\n", K);
    printKDistance(root, K);

    return 0;
}

