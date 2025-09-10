#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* createTree() {
    int data;
    printf("Enter node value (-1 for null): ");
    scanf("%d", &data);
    if (data == -1) return NULL;
    
    struct Node* root = createNode(data);
    printf("Enter left subtree of %d (BST order)\n", data);
    root->left = createTree();
    printf("Enter right subtree of %d (BST order)\n", data);
    root->right = createTree();
    return root;
}

int findMin(struct Node* root) {
    if (root == NULL) return -1; // Assuming positive values in tree
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int findMax(struct Node* root) {
    if (root == NULL) return -1; // Assuming positive values in tree
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

int main() {
    printf("Create BST (preorder, enter -1 for null nodes, maintain BST property):\n");
    struct Node* root = createTree();
    
    int min = findMin(root);
    int max = findMax(root);
    
    if (min == -1 || max == -1) {
        printf("Tree is empty\n");
    } else {
        printf("Min = %d, Max = %d\n", min, max);
    }
    return 0;
}
