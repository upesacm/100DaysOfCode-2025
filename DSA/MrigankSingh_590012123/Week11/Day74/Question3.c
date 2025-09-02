#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int getTreeHeight(struct Node* root) {
    if (root == NULL) return 0;
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void printArray(int path[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d", path[i]);
        if (i < len - 1) printf("->");
    }
    printf("\n");
}

void printPaths(struct Node* root, int path[], int pathLen) {
    if (root == NULL) return;
    
    path[pathLen] = root->data;
    pathLen++;
    
    if (root->left == NULL && root->right == NULL) {
        printArray(path, pathLen);
    } else {
        printPaths(root->left, path, pathLen);
        printPaths(root->right, path, pathLen);
    }
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
        return 0;
    }
    
    int maxHeight = getTreeHeight(root);
    int* path = (int*)malloc(maxHeight * sizeof(int));
    if (!path) {
        printf("Memory allocation failed!\n");
        freeTree(root);
        return 1;
    }
    
    printf("Root to leaf paths:\n");
    printPaths(root, path, 0);
    
    free(path);
    freeTree(root);
    return 0;
}
