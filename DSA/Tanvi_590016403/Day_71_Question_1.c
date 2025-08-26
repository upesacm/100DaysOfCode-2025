#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 1. Inorder Traversal (Left - Root - Right)
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);       // visit left
    printf("%d ", root->data);          // visit root
    inorderTraversal(root->right);      // visit right
}

// 2. Count Leaf Nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1; // leaf node
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// 3. Height of Binary Tree
int heightOfTree(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Driver code
int main() {
    /* Example Tree:
             1
            / \
           2   3
          /
         4
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    printf("\nLeaf Nodes Count: %d", countLeafNodes(root));

    printf("\nHeight of Tree: %d\n", heightOfTree(root));

    return 0;
}
