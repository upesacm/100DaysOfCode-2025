#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Print Nodes at K Distance
void printNodesAtKDistance(TreeNode* root, int k) {
    if (root == NULL || k < 0) {
        return;
    }
    if (k == 0) {
        printf("%d ", root->data);
        return;
    }
    printNodesAtKDistance(root->left, k - 1);
    printNodesAtKDistance(root->right, k - 1);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->left = createNode(4);
    root1->left->right = createNode(5);
    int k1 = 2;
    printf("Nodes at distance %d from root: ", k1);
    printNodesAtKDistance(root1, k1);
    printf("\n");

    return 0;
}
