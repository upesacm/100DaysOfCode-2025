#include <stdio.h>
#include <stdlib.h>

// Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int key) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = key;
    temp->left = temp->right = NULL;
    return temp;
}

// Utility function to get max of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to calculate height & update diameter
int diameterUtil(struct Node* root, int* diameter) {
    if (root == NULL) return 0;

    // Get heights of left and right subtrees
    int leftHeight = diameterUtil(root->left, diameter);
    int rightHeight = diameterUtil(root->right, diameter);

    // Update diameter if path through root is larger
    int localDiameter = leftHeight + rightHeight + 1;
    if (localDiameter > *diameter) {
        *diameter = localDiameter;
    }

    // Return height of current node
    return 1 + max(leftHeight, rightHeight);
}

// Function to calculate diameter of tree
int diameter(struct Node* root) {
    int dia = 0;
    diameterUtil(root, &dia);
    return dia;
}

// Driver code
int main() {
    /*
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

    printf("Diameter of tree is: %d\n", diameter(root)); 
    // Expected Output: 4 (Path: 4 → 2 → 1 → 3)

    return 0;
}

