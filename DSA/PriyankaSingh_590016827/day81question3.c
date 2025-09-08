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

// Print Nodes in Range
void printNodesInRange(TreeNode* root, int L, int R) {
    if (root == NULL) {
        return;
    }
    if (root->data > L) {
        printNodesInRange(root->left, L, R);
    }
    if (root->data >= L && root->data <= R) {
        printf("%d ", root->data);
    }
    if (root->data < R) {
        printNodesInRange(root->right, L, R);
    }
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(10);
    root1->left = createNode(5);
    root1->right = createNode(15);
    root1->left->left = createNode(3);
    root1->left->right = createNode(7);
    root1->right->right = createNode(18);
    int L1 = 7, R1 = 15;
    printf("Nodes in range [%d, %d]: ", L1, R1);
    printNodesInRange(root1, L1, R1);
    printf("\n");

    // Example 2
    TreeNode* root2 = createNode(6);
    root2->left = createNode(2);
    root2->right = createNode(8);
    root2->left->left = createNode(0);
    root2->left->right = createNode(4);
    root2->right->left = createNode(7);
    root2->right->right = createNode(9);
    int L2 = 2, R2 = 8;
    printf("Nodes in range [%d, %d]: ", L2, R2);
    printNodesInRange(root2, L2, R2);
    printf("\n");

    return 0;
}
