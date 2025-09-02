#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    if (scanf("%d", &data) != 1) {
        printf("Invalid input!\n");
        exit(1);
    }
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d\n", data);
    root->right = createTree();
    return root;
}

int findMax(struct Node* root) {
    if (root == NULL) return INT_MIN;
    
    int currentMax = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    
    if (leftMax > currentMax) currentMax = leftMax;
    if (rightMax > currentMax) currentMax = rightMax;
    
    return currentMax;
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    root = createTree();
    
    if (root == NULL) {
        printf("Tree is empty\n");
    } else {
        int max = findMax(root);
        printf("Maximum value in tree: %d\n", max);
    }
    
    freeTree(root);
    return 0;
}
