#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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

int height(struct Node* root, bool* isBalanced) {
    if (root == NULL) return 0;
    
    int leftHeight = height(root->left, isBalanced);
    int rightHeight = height(root->right, isBalanced);
    
    if (abs(leftHeight - rightHeight) > 1) {
        *isBalanced = false;
    }
    
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct Node* root) {
    if (root == NULL) return true;
    bool balanced = true;
    height(root, &balanced);
    return balanced;
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
    
    if (isBalanced(root)) {
        printf("Yes (Tree is balanced)\n");
    } else {
        printf("No (Tree is not balanced)\n");
    }
    
    freeTree(root);
    return 0;
}
