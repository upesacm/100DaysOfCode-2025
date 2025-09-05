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

// Range Sum of BST
int rangeSumBST(TreeNode* root, int L, int R) {
    if (root == NULL) {
        return 0;
    }
    int sum = 0;
    if (root->data >= L && root->data <= R) {
        sum += root->data;
    }
    if (root->data > L) {
        sum += rangeSumBST(root->left, L, R);
    }
    if (root->data < R) {
        sum += rangeSumBST(root->right, L, R);
    }
    return sum;
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
    printf("Range sum of BST: %d\n", rangeSumBST(root1, L1, R1));

    // Example 2
    TreeNode* root2 = createNode(10);
    root2->left = createNode(5);
    root2->right = createNode(15);
    root2->left->left = createNode(3);
    root2->left->right = createNode(7);
    root2->right->left = createNode(13);
    root2->right->right = createNode(18);
    int L2 = 6, R2 = 10;
    printf("Range sum of BST: %d\n", rangeSumBST(root2, L2, R2));

    return 0;
}
