#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Utility function: returns height if balanced, -1 if not balanced
int checkHeight(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1; // Left not balanced

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1; // Right not balanced

    if (abs(leftHeight - rightHeight) > 1)
        return -1; // Current node not balanced

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to check if tree is balanced
bool isBalanced(struct Node* root) {
    return checkHeight(root) != -1;
}

// Driver code
int main() {
    /* Example 1:
            1
           /
          2
         /
        3
       Output: No
    */
    struct Node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->left->left = newNode(3);

    if (isBalanced(root1))
        printf("Yes\n");
    else
        printf("No\n");

    /* Example 2:
            1
           / \
          2   3
       Output: Yes
    */
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);

    if (isBalanced(root2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}

