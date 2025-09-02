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

void printNodesAtK(struct Node* root, int k, int currentLevel) {
    if (root == NULL) return;
    
    if (currentLevel == k) {
        printf("%d ", root->data);
        return;
    }
    
    printNodesAtK(root->left, k, currentLevel + 1);
    printNodesAtK(root->right, k, currentLevel + 1);
}

void freeTree(struct Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    int k;
    
    printf("Create binary tree (preorder, enter -1 for null nodes):\n");
    root = createTree();
    
    printf("Enter distance K: ");
    if (scanf("%d", &k) != 1 || k < 0) {
        printf("Invalid distance value!\n");
        freeTree(root);
        return 1;
    }
    
    printf("Nodes at distance %d: ", k);
    printNodesAtK(root, k, 0);
    printf("\n");
    
    freeTree(root);
    return 0;
}
