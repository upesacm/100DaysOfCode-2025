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

// Print All Root to Leaf Paths
void printPathsUtil(TreeNode* root, int* path, int pathLen) {
    if (root == NULL) {
        return;
    }
    path[pathLen] = root->data;
    pathLen++;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < pathLen; i++) {
            printf("%d", path[i]);
            if (i < pathLen - 1) {
                printf("->");
            }
        }
        printf("\n");
        return;
    }
    printPathsUtil(root->left, path, pathLen);
    printPathsUtil(root->right, path, pathLen);
}

void printAllPaths(TreeNode* root) {
    int path[100];
    printPathsUtil(root, path, 0);
}

int main() {
    // Example 1
    TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);
    root1->left->right = createNode(5);
    printAllPaths(root1);

    return 0;
}
