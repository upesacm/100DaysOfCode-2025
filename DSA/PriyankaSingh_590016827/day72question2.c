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

// Check if Two Trees are Identical
int isIdentical(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    if (root1->data == root2->data &&
        isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right)) {
        return 1;
    }
    return 0;
}

int main() {
    // Example 1
    TreeNode* root1_ex1 = createNode(1);
    root1_ex1->left = createNode(2);
    root1_ex1->right = createNode(3);
    TreeNode* root2_ex1 = createNode(1);
    root2_ex1->left = createNode(2);
    root2_ex1->right = createNode(3);
    if (isIdentical(root1_ex1, root2_ex1)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // Example 2
    TreeNode* root1_ex2 = createNode(1);
    root1_ex2->left = createNode(2);
    TreeNode* root2_ex2 = createNode(1);
    root2_ex2->right = createNode(2);
    if (isIdentical(root1_ex2, root2_ex2)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
