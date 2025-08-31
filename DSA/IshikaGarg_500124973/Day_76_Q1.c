#include <stdio.h>
#include <stdlib.h>

// Tree node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to convert to Sum Tree (post-order traversal)
int toSumTree(struct Node* root) {
    if (root == NULL)
        return 0;

    // Store old value
    int old_val = root->data;

    // Recursively convert left and right subtrees
    int left_sum = toSumTree(root->left);
    int right_sum = toSumTree(root->right);

    // Update current node to sum of left and right subtree values
    root->data = left_sum + right_sum;

    // Return sum of old value + new value (for parent use)
    return root->data + old_val;
}

// Inorder traversal for checking result
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    /* Example Tree
             10
            /  \
          -2    6
          / \  / \
         8 -4 7  5
    */
    struct Node* root = newNode(10);
    root->left = newNode(-2);
    root->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right = newNode(-4);
    root->right->left = newNode(7);
    root->right->right = newNode(5);

    toSumTree(root);

    printf("Inorder Traversal of Sum Tree: ");
    inorder(root);
    return 0;
}

